#include <LiquidCrystal.h>
#include <SPI.h>
#include <SD.h>
#include "Bitcoin.h"

const int CS_PIN = 5; // SD CARD
const int BUTTON_PIN = 12;
const int SEED_SIZE = 12;
const int ENTROPY_SIZE = 32;

/* RANDOMNESS:
  32 button presses, record last two digits of microsecond timestamp (512 total random bits of entropy)
*/
/* SCROLLING:
  words displayed two at a time, button press moves list down one
*/

LiquidCrystal lcd(2, 4, 33, 32, 22, 21); // Pins, respectively: rs, enable, d4, d5, d6, d7
String seed[SEED_SIZE];

File file;

void reprint(String ln1, String ln2 = "") {
  lcd.clear();
  lcd.home();
  lcd.print(ln1);
  lcd.setCursor(0, 1);
  lcd.print(ln2);
}

void setup() 
{
  lcd.begin(16, 2); // 16 chars, 2 lines
  reprint("Initializing SD");
  if (!SD.begin(CS_PIN)) {
    reprint("SD init failed");
    while (true); // application is basically useless at this point
  }

  reprint("Press button", "randomly");

  uint8_t entropy[ENTROPY_SIZE];

  // get random data
  for (int i = 0; i < ENTROPY_SIZE; i++) {
    while (!digitalRead(BUTTON_PIN)); // wait until next button press
    reprint(String(i+1) + "/" + String(ENTROPY_SIZE));
    uint8_t num = micros() % 100; // last two digits

    entropy[i] = num;

    while (digitalRead(BUTTON_PIN)); // wait until button is released
  }

  reprint("Generating...");
  String mnemonic = generateMnemonic(SEED_SIZE, entropy, ENTROPY_SIZE);

  // copy words from generated mnemonic to word array
  int i = 0;
  for (int j = 0; j < SEED_SIZE; j++) {
    while (mnemonic[i] != ' ') {
      if (i == mnemonic.length())
        break;
      seed[j] += mnemonic[i];
      i += 1;
    }
    i += 1;
  }

  // save public key to SD card
  HDPrivateKey root(mnemonic, "");
  file = SD.open("/xpub.txt", FILE_WRITE);
  file.println(root.xpub());
  file.close();

  reprint("Done", "Pubkey on SD");
}

void loop() 
{
  //delay(1000);
  //return;

  // scroll through seed phrase with button pressed
  for (int i = 0; i < SEED_SIZE; i++) {
    lcd.clear();
    lcd.home();

    lcd.print(String(i+1) + ": " + String(seed[i]));
    lcd.setCursor(0, 1);
    if (i+1 == SEED_SIZE) {
      lcd.print("1: " + String(seed[0]));
    } else {
      lcd.print(String(i+2) + ": " + String(seed[i+1]));
    }

    while (digitalRead(BUTTON_PIN)); // wait until button is released
    while (!digitalRead(BUTTON_PIN)); // wait until next button press
  }
}
