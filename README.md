attiny-433mhz-sender
====================

AVR ATtiny85 433mhz remote control for [Intertechno IT-1500 power outlets](http://www.amazon.de/gp/product/B0054IPASK/ref=as_li_qf_sp_asin_tl?ie=UTF8&amp;camp=1638&amp;creative=6742&amp;creativeASIN=B0054IPASK&amp;linkCode=as2&amp;tag=sweetpi-21).

schematics
----------

![breadboard](https://raw.github.com/sweetpi/attiny-433mhz-sender/master/docs/sender_steckplatine.png)
![circuit diagram](https://raw.github.com/sweetpi/attiny-433mhz-sender/master/docs/sender_schaltplan.png)

part list
---------

* [433Mhz Transmitter Modul][sender]
* [AVR ATtiny85][att85]
* 2x 10kOhm Widerstand
* 2x [switch][taster]
* [battery holder][batt] for 3-5V 
* 1x [LED][led] (Optional)
* 1x LED series resistor (Optional)

 [sender]: http://www.amazon.de/s/?_encoding=UTF8&__mk_de_DE=%C3%83%C2%85M%C3%83%C2%85%C3%85%C2%BD%C3%83%C2%95%C3%83%C2%91&camp=1638&creative=19454&field-keywords=433%20mhz%20transmitter%20module&linkCode=ur2&site-redirect=de&tag=sweetpi-21&url=search-alias%3Daps
 [att85]: http://www.amazon.de/gp/product/B0053TACLU/ref=as_li_ss_tl?ie=UTF8&camp=1638&creative=19454&creativeASIN=B0053TACLU&linkCode=as2&tag=sweetpi-21
 [batt]: http://www.amazon.de/s/?_encoding=UTF8&__mk_de_DE=%C3%83%C2%85M%C3%83%C2%85%C3%85%C2%BD%C3%83%C2%95%C3%83%C2%91&camp=1638&creative=19454&field-keywords=batteriehalter%204xaa&linkCode=ur2&rh=i%3Aaps%2Ck%3Abatteriehalter%204xaa&site-redirect=de&sprefix=batteriehalter%204x%2Caps%2C155&tag=sweetpi-21&url=search-alias%3Daps
 [led]: http://www.amazon.de/s/?_encoding=UTF8&__mk_de_DE=%C3%83%C2%85M%C3%83%C2%85%C3%85%C2%BD%C3%83%C2%95%C3%83%C2%91&camp=1638&creative=19454&field-keywords=Leuchtdioden&linkCode=ur2&site-redirect=de&tag=sweetpi-21&url=search-alias%3Daps
 [taster]: http://www.amazon.de/s/?_encoding=UTF8&__mk_de_DE=%C3%83%C2%85M%C3%83%C2%85%C3%85%C2%BD%C3%83%C2%95%C3%83%C2%91&camp=1638&creative=19454&field-keywords=avr%20programmer&linkCode=ur2&site-redirect=de&tag=tube2mp3-21&url=search-alias%3Daps


source and build
---------------

    sudo apt-get install gcc-avr avr-libc

Build with make:

    make

`rc.h` implements the 433mhz protocoll for the [Intertechno IT-1500 power outlets](http://www.amazon.de/gp/product/B0054IPASK/ref=as_li_qf_sp_asin_tl?ie=UTF8&amp;camp=1638&amp;creative=6742&amp;creativeASIN=B0054IPASK&amp;linkCode=as2&amp;tag=sweetpi-21)


flash
-----

Choose your avr programmer in the `Makefile`:

    AVRDUDE_PROGRAMMER = avrispmkII

Then flash with:

    make program

[Full guide (in German)](http://www.sweetpi.de/blog/553/einen-433mhz-funksender-selber-bauen)