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
 | 11|--<330>--|B|
 | 10|--<330>--|G|
 |  9|--<330>--|R|
 |GND|---------|G|
 +---+         +-+
```
