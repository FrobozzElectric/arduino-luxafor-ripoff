#!/usr/bin/env python3

import sys
import time
from serial import Serial

port = str(sys.argv[1])
arduino = Serial(port, 9600, timeout=.1)

time.sleep(2)
arduino.write(sys.argv[2].encode())
