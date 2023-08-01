
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


