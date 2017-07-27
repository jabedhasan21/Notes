#!/bin/sh

echo ${var:-"Variable is not set"}
echo "1 - Value of var is: ${var}"

echo ${var:="Variable is not set"}
echo "2 - Value of var is: ${var}"

unset var
echo ${var:+"This is default value"}
echo "3 - Value of var is: $var"

var="Prefix"
echo ${var:+"This is default value"}
echo "4 - Value of var is: $var"

echo ${var:?"Print this message"}
echo "5 - Value of var is: ${var}"

unset var
echo ${var:?"Print this message"}
echo "6 - Value of var is: ${var}"
