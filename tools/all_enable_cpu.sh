#!/bin/sh
a=1
while [ $a -lt 192 ]
do
	echo "$a itertation"
        echo 1 > /sys/devices/system/cpu/cpu$a/online
        a=`expr $a + 1`
done

	
