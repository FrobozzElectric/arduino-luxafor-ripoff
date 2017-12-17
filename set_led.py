#!/usr/bin/env python3

import sys
import time
from serial import Serial

usage = """Usage:

%s <arduino port> <color>

Example arduino port: /dev/ttyACM1

Example colors:

    000 = off
    001 = red
    255 = green
    511 = blue
    767 = red again
""" % (sys.argv[0])

if len(sys.argv) < 3 or len(sys.argv[2]) != 3:
    print(usage)
    sys.exit(1)

port = str(sys.argv[1])
arduino = Serial(port, 9600, timeout=.1)

time.sleep(2)
arduino.write(sys.argv[2].encode())
