#!/bin/sh

echo "Input a number:"
read a

echo "Input a number:"
read b

echo "A: $a"
echo "B: $b"

if [ $a -eq $b ]
then
  echo "$a -eq $b: a is equal to b"
else
  echo "$a -eq $b: a is not equal to b"
fi

if [ $a -lt $b ]
then
  echo "$a -lt $b: a is less then b"
else
  echo "$a -lt $b: a is not less then b"
fi

if [ $a -gt $b ]
then
  echo "$a -gt $b: a is greater then b"
else
  echo "$a -gt $b: a is not greater then b"
fi

if [ $a -ge $b ]
then
   echo "$a -ge $b: a is greater or  equal to b"
else
   echo "$a -ge $b: a is not greater or equal to b"
fi

if [ $a -le $b ]
then
   echo "$a -le $b: a is less or  equal to b"
else
   echo "$a -le $b: a is not less or equal to b"
fi


if [ $a -ne $b ]
then
  echo "$a -ne $b: a is not equal to b"
else
  echo "$a -ne $b: a is equal to b"
fi
