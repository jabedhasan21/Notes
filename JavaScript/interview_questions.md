+ JavaScript?
`A single-threaded non-blocking asynchronous concurrent language.`
+ [Event Loop](https://www.youtube.com/watch?v=8aGhZQkoFbQ)

  `
  The event loops jos is to look at the stack and look at the task queue.If the stack is empty it takes the first thing on the queue and pushes it on to the stack.
  `
+ Call Back
+ Promise
+ generator
+ async awit
+ arrow functions
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

+ What is closure?

  `Closures are created whenever a variable that is defined outside the current scope is accessed from within some inner scope.`
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
