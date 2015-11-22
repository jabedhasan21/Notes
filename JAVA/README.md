## Java

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




































# Encapsulation
Encapsulation in Java is a mechanism of wrapping the data (variables) and code acting on the data (methods) together as as single unit. In encapsulation the variables of a class will be hidden from other classes, and can be accessed only through the methods of their current class, therefore it is also known as data hiding.

**To achieve encapsulation in Java**

- Declare the variables of a class as private.

- Provide public setter and getter methods to modify and view the variables values.

**Benefits of Encapsulation:**

- The fields of a class can be made read-only or write-only.

- A class can have total control over what is stored in its fields.

- The users of a class do not know how the class stores its data. A class can change the data type of a field and users of the class do not need to change any of their code.


### Polymorphism
Polymorphism is the ability of an object to take on many forms. The most common use of polymorphism in OOP occurs when a parent class reference is used to refer to a child class object.

Any Java object that can pass more than one IS-A test is considered to be polymorphic.
