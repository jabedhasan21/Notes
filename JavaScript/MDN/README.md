
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
+ A literal is a notation for representing a fixed value in source code.
+ These are fixed values, not variables, that you literally provide in your script.

+ **Array literals :** An array literal is a type of object initializer.

  - If you put two commas in a row, the array is created with undefined for the unspecified elements.
  - If you include a trailing comma at the end of the list of elements, the comma is ignored.


+ **Boolean literals :** The Boolean type has two literal values: true and false.

  - The Boolean object is a wrapper around the primitive Boolean data type.



+ **Object literals**

  - Object property names can be any string, including the empty string.

  - If the property name would not be a valid JavaScript identifier, it must be enclosed in quotes.

  - Property names that would not be valid identifiers also cannot be accessed as a dot (.) property, but can be accessed and set with the array-like notation("[]").

  - Please note

    var foo = {a: "alpha", 2: "two"};

    console.log(foo.a);    // alpha

    console.log(foo[2]);   // two

    //console.log(foo.2);  // Error: missing ) after argument list

    //console.log(foo[a]); // Error: a is not defined

    console.log(foo["a"]); // alpha

    console.log(foo["2"]); // two

+ **String literals**

You can call any of the methods of the String object on a string literal value—JavaScript automatically converts the string literal to a temporary String object, calls the method, then discards the temporary String object.


## Control flow and error handling

+ The following values will evaluate to false:

  - false
  - undefined
  - null
  - 0
  - NaN
  - the empty string ("")

All other values, including all objects evaluate to true when passed to a conditional statement.


+ **Promises**

 Promise objects allowing you to control the flow of deferred and asynchronous operations.

 A Promise is in one of these states:

    - pending: initial state, not fulfilled or rejected.
    - fulfilled: successful operation
    - rejected: failed operation.
    - settled: the Promise is either fulfilled or rejected, but not pending.


## Loops and iteration

+ **for...in statement**

The for...in statement iterates a specified variable over all the enumerable properties of an object.

+ **for...of statement**

The for...of statement creates a loop Iterating over iterable objects (including Array, Map, Set, arguments object and so on), invoking a custom iteration hook with statements to be executed for the value of each distinct property.

The following example shows the difference between a for...of loop and a for...in loop. While for...in iterates over property names, for...of iterates over property values:

let arr = [3, 5, 7];

arr.foo = "hello";

for (let i in arr) {

   console.log(i); // logs "0", "1", "2", "foo"

}

for (let i of arr) {

   console.log(i); // logs "3", "5", "7"

}

## Functions
+ Primitive parameters (such as a number) are passed to functions by value; the value is passed to the function, but if the function changes the value of the parameter, this change is not reflected globally or in the calling function.

+ If you pass an object (i.e. a non-primitive value, such as Array or a user-defined object) as a parameter and the function changes the object's properties,that change is visible outside the function, as shown in the following example:

```
function myFunc(theObject) {
  theObject.make = "Toyota";
}

var mycar = {make: "Honda", model: "Accord", year: 1998};
var x, y;

x = mycar.make; // x gets the value "Honda"

myFunc(mycar);
y = mycar.make; // y gets the value "Toyota"
                // (the make property was changed by the function)

```

##### Function expressions
---
+ A function can be anonymous; it does not have to have a name.
```
var square = function(number) { return number * number };
var x = square(4) // x gets the value 16
```
+ However, a name can be provided with a function expression and can be used inside the function to refer to itself, or in a debugger to identify the function in stack traces.

  ```
  var factorial = function fac(n) { return n<2 ? 1 : n*fac(n-1) };

  console.log(factorial(3));
  ```

+ Function expressions are convenient when passing a function as an argument to another function. The following example shows a map function being defined and then called with an anonymous function as its first parameter:

  ```
  function map(f,a) {
    var result = [], // Create a new Array
        i;
    for (i = 0; i != a.length; i++)
      result[i] = f(a[i]);
    return result;
  }
  ```
The following code:
`map(function(x) {return x * x * x}, [0, 1, 2, 5, 10]);`

