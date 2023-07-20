
# Constructor

> *Constructor is a special type of function or method which get called when a new instanct of an object is created.*

---


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Constructor](#constructor)
  - [Definition](#definition)
  - [Other variations](#other-variations)
    - [Parameterized constructor](#parameterized-constructor)
    - [Copy contructor](#copy-contructor)

<!-- /code_chunk_output -->


---

## Definition

- A constructor is just a special kind of function (or method) which get called when an instance of an object is being created.
- A constructor is a no return type function, neither of data type nor void is the return type and the function name is identical to the class name.

```java
public class Coordinate {
    public Coordinate() {
        x = 0;
        y = 0;
    }

    public void Print() {
        System.out.println(x + " " + y);
    }

    private int x;
    private int y;
}
```

Let says from the above `Coordinate` class. We want to create a point $A$ at $(3, 2)$ in $Oxy$ plane. Here is how we do it.

```java
public class Main {
    public static void Main(String[] args) {
        Coordinate pointA = new Coordinate();
        pointA.Print();
    }
}
```

## Other variations

The above constructor is called default constructor. A class can have more than one constructor for itself. Because constructor is basically a function, therefore you can follow the function overloading rules to create as many constructor you want.

### Parameterized constructor

A parameterized constructor is a contructor with one or more parameters. There could be many parameterized constructor in the same class but all of them must have different parameters.

```java
public class Coordinate {
    public Coordinate() {
        x = 0;
        y = 0;
    }

    public Coordinate(int x) {
        this.x = x;
    }

    public Coordinate(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void Print() {
        System.out.println(x + " " + y);
    }

    private int x;
    private int y;
}
```

### Copy contructor

A copy constructor is a special constructor which takes another instance of the same object, copy the data of that object, then create a new object with the copied data.

A copy constryctor will create a copy of an instance of an object.

```java
public class Coordinate {
    public Coordinate() {
        x = 0;
        y = 0;
    }

    public Coordinate(Coordinate other) {
        this.x = other.x;
        this.y = other.y;
    }

    public Coordinate(int x) {
        this.x = x;
    }

    public Coordinate(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void Print() {
        System.out.println(x + " " + y);
    }

    private int x;
    private int y;
}
```
