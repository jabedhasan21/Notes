#!/bin/sh
echo "Input a number A:"
read a
echo "Input a number B:"
read b

echo "A: $a"
echo "B: $b"

val=`expr $a + $b`
echo "a + b: $val"

val=`expr $a - $b`
echo "a - b: $val"

val=`expr $a \* $b`
echo "a * b: $val"

val=`expr $a / $b`
echo "a / b: $val"

val=`expr $a % $b`
echo "a % b: $val"

if [ $a == $b ]
then
  echo "a is equal to b"
fi

if [ $a != $b ]
then
  echo "a is not equal to b"
fi
