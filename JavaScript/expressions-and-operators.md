#  Expressions and operators
This chapter describes JavaScript's expressions and operators, including assignment, comparison, arithmetic, bitwise, logical, string, ternary and more.
#### Operators
  + Assignment operators
  + Comparison operators
  + Arithmetic operators
  + Bitwise operators
  + Logical operators
  + String operators
  + Conditional (ternary) operator
  + Comma operator
  + Unary operators
  + Relational operator

+ Assignment operators
  + Destructuring assignment
  
### Object initializer
---
+ An object initializer is an expression that describes the initialization of an Object.

+  Objects consist of properties, which are used to describe an object.

+ Values of object properties can either contain primitive data types or other objects.

+ Objects can be initialized using `new Object(), Object.create()`, or using the literal notation (initializer notation).

+ An object initializer is a list of zero or more pairs of property names and associated values of an object, enclosed in curly braces (`{}`).

+ *Syntax:*

```
var o = {};
var o = { a: "foo", b: 42, c: {} };

var a = "foo", b = 42, c = {};
var o = { a: a, b: b, c: c };

var o = {
  property: function ([parameters]) {},
  get property() {},
  set property(value) {},
};
```
+ When using the same name for your properties, the second property will overwrite the first.
```
var a = {x: 1, x: 2};
console.log(a); // { x: 2}
```
+ In ECMAScript 5 strict mode code, duplicate property names were considered a SyntaxError.  With the introduction of computed property names making duplication possible at runtime, ECMAScript 6 has removed this restriction.

#### New notations in ECMAScript 6

Please see the compatibility table for support for these notations. In non-supporting environments, these notations will lead to syntax errors.
```
// Shorthand property names (ES6)
var a = "foo", b = 42, c = {};
var o = { a, b, c };

// Shorthand method names (ES6)
var o = {
  property([parameters]) {},
  get property() {},
  set property(value) {},
  * generator() {}
};

// Computed property names (ES6)
var prop = "foo";
var o = {
  [prop]: "hey",
  ["b" + "ar"]: "there",
};
```
#### Method definitions

A property of an object can also refer to a function or a getter or setter method.
```
// Shorthand method names (ES6)
var o = {
  property([parameters]) {},
  get property() {},
  set property(value) {},
  * generator() {}
};
```

#### Computed property names
+ Starting with ECMAScript 6, the object initializer syntax also supports computed property names.
+ That allows you to put an expression in brackets [], that will be computed as the property name.

```
// Computed property names (ES6)
var i = 0;
var a = {
  ["foo" + ++i]: i,
  ["foo" + ++i]: i,
  ["foo" + ++i]: i
};

console.log(a.foo1); // 1
console.log(a.foo2); // 2
console.log(a.foo3); // 3

var param = 'size';
var config = {
  [param]: 12,
  ["mobile" + param.charAt(0).toUpperCase() + param.slice(1)]: 4
};

console.log(config); // { size: 12, mobileSize: 4 }
```

#### Prototype mutation

+ A property definition of the form \__proto\__: value or "\__proto\__": value does not create a property with the name \__proto\__.

+ Instead, if the provided value is an object or null, it changes the [[Prototype]] of the created object to that value.
+ **(If the value is not an object or null, the object is not changed.)**

```
var obj1 = {};
assert(Object.getPrototypeOf(obj1) === Object.prototype);

var obj2 = { __proto__: null };
assert(Object.getPrototypeOf(obj2) === null);

var protoObj = {};
var obj3 = { "__proto__": protoObj };
assert(Object.getPrototypeOf(obj3) === protoObj);

var obj4 = { __proto__: "not an object or null" };
assert(Object.getPrototypeOf(obj4) === Object.prototype);
assert(!obj4.hasOwnProperty("__proto__"));
```

+ Only a single prototype mutation is permitted in an object literal: multiple prototype mutations are a syntax error.

+ Property definitions that do not use "colon" notation are not prototype mutations: they are property definitions that behave identically to similar definitions using any other name.

#### Object literal notation vs JSON
The object literal notation is not the same as the JavaScript Object Notation (JSON). Although they look similar, there are differences between them:
+ JSON permits only property definition using "property": value syntax.  The property name must be double-quoted, and the definition cannot be a shorthand.

+ In JSON the values can only be strings, numbers, arrays, true, false, null, or another (JSON) object.

+ A function value can not be assigned to a value in JSON.

+ Objects like `Date` will be a string after `JSON.parse()`.

+ JSON.parse() will reject computed property names and an error will be thrown.
