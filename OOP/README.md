
# Object-oriented Programming

## Classes

A class is the template or blueprint from which objects are made. Constructing an object from a class is creating an instance of the class.

**Encapsulation** is a key concept when working with objects, which is simply combining data and behavior in one package and hiding the implementation details from the users of the object.

> - The data inside the object is called **instance fields**, and the procedures that operate on the data are called its **methods**.
> 
> - A specific object that is an instance of a class will have specific values of its instance fields. The set of those values is the current **state** of the object.

The key to making encapsulation work is to have methods never directly access instance fields in a class other than their own. Encapsulation is the way to give an object its “black box” behavior, which is the key to reuse and reliability.

## Objects

To work with OOP, you should be able to identify three key characteristics of objects:

1. The object’s behavior — what can you do with this object, or what methods can apply to it?
1. The object’s state — how does the object react when you invoke those methods?
1. The object’s identity — how is the object distinguished from others that may have the same behavior and state?

All objects that are instances of the same class share a family resemblance by supporting the same behavior. **The behavior of an object** is defined by the methods that you can call.

Each object stores information about what it currently looks like. This is **the object’s state**. An object’s state may change over time, but not spontaneously. A change in the state of an object must be a consequence of method calls.

However, the state of an object does not completely describe it, because each object has a distinct **identity**. Notice that the individual objects that are instances of a class *always* differ in their identity and *usually* differ in their state.

> *These key characteristics can influence each other!*

## Identifying Classes

Creating classes requires you to identify your classes and then add methods to each class. You need to analysis the problem, look up for the **nouns** and **verbs**. The nouns may lead to the classes, and the verbs may lead to the methods.

> *This is just an advice, the keys is your personal experiences.*

## Relationship Between Classes

The most common relationships between classes are:

1. Dependence (*"use - a"*)
1. Aggregation (*"has - a"*)
1. Inheritance (*"is - a"*)

The **dependence** relationship is that a class depends on another class if its methods use or manipulate objects of that class.

> *Try to minimize the number of classes that depend on each other.*

The **aggregation** relationship is that objects of class $A$ contain another objects of class $B$.

The **inheritance** relationship is that a class $A$ is extended from a class $B$. This means that class $A$ is the same to class $B$ but has more capabilities.


