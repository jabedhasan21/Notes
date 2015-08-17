
## Grammar and types
+ JavaScript borrows most of its syntax from Java, but is also influenced by Awk, Perl and Python.

+ JavaScript is case-sensitive and uses the Unicode character set.

+ In JavaScript, instructions are called statements and are separated by a semicolon (;). Spaces, tabs and newline characters are called whitespace.

**Declarations**

There are three kinds of declarations in JavaScript.

+ *var :*
    Declares a variable, optionally initializing it to a value.

+ *let :*
    Declares a block scope local variable, optionally initializing it to a value.

+ *const :*
    Declares a read-only named constant.

**Variables :** The names of variables, called identifiers.

**Identifier :** A sequence of characters in the code that identifies a variable, function, or property.

In JavaScript, identifiers can contain only alphanumeric characters (or "$" or " _ "), and may not start with a digit.

**Evaluating variables**

+ An attempt to access an undeclared variable will result in a ReferenceError exception being thrown.

+ The undefined value behaves as false when used in a boolean context.

+ The undefined value converts to NaN when used in numeric context.

+ When you evaluate a null variable, the null value behaves as 0 in numeric contexts and as false in boolean contexts.

**Variable hoisting :**
In JavaScript is that you can refer to a variable declared later, without getting an exception. This concept is known as hoisting.

**Global variables :**
Global variables are in fact properties of the global object. In web pages the global object is window, so you can set and access global variables using the window.variable syntax.

**Constants**
+ A constant cannot change value through assignment or be re-declared while the script is running. It has to be initialized to a value.

+ You cannot declare a constant with the same name as a function or variable in the same scope.

**Data structures and types**

Data types

The latest ECMAScript standard defines seven data types:
+ Six data types that are primitives:
  - Boolean. true and false.
  - null. A special keyword denoting a null value. Because JavaScript is case-sensitive, null is not the same as Null, NULL, or any other variant.
  - undefined. A top-level property whose value is undefined.
  - Number. 42 or 3.14159.
  - String. "Howdy"
  - Symbol (new in ECMAScript 6). A data type whose instances are unique and immutable.

+ and Object

You can think of objects as named containers for values, and functions as procedures that your application can perform.


#### Data type conversion
+ JavaScript is a dynamically typed language. That means you don't have to specify the data type of a variable when you declare it, and data types are converted automatically as needed during script execution.

+ \+ operator, JavaScript converts numeric values to strings.

+ other operators, JavaScript does not convert numeric values to strings.

#### Literals
