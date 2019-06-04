#echo "program $0 first args $1 second $2 third $3"
#!/bin/sh
set -x
#set +x

#spcial symbools
# $$ $# $? $0
echo "welcome"
echo "enter val x="
#reading from console
#read x
#echo "$x"
var="4545646"
echo $var

echo $$
#array in shell

N[0]=1
N[1]=2
echo "${N[0]}"

# external program to computes awk, expr
#
#val=2;
#sum=`expr $val + 5`
#echo $sum
#i=1
#while [ $i -lt 10 ];
#do
#i=`expr $i + 1`
#echo "$i"
#done
NUM="1 2 3 4 5"

for i in $NUM
do
    echo "$i"
done
var=2

if [ $var -eq 2 ]
then
 echo "same"
else
 echo "not same"
fi

#unset var
