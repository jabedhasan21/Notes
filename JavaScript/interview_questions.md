+ JavaScript?
`A single-threaded non-blocking asynchronous concurrent language.`
+ [Event Loop](https://www.youtube.com/watch?v=8aGhZQkoFbQ)

  `
  The event loops jos is to look at the stack and look at the task queue.If the stack is empty it takes the first thing on the queue and pushes it on to the stack.
  `
+ Call Back
+ [Strict mode?](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Strict_mode)
- Strict mode makes several changes to normal JavaScript semantics.
- First, strict mode eliminates some JavaScript silent errors by changing them to throw errors.
- Second, strict mode fixes mistakes that make it difficult for JavaScript engines to perform optimizations: strict mode code can sometimes be made to run faster than identical code that's not strict mode.
- Third, strict mode prohibits some syntax likely to be defined in future versions of ECMAScript.
+ yield?
```The yield keyword is used to pause and resume a generator function (function* or legacy generator function).The yield keyword actually returns an IteratorResult object with two properties, value and done. The value property is the result of evaluating the yield expression, and done is false, indicating that the generator function has not fully completed.
```
+ yield*?
 - The yield* expression is used to delegate to another generator or iterable object.
 - Besides generator objects, yield* can also yield other kinds of iterables, e.g. arrays, strings or arguments objects.
 - yield* is an expression, not a statement, so it evaluates to a value.

+ [Generators?](https://www.youtube.com/watch?v=ategZqxHkz4)

  - Generators are (kind of) pausable functions in JavaScript. Another word for them is co-routines. They are used (among other things) to manage async operations, and play very well with promises. A generator is a special type of function that works as a factory for iterators. A function becomes a generator if it contains one or more yield expressions and if it uses the function* syntax.
  - [1](https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Statements/function* )
  - [2](https://developer.mozilla.org/en/docs/Web/JavaScript/Guide/Iterators_and_Generators)

  - A value passed to next() will be treated as the result of the last yield expression that paused the generator.

  ```
    function* fibonacci(){
      var fn1 = 0;
      var fn2 = 1;
      while (true){  
        var current = fn1;
        fn1 = fn2;
        fn2 = current + fn1;
        var reset = yield current;
        if (reset){
            fn1 = 0;
            fn2 = 1;
        }
      }
    }

    var sequence = fibonacci();
    console.log(sequence.next().value);     // 0
    console.log(sequence.next().value);     // 1
    console.log(sequence.next().value);     // 1
    console.log(sequence.next().value);     // 2
    console.log(sequence.next().value);     // 3
    console.log(sequence.next().value);     // 5
    console.log(sequence.next().value);     // 8
    console.log(sequence.next(true).value); // 0
    console.log(sequence.next().value);     // 1
    console.log(sequence.next().value);     // 1
    console.log(sequence.next().value);     // 2
    ```

    - You can force a generator to throw an exception by calling its throw() method and passing the exception value it should throw.


+ [Async and Await?](https://www.youtube.com/watch?v=EmTYi3Myntk)
 - The async function declaration defines an asynchronous function, which returns an `AsyncFunction object`.
 - The AsyncFunction constructor creates a new async function object. In JavaScript every asynchronous function is actually an `AsyncFunction object`.
 - Note that AsyncFunction is not a global object.
 - The `await` operator is used to wait for a Promise returned by an async function.
 - When an async function is called, it returns a Promise.
 - An async function can contain an await expression, that pauses the execution of the async function and waits for the passed Promise's resolution, and then resumes the async function's execution and returns the resolved value.
 - The purpose of async/await functions are  to simplify the behavior of using promises synchronously
 - async/await is similar to combining generators and promises.
 - [async_function](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/async_function)

+ [await](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/await)
 - The await operator is used to wait for a Promise returned by an async function.
 - The await expression causes async function execution to pause, to wait for the Promise's resolution, and to resume the async function execution when the value is resolved. It then returns the resolved value. If the value is not a Promise, it's converted to a resolved Promise.
 - If the Promise is rejected, the await expression throws the rejected value.

+ [Arrow functions](https://www.youtube.com/watch?v=6sQDTgOqh-I)
 - An arrow function expression has a shorter syntax than a function expression and does not bind its own `this, arguments, super, or new.target`. Arrow functions are always anonymous. These function expressions are best suited for non-method functions, and they cannot be used as constructors.
 - Two factors influenced the introduction of arrow functions: `shorter functions` and `non-binding of this`.
 - Until arrow functions, every new function defined its own `this` value.
 - An arrow function does not create its own this context, so this has its original meaning from the enclosing context.
 - Arrow functions cannot be used as constructors and will throw an error when used with new.
 - Arrow functions do not have a prototype property.
 - The `yield` keyword may not be used in an arrow function's body (except when permitted within functions further nested within it). As a consequence, arrow functions cannot be used as `generators`.
+ [Destructuring](https://www.youtube.com/watch?v=PB_d3uBkQPs&index=4&list=PL0zVEGEvSaeHJppaRLrqjeTPnCH6vw-sm)
+ this
+ hosting ( scoping )
+ closer
+ [Prototype Chain](https://www.youtube.com/watch?v=Y3zzCY62NYc&list=PL0zVEGEvSaeHBZFy6Q8731rcwk0Gtuxub&index=4)
  - [MDN](https://developer.mozilla.org/en/docs/Web/JavaScript/Inheritance_and_the_prototype_chain)
 - Each object has an internal link to another object called its prototype.That prototype object has a prototype of its own, and so on until an object is reached with null as its prototype. By definition, null has no prototype, and acts as the final link in this `prototype chain`.
 - While this is often considered to be one of JavaScript's weaknesses, the prototypal inheritance model is in fact more powerful than the classic model.
 - JavaScript objects have a link to a prototype object.
 - When an inherited function is executed, the value of `this` points to the inheriting object, not to the prototype object where the function is an own property.
 - define in prototype is effectively shared by all instances, and you can even later change parts of prototype and have the changes appear in all existing instances, if you wanted to.

   ```
   // So, when you call

   var o = new Foo();

   // JavaScript actually just does
   
   var o = new Object();
    o.[[Prototype]] = Foo.prototype;
    Foo.call(o);
   ```
+ class keyword
+ what is do the `new` keyword
   - 1st Create new plain JavaScript object.
   - 2nd Check the prototype of object and set the prototype to the new created object.
   - 3rd Call the Object constructor with the `this` and the value if we passed arguments.
   - 4th return the newly created object.
   -  Below the example

  ```
  function Person(saying){
    this.saying = saying
  }

  Person.prototype.talk = function(){
    console.log('I say:', this.saying)
  }

  let donaldTrump = new Person('I am president of USA.!!')
   donaldTrump.talk()

   function myOwnNew(constructor){
      let obj = {}
      Object.setPrototypeOf(obj, constructor.prototype)
      let argArray = Array.prototype.slice.apply(arguments)
      constructor.apply(obj, argArray.slice(1))
      return obj
   }

   let obama = myOwnNew(Person, 'I am ex president of USA.!!')
   obama.talk()
   ```

+ [--proto-- Vs prototype](https://www.youtube.com/watch?v=DqGwxR_0d1M&list=PL0zVEGEvSaeHBZFy6Q8731rcwk0Gtuxub&index=5)

 - We explore the `__proto__` property on JavaScript Objects, and how it relates to the normal prototype.
 - Basically, the .`__proto__` property points to the object that the current object actually will use when doing lookups on the `prototype chain`,
 - while ".prototype" only exists on `functions`, in case you want to use those objects as constructors passed to the new keyword.
 - Example

   ```
   let cat = {breed: 'munchkin'}
   let myCat = {name: 'Flyffykins'}
   Object.setPrototypeOf(myCat, cat)

   console.log(myCat.name)
   console.log(myCat.breed)
   console.log(myCat.__proto__)

   cat.tailLength = 15

   console.log(myCat.__proto__)
   console.log(myCat.tailLength)
  ```
+ [Object.create - Object Creation](https://www.youtube.com/watch?v=CDFN1VatiJA&t=442s&list=PL0zVEGEvSaeHBZFy6Q8731rcwk0Gtuxub&index=6)
 - The Object.create() method in JavaScript creates a new object with the specified prototype object and properties.
  - Example
    ```
   const cat = {
       makeSound: function(){
         console.log(this.sound)
       }
    }

    function ObjectCreate(proto){
      let obj = {}
      Object.setPrototypeOf(obj,proto)
      return obj;
    }
    //const mark = Object.create(cat)
    const mark = ObjectCreate(cat)
    mark.sound = 'wooFFF'
    mark.makeSound()

    const waffles = Object.create(cat)
    // or we can do the same thing using ObjectCreate function
    //const waffles = ObjectCreate(cat)
    mark.sound = 'moweeeefgdgf'
    mark.makeSound()

    console.log('Is mark a cat?', cat.isPrototypeOf(mark))
    console.log('Is waffles a cat?', cat.isPrototypeOf(waffles))
    ```

# Questions
+ What are disadvantages of using JavaScript?
+ How many types of functions JavaScript supports?

+ What is callback?

  `Callback can be any function that another function calls or callback can be more explicitly an asynchronous callback as in one that will get pushed back on the callback queue in the future.`

  `A callback is a plain JavaScript function passed to some method as an argument or option. Some callbacks are just events, called to give the user a chance to react when a certain state is triggered.`

+ [What is closure?](https://developer.mozilla.org/en/docs/Web/JavaScript/Closures)

  `Closures are functions that refer to independent (free) variables (variables that are used locally, but defined in an enclosing scope). In other words, these functions 'remember' the environment in which they were created.`
 - the local variables within a function only exist for the duration of that function's execution.
 - **A closure is the combination of a function and the lexical environment (or simply "environment") within which that function was declared.**
 - This has obvious parallels to object oriented programming.
 - Languages such as Java provide the ability to declare methods private, meaning that they can only be called by other methods in the same class. JavaScript does not provide a native way of doing this, but it is possible to emulate private methods using closures.
 - Using closures in this way provides a number of benefits that are normally associated with object oriented programming, in particular data hiding and encapsulation.
 - It is unwise to unnecessarily create functions within other functions if closures are not needed for a particular task, as it will negatively affect script performance both in terms of processing speed and memory consumption.

+ How typeof operator works?
+ What typeof returns for a null value?

+ What is a compose method?
 - [compose](https://gist.github.com/ripter/2786033)
 - [Code](https://gist.github.com/neftaly/6e11268f1cd230094c81)
 - Example
  ```
      const pipe = (headFn, ...restFns) => (...args) => restFns.reduce(
        (value, fn) => fn(value),
        headFn(...args)
       );

      const compose = (...fns) => pipe(...fns.reverse());

      function text(a) {
          return 'item: ' + a;
      }

      function hello(a) {
          return 'Hello ' + a;
      }

      var c = compose(text, hello);
      c('Chris');  // outputs: 'item: Hello Chris'

      // so c looks something like:
      function c(a) {
          return text(hello(a));
      }
```

+ Browser repaint time?

  `The browser would like to repaint the screen every 16.6 milliseconds , 60 frame a second is deal.`

  `Like the render kind of call is almost like callback in itself. It has to wait the stack is clear.`

  `The difference is that the render is given a higher priority  then your callback. Every 16 milliseconds it's going to queue a rend, wait till the stack is clear before it can actually do that render.`

+ [The history of “typeof null”]( http://www.2ality.com/2013/10/typeof-null.html)

+ [javascript-scene](https://medium.com/javascript-scene/10-interview-questions-every-javascript-developer-should-know-6fa6bdf5ad95#.kieot4rwd)
