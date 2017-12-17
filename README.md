## arduino-luxafor-ripoff
This is a simple Arduino sketch and Python utility for controlling an RGB LED over serial.

### Installation
```
$ pip3 install pyserial
```

### Usage
Example to set the LED red:
```shell
$ ./set_led.py /dev/ttyACM0 001
```

### Arduino Schematic
```
Arduino      RGB LED
 +---+         +-+
 | 11|--<820>--|B|
 | 10|--<820>--|G|
 |  9|--<820>--|R|
 |GND|---------|G|
 +---+         +-+
```
