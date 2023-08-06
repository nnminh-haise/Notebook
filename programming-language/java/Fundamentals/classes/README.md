
# Java class

> What you might need to know about class in Java

## The Basic

Basic syntax:

```java
class <class_name> {
    <field_1>
    <field_2>
    ...
    <constructor_1>
    <constructor_2>
    ...
    <method_1>
    <method_2>
    ...
}
```

Sample code: `Employee.java`

```java
import java.time.LocalDate;

public class Employee {

    // Instance fields
    private String name;
    private double salary;
    private LocalDate hireday;

    // Constructors
    Employee(String name, double salary, int day, int month, int year) {
        this.name = name;
        this.salary = salary;
        this.hireday = LocalDate.of(year, month, day);
    }

    Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
        this.hireday = LocalDate.now();
    }

    // Methods
    public String getName() {
        return this.name;
    }

    public double getSalary() {
        return this.salary;
    }

    public LocalDate getHireDate() {
        return this.hireday;
    }
}
```

### Writing Actual Classes In Java

Creating a class in Java requires users to match the file's name with the class name. For example, if you want to create a class called "Employee" then you need to create a file with the exact name "Employee.java".

> - *The access modifier "public" is added if you want the class can be access from other classes and packages. By default, the access modifier will be "private".*
> - *Compiling the java file using terminal: "javac [filename].java" such as "javac Employee.java" or "javac Employee*.java" to compile all the file start with "Employee".*

---

## Constructor

Constructor is a method that runs at first when an instance of a class is created (when you construct an object of that class). The constructor's name is the same as the class name. You can create as many as constructor you want, as long as each of them has different arguments.

> *A constructor can only be called in conjunction with the new operator. You can’t apply a constructor to an existing object to reset the instance fields.*

Basic syntax:

```java
class <class_name> {
    <field_1>
    <field_2>
    ...
    
    <class_name>(parameters) {
        <code>
    }
    <class_name>(different parameters) {
        <code>
    }
    ...
    
    <method_1>
    <method_2>
    ...
}
```

Sample code: `Employee.java`

```java
import java.time.LocalDate;

public class Employee {

    // Instance fields
    // ...

    // Constructors
    Employee(String name, double salary, int day, int month, int year) {
        this.name = name;
        this.salary = salary;
        this.hireday = LocalDate.of(year, month, day);
    }

    Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
        this.hireday = LocalDate.now();
    }

    // Methods
    // ...
}
```

---

## Fields

### Final instance fields

The `final` keyword ensure that the field is only assigned once in its life-time cycle. With that, the field must be initialized with a value since created or must be initialized with a value when the object is constructed.

The `final` modifier particularly useful for fields whose type is a *primitive* or an *immutable class*. In the other hand, with *mutable class*, the fields cannot be reassigned but the content can be change, maybe through the class's method.

Using `final` modifier with immutable class:

```java
public class Book {
    private final String ISBN;
    private String name;
    private Integer pageNumber;
    private String author;
    private Integer publicYear;
    private String category;

    public Book(String ISBN, String name, Integer pageNumber, String author, Integer publicYear, String category) {
        this.ISBN = ISBN;
        this.name = name;
        this.pageNumber = pageNumber;
        this.author = author;
        this.publicYear = publicYear;
        this.category = category;
    }

    // ! While using String as the type of ISBN, the class cannot has this method.
    // public void extendISBN(String data) {
    //     this.ISBN.append(String.format("-%s", data));
    // }

    public String toString() {
        return String.format(
                "Book [%s]: %s of %s [%s]",
                this.ISBN,
                this.name,
                this.author,
                this.category
        );
    }
}

// * Usage
public class Main {
    public static void main(String[] args) {
        Book caycamngot = new Book(
                "121321312",
                "Cay Cam Ngot Cua Toi",
                240,
                "Jose Mauro de VASCONCELOS",
                2020,
                "Truyen Ngan"
        );

        System.out.println(caycamngot);
    }
}
```

Using `final` modifier with mutable class:

