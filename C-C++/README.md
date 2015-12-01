# Questions
+ What are the differences between C and C++?

  + 1) C++ is a kind of superset of C, most of C programs except few exceptions (See this and this) work in C++ as well.
  + 2) C is a procedural programming language, but C++ supports both procedural and Object Oriented programming.
  + 3) Since C++ supports object oriented programming, it supports features like function overloading, templates, inheritance, virtual functions, friend functions. These features are absent in C.
  + 4) C++ supports exception handling at language level, in C exception handling is done in traditional if-else style.
  + 5) C++ supports references, C doesn’t.
  + 6) In C, scanf() and printf() are mainly used input/output. C++ mainly uses streams to perform input and output operations. cin is standard input stream and cout is standard output stream.
  There are many more differences, above is a list of main differences.

+ What are the differences between references and pointers?
+ What are virtual functions – Write an example?
+ What is this pointer?

  The ‘this’ pointer is passed as a hidden argument to all nonstatic member function calls and is available as a local variable within the body of all nonstatic functions. ‘this’ pointer is a constant pointer that holds the memory address of the current object. ‘this’ pointer is not available in static member functions as static member functions can be called without any object (with class name).

+ Can we do “delete this”?
+ What are VTABLE and VPTR?

    vtable is a table of function pointers. It is maintained per class.
    vptr is a pointer to vtable. It is maintained per object (See this for an example).
    Compiler adds additional code at two places to maintain and use vtable and vptr.

# Reference
(1). [Toptal](http://www.toptal.com/c-plus-plus/interview-questions)

(2). [geeksquiz](http://geeksquiz.com/commonly-asked-c-interview-questions-set-1/)

(3). [scanftree](http://scanftree.com/programs/c/)

(4). [a2zinterviews](http://www.a2zinterviews.com/Languages/c++/)
