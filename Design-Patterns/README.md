## Design Patterns
 + [**Gang of Four Design Patterns**](http://c2.com/cgi/wiki?DesignPatternsBook)

 + [**TutorialsPoint**](http://www.tutorialspoint.com/design_pattern/observer_pattern.htm)

 + [**solid-principles**](https://www.baeldung.com/solid-principles)
    + https://www.digitalocean.com/community/conceptual_articles/s-o-l-i-d-the-first-five-principles-of-object-oriented-design

 + [**solid-principles-Ex**](SOLID Design Principles)

 + [**liskov-substitution-principle**](https://www.baeldung.com/cs/liskov-substitution-principle)
 
 + [Liskov Substitution Principle-Ex](https://www.youtube.com/watch?v=Z_ySH41NmUQ)

 + [DDD(Domain-driven design)](https://www.youtube.com/watch?v=wD-d0oZI4YM&list=PLZBNtT95PIW3BPNYF5pYOi4MJjg_boXCG)

 + [Implementing DDD in code](https://www.youtube.com/watch?v=aZAEjVFpU1s)

 + [DRY/KISS/YAGNI PRINCIPLE](https://www.c-sharpcorner.com/article/software-design-principles-dry-kiss-yagni/)
    - DRY  - DON’T REPEAT YOURSELF
    - KISS - KEEP IT SIMPLE STUPID
    - YAGNI - You aren't gonna need it

(1). **Singleton( creational pattern )**

*This pattern involves a single class which is responsible to create an object while making sure that only single object gets created. This class provides a way to access its only object which can be accessed directly without need to instantiate the object of the class.*

(2). **Decorator( structural pattern )**

Decorator pattern allows a user to add new functionality to an existing object without altering its structure. This pattern acts as a wrapper to existing class.

This pattern creates a decorator class which wraps the original class and provides additional functionality keeping class methods signature intact.


(3). **Observer( behavioral pattern )**

*Observer pattern is used when there is one-to-many relationship between objects such as if one object is modified, its depenedent objects are to be notified automatically.*

(4). **Strategy( behavior pattern )**

* In Strategy pattern, a class behavior or its algorithm can be changed at run time.
* Usages: 
   * Shopping Cart
      * PaymentMethod: Visa/MasterCard and Different types of Item can be added in Cart


(5). **Adapter( structural pattern )**

*Adapter pattern works as a bridge between two incompatible interfaces.This pattern combines the capability of two independent interfaces.*

(6). **Factory( creational pattern )**

This pattern provides one of the best ways to create an object.

In Factory pattern, we create object without exposing the creation logic to the client and refer to newly created object using a common interface.

(7). **Abstract Factory( creational pattern )**

Abstract Factory patterns work around a super-factory which creates other factories. This factory is also called as factory of factories.

This pattern provides one of the best ways to create an object.

In Abstract Factory pattern an interface is responsible for creating a factory of related objects without explicitly specifying their classes. Each generated factory can give the objects as per the Factory pattern.

(8). **Facade ( structural pattern )**

Facade pattern hides the complexities of the system and provides an interface to the client using which the client can access the system.

 This pattern adds an interface to existing system to hide its complexities.

 This pattern involves a single class which provides simplified methods required by client and delegates calls to methods of existing system classes.


(9). ****