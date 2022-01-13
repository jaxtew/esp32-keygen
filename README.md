# esp32-keygen
Use Arduino-based electronics to generate BIP-39 mnemonic phrases to be used in Bitcoin hardware wallets.
* True randomness for key generation with a physical button
* No Internet connection (can use microcontroller with no physical wireless connectivity to gaurantee)
* Mnemonic phrase shown on LCD screen
* Corresponding public key saved to SD card
* Very easy to use

## Circuit

Components needed to build the circuit below:
* [esp32](https://www.amazon.com/Teyleten-Robot-ESP-WROOM-32-Development-Microcontroller/dp/B09J941VV7/ref=sr_1_1_sspa?crid=2N29BO4YQFDWF&keywords=esp32&qid=1641964022&sprefix=esp32%2Caps%2C91&sr=8-1-spons&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExSkQzN0RHQ1k1WlpWJmVuY3J5cHRlZElkPUEwMDY1MjI0MTBTVElITlY1NEE0SiZlbmNyeXB0ZWRBZElkPUExMDA3MDA5MjFER0FEUVo3MDNWVCZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU&th=1) or [Arduino](https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/ref=sr_1_3?crid=6D2CPDLTXTVB&keywords=arduino+uno&qid=1641964069&sprefix=arduino+uno%2Caps%2C94&sr=8-3) microcontroller
* [SD Card](https://www.amazon.com/HiLetgo-Adater-Interface-Conversion-Arduino/dp/B07BJ2P6X6/ref=sr_1_3?crid=14J08SPZ2OE9A&keywords=arduino+sd+card+module&qid=1641964121&sprefix=arduino+sd+card+module%2Caps%2C82&sr=8-3) module
* [LCD Display](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=sr_1_1_sspa?crid=1O56KYCE0JUKH&keywords=arduino+lcd+display&qid=1641964255&sprefix=arduino+lcd+display%2Caps%2C90&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEyTkw5QlgxMUIyTkI1JmVuY3J5cHRlZElkPUEwMjk3MTMzMlRWT1ExMjlHWlpEUyZlbmNyeXB0ZWRBZElkPUEwOTQ2Njk5WkMzQ1VOQ0VZQ0NZJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==) module (and potentiometer to control brightness)
* [Button](https://www.amazon.com/OCR-180PcsTactile-Momentary-Switches-Assortment/dp/B01MRP025V/ref=sr_1_5?crid=3AHU372XUBU6Q&keywords=breadboard+buttons&qid=1641964299&sprefix=breadboard+buttons%2Caps%2C86&sr=8-5)
* [Power Supply](https://www.amazon.com/Magic-shell-Breadboard-Battery-Assortment/dp/B07RVHQB1S/ref=sr_1_4?keywords=arduino+power+supply+module&qid=1641964369&sprefix=arduino+power+%2Caps%2C85&sr=8-4) module and 9v battery (or whatever powering solution you want)
* [Breadboard](https://www.amazon.com/Breadboards-Solderless-Breadboard-Distribution-Connecting/dp/B07DL13RZH/ref=sr_1_3?crid=T3PBTE5Q7KT4&keywords=breadboard&qid=1641964480&sprefix=breadboard%2Caps%2C91&sr=8-3) and [jumper wires](https://www.amazon.com/EDGELEC-Breadboard-Optional-Assorted-Multicolored/dp/B07GD1ZCHQ/ref=sr_1_4?crid=1S9JE3R8NKVBH&keywords=breadboard%2Bjumper%2Bwires&qid=1641964523&sprefix=breadboard%2Bjumper%2Bwire%2Caps%2C87&sr=8-4&th=1)
* A can-do attitude

![esp32_keygen](https://user-images.githubusercontent.com/6759159/149066876-55fd0ca9-81c0-43b4-95d0-cd499b88e876.jpg)

More detailed wire layouts to come.

Not intended to be used as a hardware wallet itself. Do not send Bitcoin to any keys generated with this without ensuring they can be properly recovered.
