#!/bin/sh
a=1
while [ $a -lt 192 ]
do
        echo $a "- iteration"

	cat /sys/devices/system/cpu/cpu$a/online

        #perf record -e instructions -e branches -e branch-misses -e block:block_rq_issue -e major-faults -e faults -e cycles -e context-switches -e cache-misses -C0-7 -o dop8-iter-$a.data  numactl --physcpubind=16 --localalloc ./hammerdbcli auto pgsql-tpch-run.tcl

        a=`expr $a + 1`

done

