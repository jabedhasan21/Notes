#!/bin/sh

for (( i = 100; i < 109; i++ )); do
  echo $i;
done

for var in 0 1 2 3 4 5 6 7 8 9
do
  echo $var
done

for FILE in $HOME/.bash*
do
  echo $FILE
done

for DRINK in tea  sd cofee water juice appe all none
do
   case $DRINK in
      tea|cofee|water|all)
         echo "Go to canteen"
         ;;
      juice|appe)
         echo "Available at home"
      ;;
      none)
         break
      ;;
      *) echo "ERROR: Invalid selection"
      ;;
   esac
done

select DRINK in tea cofee water juice appe all none
do
   case $DRINK in
      tea|cofee|water|all)
         echo "Go to canteen"
         ;;
      juice|appe)
         echo "Available at home"
      ;;
      none)
         break
      ;;
      *) echo "ERROR: Invalid selection"
      ;;
   esac
done
