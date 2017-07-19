#!/bin/sh
echo "File name:`basename ${0}`"
echo "Enter a number:"
read a
case `expr $a % 2` in
  1) echo "Number is odd"
  ;;
  0) echo "Number is even"
esac

option="${1}"
case "$option" in
  -f) FILE="${2}"
       echo "File name is $FILE"
    ;;
  -d) DIR="${2}"
      echo "Dir name is $DIR"
    ;;
  *)
  echo "`basename ${0}`:usage: [-f file] | [-d directory]"
      exit 1 # Command to come out of the program with status 1
      ;;
esac
