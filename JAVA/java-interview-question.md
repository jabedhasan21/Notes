# Java Question
* Java Stack Vs Heap memory?
    * Java Heap Space is used throughout the application, but Stack is only used for the method — or methods — currently running.
    * The Heap Space contains all objects are created, but Stack contains any reference to those objects.
    * Objects stored in the Heap can be accessed throughout the application.
    * https://stackify.com/java-heap-vs-stack/


* Is Java pass by value or pass by reference? Why?

    Ans: Java always passes arguments by value, NOT by reference. It doesn't matter what the value is in Java primitive or address/reference(roughly) of object, it is ALWAYS passed by value.
    Why
        * Function is free to modify a parameter without inadvertently changing the data at the calling location.
        * Another advantage is that the function argument may be any expression - not just a variable.

    * Java only passes by value.
    * Java always passes arguments by value, NOT by reference.
    * It doesn't matter what the value is in Java: primitive or address(roughly) of object, it is ALWAYS passed by value.
    * Java passes the reference by value.
    * If a Java object "behaves" like it is being passed by reference, that is a property of mutability and has absolutely nothing to do with passing mechanisms.
    * Java variables are passed by value, meaning that a copy of the value is passed. Just remember that the copied value points to a real object in the Java memory heap. Passing by value still changes the value of the real object.
    * Why
        * Function is free to modify a parameter without inadvertently changing the data at the calling location.
        * Another advantage is that the function argument may be any expression - not just a variable.

    * https://www.infoworld.com/article/3512039/does-java-pass-by-reference-or-pass-by-value.html#:~:text=Java%20always%20passes%20parameter%20variables,object%20in%20the%20memory%20heap.&text=%E2%80%9CPassing%20by%20value%E2%80%9D%20refers%20to,of%20the%20variable%20in%20memory.
    * https://stackoverflow.com/questions/40480/is-java-pass-by-reference-or-pass-by-value?page=2&tab=votes#tab-top
    * https://www.cs.virginia.edu/~jh2jf/courses/cs2110/java-pass-by-value.html
    * http://icarus.cs.weber.edu/~dab/cs1410/textbook/6.Functions/value.html

* What is preferable? Mutable or immutable classes? Why?
    Ans:
    * Immutable is preferable.
    Why:
    * Immutable objects are thread-safe by default.
    * Mutable objects are sometimes not be thread-safe.

* How do you make a class immutable in Java?
    Ans: 
    * We need to declared class as final, so that it can't be extended.
    * All fields should be private so that direct access to the fields is blocked.
    * No need to define setters method.
    * All mutable fields should be as final so that they can not be iterated once initialized.

    * https://www.javatpoint.com/mutable-and-immutable-in-java

* What do you understand of the principle of the “Single Responsibility Principle”?
    Ans: 
    * To follow Single Responsibility Principle, class are not allowed to have more than one responsibility.
    * A class should have one, and only one, reason to change.
    * Single Responsibility Principle is relatively simple: it makes software easier to implement and prevents unexpected side-effects of future changes.

    * https://stackify.com/solid-design-principles/
* Which data type in Java should be used to represent monetary values?
    Ans:
    * BigDecimal data type in Java should be used to represent monetary values.
    * Primitive type: int and long are also useful for monetary calculations if the decimal precision is not required.

    * https://dzone.com/articles/never-use-float-and-double-for-monetary-calculatio
    * http://www.mathspadilla.com/matI/Unit1-RealNumbers/real_numbers.html
* composition?
* inheritance?
* polymorphic behavior?
* mutually exclusive?
* When should you favor composition over inheritance?
    Ans: When only some part of the behavior of entity/class need to expose to other entity/class then I favour composition.

    * Prefer composition over inheritance as it is more malleable / easy to modify later, but do not use a compose-always approach. With composition, it's easy to change behavior on the fly with Dependency Injection / Setters. Inheritance is more rigid as most languages do not allow you to derive from more than one type.

    * https://stackoverflow.com/questions/38820/which-class-design-is-better
    * https://stackoverflow.com/questions/49002/prefer-composition-over-inheritance
* What programming languages are you fluent in?
    Java
* What programming languages are you familiar with?
    Java, JavaScript, PHP, Go, Kotlin, C, C++, C#.