returns [0, 1, 8, 125, 1000].

#### Calling functions
+ Defining a function does not execute it.
+ Defining the function simply names the function and specifies what to do when the function is called.
+ Calling the function actually performs the specified actions with the indicated parameters.
+ Functions must be in scope when they are called, but the function declaration can be hoisted (appear below the call in the code), as in this example:

    ```
    console.log(square(5));
    /* ... */
    function square(n) { return n*n }
    ```
+ The scope of a function is the function in which it is declared, or the entire program if it is declared at the top level.

**Note:** This works only when defining the function using the above syntax (i.e. function funcName(){}). The code below will not work.
  ```
  console.log(square(5));
  square = function (n) {
    return n * n;
  }
  ```
 + The arguments of a function are not limited to strings and numbers. You can pass whole objects to a function.

#### Function scope
+ Variables defined inside a function cannot be accessed from anywhere outside the function, because the variable is defined only in the scope of the function.
+ However, a function can access all variables and functions defined inside the scope in which it is defined.
+ In other words, a function defined in the global scope can access all variables defined in the global scope.
+ A function defined inside another function can also access all variables defined in its parent function and any other variable to which the parent function has access.

  ```
  // The following variables are defined in the global scope
  var num1 = 20,
      num2 = 3,
      name = "Chamahk";

  // This function is defined in the global scope
  function multiply() {
    return num1 * num2;
  }

  multiply(); // Returns 60

  // A nested function example
  function getScore () {
    var num1 = 2,
        num2 = 3;

    function add() {
      return name + " scored " + (num1 + num2);
    }

    return add();
  }

  getScore(); // Returns "Chamahk scored 5"
  ```
#### Scope and the function stack
**Recursion :**
A function can refer to and call itself. There are three ways for a function to refer to itself:
 + the function's name
 + arguments.callee
 + an in-scope variable that refers to the function

#### Nested functions and closures
+ You can nest a function within a function. The nested (inner) function is private to its containing (outer) function.It also forms a closure.
+ Since a nested function is a closure, this means that a nested function can "inherit" the arguments and variables of its containing function. In other words, the inner function contains the scope of the outer function.
+ To summarize:
    + The inner function can be accessed only from statements in the outer function.
    + The inner function forms a closure: the inner function can use the arguments and variables of the outer function, while the outer function cannot use the arguments and variables of the inner function.
+ Since the inner function forms a closure, you can call the outer function and specify arguments for both the outer and inner function:
  ```
  function outside(x) {
    function inside(y) {
      return x + y;
    }
    return inside;
  }
  fn_inside = outside(3); // Think of it like: give me a function that adds 3 to whatever you give it
  result = fn_inside(5); // returns 8

  result1 = outside(3)(5); // returns 8
  ```

#### Preservation of variables
 + Notice how x is preserved when inside is returned.
 + A closure must preserve the arguments and variables in all scopes it references. Since each call provides potentially different arguments, a new closure is created for each call to outside. The memory can be freed only when the returned inside is no longer accessible.

+ This is not different from storing references in other objects, but is often less obvious because one does not set the references directly and cannot inspect them.

#### Multiply-nested functions
+ Functions can be multiply-nested, i.e. a function (A) containing a function (B) containing a function (C). Both functions B and C form closures here, so B can access A and C can access B. In addition, since C can access B which can access A, C can also access A.
+ Thus, the closures can contain multiple scopes; they recursively contain the scope of the functions containing it. This is called scope chaining.
+ Consider the following example:
```
function A(x) {
  function B(y) {
    function C(z) {
      console.log(x + y + z);
    }
    C(3);
  }
  B(2);
}
A(1); // logs 6 (1 + 2 + 3)
```
+ The reverse, however, is not true. A cannot access C, because A cannot access any argument or variable of B, which C is a variable of. Thus, C remains private to only B.

