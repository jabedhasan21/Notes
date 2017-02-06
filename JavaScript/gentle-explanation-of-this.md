# Gentle explanation of 'this' keyword in JavaScript
### `this` in function invocation
+ this is the global object in a function invocation
+ In a function invocation the execution context is the global object.
+ Example
```
function sum(a, b) {  
   console.log(this === window); // => true
   this.myNumber = 20; // add 'myNumber' property to global object
   return a + b;
}
// sum() is invoked as a function
// this in sum() is a global object (window)
sum(15, 16);     // => 31  
window.myNumber; // => 20  
```

###  `this` in function invocation, strict mode
+ this is `undefined` in a function invocation in     `strict mode`
+ Example
```
function multiply(a, b) {  
  'use strict'; // enable the strict mode
  console.log(this === undefined); // => true
  return a * b;
}
// multiply() function invocation with strict mode enabled
// this in multiply() is undefined
multiply(2, 5); // => 10
```
+ A single JavaScript file may contain both strict and non-strict modes. So it is possible to have different context behavior in a single script for the same invocation type:
```
function nonStrictSum(a, b) {  
  // non-strict mode
  console.log(this === window); // => true
  return a + b;
}
function strictSum(a, b) {  
  'use strict';
  // strict mode is enabled
  console.log(this === undefined); // => true
  return a + b;
}
// nonStrictSum() is invoked as a function in non-strict mode
// this in nonStrictSum() is the window object
nonStrictSum(5, 6); // => 11  
// strictSum() is invoked as a function in strict mode
// this in strictSum() is undefined
strictSum(8, 12); // => 20  
```
+ the context of the inner function depends only on invocation, but not on the outer function's context.

###  Method invocation
+ A method is a function stored in a property of an object
```
var myObject = {  
  // helloFunction is a method
  helloFunction: function() {
    return 'Hello World!';
  }
};
var message = myObject.helloFunction();
```

### `this` in method invocation
+ `this` is the object that owns the method in a method invocation.

### Pitfall: separating method from its object

### Constructor invocation

### this in constructor invocation
+ this is the newly created object in a constructor invocation.

### Pitfall: forgetting about `new`
+ Using a function invocation to create objects is a potential problem (excluding factory pattern), because some constructors may omit the logic to initialize the object when `new` keyword is missing.
+ Example
```
function Vehicle(type, wheelsCount) {  
  this.type = type;
  this.wheelsCount = wheelsCount;
  return this;
}
// Function invocation
var car = Vehicle('Car', 4);  
car.type;       // => 'Car'  
car.wheelsCount // => 4  
car === window  // => true
```

### Indirect invocation
+ Indirect invocation is performed when a function is called using myFun.call() or myFun.apply() methods.
+ Functions in JavaScript are first-class objects, which means that a function is an object. The type of this object is Function.
```
function increment(number) {  
  return ++number;  
}
increment.call(undefined, 10);    // => 11  
increment.apply(undefined, [10]); // => 11  
```
The main difference between the two is that `.call()` accepts a list of arguments, for example myFun.call(thisValue, 'val1', 'val2'). But `.apply()` accepts a list of values in an array-like object, e.g. myFunc.apply(thisValue, ['val1', 'val2']).

### this in indirect invocation
+ `this` is the first argument of `.call()` or `.apply()` in an indirect invocation.
+ The following example shows the indirect invocation context:
```
var rabbit = { name: 'White Rabbit' };  
function concatName(string) {  
  console.log(this === rabbit); // => true
  return string + this.name;
}
// Indirect invocations
concatName.call(rabbit, 'Hello ');  // => 'Hello White Rabbit'  
concatName.apply(rabbit, ['Bye ']); // => 'Bye White Rabbit'
```
+ Another practical example is creating hierarchies of classes in ES5 to call the parent constructor:
```
function Runner(name) {  
  console.log(this instanceof Rabbit); // => true
  this.name = name;  
}
function Rabbit(name, countLegs) {  
  console.log(this instanceof Rabbit); // => true
  // Indirect invocation. Call parent constructor.
  Runner.call(this, name);
  this.countLegs = countLegs;
}
var myRabbit = new Rabbit('White Rabbit', 4);  
myRabbit; // { name: 'White Rabbit', countLegs: 4 }  
```

### Bound function
### Tight context binding
.bind() makes a permanent context link and will always keep it. A bound function cannot change its linked context when using .call() or .apply() with a different context, or even a rebound doesn't have any effect.

## Arrow function
+ You could even omit the return, when the function has only 1 statement.
+ Also it doesn't provide the `arguments` object.
+ `this` is the enclosing context where the arrow function is defined.
+ The arrow function doesn't create its own execution context, but takes this from the outer function where it is defined.
+ If the arrow function is defined in the top most scope (outside any function), the context is always the global object (window in a browser):
```
var getContext = () => {  
   console.log(this === window); // => true
   return this;
};
console.log(getContext() === window); // => true
```
+ An arrow function is bound with the lexical context once and forever. this cannot be modified even if using the context modification methods:
```
var numbers = [1, 2];  
(function() {  
  var get = () => {
    console.log(this === numbers); // => true
    return this;
  };
  console.log(this === numbers); // => true
  get(); // => [1, 2]
  // Use arrow function with .apply() and .call()
  get.call([0]);  // => [1, 2]
  get.apply([0]); // => [1, 2]
  // Bind
  get.bind([0])(); // => [1, 2]
}).call(numbers);
```
+ the arrow function always keeps the initial context.
+ Indirect call with other context get.call([0]) or . get.apply([0]), rebinding get.bind([0])() have no effect.
+ Arrow function cannot be used as a constructor. If invoking it as a constructor new get(), JavaScript throws an error: TypeError: get is not a constructor.
+ arrow function have a static context that doesn't change on different invocation types.

## [Reference](https://rainsoft.io/gentle-explanation-of-this-in-javascript)
