# C++ Basic Syntax

C++ is a general-purpose, object-oriented programming language. It was developed in 1979 by Bjarne Stroustrup at AT & T Bell Laboratory. It is a high-level programming language & advanced version of C programming language. As Compared to other programming languages like Java, and Python, it is the fastest programming language.

## What is Syntax?
Syntax refers to the rules and regulations for writing statements in a programming language. They can also be viewed as the grammatical rules defining the structure of a programming language.

The C++ language also has its syntax for the functionalities it provides. Different statements have different syntax specifying their usage but C++ programs also have basic syntax rules that are followed throughout all the programs.

## Basic Syntax of a C++ Program
We can learn about basic C++ Syntax using the following program.

```cpp
#include <iostream>                 // header file

using namespace std;                // standard namespace

int main()                          // main function
{
    int num1 = 10;                  // declaration of variable
    int num2 = 20;
    int result = num1 + num2;       // expressions
    cout << result << endl;         // output
    return 0;                       // return statement
}
```

The codes above shows the basic C++ program that contains header files, main function, namespace declaration, etc. Let’s try to understand them one by one.

### 1. Header File
The header files contain the definition of the functions and macros we are using in our program. They are defined on the top of the C++ program.

In line #1, we used the `#include <iostream>` statement to tell the compiler to include an `iostream` header file library which stores the definition of the cin and `cout` methods that we have used for input and output. `#include` is a preprocessor directive using which we import header files.

**Syntax**:
```cpp
#include <library_name>
```

### 2. Namespace
A namespace in C++ is used to provide a scope or a region where we define identifiers. It is used to avoid name conflicts between two identifiers as only unique names can be used as identifiers.

In line #2, we have used the using namespace std statement for specifying that we will be the standard namespace where all the standard library functions are defined.

**Syntax**:
```cpp
#include <library_name>
```

### 3. Main Function
Functions are basic building blocks of a C++ program that contains the instructions for performing some specific task. Apart from the instructions present in its body, a function definition also contains information about its return type and parameters. To know more about C++ functions, please refer to the article Functions in C++.

In line #3, we defined the main function as int main(). The main function is the most important part of any C++ program. The program execution always starts from the main function. All the other functions are called from the main function. In C++, the main function is required to return some value indicating the execution status.

**Syntax**:
```cpp
int main() {

    ... code ....
    return 0;
}
```

### 4. Blocks
Blocks are the group of statements that are enclosed within { } braces. They define the scope of the identifiers and are generally used to enclose the body of functions and control statements.

The body of the main function is from line #4 to line #9 enclosed within  { }.

**Syntax**:
```cpp
{
      
  // Body of the Function
  
    return 0;
}
```

### 5. Semicolons
As you may have noticed by now, each statement in the above code is followed by a ( ; ) semicolon symbol. It is used to terminate each line of the statement of the program. When the compiler sees this semicolon, it terminates the operation of that line and moves to the next line.

**Syntax**:
```cpp
any_statement ;
```

### 6. Identifiers
We use identifiers for the naming of variables, functions, and other user-defined data types. An identifier may consist of uppercase and lowercase alphabetical characters, underscore, and digits. The first letter must be an underscore or an alphabet.

**Example**:
```cpp
int num1 = 10;
int num2 = 20;
```

### 7. Keywords
In the C++ programming language, there are some reserved words that are used for some special meaning in the C++ program. It can’t be used for identifiers.

For example, the words int, return, and using are some keywords used in our program. These all have some predefined meaning in the C++ language.

There are total 95 keywords in C++. These are some keywords.

|      |        |     |       |       |      |      |       |
|------|--------|-----|-------|-------|------|------|-------|
| int  | void   | if  | while | for   | auto | bool | break |
| this | static | new | true  | false | case | char | class |


### 8. Basic Output cout
In line #7, we have used the cout method which is the basic output method in C++ to output the sum of two numbers in the standard output stream (stdout).

**Syntax**:
```cpp
cout << result << endl;
```

### Output

```shell
30
```