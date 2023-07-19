#include <iostream>
#include <memory>

class Door
{
public:
    virtual void getDescription() const = 0;
};

class WoodenDoor : public Door
{
public:
    void getDescription() const override
    {
        std::cout << "I am a wooden door" << std::endl;
    }
};

class IronDoor : public Door
{
public:
    void getDescription() const override
    {
        std::cout << "I am an iron door" << std::endl;
    }
};

class DoorFittingExpert
{
public:
    virtual void getDescription() const = 0;
};

class Welder : public DoorFittingExpert
{
public:
    void getDescription() const override
    {
        std::cout << "I can only fit iron doors" << std::endl;
    }
};

class Carpenter : public DoorFittingExpert
{
public:
    void getDescription() const override
    {
        std::cout << "I can only fit wooden doors" << std::endl;
    }
};

class DoorFactory
{
public:
    virtual std::unique_ptr<Door> makeDoor() const = 0;
    virtual std::unique_ptr<DoorFittingExpert> makeFittingExpert() const = 0;
};

class WoodenDoorFactory : public DoorFactory
{
public:
    std::unique_ptr<Door> makeDoor() const override
    {
        return std::make_unique<WoodenDoor>();
    }

    std::unique_ptr<DoorFittingExpert> makeFittingExpert() const override
    {
        return std::make_unique<Carpenter>();
    }
};

class IronDoorFactory : public DoorFactory
{
public:
    std::unique_ptr<Door> makeDoor() const override
    {
        return std::make_unique<IronDoor>();
    }

    std::unique_ptr<DoorFittingExpert> makeFittingExpert() const override
    {
        return std::make_unique<Welder>();
    }
};

int main()
{
    std::unique_ptr<DoorFactory> woodenFactory = std::make_unique<WoodenDoorFactory>();

    std::unique_ptr<Door> door = woodenFactory->makeDoor();
    std::unique_ptr<DoorFittingExpert> expert = woodenFactory->makeFittingExpert();

    door->getDescription();   // Output: I am a wooden door
    expert->getDescription(); // Output: I can only fit wooden doors

    // Same for Iron Factory
    std::unique_ptr<DoorFactory> ironFactory = std::make_unique<IronDoorFactory>();

    door = ironFactory->makeDoor();
    expert = ironFactory->makeFittingExpert();

    door->getDescription();   // Output: I am an iron door
    expert->getDescription(); // Output: I can only fit iron doors

    return 0;
}
