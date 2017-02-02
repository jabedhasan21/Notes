+ JavaScript?
`A single-threaded non-blocking asynchronous concurrent language.`
+ [Event Loop](https://www.youtube.com/watch?v=8aGhZQkoFbQ)

  `
  The event loops jos is to look at the stack and look at the task queue.If the stack is empty it takes the first thing on the queue and pushes it on to the stack.
  `
+ Call Back
+ Promise
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
+ this
+ hosting ( scoping )
+ closer
+ prototype chaining

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
