# Java
What are the principle conscepts od OOPS?

 There are four principle conscepts upon which object oriented design and programming rest. They are:

    + Abstraction
    + Polymorphism
    + Inheritance
    + Encapsulation.

# Inheritance
Inheritance can be defined as the process where one class acquires the properties (methods and fields) of another. With the use of inheritance the information is made manageable in a hierarchical order.
 + The class which inherits the properties of other is known as subclass (derived class, child class)
 + The class whose properties are inherited is known as superclass (base class, parent class).

#### extends Keyword
extends is the keyword used to inherit the properties of a class. Below given is the syntax of extends keyword.
```
class Super{
.....
.....
}

class Sub extends Super{
.....
.....

}
```

Sample Code
```
class Calculation{
   int z;
   public void addition(int x, int y){
      z=x+y;
      System.out.println("The sum of the given numbers:"+z);
   }
   public void Substraction(int x,int y){
      z=x-y;
      System.out.println("The difference between the given numbers:"+z);
   }

}

public class My_Calculation extends Calculation{

   public void multiplication(int x, int y){
      z=x*y;
      System.out.println("The product of the given numbers:"+z);
   }
   public static void main(String args[]){
      int a=20, b=10;
      My_Calculation demo = new My_Calculation();
      demo.addition(a, b);
      demo.Substraction(a, b);
      demo.multiplication(a, b);

   }

}
```
After executing the program it will produce the following result.
```
The sum of the given numbers:30
The difference between the given numbers:10
The product of the given numbers:200
```



# Abstraction

+ Object oriented programming Abstraction is a process process of hiding the implementation details from the user, only the functionality will be provided to the user.

+ In other words user will have the information on what the object does instead of how it does it.

+ In Java Abstraction is achieved using Abstract classes, and Interfaces.

#### What is Abstract Class?
A class which contains the abstract keyword in its declaration is known as abstract class.
+ Abstract classes may or may not contain abstract methods ie., methods with out body ( public void get(); )
+ But, if a class have at least one abstract method, then the class must be declared abstract.
+ If a class is declared abstract it cannot be instantiated.
+ To use an abstract class you have to inherit it from another class, provide implementations to the abstract methods in it.
+ If you inherit an abstract class you have to provide implementations to all the abstract methods in it.

#### Ways to achieve Abstaction
There are two ways to achieve abstraction in java.
+ Abstract class (0 to 100%)
+ Interface (100%)

#### Example
This section provides you an example of the abstract class to create an abstract class just use the abstract keyword before the class keyword, in the class declaration .
```
public abstract class Employee
{
   private String name;
   private String address;
   private int number;
   public Employee(String name, String address, int number)
   {
      System.out.println("Constructing an Employee");
      this.name = name;
      this.address = address;
      this.number = number;
   }
   public double computePay()
   {
     System.out.println("Inside Employee computePay");
     return 0.0;
   }
   public void mailCheck()
   {
      System.out.println("Mailing a check to " + this.name
       + " " + this.address);
   }
   public String getName()
   {
      return name;
   }
   public String getAddress()
   {
      return address;
   }
   public void setAddress(String newAddress)
   {
      address = newAddress;
   }
   public int getNumber()
   {
     return number;
   }
}
```

#### Inheriting the Abstract Class:
We can inherit the properties of Employee class just like concrete class as shown below:

```
public class Salary extends Employee
{
   private double salary; //Annual salary
   public Salary(String name, String address, int number, double
      salary)
   {
       super(name, address, number);
       setSalary(salary);
   }
   public void mailCheck()
   {
       System.out.println("Within mailCheck of Salary class ");
       System.out.println("Mailing check to " + getName()
       + " with salary " + salary);
   }
   public double getSalary()
   {
       return salary;
   }
   public void setSalary(double newSalary)
   {
       if(newSalary >= 0.0)
       {
          salary = newSalary;
       }
   }
   public double computePay()
   {
      System.out.println("Computing salary pay for " + getName());
      return salary/52;
   }
}
```

Here, you cannot instantiate the Employee class, but you can instantiate the Salary Class, and using this instance you can access the all the three fields and all methods of Employee class as shown below.

```
public class AbstractDemo
{
   public static void main(String [] args)
   {
      Salary s = new Salary("Mr Foo", "Ambehta, UP", 3, 3600.00);
      Employee e = new Salary("John Adams", "Boston, MA", 2, 2400.00);

      System.out.println("Call mailCheck using Salary reference --");
      s.mailCheck();

      System.out.println("\n Call mailCheck using Employee reference--");
      e.mailCheck();
    }
}
```
This produces the following result:
```
Constructing an Employee
Constructing an Employee
Call mailCheck using  Salary reference --
Within mailCheck of Salary class
ailing check to Mohd Mohtashim with salary 3600.0

Call mailCheck using Employee reference--
Within mailCheck of Salary class
ailing check to John Adams with salary 2400.
```

#### Abstract Methods:
 + abstract keyword is used to declare the method as abstract.
 + You have to place the abstract keyword before the method name in the method declaration.
 + An abstract method contains a method signature, but no method body.

 + Instead of curly braces an abstract method will have a semoi colon ( ; ) at the end.

 Below given is an example of the abstract method.

