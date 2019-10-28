/*
  Blink until wdt reset for ATtiny85.
  Using redefined wdt_enable() from a header file / copybook.
  Uses : https://github.com/SpenceKonde/ATTinyCore
*/

#include <avr/wdt.h>

#ifdef __AVR_ATtiny85__                // extend as required 24,45 work too.
  #include "wdt_x5.h"
#endif

void setup() {
  wdt_reset();
  MCUSR &= ~(1 << WDRF);               // or just zero the whole thing, maybe save.
  wdt_disable();
  pinMode(LED_BUILTIN, OUTPUT);
  delay(3000);                         // in theory enabled here and reset in loop.
}

void loop() {
  //  wdt_enable(WDTO_250MS);          // you'll need pulseview to see this.
  //  wdt_enable(WDTO_500MS);
      wdt_enable(WDTO_1S);             // 3  blinks at 100/400
  //  wdt_enable(WDTO_2S);             // 5  blinks at 100/400
  //  wdt_enable(WDTO_4S);             // 10 blinks at 100/400
  //  wdt_enable(WDTO_8S);             // 19 blinks at 100/400

  for (;;) {                           // from blink example code
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on
    delay(100);                        // wait
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off
    delay(400);                        // wait
  }
}
