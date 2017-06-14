**The original UNIX shell was written in the mid-1970s by Stephen R. Bourne while he was at AT&T Bell Labs in New Jersey.**

+ The basic concept of a shell script is a list of commands, which are listed in the order of execution.
+ Shell scripts and functions are both interpreted. This means they are not compiled.

# Shell Types
+ The Bourne shell
  - Bourne shell ( sh)
  - Korn shell ( ksh)
  - Bourne Again shell ( bash)
  - POSIX shell ( sh)
+ The C shell
 - C shell ( csh)
 - TENEX/TOPS C shell ( tcsh)

# Variables
+ A variable is a character string to which we assign a value. The value assigned could be a number, text, filename, device, or any other type of data.
+ The name of a variable can contain only letters (a to z or A to Z), numbers ( 0 to 9) or the underscore character ( _ ).

##### Defining Variables
  + variable_name=variable_value
  + ex. `NAME`="Jabed Bangali"
  + To access the value stored in a variable, prefix its name with the dollar sign (`$`)

  + **Read-only Variables :**
  ```#!/bin/sh
    NAME="Jabed Bangali"
    readonly NAME
    NAME="Hasan Md Jabed"
  ```
  + **Unsetting Variables:** `unset variable_name`
   - You cannot use the unset command to unset variables that are marked `readonly`.

##### Variable Types
+ Local Variables:
+ Environment Variables:
+ Shell Variables:

##### Special Variables
+ The `$` character represents the process ID number, or PID, of the current shell :`echo $$`

+ `$0`: The filename of the current script.

+ `$#`: The number of arguments supplied to a script.

+ `$n`: These variables correspond to the arguments with which a script was invoked. Here n is a positive decimal number corresponding to the position of an argument (the first argument is $1, the second argument is $2, and so on).

+ `$*`: All the arguments are double quoted. If a script receives two arguments, $* is equivalent to $1 $2.

+ `$@`: All the arguments are individually double quoted. If a script receives two arguments, $@ is equivalent to $1 $2.