```
public abstract class Employee
{
   private String name;
   private String address;
   private int number;

   public abstract double computePay();

   //Remainder of class definition
}
```

Declaring a method as abstract has two consequences:
  + The class containing it must be declared as abstract.
  + Any class inheriting the current class must either override the abstract method or declare itself as abstract.

Suppose Salary class is inherits the Employee class, then it should implement the computePay() method as shown below:

```
public class Salary extends Employee
{
   private double salary; // Annual salary

   public double computePay()
   {
      System.out.println("Computing salary pay for " + getName());
      return salary/52;
   }

   //Remainder of class definition
}
```

# Polymorphism
Polymorphism is the ability of an object to take on many forms. The most common use of polymorphism in OOP occurs when a parent class reference is used to refer to a child class object.

+ Any Java object that can pass more than one IS-A test is considered to be polymorphic.

#### Example:
Let us look at an example.
```
public interface Vegetarian{}
public class Animal{}
public class Deer extends Animal implements Vegetarian{}
```
Now, the Deer class is considered to be polymorphic since this has multiple inheritance. Following are true for the above example:

  + A Deer IS-A Animal
  + A Deer IS-A Vegetarian
  + A Deer IS-A Deer
  + A Deer IS-A Object

When we apply the reference variable facts to a Deer object reference, the following declarations are legal:
```
Deer d = new Deer();
Animal a = d;
Vegetarian v = d;
Object o = d;
```
All the reference variables d,a,v,o refer to the same Deer object in the heap.

#### Virtual Methods:
In this section, I will show you how the behaviour of overridden methods in Java allows you to take advantage of polymorphism when designing your classes.
 + An overridden method is essentially hidden in the parent class, and is not invoked unless the child class uses the super keyword within the overriding method.

 ```
 public class Employee
{
   private String name;
   private String address;
   private int number;
   public Employee(String name, String address, int number)
   {
      System.out.println("Constructing an Employee");
      this.name = name;
      this.address = address;
      this.number = number;
   }
   public void mailCheck()
   {
      System.out.println("Mailing a check to " + this.name
       + " " + this.address);
   }

   public String getName()
   {
      return name;
   }
   public String getAddress()
   {
      return address;
   }
   public void setAddress(String newAddress)
   {
      address = newAddress;
   }
   public int getNumber()
   {
     return number;
   }
}
```
Now suppose we extend Employee class as follows:

```
public class Salary extends Employee
{
   private double salary; //Annual salary
   public Salary(String name, String address, int number, double
      salary)
   {
       super(name, address, number);
       setSalary(salary);
   }
   public void mailCheck()
   {
       System.out.println("Within mailCheck of Salary class ");
       System.out.println("Mailing check to " + getName()
       + " with salary " + salary);
   }
   public double getSalary()
   {
       return salary;
   }
   public void setSalary(double newSalary)
   {
       if(newSalary >= 0.0)
       {
          salary = newSalary;
       }
   }
   public double computePay()
   {
      System.out.println("Computing salary pay for " + getName());
      return salary/52;
   }
}
```
Now, you study the following program carefully and try to determine its output:

```
public class VirtualDemo
{
   public static void main(String [] args)
   {
      Salary s = new Salary("Mohd Mohtashim", "Ambehta, UP", 3, 3600.00);
      Employee e = new Salary("John Adams", "Boston, MA", 2, 2400.00);
      System.out.println("Call mailCheck using Salary reference --");
      s.mailCheck();
      System.out.println("\n Call mailCheck using Employee reference--");
      e.mailCheck();
    }
}
```
This would produce the following result:

```
Constructing an Employee
Constructing an Employee
Call mailCheck using Salary reference --
Within mailCheck of Salary class
ailing check to Mohd Mohtashim with salary 3600.0

Call mailCheck using Employee reference--
Within mailCheck of Salary class
ailing check to John Adams with salary 2400.0
```

+ Here, we instantiate two Salary objects . one using a Salary reference s, and the other using an Employee reference e.

+ While invoking s.mailCheck() the compiler sees mailCheck() in the Salary class at compile time, and the JVM invokes mailCheck() in the Salary class at run time.

+ Invoking mailCheck() on e is quite different because e is an Employee reference. When the compiler sees e.mailCheck(), the compiler sees the mailCheck() method in the Employee class.

+ Here, at compile time, the compiler used mailCheck() in Employee to validate this statement. At run time, however, the JVM invokes mailCheck() in the Salary class.

+ This behavior is referred to as virtual method invocation, and the methods are referred to as virtual methods. All methods in Java behave in this manner, whereby an overridden method is invoked at run time, no matter what data type the reference is that was used in the source code at compile time.


# Encapsulation
Encapsulation in Java is a mechanism of wrapping the data (variables) and code acting on the data (methods) together as as single unit. In encapsulation the variables of a class will be hidden from other classes, and can be accessed only through the methods of their current class, therefore it is also known as data hiding.

**To achieve encapsulation in Java**

- Declare the variables of a class as private.

- Provide public setter and getter methods to modify and view the variables values.

**Benefits of Encapsulation:**

- The fields of a class can be made read-only or write-only.

- A class can have total control over what is stored in its fields.

- The users of a class do not know how the class stores its data. A class can change the data type of a field and users of the class do not need to change any of their code.
