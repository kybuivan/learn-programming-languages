---
title: CppReference Templates 20130729
author: ky
date: 2023-07-01 00:00:00 +0700
categories: [Blogging]
tags: [cpp11]
pin: true
---
# Contents
* [Class Template](#class-template)
* [Function Template](#function-template)
* [Member Template](#member-templates)
* [Template Specialization](#template-specialization)

## Class Template
A class template defines a family of classes.

| Syntax                                    |
| ----------------------------------------- |
| `template < parameter-list > declaration` |

### Explanation
*declaration* defines or declares a class (including struct and union), a member class or member enumeration type, a function or member function, a static data member of a class template, or a type alias. It may also define a template specialization. This page focuses on class templates.

*parameter-list* is a non-empty comma-separated list of the template parameters, each of which is either non-type parameter, a type parameter, a template parameter, or a parameter pack of any of those. This page focuses on the parameters that are not parameter packs.

#### Non-type template parameter

|                       |                     |
| --------------------- | ------------------- |
| `type name`           | `(1)`               |
| `type name = default` | `(1)`               |
| `type ... name>`      | `(3) (since C++11)` |

1. A non-type template parameter with an optional name
2. A non-type template parameter with an optional name and a default value
3. A non-type template parameter pack with an optional name

type is one of the following types (optionally cv-qualified, the qualifiers are ignored)
- integral type
- enumeration
- pointer to object or to function
- lvalue reference to object or to function
- pointer to member object or to member function
- std::nullptr_t (since C++11)

Array and function types may be written in a template declaration, but they are automatically replaced by pointer to data and pointer to function as appropriate.

When the name of a non-type template parameter is used in an expression within the body of the class template, it is an unmodifiable prvalue unless its type was an lvalue reference type.

#### Type template parameter

|                                 |                     |
| ------------------------------- | ------------------- |
| `typename name`                 | `(1)`               |
| `class name`                    | `(2)`               |
| `typename/class name = default` | `(3)`               |
| `typename/class ... name`       | `(4) (since C++11)` |

1. A type template parameter with an optional name
2. Exactly the same as 1.
3. A type template parameter with an optional name and a default
4. A type template parameter pack with an optional name

#### Template template parameter

|                                              |                     |
| -------------------------------------------- | ------------------- |
| `template < parameter-list > name`           | `(1)`               |
| `template < parameter-list > name = default` | `(2)`               |
| `template < parameter-list > ... name`       | `(3) (since C++11)` |

1. A template template parameter with an optional name
2. A template template parameter with an optional name and a default
3. A template template parameter pack with an optional name

### Class template instantiation
A class template by itself is not a type, or an object, or any other entity. No code is generated from a source file that contains only template definitions. In order for any code to appear, a template must be instantiated: the template arguments must be provided so that the compiler can generate an actual class (or function, from a function template).

#### Explicit instantiation

|                                                  |                     |
| ------------------------------------------------ | ------------------- |
| `template class name < argument-list > ;`        | `(1)`               |
| `extern template class name < argument-list > ;` | `(2) (since C++11)` |

1. Explicit instantiation definition
2. Explicit instantiation declaration

An explicit instantiation definition forces instantiation of the class, struct, or union they refer to. It may appear in the program anywhere after the template definition, and for a given argument-list, is only allowed to appear once in the program.

An explicit instantiation declaration (an extern template) prevents implicit instantiations: the code that would otherwise cause an implicit instantiation has to use the explicit instantiation definition provided somewhere else in the program.

#### Implicit instantiation
When code refers to a template in context that requires a completely defined type, or when the completeness of the type affects the code, and this particular type has not been explicitly instantiated, implicit instantiation occurs. For example, when an object of this type is constructed, but not when a pointer to this type is constructed.

This applies to the members of the class template: unless the member is used in the program, it is not instantiated, and does not require a definition.


```cpp
template<class T> struct Z {
    void f() {}
    void g(); // never defined
}; // template definition
template struct Z<double>; // explicit instantiation of Z<double>
Z<int> a; // implicit instantiation of Z<int>
Z<char>* p; // nothing is instantiated here
p->f(); // implicit instantiation of Z<char> and Z<char>::f() occurs here.
// Z<char>::g() is never needed and never instantiated: it does not have to be defined
```

#### Non-type template parameters
The following limitations apply when instantiating class templates that have non-type template parameters:

* For integral and arithmetic types, the template argument provided during instantiation must be a constant expression.
* For pointers to objects, the template arguments have to designate the address of an object with static storage duration and a linkage (either internal or external), or a constant expression that evaluates to the appropriate null pointer value.
* For pointers to functions, the valid arguments are pointers to functions with linkage (or constant expressions that evaluate to null pointer values).
* For lvalue reference parameters, the argument provided at instantiation cannot be a temporary, an unnamed lvalue, or a named lvalue with no linkage.
* For pointers to members, the argument has to be a pointer to member expressed as &Class::Member or a constant expression that evaluates to null pointer value.
In particular, this implies that string literals, addresses of array elements, and addresses of non-static members cannot be used as template arguments to instantiate templates whose corresponding non-type template parameters are pointers to data.

### Examples
#### Non-type template parameters
```cpp
#include <iostream>
 
// simple non-type template parameter
template<int N>
struct S {
    int a[N];
};
 
template<const char*>
struct S2 {};
 
// complicated non-type example
template <
    char c, // integral type
    int (&ra)[5], // lvalue reference to object (of array type)
    int (*pf)(int), // pointer to function
    int (S<10>::*a)[10] // pointer to member object (of type int[10])
> struct Complicated {
    // calls the function selected at compile time
    // and stores the result in the array selected at compile time
    void foo(char base) {
        ra[4] = pf(c - base);
    }
};
 
//  S2<"fail"> s2; // Error: string literal cannot be used
char okay[] = "okay"; // static object with linkage
// S2< &okay[0] > s2; // Error: array element has no linkage
S2<okay> s2; // works
 
int a[5];
int f(int n) { return n;}
int main()
{
    S<10> s; // s.a is an array of 10 int
    s.a[9] = 4;
 
    Complicated<'2', a, f, &S<10>::a> c;
    c.foo('0');
 
    std::cout << s.a[9] << a[4] << '\n';
}
```
Output:

```shell
42
```

## Function Template
A function template defines a family of functions.

| Syntax                                    |
| ----------------------------------------- |
| `template < parameter-list > declaration` |

### Explanation
*declaration* defines or declares a class (including struct and union), a member class or member enumeration type, a function or member function, a static data member of a class template, or a type alias. It may also define a template specialization. This page focuses on function templates.

*parameter-list* is a non-empty comma-separated list of the template parameters, each of which is either non-type parameter, a type parameter, a template parameter, or a parameter pack of any of those. For function templates, template parameters are declared in the same manner as for class templates: see class template page for details.
### Function template instantiation
A function template by itself is not a type, or a function, or any other entity. No code is generated from a source file that contains only template definitions. In order for any code to appear, a template must be instantiated: the template arguments must be determined so that the compiler can generate an actual function (or class, from a class template).
#### Explicit instantiation

|                                                                          |                     |
| ------------------------------------------------------------------------ | ------------------- |
| `template return-type < argument-list > name ( parameter-list ) ;`       | `(1)`               |
| `template return-type name ( parameter-list ) > ;`                       | `(2)`               |
| `extern template return-type < argument-list > name ( parameter-list) ;` | `(3) (since C++11)` |
| `extern template return-type name ( parameter-list) ;`                   | `(4) (since C++11)` |

1. Explicit instantiation definition without template argument deduction
2. Explicit instantiation definition with template argument deduction
3. Explicit instantiation declaration without template argument deduction
4. Explicit instantiation declaration with template argument deduction

An explicit instantiation definition forces instantiation of the function or member function they refer to. It may appear in the program anywhere after the template definition, and for a given argument-list, is only allowed to appear once in the program.

An explicit instantiation declaration (an extern template) prevents implicit instantiations: the code that would otherwise cause an implicit instantiation has to use the explicit instantiation definition provided somewhere else in the program.

```cpp
template<typename T>
void f(T s)
{
    std::cout << s << '\n';
}
template void f<double>(double); // instantiates f<double>(double)
template void f<>(char); // instantiates f<char>(char)
template void f(int); // instantiates f<int>(int)
```

#### Implicit instantiation
When code refers to a function in context that requires the function definition to exist, and this particular function has not been explicitly instantiated, implicit instantiation occurs. The list of template arguments does not have to be supplied if it can be deduced from context

```cpp
#include <iostream>
template<typename T>
void f(T s)
{
    std::cout << s << '\n';
}

int main()
{
    f<double>(1); // instantiates and calls f<double>(double)
    f<>('a'); // instantiates and calls f<char>(char)
    f(7); // instantiates and calls f<int>(int)
    void (*ptr)(std::string) = f; // instantiates f<string>(string)
}
```

### Template argument deduction
In order to instantiate a function template, every template argument must be known, but not every template argument has to be specified. When possible, the compiler will deduce the missing template arguments from the function arguments. This occurs when a function call is attempted and when an address of a function template is taken.

```cpp
template<typename To, typename From> To convert(From f);
 
void g(double d) {
    int i = convert<int>(d); // calls convert<int,double>(double)
    char c = convert<char>(d); // calls convert<char,double>(double)
    int(*ptr)(float) = convert; // instantiates convert<int, float>(float)
}
```

This mechanism makes it possible to use template operators, since there is no syntax to specify template arguments for an operator other than by re-writing it as a function call expression.

```cpp
#include <iostream>
int main() {
    std::cout << "Hello, world" << std::endl;
    // operator<< is looked up via ADL as std::operator<<,
    // then deduced to operator<<<char, std::char_traits<char>> both times
    // std::endl is deduced to std::endl<char, std::char_traits<char>>
}
```
Template argument deduction takes place after the function template name lookup (which may involve argument-dependent lookup) and before overload resolution.

For each function parameter of type P specified in the function template, the compiler examines the corresponding function call argument of type A as follows:
* If P is a (possibly cv-qualified, possibly reference to) std::initializer_list<Q> and the function call argument is a brace-enclosed list of initializers, argument deduction is attempted between the type Q and each element of the braced-init-list, which all must match

```cpp
template<class Q>
void f(std::initializer_list<Q>);
int main()
{
    f({1,2,3});    // OK: calls void f(initializer_list<int>)
//  f({1,"asdf"}); // error: Q can't be both int and const char*
}
```

* Otherwise, if the function call argument is a braced-init-list, the type cannot be deduced and must be specified

```cpp
template<class T>
void f(T);
int main()
{
//  f({1,2,3}); // error: T cannot be deduced from a braced-init-list
    f<std::vector<int>>({1,2,3}); // OK, T is specified
}
```

* If the function template ends with a parameter pack, each remaining argument is compared with the type of the parameter pack and each comparison deduces the next type in the expansion.

```cpp
template<class H, class ...Tail>
void f(H, Tail...);
int main()
{
    int x; double y; char z;
    f(x, y, z); // H = int, Tail = {double, char}
}
```

* If a function template has a parameter pack that is not at the end, the pack is not deducible and must be specified, along with all the types that follow.
* If P is a non-reference type,
  * If A is an array type, the pointer to an element of A is used in place of A for deduction.
  * If A is a function type, the pointer to this function type is used in place of A for deduction.
  * Otherwise, if A is a cv-qualified type, then the top level cv-qualifiers are ignored for deduction
* If P is a cv-qualified type, the top-level cv qualifiers are ignored for deduction.
* If P is a reference type, the type referred to by P is used for deduction.
* If P is an rvalue reference to a template parameter, and the corresponding function call argument is an lvalue, the type lvalue reference to A is used in place of A for deduction (Note: this is the basis for the action of std::forward)

```cpp
template <class T>
int f(T&&); // P is rvalue reference to cv-unqualified T (special case)

template <class T>
int g(const T&&); // P is rvalue reference to cv-qualified T (not special)

int main()
{
    int i;
    int n1 = f(i); // argument is lvalue:     calls f<int&>(int&) (special case)
    int n2 = f(0); // argument is not lvalue: calls f<int>(int&&)

//    int n3 = g(i); // error: deduces to g<int>(const int&&), which
//    // cant bind an rvalue reference to an lvalue:
}
```

* After these transformations, the deduction process attempts to find such template arguments that would make P and A identical, except that
> Reason: the three exceptions and the implicit conversions
* If P is a function type, pointer to function, or pointer to member function,
  * If the argument is a set of overloaded functions that includes at least one function template, the parameter cannot be deduced.
  * If the argument is a set of overloaded functions not containing function templates, template argument deduction is attempted with each overload. If only one succeeds, that successful deduction is used. If more than one succeeds, the template parameter cannot be deduced.

```cpp
template <class T>
int f(T (*p)(T));

int g(int);
int g(char); // two overloads

int main()
{
 int i = f(g); // only one overload works: calls f(int (*)(int))
}
```

> Reason: The huge amount of stuff from 14.8.2.5. Except it will have to be made easy-to-follow somehow

### Template argument substitution
When a template argument is specified explicitly, but does not match the type of the corresponding function argument exactly, the template argument is adjusted by the following rules:

### Template argument specialization
> Reason: note that there is a page for specializations in general, only function specifics go here: lack of partials, interaction with function overloads

#### Overload resolution
To compile a call to a function template, the compiler has to decide between non-template overloads, template overloads, and the specializations of the template overloads.

```cpp
template< class T > void f(T);              // template overload
template< class T > void f(T*);             // template overload
void                     f(double);         // nontemplate overload
template<>          void f(int);            // specialization of #1

f('a');        // calls #1
f(new int(1)); // calls #2
f(1.0);        // calls #3
f(1);          // calls #4
```
Note that only non-template and primary template overloads participate in overload resolution. The specializations are not overloads and are not considered. Only after the overload resolution selects the best-matching primary function template, its specializations are examined to see if one is a better match.

```cpp
template< class T > void f(T);    // overload #1 for all types
template<>          void f(int*); // specialization of #1 for pointers to int
template< class T > void f(T*);   // overload #2 for all pointer types

f(new int(1)); // calls #2, even though #1 would be a perfect match
```
For detailed rules on overload resolution, see overload resolution

### Example
> Reason: no example.

## Member Templates

Template declarations (both class and function) can appear inside a member specification of any class, stuct, or union that aren't local class

If the enclosing class declaration is, in turn, a template itself, when member template is defined out of body, it takes two sets of template parameters: one for the enclosing class, and another for itself:


```cpp
template<typename T>
struct string {
    // member template function
    template<typename T2>
    int compare(const T2&);
    // constructors can be templates too
    template<typename T2>
    string(const std::string<T2>& s) { /*...*/ }
};
// out of class definition of string<T1>::compare<T2> 
template<typename T1> // for the enclosing class template
template<typename T2> // for the member template
int string<T1>::compare(const T2& s) { /* ... */ }
```

### Member function templates
Destructor and copy constructor cannot be templates, but other special member functions can be. If a template constructor is declared which could be instantiated with the type signature of a copy constructor, the implicitly-declared copy constructor is used instead.

A member function template cannot be virtual, and a member function template in a derived class cannot override a virtual member function from the base class.

```cpp
class Base {
    virtual void f(int);
};
struct Derived : Base {
    // this member template does not override B::f
    template <class T> void f(T);
 
    // non-member override can call the template:
    void f(int i) override {
         f<>(i);
    }
};
```

A non-template member function and a template member function with the same name may be declared. In case of conflict (when some template specialization matches the non-template function signature exactly), use of that name and type refers to the non-template member unless an explicit template argument list is supplied.

```cpp
template<typename T>
struct A {
    void f(int); // non-template member
    template<typename T2> void f(T2); // member template
};
 
int main()
{
    A<char> ac;
    ac.f('c'); // calls template function A<char>::f<char>(int)
    ac.f(1);   // calls non-template function A<char>::f(int)
    ac.f<>(1); // calls template function A<char>::f<int>(inf)
}
```
### Conversion function templates
A user-defined conversion function can be a template.

```cpp
struct A {
    template<typename T>
    operator T*(); // conversion to pointer to any type
};
 
// out-of-class definition
template<typename T>
A::operator T*() {return nullptr;}
 
// explicit specialization for char*
template<>
A::operator char*() {return nullptr;}
 
// explicit instantiation
template A::operator void*();
 
int main() {
    A a;
    int* ip = a.operator int*(); // explicit call to A::operator int*()
}
```
During overload resolution, specialization of conversion function templates are not found by name lookup. Instead, all visible conversion function templates are considered, and every specialization produced by template argument deduction is used as if found by name lookup.

Using-declarations in derived classes cannot refer to specializations of template conversion functions from base classes.

## Template Specialization
Allows customizing the template code for a given set of template arguments.

| Syntax                    |
| ------------------------- |
| `template <> declaration` |

Any of the following can be fully specialized:
  1. function template
  2. class template
  3. member function of a class template
  4. static data member of a class template
  5. member class of a class template
  6. member enumeration of a class template
  7. member class template of a class or class template
  8. member function template of a class or class template
For example,

```cpp
#include <iostream>
template<typename T>   // primary template
struct is_void : std::false_type
{
};
template<>  // explicit specialization for T = void
struct is_void<void> : std::true_type
{
};
int main()
{
    // for any type T other than void, the 
    // class is derived from false_type
    std::cout << is_void<char>::value << '\n'; 
    // but when T is void, the class is derived
    // from true_type
    std::cout << is_void<void>::value << '\n';
}
```
### In detail
Explicit specialization can only appear in the same namespace as the primary template, and has to appear after the non-specialized template declaration. It is always in the scope of that namespace:

```cpp
namespace N {
    template<class T> class X { /*...*/ }; // primary template
    template<> class X<int> { /*...*/ }; // specialization in same namespace
 
    template<class T> class Y { /*...*/ }; // primary template
    template<> class Y<double>; // forward declare specialization for double
}
template<>
class N::Y<double> { /*...*/ }; // OK: specialization in same namespace
```
Specialization must be declared before the first use that would cause implicit instantiation, in every translation unit where such use occurs:

```cpp
class String {};
template<class T> class Array { /*...*/ };
template<class T> void sort(Array<T>& v) { /*...*/ } // primary template
 
void f(Array<String>& v) {
    sort(v); // implicitly instantiates sort(Array<String>&), 
}            // using the primary template for sort()
 
template<>  // ERROR: explicit specialization of sort(Array<String>)
void sort<String>(Array<String>& v); // after implicit instantiation
```
A template specialization that was declared but not defined can be used just like any other incomplete type (e.g. pointers and references to it may be used)

```cpp
template<class T> class X; // primary template
template<> class X<int>; // specialization (declared, not defined)
X<int>* p; // OK: pointer to incomplete type
X<int> x; // error: object of incomplete type
```

### Explicit specializations of function templates
When specializing a function template, its template arguments can be omitted if template argument deduction can provide them from the function arguments:

```cpp
template<class T> class Array { /*...*/ };
template<class T> void sort(Array<T>& v); // primary template
template<> void sort(Array<int>&); // specialization for T = int
// no need to write
// template<> void sort<int>(Array<int>&);
```
A function with the same name and the same argument list as a specialization is not a specialization (see template overloading in function_template)

An explicit specialization of a function template is inline only if it is declared with the inline specifier (or defined as deleted), it doesn't matter if the primary template is inline.

Default function arguments cannot be specified in explicit specializations of function templates, member function templates, and member functions of class templates when the class is implicitly instantiated.

An explicit specialization cannot be a friend.

#### Members of specializations
When defining a member of an explicitly specialized class template outside the body of the class, the syntax template <> is not used, except if it's a member of an explicitly specialized member class template, which is specialized as a class template, because otherwise, the syntax would require such definition to begin with template<parameters> required by the nested template

```cpp
template< typename T>
struct A {
    struct B {};  // member class 
    template<class U> struct C { }; // member class template
};
 
template<> // specialization
struct A<int> {
    void f(int); // member function of a specialization
};
// template<> not used for a member of a specialization
void A<int>::f(int) { /* ... */ }
 
template<> // specialization of a member class
struct A<char>::B {
    void f();
};
// template<> not used for a member of a specialized member class either
void A<char>::B::f() { /* ... */ }
 
template<> // specialization of a member class template
template<class U> struct A<char>::C {
    void f();
};
 
// template<> is used when defining a member of an explicitly
// specialized member class template specialized as a class template
template<>
template<class U> void A<char>::C<U>::f() { /* ... */ }
```
An explicit specialization of a static data member of a template is a definition if the declaration includes an initializer; otherwise, it is a declaration. These definitions must use braces for default initialization:

```cpp
template<> X Q<int>::x; // declaration of a static member
template<> X Q<int>::x (); // error: function declaration
template<> X Q<int>::x {}; // definition of a default-initialized static member
```
A member or a member template of a class template may be explicitly specialized for a given implicit instantiation of the class template, even if the member or member template is defined in the class template definition.

```cpp
template<typename T>
struct A {
    void f(T); // member, declared in the primary template
    void h(T) {} // member, defined in the primary template
    template<class X1> void g1(T, X1); // member template
    template<class X2> void g2(T, X2); // member template
};
 
// specialization of a member
template<> void A<int>::f(int);
// member specialization OK even if defined in-class
template<> void A<int>::h(int) {}
 
// out of class member template definition
template<class T>
template<class X1> void A<T>::g1(T, X1) { }
 
// member template specialization
template<>
template<class X1> void A<int>::g1(int, X1);
 
// member template specialization
template<>
template<> void A<int>::g2<char>(int, char); // for X2 = char
// same, using template argument deduction (X1 = char)
template<> 
template<> void A<int>::g1(int, char);
```
Member or a member template may be nested within many enclosing class templates. In an explicit specialization for such a member, there's a template<> for every enclosing class template that is explicitly specialized.

```cpp
template<class T1> class A {
    template<class T2> class B {
        void mf();
    };
};
template<> template<> class A<int>::B<double>;
template<> template<> void A<char>::B<char>::mf();
```
In such a nested declaration, some of the levels may remain unspecialized (except that it can't specialize a class member template if its enclosing class is unspecialized). For each of those levels, the declaration needs template<arguments>, because such specializations are themselves templates:

```cpp
template <class T1> class A {
    template<class T2> class B {
        template<class T3> void mf1(T3); // member template
        void mf2(); // non-template member
     };
};
 
// specialization
template<> // for the specialized A
template<class X> // for the unspecialized B
class A<int>::B {
    template <class T> void mf1(T);
};
 
// specialization
template<> // for the specialized A
template<> // for the specialized B
template<class T> // for the unspecialized mf1
void A<int>::B<double>::mf1(T t) { }
 
// ERROR: B<double> is specialized and is a member template, so its enclosing A
// must be specialized also
template<class Y>
template<> void A<Y>::B<double>::mf2() { }
```

## See also:
[cppreference-doc-20130729](https://en.cppreference.com/w/File:cppreference-doc-20130729.zip)