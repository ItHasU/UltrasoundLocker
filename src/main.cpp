#include "DigiKeyboardFr.h"

const int TRIG = 0; // TRIG PIN
const int ECHO = 2; // ECHO PIN

int awayCount = 0;

void setup()
{
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);

  pinMode(TRIG, OUTPUT);
  digitalWrite(ECHO, LOW);
  pinMode(ECHO, INPUT);
}

void loop()
{
  // Trigger ultrasound sensor
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Wait for echo
  int lecture_echo = pulseIn(ECHO, HIGH);
  int cm = lecture_echo / 58;

  if (cm > 50)
  {
    awayCount++;
  }
  else
  {
    awayCount = 0;
  }

  if (awayCount > 3 && awayCount < 10)
  {
    // Away for more than XX cycles
    // After YY cycles, we concider it is no more necessary to send lockdown shortcut
    // ... this may also allow the computer to go into sleep mode
    DigiKeyboard.sendKeyStroke(KEY_L, MOD_GUI_LEFT);
  }

  // It's better to use DigiKeyboard.delay() over the regular Arduino delay()
  // if doing keyboard stuff because it keeps talking to the computer to make
  // sure the computer knows the keyboard is alive and connected
  DigiKeyboardFr.delay(1000);
}
