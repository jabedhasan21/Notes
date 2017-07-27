#!/bin/sh

# Example
printf "This is a test \\ backslash"
echo

printf "This is a test \a alert (BEL)"
echo

printf "This is a test \b backspace"
echo

printf "suppress trailing \c newline"
echo

printf "carriage return\rnine"
echo

printf "This is new line\nnine"
echo

printf "stackoverflow\fnine\fgreat (form feed)"
echo

printf "horizontal \t \t \t tab"
echo

printf "vertical \v \v \v tab"
echo

echo "\n\n\n\n"

DATE=`date`
echo "Date is $DATE"

USERS=`who | wc -l`
echo "Logged in user are $USERS"

UP=`date ; uptime`
echo "Uptime is $UP"
