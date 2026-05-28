#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
#include "HX711.h"

// Pin Definitions
#define RST_PIN         9
#define SS_PIN          10
#define LOADCELL_DOUT_PIN A0
#define LOADCELL_SCK_PIN  A1

// Threshold in grams (2kg = 2000g)
const float THRESHOLD = 2000.0;

// Calibration factor (Adjust this value based on your specific load cell calibration)
const long CALIBRATION_FACTOR = 420; 

// Authorized RFID Card UID (Replace with your actual card's UID bytes)
const byte AUTHORIZED_UID[] = {0XDE, 0xAD, 0xBE, 0xEF}; 

// Object Initializations
LiquidCrystal_I2C lcd(0x27, 16, 2); // Change address to 0x3F if 0x27 doesn't work
MFRC522 mfrc522(SS_PIN, RST_PIN);
HX711 scale;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  
  // Initialize Load Cell
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(CALIBRATION_FACTOR);
  scale.tare(); // Resets the scale to 0

  // Standard simple startup display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("measuring.....");
  delay(2000);
}

void loop() {
  // 1. Measure and Process Weight
  float weight = scale.get_units(5); // Average of 5 readings
  
  // If reading is slightly negative due to noise, snap it to 0
  if (weight < 0 && weight > -10.0) {
    weight = 0.0;
  }

  // Print to Serial Monitor
  Serial.print("Weight: ");
  Serial.print(weight, 2);
  Serial.println(" g");

  if (weight < THRESHOLD) {
    Serial.println("STOCK is LOW - Refill");
  } else {
    Serial.println("STOCK level is OK");
  }

  // Update Default LCD Display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Wt: ");
  lcd.print(weight / 1000.0, 3); // Convert grams to kg for LCD view
  lcd.print(" kg");
  lcd.setCursor(0, 1);
  lcd.print("Scan Card...");

  // 2. Check for RFID Scans
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    if (checkUID(mfrc522.uid.uidByte, mfrc522.uid.size)) {
      // Access Granted
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Authorized");
      lcd.setCursor(0, 1);
      lcd.print("Refill Allowed");
      
      Serial.println("Access Granted: Authorized Refill");
    } else {
      // Access Denied
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Access Denied");
      
      Serial.println("Access Denied!");
    }
    
    // Halt PICC & Stop encryption on PCD
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    
    delay(3000); // Hold the auth message on screen for 3 seconds
  }

  delay(500); // Main loop pacing
}

// Helper function to validate the scanned RFID UID against authorized master tag
bool checkUID(byte *scannedUID, byte size) {
  if (size != sizeof(AUTHORIZED_UID)) return false;
  for (byte i = 0; i < size; i++) {
    if (scannedUID[i] != AUTHORIZED_UID[i]) {
      return false;
    }
  }
  return true;
}
