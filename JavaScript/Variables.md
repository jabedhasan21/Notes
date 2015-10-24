# Global Objects
## String

The String global object is a constructor for strings, or a sequence of characters.

##### Distinction between string primitives and String objects

+ JavaScript automatically converts primitives to String objects, so that it's possible to use String object methods for primitive strings. In contexts where a method is to be invoked on a primitive string or a property lookup occurs, JavaScript will automatically wrap the string primitive and call the method or perform the property lookup.

+ String primitives and String objects also give different results when using eval().

+ Primitives passed to eval are treated as source code; String objects are treated as all other objects are, by returning the object.

+ For example:

  ```
  var s1 = '2 + 2';  // creates a string primitive

  var s2 = new String('2 + 2'); // creates a String object

  console.log(eval(s1)); // returns the number 4

  console.log(eval(s2)); // returns the string "2 + 2"
    ```

+ A String object can always be converted to its primitive counterpart with the valueOf() method.

  console.log(eval(s2.valueOf())); // returns the number 4

  ## Function
  + The Function constructor creates a new Function object.
  + In JavaScript every function is actually a Function object.

**Syntax** `new Function ([arg1[, arg2[, ...argN]],] functionBody)
`

 Example can be run directly in your JavaScript console
 Create a function that takes two arguments and returns the sum of those arguments

```
var adder = new Function('a', 'b', 'return a + b');

// Call the function

adder(2, 6);

// > 8
```
