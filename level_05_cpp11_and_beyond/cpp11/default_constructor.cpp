// https://en.cppreference.com/w/cpp/language/default_constructor

#include <iostream>

struct A
{
    int x;
    A(int x = 1) : x(x)
    {
    } // user-defined default constructor
};

struct B : A
{
    // B::B() is implicitly-defined, calls A::A()
};

struct C
{
    A a;
    // C::C() is implicitly-defined, calls A::A()
};

struct D : A
{
    D(int y) : A(y)
    {
    }
    // D::D() is not declared because another constructor exists
};

struct E : A
{
    E(int y) : A(y)
    {
    }
    E() = default; // explicitly defaulted, calls A::A()
};

struct F
{
    int &ref;    // reference member
    const int c; // const member
    // F::F() is implicitly defined as deleted
};

// user declared copy constructor (either user-provided, deleted or defaulted)
// prevents the implicit generation of a default constructor

struct G
{
    G(const G &)
    {
    }
    // G::G() is implicitly defined as deleted
};

struct H
{
    H(const H &) = delete;
    // H::H() is implicitly defined as deleted
};

struct I
{
    I(const I &) = default;
    // I::I() is implicitly defined as deleted
};

int main()
{
    A a;
    B b;
    C c;
    //  D d; // compile error
    E e;
    //  F f; // compile error
    //  G g; // compile error
    //  H h; // compile error
    //  I i; // compile error

    return 0;
}
