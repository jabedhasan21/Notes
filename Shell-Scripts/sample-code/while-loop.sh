#!/bin/sh

echo "Enter a number:"
read num;
sum=0;
nslp=$num

printf 'The sum of the series( 1+2+...+%s ) is:' "$num"

while [[ $num -gt 0 ]]; do
  sum=`expr $sum + $num`
  num=`expr $num - 1`
done

printf '%s' "$sum"
echo

# Nesting while Loops

a=0
while [ "$a" -lt $nslp ]    # this is loop1
do
   b="$a"
   while [ "$b" -ge 0 ]  # this is loop2
   do
      printf '%s' "$b "
      b=`expr $b - 1`
   done
   echo
   a=`expr $a + 1`
done
