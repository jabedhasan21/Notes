#!/bin/sh
file="./array.sh"

if [ -b $file ]
then
  echo "File is a block special file"
else
  echo "File is not a block special file"
fi

if [ -c $file ]
then
  echo "File is a character special file"
else
  echo "File is not a character special file"
fi

if [ -d $file ]
then
  echo "File is a directory"
else
  echo "File is not a directory"
fi

if [ -g $file ]
then
  echo "File has set it's group ID (SGID) bit"
else
  echo "File has not set group ID (SGID) bit"
fi

if [ -k $file ]
then
  echo "File has set it's sticky bit"
else
  echo "File has not set sticky bit"
fi

if [ -p $file ]
then
  echo "File is a named pipe"
else
  echo "File is not a named pipe"
fi

if [ -t $file ]
then
  echo "File descriptor is open and associated with a terminal"
else
  echo "File descriptor is not open and associated with a terminal"
fi

if [ -u $file ]
then
  echo "File has Set it's User ID (SUID) bit"
else
  echo "File is not Set it's User ID (SUID) bit"
fi

if [ -r $file ]
then
  echo "File has read access"
else
  echo "File does not have read access"
fi

if [ -w $file ]
then
  echo "File has write permission"
else
  echo "File does not have write permission"
fi

if [ -x $file ]
then
  echo "File has execute permission"
else
  echo "File does not have execute permission"
fi

if [[ -f $file ]]; then
  echo "File is an ordinary file"
else
  echo "This is sepcial file"
fi

if [[ -d $file ]]; then
  echo "File is a directory"
else
  echo "This is not a directory"
fi

if [ -s $file ]
then
  echo "File size is not zero"
else
  echo "File size is zero"
fi

if [ -e $file ]
then
   echo "File exists"
else
   echo "File does not exist"
fi
