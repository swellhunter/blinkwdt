# blinkwdt - For ATtiny85 Watch Dog Timer Reset.

It's not what you think. 
This is not a WDIE example of a Watch Dog Timer Interrupt being used to toggle a LED in a non-blocking manner.

Rather, this is a test bed to verify the correct operation of an alternatively defined wdt_enable().
Initially this was to confirm that only "one punch" was required for the WDTCR. As indicated by:

https://bigdanzblog.wordpress.com/2015/07/20/resetting-rebooting-attiny85-with-watchdog-timer-wdt/

There are other ways this could be done in Arduino land for the ATTinyx5's. But this is probably closest to the code Atmel would have supplied for the function, and also how it might be done in a project.

I am using Spence Konde's ATTinyCore : https://github.com/SpenceKonde/ATTinyCore

A possible (destructive) enhancement would be to increment the WDTO value, storing it in EEPROM between boots.

It works in any case.

As an observation, the state of the output pin is apparently preserved through a WDT reboot.
I was previously led to believe that this should not be happening, and the device should run through a stage of resetting such things to default initialised values.

(Although traditionally this did not even happen for the stack pointer, and this is a recent enhancement on newer devices.).

So I really cannot see the difference between using the WDT for a forced reboot after an intentional stall and :

```
SP    = RAMEND;
MCUSR = 0;
SREG  = 0;
asm("RJMP 0"); 
```

The ATtiny25/45/85 MCU's do not have a CCP register. The ATtiny10 does, bizarrely the signature is also 0xD8, and there are 4 clock cycles to make changes, during which interrupts are ignored. (Check this).

They dont have a a WDTCSR either, it is a WDTCR, and as evidenced by this program it is not particularly protected during an enable. One punch is enough.

To do : set it up for 2s, wait half a second, and change it to 8s, to test if two punches are required for a "change".
