
# Structured binding declaration

> ***Only work with C++17 or above.***

---

## Table of contents

1. [Definition](#definition)
1. [Usage](#usage)
1. [References](#references)



---

## Definition

- Structured binding declaration is used to binding the specified names to sub-objects or elements of the initializer.
- Structured binding is an alias to an existing object and also does not have to be of a reference type.

## Usage

```cpp
auto [<identifier-list>] = <expression>;
```

***Example:***

```cpp
#include <iostream>
#include <tuple>

std::tuple < int, double, bool > dataProcessing() {
    return {
        20, 12.1, true
    };
}

int main() {
    auto [intValue, doubleValue, boolValue] = dataProcessing();
    
    std::cout << intValue << std::endl;
    std::cout << doubleValue << std::endl;
    std::cout << boolValue << std::endl;

    return 0;
}
```

A structured binding declaration introduces all identifiers int the *indentifier-list* as name in the surrounding scope and binds them to sub=objects or elements of the object denoted by *expression*.

### Binding an array

Each identifier in the *identifier-list* becomes the name of an lvalue that refers to the corresponding element of the array. **The number of identifiers must equal the number of array elements.**



## References

1. [Structured binding declaration | cppreference](https://en.cppreference.com/w/cpp/language/structured_binding)



