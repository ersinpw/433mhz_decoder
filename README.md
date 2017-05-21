# 433Mhz 

This script allows you to read 433Mhz codes using a Raspberry Pi. The code is tested with Raspberry pi zero and Raspberry pi 3.
The 433Mhz receiver module I have used was the superheterodyne qiachip. This module contains 4 pins (5V VCC, GND and two for Data). It doesn't matter which Data pin you use, they give identical result.

# Connection table

| 433Mhz Pin | Raspberry Pi Pin |
| ------------- | ------------- |
| VCC  | 5V  |
| GND  | GND  |
| Data | GPIO 21/27 |

# Installation

A one line installation:
```console
make
```

And you are done!

# How to run?

```console
./RFsniffer
```
