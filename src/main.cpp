#include "Arduino.h"
#include "DigiKeyboardFr.h"

const int TRIG = 0;             // TRIG PIN, we use 0 cause it is not related to USB
const int USB_TIMEOUT_MS = 100; // Timeout during which the usb will have some time to do its stuff
                                // Keep this low since we won't retrieve the button state during this time

void setup()
{
  pinMode(TRIG, INPUT_PULLUP);

  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
}

void loop()
{
  // Wait for button pushed
  int pushed = digitalRead(TRIG);
  if (pushed == LOW)
  {
    // Trigger lock
    DigiKeyboard.sendKeyStroke(KEY_FR_L, MOD_GUI_LEFT);
  }

  // It's better to use DigiKeyboard.delay() over the regular Arduino delay()
  // if doing keyboard stuff because it keeps talking to the computer to make
  // sure the computer knows the keyboard is alive and connected
  DigiKeyboard.delay(USB_TIMEOUT_MS);
}
