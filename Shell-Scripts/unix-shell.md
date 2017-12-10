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

### Make the script executable: `chmod +x hello-script.sh`

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

+ `$?`: The exit status of the last command executed.

+ `$$`: The process number of the current shell. For shell scripts, this is the process ID under which they are executing.

+ `$!`: The process number of the last background command.

##### Exit Status:
+ The `$?` variable represents the exit status of the previous command.
+ Return an exit status of `0` if they were `successful`, and `1` if they were `unsuccessful`.

## Arrays
+ example:
  ```
  NAME[0]="Hasan"
  NAME[1]="Md"
  NAME[2]="Jabed"
  ```
+ In `ksh` shell, here is the syntax of array initialization.

    `set -A array_name value1 value2 ... valuen`

+ In `bash` shell: `array_name = (value1 ... valuen)`


# Operators
### Arithmetic Operators
+ Bourne shell didn't originally have any mechanism to perform simple arithmetic operations but it uses external programs, either `awk` or `expr`.
+ Ex.
  ```#!/bin/sh
  val=`expr 2 + 2`
  echo "Total value : $val"
  ```

+ The following points need to be considered while using Arithmetic Operators −
 - There must be spaces between operators and expressions. For example, 2+2 is not correct; it should be written as 2 + 2.
 - The complete expression should be enclosed between ‘ ‘, called the inverted commas.

 + It is very important to understand that all the conditional expressions should be inside square braces with spaces around them, for example `[ $a == $b ]` is correct whereas, `[$a==$b]` is incorrect.

### Relational Operators:
 + `-eq`: Checks if the value of two operands are equal.

 + `-ne`: Checks if the value of two operands are not equal.

 + `-gt`: Checks if the value of `left operand` is greater than the value of `right operand`.

 + `-lt`: Checks if the value of `left operand` is less than the value of `right operand`.

 + `-ge`: Checks if the value of `left operand` is greater than or equal to the value of `right operand`.

 + `-le`: Checks if the value of `left operand` is less than or equal to the value of `right operand`.

### Boolean Operators
+ `!`: This is logical negation. This inverts a true condition into false and vice versa.`	[ ! false ] is true.`

+ `-o`: This is logical OR. If one of the operands is true, then the condition becomes true.
`[ $a -lt 20 -o $b -gt 100 ] is true.`

+ `-a`: This is logical AND. If both the operands are true, then the condition becomes true otherwise false.`[ $a -lt 20 -a $b -gt 100 ] is false.`

### String Operators
+ `=`: Checks if the value of two operands are equal or not. `[ $a = $b ]`

+ `!=`: Checks if the value of two operands are equal or not.`[ $a != $b ]`

+ `-z`: Checks if the given string operand size is zero; if it is zero length, then it returns true.`[ -z "$a" ]`

+ `-n`: Checks if the given string operand size is non-zero; if it is nonzero length, then it returns true. `[ -n "$a" ]`

+ `str`: Checks if str is not the empty string; if it is empty, then it returns false.`[ "$a" ]`

