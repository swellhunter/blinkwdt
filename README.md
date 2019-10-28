# blinkwdt

It's not what you think. 
This is not a WDIE example of a Watch Dog Timer Interrupt being used to toggle a LED in a non-blocking manner.

Rather, this is a test bed to verify the correct operation of an alternatively defined wdt_enable().
Initially this was to confirm that only "one punch" was required for the WDTCR. As indicated by:

https://bigdanzblog.wordpress.com/2015/07/20/resetting-rebooting-attiny85-with-watchdog-timer-wdt/

There are other ways this could be done in Arduino land for the ATTinyx5's. But this is probably closest to the code Atmel would have supplied for the function, and also how it might be done in a project.

I am using Spence Konde's ATTinyCore : https://github.com/SpenceKonde/ATTinyCore

A possible (destructive) enhancement would be to increment the WDTO value, storing it in EEPROM between boots.

It works in any case.