```java
public class Book {
    private final StringBuilder ISBN;
    private String name;
    private Integer pageNumber;
    private String author;
    private Integer publicYear;
    private String category;

    public Book(StringBuilder ISBN, String name, Integer pageNumber, String author, Integer publicYear, String category) {
        this.ISBN = ISBN;
        this.name = name;
        this.pageNumber = pageNumber;
        this.author = author;
        this.publicYear = publicYear;
        this.category = category;
    }

    // * Can be use because StringBuilder is a mutable class. 
    public void extendISBN(String data) {
        this.ISBN.append(String.format("-%s", data));
    }

    public String toString() {
        return String.format(
                "Book [%s]: %s of %s [%s]",
                this.ISBN,
                this.name,
                this.author,
                this.category
        );
    }
}

// * Usage
public class Main {
    public static void main(String[] args) {
        StringBuilder bookISBN = new StringBuilder();
        bookISBN.append("121321312");

        Book caycamngot = new Book(
                bookISBN,
                "Cay Cam Ngot Cua Toi",
                240,
                "Jose Mauro de VASCONCELOS",
                2020,
                "Truyen Ngan"
        );

        System.out.println(caycamngot);
    }
}
```

### Static fields

The `static` modifier at the front of a field show that that field is unique among all of the instances of that class.

Let says that the class `Employee` has two fields `id` and `nextId` below:

```java
//...
public class Employee {
    private static int nextId = 1;
    private int id;
    //...
}
```

Then, each of every instance of the `Employee` class such as `Employee sam, john, peter` has a copy of the field `id`, in this case there will be three different version of the field `id` among those three instances. But there only one version of the field `nextId` which is shared among those three instances. Even when there is no instance of that class, the `static` field of that class still can be used because that field belongs to the class itself.

```java
import java.time.LocalDate;

public class Employee {
    private static int nextId = 1;

    private int id;

    private String name;
    private double salary;
    private LocalDate hireday;

    Employee(String name, double salary, int day, int month, int year) {
        this.name = name;
        this.salary = salary;
        this.hireday = LocalDate.of(year, month, day);
    }
    Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
        this.hireday = LocalDate.now();
    }

    public String toString() {
        return String.format("Employee [ID = %s]: %s", this.id, this.name);
    }
    public void setId() {
        this.id = Employee.nextId;
        Employee.nextId++;
    }
    public String getName() {
        return this.name;
    }
    public double getSalary() {
        return this.salary;
    }
    public LocalDate getHireDate() {
        return this.hireday;
    }
    public boolean equals(Employee other) {
        return this.name.equals(other.name);
    }
}

// * Usage
public class Main {
    public static void main(String[] args) {
        Employee john = new Employee("John", 1000);
        john.setId();
        Employee peter = new Employee("Peter", 1000);
        peter.setId();
        Employee nick = new Employee("Nick", 1000);
        nick.setId();

        System.out.println(john);
        System.out.println(peter);
        System.out.println(nick);
    }
}
```

### Static constants

A static constant is a field with the `static` modifier at front.

Normally, `public Double PI = 3.14;` is a field and the `static` modifier ensures this field is unique among the instances of that class. However, having a field of a class public is not good. It breaks the encapsulation of Java. Therefore by adding the `final` modifier to the field to make it a static constant is acceptable.

```java
public class Math {
    //...
    public static final double PI = 3.14;
    //...
}

// * Usage
public class Main {
    public static void main(String[] args) {
        System.out.println("Pi: " + Math.PI);
    }
}
```

---

## Methods

A method can access the private data of the object on which it is invoked.

The `Employee` class has a method called `equals()` below: `Employee.java`

```java
import java.time.LocalDate;

public class Employee {
    // ...
    public boolean equals(Employee other) {
        return this.name.equals(other.name);
    }
}
```

A usage of the above class could be: `Main.java`

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

> *A private method is a method which has the access modifier "private" at the front. Usually we have those private methods as a helper method for a computational reason.*

### Static methods

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

> **Note:** *It is legal to use an object to call a static method. For example, if john is an Employee object, then you can call john.getNextId() instead of Employee.getNextId(). However, we find that notation confusing.The getNextId method doesn’t look at john at all to compute the result. We recommend that you use class names, not objects, to invoke static methods.*

Use static methods in two situations:

- When a method doesn’t need to access the object state because all needed parameters are supplied as explicit parameters (example: Math.pow).
- When a method only needs to access static fields of the class (example: Employee.getNextId).

### Factory methods

Factory methods are methods that construct instances of that class.

There are two reason why we don't use the class's constructor in this case:

- You can’t give names to constructors. The constructor name is always the same as the class name. But we want two different names to get the currency instance and the percent instance.
- When you use a constructor, you can’t vary the type of the constructed object. But the factory methods actually return objects of the class which inherits from the class.

### Method parameters


