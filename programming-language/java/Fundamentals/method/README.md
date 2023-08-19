
# Method

---

<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Static methods](#static-methods)
- [Factory methods](#factory-methods)
- [Method parameters](#method-parameters)

<!-- /code_chunk_output -->

---

A method can access the private data of the object on which it is invoked.

The `Employee` class has a method called `equals()` below:

`Employee.java`

```java
import java.time.LocalDate;

public class Employee {
    // ...
    public boolean equals(Employee other) {
        return this.name.equals(other.name);
    }
}
```

A usage of the above class could be:

`Main.java`

```java
public class Main {
    public static void main(String[] args) {
        Employee sam = new Employee("Sam", 1500);
        Employee boss = new Employee("Anne", 15000);

        System.out.println(sam.equals(boss));
    }
}
```

*Normally, the `equals` method can use the private data of the object `sam`, but `boss` is a different instance of the same class of `sam`. Therefore the method `equals` can use the private data of `boss`.*

> ***Notes:***
>
> 💡 Methods of a same class can access private data of many instances of the same class.
> 💡 A private method is a method which has the access modifier "private" at the front. Usually we have those private methods as a helper method for a computational reason.

---

## Static methods

Static methods are methods that do not operate on objects. A static methods has no implicit parameter (no `this` parameter).

```java
public class Employee {
    private static int nextId = 1;
    private int id;

    //...
    public static int getNextId() {
        return Employee.nextId;
    }
    //...
}

// * Usage
public class Main {
    public static void main(String[] args) {
        Employee john = new Employee("John", 1000);
        john.setId();
        System.out.println("Next employee id: " + Employee.getNextId());
        Employee peter = new Employee("Peter", 1000);
        peter.setId();
        System.out.println("Next employee id: " + Employee.getNextId());
        Employee nick = new Employee("Nick", 1000);
        nick.setId();
        System.out.println("Next employee id: " + Employee.getNextId());

        System.out.println(john);
        System.out.println(peter);
        System.out.println(nick);
    }
}
```

> ***Alert:***
>
> ❗️ It is legal to use an object to call a static method. For example, if john is an Employee object, then you can call john.getNextId() instead of Employee.getNextId(). However, we find that notation confusing.The getNextId method doesn’t look at john at all to compute the result. We recommend that you use class names, not objects, to invoke static methods.

**Use static methods in two situations:**

- When a method doesn’t need to access the object state because all needed parameters are supplied as explicit parameters (example: Math.pow).
- When a method only needs to access static fields of the class (example: Employee.getNextId).

---

## Factory methods

Factory methods are methods that construct instances of that class.

Two reason why we don't use the class's constructor in this case:

- You can’t give names to constructors. The constructor name is always the same as the class name. But we want two different names to get the currency instance and the percent instance.
- When you use a constructor, you can’t vary the type of the constructed object. But the factory methods actually return objects of the class which inherits from the class.

---

## Method parameters

Parameters in Java are called by value by default and this applies to all the primitive data types in Java.

And with objects, they will pass a "object reference" into methods. Basically they are the address of an instance belongs to a class.


