#include <SPI.h>
#include <MFRC522.h>

constexpr uint8_t RST_PIN = 9;
constexpr uint8_t SS_PIN = 10;
int DENY_PIN = 3;
int ALLOW_PIN = 2;

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
	Serial.begin(9600);
	while (!Serial);
	SPI.begin();
	mfrc522.PCD_Init();
	mfrc522.PCD_DumpVersionToSerial();
	Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));

  pinMode(DENY_PIN, OUTPUT);
  pinMode(ALLOW_PIN, OUTPUT);
}

void loop() {
	if ( ! mfrc522.PICC_IsNewCardPresent()) {
		return;
	}

	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
	}

  String content= "";
  byte letter;
  
  for (byte i = 0; i < mfrc522.uid.size; i++){
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "04 41 66 12 4E 45 80"){
    Serial.println("Authorized access");
    Serial.println();

    digitalWrite(ALLOW_PIN, HIGH);
    delay(2000);
    digitalWrite(ALLOW_PIN, LOW);
  } else {
    Serial.println(" Access denied");
    
    digitalWrite(DENY_PIN, HIGH);
    delay(2000);
    digitalWrite(DENY_PIN, LOW);
  }
}
