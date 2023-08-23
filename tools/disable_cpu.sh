#!/bin/sh
a=96
while [ $a -lt 103 ]
do
        echo 0 > /sys/devices/system/cpu/cpu$a/online
        a=`expr $a + 1`
done
#b=144
#while [ $b -lt 192 ]
#do
#        echo 0 > /sys/devices/system/cpu/cpu$b/online
#        b=`expr $b + 1`
#done

	
