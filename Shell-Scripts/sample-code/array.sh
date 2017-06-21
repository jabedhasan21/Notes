#!/bin/sh

NAME[0]="Hasan"
NAME[1]="Md"
NAME[2]="Jabed"
echo "First Index: ${NAME[0]}"
echo "Second Index: ${NAME[1]}"
echo "Using * as Index: ${NAME[*]}"
echo "Using @ as Index: ${NAME[@]}"
