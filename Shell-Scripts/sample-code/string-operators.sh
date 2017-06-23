#!/bin/sh

echo "Input a string:"
read a

echo "Input a string:"
read b


echo "A: $a"
echo "Length: ${#a}"

echo "B: $b"
echo "Length: ${#b}"



if [ "$a" = "$b" ]
then
  echo "$a = $b : a is equal to b"
else
  echo "$a = $b: a is not equal to b"
fi

if [ "$a" != "$b" ]
then
  echo "$a != $b : a is not equal to b"
else
  echo "$a != $b : a is equal to b"
fi

if [ -z "$a" ]
then
  echo "-z $a: string length is zero"
else
  echo "-z $a: string length is not zero"
fi

if [ -n "$a" ]
then
  echo "-n $a: string length is not zero"
else
  echo "-n $a: string length is zero"
fi

if [ "$a" ]
then
  echo "$a: string is not empty"
else
  echo "$a : string is empty"
fi
