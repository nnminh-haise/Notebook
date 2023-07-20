# Java Operators Documentation

## Arithmetic Operators

Arithmetic operators are used to perform mathematical operations on numeric operands.

| Operator | Description         |
| :------: | ------------------- |
|   `+`    | Addition            |
|   `-`    | Subtraction         |
|   `*`    | Multiplication      |
|   `/`    | Division            |
|   `%`    | Modulus (Remainder) |
|   `++`   | Increment by 1      |
|   `--`   | Decrement by 1      |

**Sample:**

```java
public class ArithmeticOperatorsSample {
    public static void main(String[] args) {
        int num1 = 10;
        int num2 = 5;
        
        int addition = num1 + num2;
        int subtraction = num1 - num2;
        int multiplication = num1 * num2;
        int division = num1 / num2;
        int modulus = num1 % num2;
        
        int increment = num1++;
        int decrement = num2--;
        
        System.out.println("Addition: " + addition);
        System.out.println("Subtraction: " + subtraction);
        System.out.println("Multiplication: " + multiplication);
        System.out.println("Division: " + division);
        System.out.println("Modulus: " + modulus);
        System.out.println("Increment: " + increment);
        System.out.println("Decrement: " + decrement);
    }
}
```

## Assignment Operators

Assignment operators are used to assign values to variables.

| Operator | Description               |
| :------: | ------------------------- |
|   `=`    | Simple assignment         |
|   `+=`   | Addition assignment       |
|   `-=`   | Subtraction assignment    |
|   `*=`   | Multiplication assignment |
|   `/=`   | Division assignment       |
|   `%=`   | Modulus assignment        |
|  `<<=`   | Left shift assignment     |
|  `>>=`   | Right shift assignment    |
|   `&=`   | Bitwise AND assignment    |
|   `|=`   | Bitwise OR assignment     |
|   `^=`   | Bitwise XOR assignment    |

**Sample:**

```java
public class AssignmentOperatorsSample {
    public static void main(String[] args) {
        int x = 10;
        int y = 5;
        
        x += y;  // Equivalent to: x = x + y;
        System.out.println("Addition assignment: " + x);
        
        x -= y;  // Equivalent to: x = x - y;
        System.out.println("Subtraction assignment: " + x);
        
        x *= y;  // Equivalent to: x = x * y;
        System.out.println("Multiplication assignment: " + x);
        
        x /= y;  // Equivalent to: x = x / y;
        System.out.println("Division assignment: " + x);
        
        x %= y;  // Equivalent to: x = x % y;
        System.out.println("Modulus assignment: " + x);
        
        x <<= 2; // Equivalent to: x = x << 2;
        System.out.println("Left shift assignment: " + x);
        
        x >>= 1; // Equivalent to: x = x >> 1;
        System.out.println("Right shift assignment: " + x);
        
        x &= 3;  // Equivalent to: x = x & 3;
        System.out.println("Bitwise AND assignment: " + x);
        
        x |= 5;  // Equivalent to: x = x | 5;
        System.out.println("Bitwise OR assignment: " + x);
        
        x ^= 6;  // Equivalent to: x = x ^ 6;
        System.out.println("Bitwise XOR assignment: " + x);
    }
}
```

## Comparison Operators

Comparison operators are used to compare values and determine the relationship between them.

| Operator | Description              |
| :------: | ------------------------ |
|   `==`   | Equality                 |
|   `!=`   | Inequality               |
|   `>`    | Greater than             |
|   `>=`   | Greater than or equal to |
|   `<`    | Less than                |
|   `<=`   | Less than or equal to    |

**Sample:**

```java
public class ComparisonOperatorsSample {
    public static void main(String[] args) {
        int num1 = 10;
        int num2 = 5;
        
        boolean isEqual = num1 == num2;
        boolean isNotEqual = num1 != num2;
        boolean isGreaterThan = num1 > num2;
        boolean isGreaterThanOrEqual = num1 >= num2;
        boolean isLessThan = num1 < num2;
        boolean isLessThanOrEqual = num1 <= num2;
        
        System.out.println("Equal: " + isEqual);
        System.out.println("Not Equal: " + isNotEqual);
        System.out.println("Greater Than: " + isGreaterThan);
        System.out.println("Greater Than or Equal: " + isGreaterThanOrEqual);
        System.out.println("Less Than: " + isLessThan);
        System.out.println("Less Than or Equal: " + isLessThanOrEqual);
    }
}
```

