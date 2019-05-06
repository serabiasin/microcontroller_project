#!/bin/sh 

 make clean && make && cd build && st-flash write *.bin 0x8000000 && cd ..
