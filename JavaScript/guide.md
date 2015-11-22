# Working with objects
+ JavaScript is designed on a simple object-based paradigm.
+ An object is a collection of properties, and a property is an association between a name (or key) and a value.
+ A property's value can be a function, in which case the property is known as a method.
+ In addition to objects that are predefined in the browser, you can define your own objects.
+ This chapter describes how to use objects, properties, functions, and methods, and how to create your own objects.

#### Objects overview
+ In JavaScript, an object is a standalone entity, with properties and type.
+ Compare it with a cup, for example. A cup is an object, with properties. A cup has a color, a design, weight, a material it is made of, etc. The same way, JavaScript objects can have properties, which define their characteristics.

#### Objects and properties
+ A property of an object can be explained as a variable that is attached to the object.
+ Object properties are basically the same as ordinary JavaScript variables, except for the attachment to objects.
+ The properties of an object define the characteristics of the object.
+ Like all JavaScript variables, both the object name (which could be a normal variable) and property name are case sensitive.
```
var myCar = new Object();
myCar.make = "Ford";
myCar.model = "Mustang";
myCar.year = 1969;
```
+ Properties of JavaScript objects can also be accessed or set using a bracket notation.
+ Objects are sometimes called associative arrays, since each property is associated with a string value that can be used to access it.
```
myCar["make"] = "Ford";
myCar["model"] = "Mustang";
myCar["year"] = 1969;
```
+ An object property name can be any valid JavaScript string, or anything that can be converted to a string, including the empty string.
+ However, any property name that is not a valid JavaScript identifier (for example, a property name that has a space or a hyphen, or that starts with a number) can only be accessed using the square bracket notation.
+ This notation is also very useful when property names are to be dynamically determined (when the property name is not determined until runtime).

*Examples are as follows:*
```
// four variables are created and assigned in a single go,
// separated by commas
var myObj = new Object(),
    str = "myString",
    rand = Math.random(),
    obj = new Object();

myObj.type              = "Dot syntax";
myObj["date created"]   = "String with space";
myObj[str]              = "String value";
myObj[rand]             = "Random Number";
myObj[obj]              = "Object";
myObj[""]               = "Even an empty string";

console.log(myObj);
```

#### Enumerating all properties of an object
Starting with ECMAScript 5, there are three native ways to list/traverse object properties:
+ `for...in` loops

  This method traverses all enumerable properties of an object and its prototype chain.

+ `Object.keys(o)`

  This method returns an array with all the own (not in the prototype chain) enumerable properties' names ("keys") of an object o.

+ `Object.getOwnPropertyNames(o)`

  This method returns an array containing all own properties' names (enumerable or not) of an object o.

  #### Creating new objects
  + Using object initializers
  ```
  var obj = { property_1:   value_1,   // property_# may be an identifier...
            2:            value_2,   // or a number...
            // ...,
            "property n": value_n }; // or a string
  ```
  + Using a constructor function
    * Alternatively, you can create an object with these two steps:
        + Define the object type by writing a constructor function. There is a strong convention, with good reason, to use a capital initial letter.
        + Create an instance of the object with new.
        ```
        function Car(make, model, year) {
              this.make = make;
              this.model = model;
              this.year = year;
        }

        var mycar = new Car("Eagle", "Talon TSi", 1993);
        ```
+ Using the Object.create method

    + Objects can also be created using the Object.create() method. This method can be very useful, because it allows you to choose the prototype object for the object you want to create, without having to define a constructor function.

    ```
    // Animal properties and method encapsulation
    var Animal = {
        type: "Invertebrates", // Default value of properties
        displayType : function(){  // Method which will display type of Animal
          console.log(this.type);
        }
    }

      // Create new animal type called animal1
      var animal1 = Object.create(Animal);
      animal1.displayType(); // Output:Invertebrates

      // Create new animal type called Fishes
      var fish = Object.create(Animal);
      fish.type = "Fishes";
      fish.displayType(); // Output:Fishes
```


#### Inheritance
All objects in JavaScript inherit from at least one other object.

#### Indexing object properties

#### Defining properties for an object type

#### Defining methods

+ A method is a function associated with an object.
+ or, simply put, a method is a property of an object that is a function.
+ Methods are defined the way normal functions are defined, except that they have to be assigned as the property of an object.

```
function pretty_print(result){
    console.log(result);
}
function displayCar() {
  var result = "A Beautiful " + this.year + " " + this.make
    + " " + this.model+". & "+this.owner.name+" is using";
  pretty_print(result);
}

function Person(name, age, sex) {
  this.name = name;
  this.age = age;
  this.sex = sex;
}

function Car(make, model, year, owner) {
  this.make = make;
  this.model = model;
  this.year = year;
  this.owner = owner;
  this.displayCar = displayCar;
}

var rand = new Person("Rand McKinnon", 33, "M");
var car1 = new Car("Eagle", "Talon TSi", 1993, rand);
car1.displayCar();
```

#### Using this for object references
#### Defining getters and setters
START
