#include <iostream>
#include <memory>
#include <string>

class Door
{
public:
    virtual float getWidth() const = 0;
    virtual float getHeight() const = 0;
};

class WoodenDoor : public Door
{
public:
    WoodenDoor(float width, float height) : width(width), height(height)
    {
    }

    float getWidth() const override
    {
        return width;
    }

    float getHeight() const override
    {
        return height;
    }

protected:
    float width;
    float height;
};

class DoorFactory
{
public:
    static std::shared_ptr<Door> makeDoor(float width, float height)
    {
        return std::make_shared<WoodenDoor>(width, height);
    }
};

int main()
{
    // Make me a door of 100x200
    auto door = DoorFactory::makeDoor(100, 200);

    std::cout << "Width: " << door->getWidth() << std::endl;
    std::cout << "Height: " << door->getHeight() << std::endl;

    // Make me a door of 50x100
    auto door2 = DoorFactory::makeDoor(50, 100);
    return 0;
}
