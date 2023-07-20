
# Variables

---

## Declaring a variable

A variable can be created follow the format: `{Data type} {Variable name}`. Remember to add a semicolon at the end of every statement.

Examples:

```java
public class Main {
    public static void main(String[] args) {
        int a;
        double b;
        char c;
        boolean d;
    }
}
```

A variable name must start with a letter and must be a sequence of letters or digits. All character in a variable name are case significant, and their length is unlimited.

Cannot use Java reserved name as a variable name.

Multiple variables can be declared in a single line:

```java
public class Main {
    public static void main(String[] args) {
        int i, j;
    }
}
```

**Notes:**

The above code can be compiled and run just fine but be aware that when you trying to use it, the Java compiler will raises an error.

---

## Initializing variables

Creating variables containing no value is called declarations.

```java
public class Main {
    public static void main(String[] args) {
        int a; // declare a variable a
    }
}
```

Creating variables with correct values is called initializations.

```java
public class Main {
    public static void main(String[] args) {
        int a = 100; // initialize variable a with value 100
    }
}
```

Initializing variables with wrong values will cause an error from the compiler.

```java
public class Main {
    public static void main(String[] args) {
        int a = "100"; // Error
    }
}
```

Using the printing statement, you can print the value of the variables to the console.

```java
public class Main {
    public static void main(String[] args) {
        int a = 100;
        System.out.println("Value of a: " + a); // using the variable a
    }
}
```

In the other hand, using an uninitialized variable in Java is not allowed!

```java
public class Main {
    public static void main(String[] args) {
        int a;
        System.out.println("Value of a: " + a); // ERROR here
    }
}
```

---

## Constants

> *Constants is a special type of variables that you only assign the value to it once and that value will never be changed.*

You use the keyword `final` to indicate a variable as a constant:

```java
public class Main {
    public static void main(String[] args) {
        final double VALUE_OF_PI = 3.14;
        System.out.println("Value of Pi: " + VALUE_OF_PI);
    }
}
```

It's a good practice to use capital letters only when naming the constant.

---

## Type of variables

> *There are three types of variables: local, instance and static.*

### Local variables

Local variables are variables which are created inside a method and only use inside that method. Other methods or class which that method belongs to also cannot use it.

```java
public class Main {
    public static int MultiplyBy10(int value) {
        int c = 1000;
        return value * 10;
    }

    public static void main(String[] args) {
        int a = 100;
        int b = MultiplyBy10(a);
        System.out.println("Value of a after multiply by 10: " + b);
    }
}
```

In this case, the variable `c` is a local variable.

### Instance variables

Instance variables are variables which are created when a instance of a class is created.

Instance variables are createed inside of a class but outside of methods.

Instance variables are not declared as `static`.

Values of instance variables is not shared among instances of a same class.


```java
public class Main {
    public static int MultiplyBy10(int value) {
        return value * 10;
    }

    public static void main(String[] args) {
        int a = 100;
        int b = MultiplyBy10(a);
        System.out.println("Value of a after multiply by 10: " + b);
    }
}
```

In this example, `a` and `b` is instance variables and `value` is a local variable.


### Static variables

Static variables are variables which are declared with the keyword `static` and cannot be local.

Static variables value are shared among instances.

Memory allocation for static variables happens only once when the class is loaded in the memory.

**Example:**

Considering the class `A` below:

```java
public class A {
    private static double a = 3.14;

    public static double getA() {
        return a;
    }

    public static void setA(double newValue) {
        a = newValue;
    }

    public static void Print() {
        System.out.println("Value of A: " + a);
    }
}
```

And the output from this below code:

```java
public class Main {
    public static void main(String[] args) {
        A a = new A();
        A b = new A();

        a.setA(100);
        a.Print(); // Print 100
        b.Print(); // Print 100

        b.setA(10000);
        a.Print(); // Print 10000
        b.Print(); // Print 10000
    }
}
```

This code shows that the value of the static variable `a` inside the class `A` is shared among the instances `a` and `b` inside the class `Main`.

