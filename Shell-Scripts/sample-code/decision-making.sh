#!/bin/sh
echo 'Enter a number:'
read a

echo 'Enter a number:'
read b

if [ $a -gt $b ]
 then
  echo 'A is greater than B'
fi

if [ $a == $b ]
then
  echo "A is equal to B"
else
    echo "A is not equal to B"
fi

if [[ $a == $b ]]; then
  echo "A is equal to B"
elif [[ $a -gt $b ]]; then
  echo "A is greater than B"
elif [[ $a -lt $b ]]; then
  echo "A is less than B"
else
  echo "None of the condition met"
fi
