#!/bin/sh
x=`mips-linux-gnu-readelf -s $1 | grep tPanelFullHD_CMO216_H1L01 | awk '{print $2}'`
y=`mips-linux-gnu-readelf -S $1 | grep '\.data ' | awk '{print $4}'`
len=`mips-linux-gnu-readelf -s $1 | grep tPanelFullHD_CMO216_H1L01 | awk '{print $3}'`
x=`echo $((0x$x))`
y=`echo $((0x$y))`
offset=`echo $((x-y))`
mips-linux-gnu-objcopy -O binary -j .data $1 tmp.bin
dd if=tmp.bin of=$2/pnl.bin bs=1 count=${len} skip=${offset}
rm -f tmp.bin
