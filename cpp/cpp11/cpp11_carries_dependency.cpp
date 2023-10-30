// https://en.cppreference.com/w/cpp/language/attributes/carries_dependency

#include <atomic>
#include <iostream>
 
void print(int* val)
{
    std::cout << *val << std::endl;
}
 
void print2(int* val [[carries_dependency]])
{
    std::cout << *val << std::endl;
}
 
int main()
{
    int x{42};
    std::atomic<int*> p = &x;
    int* local = p.load(std::memory_order_consume);
 
    if (local)
    {
        // The dependency is explicit, so the compiler knows that local is
        // dereferenced, and that it must ensure that the dependency chain
        // is preserved in order to avoid a fence (on some architectures).
        std::cout << *local << std::endl;
    }
 
    if (local)
    {
        // The definition of print is opaque (assuming it is not inlined),
        // so the compiler must issue a fence in order to ensure that
        // reading *p in print returns the correct value.
        print(local);
    }
 
    if (local)
    {
        // The compiler can assume that although print2 is also opaque then
        // the dependency from the parameter to the dereferenced value is
        // preserved in the instruction stream, and no fence is necessary (on
        // some architectures). Obviously, the definition of print2 must actually
        // preserve this dependency, so the attribute will also impact the
        // generated code for print2.
        print2(local);
    }
    
    return 0;
}