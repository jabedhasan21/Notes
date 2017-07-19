#!/bin/sh
echo "Enter a numner:"
read a;
fact=1;
until [[ ! $a -gt 0 ]]; do
  fact=`expr $fact \* $a`
  a=`expr $a - 1`
done

echo "The factorial of the number is: $fact"
