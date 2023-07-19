// https://en.cppreference.com/w/cpp/memory/shared_ptr

#include <iostream>
#include <memory>

struct MyObj
{
    MyObj()
    {
        std::cout << "MyObj constructed\n";
    }

    ~MyObj()
    {
        std::cout << "MyObj destructed\n";
    }
};

struct Container : std::enable_shared_from_this<Container> // note: public inheritance
{
    std::shared_ptr<MyObj> memberObj;

    void CreateMember()
    {
        memberObj = std::make_shared<MyObj>();
    }

    std::shared_ptr<MyObj> GetAsMyObj()
    {
        // Use an alias shared ptr for member
        return std::shared_ptr<MyObj>(shared_from_this(), memberObj.get());
    }
};

#define COUT(str) std::cout << '\n' << str << '\n'

#define DEMO(...) std::cout << #__VA_ARGS__ << " = " << __VA_ARGS__ << '\n'

int main()
{
    COUT("Creating shared container");
    std::shared_ptr<Container> cont = std::make_shared<Container>();
    DEMO(cont.use_count());
    DEMO(cont->memberObj.use_count());

    COUT("Creating member");
    cont->CreateMember();
    DEMO(cont.use_count());
    DEMO(cont->memberObj.use_count());

    COUT("Creating another shared container");
    std::shared_ptr<Container> cont2 = cont;
    DEMO(cont.use_count());
    DEMO(cont->memberObj.use_count());
    DEMO(cont2.use_count());
    DEMO(cont2->memberObj.use_count());

    COUT("GetAsMyObj");
    std::shared_ptr<MyObj> myobj1 = cont->GetAsMyObj();
    DEMO(myobj1.use_count());
    DEMO(cont.use_count());
    DEMO(cont->memberObj.use_count());
    DEMO(cont2.use_count());
    DEMO(cont2->memberObj.use_count());

    COUT("Copying alias obj");
    std::shared_ptr<MyObj> myobj2 = myobj1;
    DEMO(myobj1.use_count());
    DEMO(myobj2.use_count());
    DEMO(cont.use_count());
    DEMO(cont->memberObj.use_count());
    DEMO(cont2.use_count());
    DEMO(cont2->memberObj.use_count());

    COUT("Resetting cont2");
    cont2.reset();
    DEMO(myobj1.use_count());
    DEMO(myobj2.use_count());
    DEMO(cont.use_count());
    DEMO(cont->memberObj.use_count());

    COUT("Resetting myobj2");
    myobj2.reset();
    DEMO(myobj1.use_count());
    DEMO(cont.use_count());
    DEMO(cont->memberObj.use_count());

    COUT("Resetting cont");
    cont.reset();
    DEMO(myobj1.use_count());
    DEMO(cont.use_count());

    return 0;
}