## Logical Operators

Logical operators are used to perform logical operations on boolean values.

| Operator | Description |
| :------: | ----------- |
|   `&&`   | Logical AND |
|   `||`   | Logical OR  |
|   `!`    | Logical NOT |

**Sample:**

```java
public class LogicalOperatorsSample {
    public static void main(String[] args) {
        boolean isSunny = true;
        boolean isWarm = false;
        
        // Logical AND operator &&
        boolean isGoodWeather = isSunny && isWarm;
        System.out.println("Is it good weather? " + isGoodWeather);
        
        // Logical OR operator ||
        boolean isAnyConditionMet = isSunny || isWarm;
        System.out.println("Is any condition met? " + isAnyConditionMet);
        
        // Logical NOT operator !
        boolean isNotSunny = !isSunny;
        System.out.println("Is it not sunny? " + isNotSunny);
    }
}
```

## Bitwise Operators

Bitwise operators are used to perform bitwise operations on integer values.

| Operator | Description          |
| :------: | -------------------- |
|   `&`    | Bitwise AND          |
|   `|`    | Bitwise OR           |
|   `^`    | Bitwise XOR          |
|   `~`    | Bitwise complement   |
|   `<<`   | Left shift           |
|   `>>`   | Right shift          |
|  `>>>`   | Unsigned right shift |

**Sample:**

```java
public class BitwiseOperatorsSample {
    public static void main(String[] args) {
        int num1 = 5;  // 0101 in binary
        int num2 = 3;  // 0011 in binary
        
        int bitwiseAnd = num1 & num2;
        int bitwiseOr = num1 | num2;
        int bitwiseXor = num1 ^ num2;
        int bitwiseComplement = ~num1;
        int leftShift = num1 << 2;
        int rightShift = num1 >> 1;
        int zeroFillRightShift = num1 >>> 1;
        
        System.out.println("Bitwise AND: " + bitwiseAnd);
        System.out.println("Bitwise OR: " + bitwiseOr);
        System.out.println("Bitwise XOR: " + bitwiseXor);
        System.out.println("Bitwise Complement: " + bitwiseComplement);
        System.out.println("Left Shift: " + leftShift);
        System.out.println("Right Shift: " + rightShift);
        System.out.println("Zero-fill Right Shift: " + zeroFillRightShift);
    }
}
```

## Conditional Operator (Ternary)

The conditional operator, also known as the ternary operator, is a shorthand way to write if-else statements.

| Operator | Description         |
| :------: | ------------------- |
|  `? :`   | Ternary conditional |

**Sample:**

```java
public class ConditionalOperatorsSample {
    public static void main(String[] args) {
        int num1 = 10;
        int num2 = 5;
        
        // Ternary operator
        int max = (num1 > num2) ? num1 : num2;
        
        // Conditional AND operator
        boolean condition1 = (num1 > 0) && (num2 > 0);
        
        // Conditional OR operator
        boolean condition2 = (num1 > 0) || (num2 > 0);
        
        System.out.println("Maximum: " + max);
        System.out.println("Condition 1: " + condition1);
        System.out.println("Condition 2: " + condition2);
    }
}

```

## Instanceof Operator

The instanceof operator is used to check if an object is an instance of a particular class or implements a particular interface.

|   Operator   | Description              |
| :----------: | ------------------------ |
| `instanceof` | Type comparison operator |

**Sample:**

```java
public class InstanceOfOperatorSample {
    public static void main(String[] args) {
        String str = "Hello, world!";
        Integer number = 42;
        Object obj = str;
        
        System.out.println("str instanceof String: " + (str instanceof String));
        System.out.println("number instanceof Integer: " + (number instanceof Integer));
        System.out.println("obj instanceof String: " + (obj instanceof String));
        System.out.println("obj instanceof Integer: " + (obj instanceof Integer));
    }
}
```
