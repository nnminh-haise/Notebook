
# Create your first Hello Module

---

## Table of contents

- [Prerequisites](#prerequisites)
- [Create module](#create-module)
- [Code explaination](#code-explaination)
- [Using other package](#using-other-package)

---

## Prerequisites

- Install the latest `go` version.
- Having a text editor which can support golang for easy coding.

## Create module

1. Choose a directory for your module. Let choose the `home` directory to store the module.

```bash
$ cd ~
```

💡 *My suggestion is that you should create a dedicated directory for containing your `go` modules during the learning curve. This way you can browse and search for your code more easily if needed.*

2. Create a `hello` directory to store the module.

```bash
$ mkdir hello
$ cd hello
```

3. `golang` manage your code base on modules which means that each program is a module so there is a system for tracking and managing those modules. To enable the ability to dependency tracking for your code, use the `go mod init` command. In the development environment, each module will be manage base on their directory which also be the module path. So it's good to pay attention to the placement of your module. For the sake of an easy demonstration, I will use `example/hello`

```bash
$ go mod init example/hello
go: creating new go.mod: module example/hello
```

4. Open your favor text editor and place the below code into a file called `hello.go`.

<div id="source-code-name">hello.go</div>

```go
package main

import "fmt"

func main() {
    fmt.Println("Hello")
}
```

5. Save the file and use the below command to run your code.

```bash
$ go run .
```

## Code explaination

```go
package main
```

This is how you indicate that you are declaring a package called `main`. *A package is the way to group functions and it is made up of all files in the same directory.*


```go
import "fmt"
```

Your are importing a package called `fmt` which is a popular package containing functions for formatting text. This is one of the [standard library](https://pkg.go.dev/std) packages you got when you intall `go`.

```go
func main() {
    fmt.Println("Hello")
}
```

You can create a function by using the key word `func` which is a short form of the word function follows the function's name and parenthese wraps around the needed arguments and lastly a pair of braces containning all your code.

The above code implements the `main` function which is the function will be executed by default when you run the `main` package.

You are using the function `Println` in the `fmt` package to print the world "Hello" to the console. This is one of the many funtions which `fmt` provides for you.

## Using other package

If there is a function implements a task you might need, you can import the packge which contains that function and use in your code.

For example: You can spice up printing in the console by adding the [`quote` package](https://pkg.go.dev/rsc.io/quote/v4) to your code.

- Visit the [`quote` package](https://pkg.go.dev/rsc.io/quote/v4).
- In the **Documentation** section, under **Index** notes the list of function you call use in your code. We will use the `Go` function.
- Note that the `quote` package is included in the `rsc.io/quote` module.

> You can use the [pkg.go.dev](pkg.go.dev) site to find published modules whose packages have functions you can use in your own code. Packages are published in modules like `rsc.io/quote` where others can use them. Modules are improved with new versions over time, and you can upgrade your code to use the improved versions.

In your `helllo.go` source file, import the `rsc.io/quote` module and use the `Go` function.

<div id="source-code-name">hello.go</div>

```go
package main

import (
    "fmt"

    "rsc.io/quote"
)

func main() {
    fmt.Println(quote.Go())
}
```

Next you will add the `quote` module as the requirement and a `go.sum` file for use in authenticating the module.

```bash
$ go mod tidy
go: finding module for package rsc.io/quote
go: downloading rsc.io/quote v1.5.2
go: found rsc.io/quote in rsc.io/quote v1.5.2
go: downloading rsc.io/sampler v1.3.0
go: downloading golang.org/x/text v0.0.0-20170915032832-14c0d48ead0c
```

Use the `go run` command to see the result.

```bash
$ go run .
Don't communicate by sharing memory, share memory by communicating.
```

The `go mod tidy` command will find the needed module and download the package which contains the module you imported. By default it will download the latest version.

---

<style>
#source-code-name {
    padding-top: 3px;
    padding-bottom: 3px;
    padding-left: 5px;
    padding-right: 5px;
    font-weight: bold;
    width: fit-content;
    background-color: #EEEEEE;
    color: #2C3333;
}
</style>
