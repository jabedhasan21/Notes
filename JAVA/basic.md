### What is Java?
+ Java is a `programming language` and a `platform`.

+ Java is a `high level`, `robust`, `secured` and `object-oriented` programming language.

+ Java has its own runtime environment (`JRE`) and `API`, it is called `platform`.

### Types of Java Applications?
 There are mainly 4 type of applications that can be created using java programming:
 + Standalone Application.
 + Web Application.
 + Enterprise Application.
 + Mobile Application.( Android and Java ME are used for creating mobile applications )

## [The Java Programming Language Platforms](https://docs.oracle.com/cd/E19798-01/821-1770/gcrkk/index.html)
There are four platforms of the Java programming language:
+ Java Platform, Standard Edition (Java SE)
+ Java Platform, Enterprise Edition (Java EE)
+ Java Platform, Micro Edition (Java ME)
    - [Whay Java ME Dead](https://stackoverflow.com/questions/26563100/is-jme-still-alive)
+ Java FX

### [Java Enterprise Evolution](https://www.baeldung.com/java-enterprise-evolution)

### Java Platform Independent?
 A platform is the hardware or software environment in which a program runs.

 There are two types of platforms software-based and hardware-based. Java provides software-based platform.

 The Java platform differs from most other platforms in the sense that it is a software-based platform that runs on the top of other hardware-based platforms. It has two components:
+ Runtime Environment
+ API(Application Programming Interface)

### What happens at runtime?
1. class file.
2. Classloader.
3. Bytecode Verifier.
4. Interpreter.
5. Runtime.
6. Hardware.

### Question
---
 + ###  Can you save a java source file by other name than the class name?

 + ###  Why java main method is static?

----
### Difference between JDK, JRE and JVM?
 +  **JVM( Java Virtual Machine ):**
It is an abstract machine. It is a specification that provides runtime environment in which java bytecode can be executed.
 + **JRE( Java Runtime Environment ):**
It is the implementation of JVM. It physically exists. It contains set of libraries + other files that JVM uses at runtime.
 + **JDK( Java Development Kit ):**
It physically exists. It contains JRE + development tools e.g.(javac, java etc).

### Internal Architecture of JVM?
+ Classloader
+ Class(Method) Area
+ Heap( It is the runtime data area in which objects are allocated. )
+ Stack( It holds local variables and partial results )
+ Program Counter Register
+ Native Method Stack
+ Execution Engine

### Java static variable?
+ The static variable gets memory only once in `class area` at the time of class loading.
+ It makes your program memory efficient (i.e it saves memory).

### Restrictions for static method?
+ The static method can not use non static data member or call non-static method directly.

###  Java static block?
+ Is used to initialize the static data member.
+ It is executed before main method at the time of classloading.

### exception vs error in java
* Errors should not be caught or handled (except in the rarest of cases).
* An Error is a subclass of Throwable that indicates serious problems that a reasonable application should not try to catch. Most such errors are abnormal conditions.
* An Error "indicates serious problems that a reasonable application should not try to catch."
* An Exception "indicates conditions that a reasonable application might want to catch."


* https://stackoverflow.com/questions/5813614/what-is-difference-between-errors-and-exceptions
* https://stackoverflow.com/questions/912334/differences-between-exception-and-error
* https://docs.oracle.com/javase/6/docs/api/java/lang/Error.html
* https://techdifferences.com/difference-between-error-and-exception.html
* https://www.geeksforgeeks.org/errors-v-s-exceptions-in-java/
