#echo "program $0 first args $1 second $2 third $3"
#!/bin/sh
>log
sudo /home/satyan/ro/resource-optimizer/membalancer/membalancer  -f 25 -u -P 5908 -v1 -m 0.0001 -M 1 -r 2 100 -H -b -c 0-31,128-159 >>log 2>&1 &
first_pid=$!
echo $first_pid
>sar_data
sar 1 600 -o sar_data > /dev/null 2>&1 &
second_pid=$!
echo $second_pid
>numactl_log
sudo sync; echo 3 | sudo tee /proc/sys/vm/drop_caches; numactl --cpunodebind 0 --membind 1  /home/satyan/code/script/XSBench -s Large -g 32000 -l 2000 > numactl_log 2>&1 
third_pid=$!
echo $third_pid
kill $first_pid
kill $second_pid


