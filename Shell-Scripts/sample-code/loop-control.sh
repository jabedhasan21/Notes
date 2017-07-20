#!/bin/sh

#The infinite Loop: if a >= 10
echo "Enter a number:"
read a;

until [  $a -lt 10 ]; do
  echo $a
  a=`expr $a + 1`
done

#The break Statement
for var1 in 1 2 3
do
   for var2 in 0 5
   do
      if [ $var1 -eq 2 -a $var2 -eq 0 ]
      then
         break 2
      else
         echo "$var1 $var2"
      fi
   done
done

#The continue statement

NUMS="1 2 3 4 5 6 7"

for NUM in $NUMS
do
   Q=`expr $NUM % 2`
   if [ $Q -eq 0 ]
   then
      echo "Number is an even number!!: $NUM"
      continue
   fi
   echo "Found odd number: $NUM"
done
