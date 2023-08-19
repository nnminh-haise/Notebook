
# A Simple Java Program

---

This is a simple Java program prints "Hello World" to the console.

`Playground.java`

```java
public class Playground {
    public static void main(String[] args) {
        System.out.println("Hello World");
    }
}
```

Through this first example, these are the things you need to know about java.

1. Java is a "case sensitive" programming language. This means that "Main" is different than "main" and so on.
2. The class name must be the same as the file name. This means that if the class name is "Main" then the file must be "Main.java" as the example above.
3. Everything in java must be stored inside a class (*if you don't familiar to this term, you can just understand it as a container for the logic that define the behavior of the application*).
4. The keyword `public` is an access modifier control the level of access other part of the program to this class. And the `public` keyword shows that this class can be access from other part of the program. There are other access modifier you will meet in the future don't worry!
5. The method `main` must be a public method. Again, if you don't familiar with this term, just understand that method or function is a set of logic perform a specific behavior of a class. A class could has as many methods it needs.

***Naming convention***

Naming rules for Java is quite simple, the first character must be a letter, the following character could be a combination of digits and letters. The length is basically limitless but I advise you to make it meaningful to the one who read your code. And remember, Java is a case sensitive programming language!

A recommendation naming convention from the former Java developers is that you should follow the [*camelCase*](https://en.wikipedia.org/wiki/Camel_case) naming convention. Basically if you want to name something such as "the best code ever" then you should type something like this "theBestCodeEver". Instead of using space to separate each words, you can make the first letter of each word capital and keep the other normal.

## Explanation

For now, you can just admit those keyword `public`, `static` and `void` is something essential to a java program and a basic java program should follow the below frame:

```java
public class [ClassName] {
    public static void main(String[] args) {
        [statements]
    }
}
```

A class name should follow the naming convention I mentioned above and must be the same to the file's name!

You can see the braces `{ }` in the source code, the braces delineates the parts (or blocks) in your program. In Java all the method must start with an opening brace `{` and end with a close brace `}`. We usually call the inside part of the braces "the body" of something. If the braces belongs to the class, then the inside is the body of that class, the same goes to methods.

Inside the `main` method above, there is only one line `System.out.println("Hello World");`. This is called a statement, you can understand Java statements as sentences of the language. All Java statements must end with a semicolon. In particular, carriage returns do not mark the end of a statement, so statements can span multiple lines if need be.

The body of the main method contains a statement that outputs a single line of text to the console. Here, we are using the `System.out` object and calling its `println` method. Notice the periods used to invoke a method. Java uses the general syntax `object.method(parameters)` as its equivalent of a function call.

In this case, we are calling the `println` method and passing it a string parameter. The method displays the string parameter on the console. It then terminates the output line, so that each call to `println` displays its output on a new line.

Methods in Java, like functions in any programming language, can use zero, one, or more parameters (some programmers call them arguments). Even if a method takes no parameters, you must still use empty parentheses. For example, a variant of the println method with no parameters just prints a blank line. You invoke it with the call `System.out.println();`.

---

## Comments

Comments are code that will be skipped when the program is running. So adding comments to your code will enhance the reading ability and help making the code maintainable with the future updates.

You can add comments in a line by adding the `//` symbol before writing your comments.

`Playground.java`

```java
public class Playground {
    public static void main(String[] args) {
        System.out.println("Hello World"); // This statement prints a greet to the console.
    }
}
```

If you need multiple lines comments, you can surround your comments inside `/* */` like this:

```java
/**
 * This is an example of a simple java program.
 * This program prints a greeting to the console.
 * 
 * @author nnminh
 */
public class Playground {
    public static void main(String[] args) {
        System.out.println("Hello World"); // This statement prints a greeting to the console.
    }
}
```