+ [string check in bash with -z and -n](https://stackoverflow.com/questions/16355213/string-check-in-bash-with-z-and-n)

### File Test Operators
+ `[ -b $file ]`: Checks if file is a `block special` file; if yes, then the condition becomes `true`.

+ `-c`: If file is a `character` special file.

+ `-d`: If file is a `directory`.

+ `-f`: If file is an `ordinary file` as opposed to a directory or special file.

+ `-g`: If file has it's set `group ID (SGID) bit` set.

+ `-k`: If file has it's `sticky bit` set.

+ `-p`: If file is a `named pipe`.

+ `-t`: If file `descriptor is open` and associated with a terminal.

+ `-u`: If file has it's Set `User ID (SUID) bit` set.

+ `-r`:  If file is `readable`.

+ `-w`:  If file is `writable`.

+ `-x`:  If file is `executable`.

+ `-s`:  If file has `size greater than 0`.

+ `-e`: if file `exists`.

+ [C Shell Operators](https://www.tutorialspoint.com/unix/unix-c-shell-operators.htm)

+ [Korn Shell Operators](https://www.tutorialspoint.com/unix/unix-korn-shell-operators.htm)

### Shell Decision Making
+ Unix Shell supports following forms of `if…else` statement −
  - `if...fi` statement
  - `if...else...fi` statement
  - `if...elif...else...fi` statement
+ `case...esac` Statement

### Shell Loop Types
+ while
+ for
+ **until**
  ```
  until command
  do
   Statement(s) to be executed until command is false
   done
  ```
+ **select**: The select loop provides an easy way to create a numbered menu from which users can select options. It is useful when you need to ask the user to choose one or more items from a list of choices.
  ```
  select var in word1 word2 ... wordN
  do
     Statement(s) to be executed for every word.
  done
  ```

  You can change the prompt displayed by the select loop by altering the variable `PS3` as follows −

  $PS3 = "Please make a selection => " ; export PS3

### Loop Control
+ The infinite Loop
+ The break Statement: The break command can also be used to exit from a nested loop using this format − `break n`.
  Here `n` specifies the `nth` enclosing loop to the exit from.
+ The continue statement: Like with the break statement, an integer argument can be given to the continue command to skip commands from nested loops. `continue n`

### Substitution
+ **What is Substitution?**

  The shell performs substitution when it `encounters an expression` that contains one or more `special characters`.

#### Variable Substitution
Variable substitution `enables` the shell programmer to `manipulate the value of a variable` based on its `state`.

+ `${var}`: Substitute the value of var.

+ `${var:-word}`: If var is `null or unset`, word is `substituted` for var. The value of var does not change.

+ `${var:+word}`: If var is `set`, word is `substituted` for var. The value of var does not change.

+ `${var:=word}`: If var is `null or unset`, var is `set` to the value of word.

+ `${var:?message}`: If var is `null or unset`, message is printed to standard error. This `checks that variables are set correctly`.

### Quoting Mechanisms
+ **The Metacharacters :** Unix Shell provides various metacharacters which have special meaning while using them in any Shell Script and causes termination of a word unless quoted.

+ For example, `?` matches with a single character while listing files in a directory and an `*` matches more than one character.

+ Here is a list of most of the shell special characters (also called `metacharacters`) :
 `* ? [ ] ' " \ $ ; & ( ) | ^ < > new-line space tab`

+ A character may be quoted (i.e., made to stand for itself) by preceding it with a `\`.

+ `echo Hello; Word` : this execution will not show the expected result.

+ But this `echo Hello\; Word` will show expected result for the `Back slash \`


##### Quoting & Description
+ **Single quote : (' '):** All special characters between these quotes lose their special meaning.

 + `echo <-$1500.**>; (update?) [y|n]` This will show  parse error.

 + Putting a backslash in front of each special character is tedious and makes the line difficult to read. Like: `echo \<-\$1500.\*\*\>\; \(update\?\) \[y\|n\]`

 + There is an easy way to quote a large group of characters. Put a single quote (') at the beginning and at the end of the string −  `echo '<-$1500.**>; (update?) [y|n]'`

 + If a single quote appears within a string to be output, you should not put the whole string within single quotes instead you should precede that using a backslash (\) as follows − `echo It\'s Shell Programming`

+ **Double quote : ( " " ):** Most special characters between these quotes lose their special meaning with these exceptions - `$`  `\$` `\'` `\"`  `\\` and **`**
 + Try to execute the following shell script. This shell script makes use of single quote −
 ```
 VAR=ZARA
 echo '$VAR owes <-$1500.**>; [ as of (`date +%m/%d`) ]'
 ```
 + Upon execution, you will receive the following result − ```$VAR owes <-$1500.**>; [ as of (`date +%m/%d`) ]```

 + This is not what had to be displayed. It is obvious that single quotes prevent variable substitution. If you want to substitute variable values and to make inverted commas work as expected, then you would need to put your commands in double quotes as follows −
 ```
 VAR=ZARA
echo "$VAR owes <-\$1500.**>; [ as of (`date +%m/%d`) ]"
```
+ **Backquotes:** Putting any Shell command in between backquotes executes the command.
```
DATE=`date`
echo "Current Date: $DATE"
```
### Shell Input/Output I/O Redirections
+ **Output Redirection:** The output from a command normally intended for standard output can be easily diverted to a file instead. This capability is known as output redirection.

  If the notation `>` file is appended to any command that normally writes its output to standard output, the output of that command will be written to file instead of your terminal.

  + `$ who > users`

  + You can use `>>` operator to append the output in an existing file as follows: `echo line 2 >> users`
+ **Input Redirection:** Just as the output of a command can be redirected to a file, so can the input of a command be redirected from a file. As the **greater-than character** `>` is used for output redirection, the **less-than character** `<` is used to redirect the input of a command.

  The commands that normally take their input from the standard input can have their input redirected from a file in this manner. For example, to count the number of lines in the file users generated above, you can execute the command as follows −
  ```
  $ wc -l users
  2 users
  ```

  Upon execution, you will receive the following output. You can count the number of lines in the file by redirecting the standard input of the wc command from the file users −
  ```
  $ wc -l < users
  2
  ```

  Note that there is a difference in the output produced by the two forms of the `wc` command. In the first case, the name of the file users is listed with the line count; in the second case, it is not.

  In the first case, wc knows that it is reading its input from the file users. In the second case, it only knows that it is reading its input from standard input so it does not display file name.


+ **Here Document:**