#### Name conflicts
+ When two arguments or variables in the scopes of a closure have the same name, there is a name conflict.
+ More inner scopes take precedence, so the inner-most scope takes the highest precedence, while the outer-most scope takes the lowest. This is the scope chain.
+ Consider the following:

  ```
  function outside() {
    var x = 10;
    function inside(x) {
      return x;
    }
    return inside;
  }
  result = outside()(20); // returns 20 instead of 10
  ```
+ The name conflict happens at the statement return x and is between inside's parameter x and outside's variable x. The scope chain here is {inside, outside, global object}. Therefore inside's x takes precedences over outside's x, and 20 (inside's x) is returned instead of 10 (outside's x).

## Closures
+ Closures are one of the most powerful features of JavaScript. JavaScript allows for the nesting of functions and grants the inner function full access to all the variables and functions defined inside the outer function (and all other variables and functions that the outer function has access to). However, the outer function does not have access to the variables and functions defined inside the inner function. This provides a sort of security for the variables of the inner function. Also, since the inner function has access to the scope of the outer function, the variables and functions defined in the outer function will live longer than the outer function itself, if the inner function manages to survive beyond the life of the outer function.
+ A closure is created when the inner function is somehow made available to any scope outside the outer function.
+ There are, however, a number of pitfalls to watch out for when using closures. If an enclosed function defines a variable with the same name as the name of a variable in the outer scope, there is no way to refer to the variable in the outer scope again.
  ```
  var createPet = function(name) {  // Outer function defines a variable called "name"
    return {
      setName: function(name) {    // Enclosed function also defines a variable called "name"
        name = name;               // ??? How do we access the "name" defined by the outer function ???
      }
    }
  }
  ```
+ The magical `this` variable is very tricky in closures. They have to be used carefully, as what this refers to depends completely on where the function was called, rather than where it was defined.

#### Using the arguments object
+ The arguments of a function are maintained in an array-like object. Within a function, you can address the arguments passed to it as follows: `arguments[i]`.
  ```
  function myConcat(separator) {
     var result = "", // initialize list
         i;
     // iterate through arguments
     for (i = 1; i < arguments.length; i++) {
        result += arguments[i] + separator;
     }
     return result;
  }

  // returns "red, orange, blue, "
  myConcat(", ", "red", "orange", "blue");

  // returns "elephant; giraffe; lion; cheetah; "
  myConcat("; ", "elephant", "giraffe", "lion", "cheetah");

  // returns "sage. basil. oregano. pepper. parsley. "
  myConcat(". ", "sage", "basil", "oregano", "pepper", "parsley");
  ```
+ **Note:** The `arguments` variable is "array-like", but not an array. It is array-like in that is has a numbered index and a length property. However, it does not possess all of the array-manipulation methods.

## Function parameters
+ Starting with ECMAScript 6, there are `two` new kinds of parameters: `default parameters` and `rest parameters`.
+ Default parameters
  + Old
    ```
    function multiply(a, b) {
      b = typeof b !== 'undefined' ?  b : 1;

      return a*b;
    }

    multiply(5); // 5
    ```
  + New

    ```
    function multiply(a, b = 1) {
      return a*b;
    }

    multiply(5); // 5
    ```
+ Rest parameters
  ```
  function multiply(multiplier, ...theArgs) {
    return theArgs.map(x => multiplier * x);
  }

  var arr = multiply(2, 1, 2, 3);
  console.log(arr); // [2, 4, 6]
  ```
## Arrow functions
+ An arrow function expression (also known as fat arrow function) has a shorter syntax compared to function expressions and lexically binds the this value.
+ Arrow functions are always anonymous.
+ [ES6 In Depth: Arrow functions](https://hacks.mozilla.org/2015/06/es6-in-depth-arrow-functions/)
+ Two factors influenced the introduction of arrow functions: `shorter functions` and `lexical this`.
#### Shorter functions
In some functional patterns, shorter functions are welcome. Compare:
  ```
  var a = [
    "Hydrogen",
    "Helium",
    "Lithium",
    "Beryl­lium"
  ];

  var a2 = a.map(function(s){ return s.length });

  var a3 = a.map( s => s.length );
  ```
## Lexical this
