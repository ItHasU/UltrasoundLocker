#include "DigiKeyboardFr.h"

void setup()
{
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
}

void loop()
{
  // every charater that thislibrary can type
  DigiKeyboard.sendKeyStroke(KEY_L, MOD_GUI_LEFT);

  // It's better to use DigiKeyboard.delay() over the regular Arduino delay()
  // if doing keyboard stuff because it keeps talking to the computer to make
  // sure the computer knows the keyboard is alive and connected
  DigiKeyboardFr.delay(10000);
}
