# Design Patterns

<p align="center">
This repository contains examples of design patterns implemented in C++.
</p>

## List of Design Patterns
Here's a list of the design patterns available in this repository:

<br>

|[Creational Design Patterns](#creational-design-patterns)|[Structural Design Patterns](#structural-design-patterns)|[Behavioral Design Patterns](#behavioral-design-patterns)|
|:-|:-|:-|
|[Simple Factory](#-simple-factory)|[Adapter](#-adapter)|[Chain of Responsibility](#-chain-of-responsibility)|
|[Factory Method](#-factory-method)|[Bridge](#-bridge)|[Command](#-command)|
|[Abstract Factory](#-abstract-factory)|[Composite](#-composite)|[Iterator](#-iterator)|
|[Builder](#-builder)|[Decorator](#-decorator)|[Mediator](#-mediator)|
|[Prototype](#-prototype)|[Facade](#-facade)|[Memento](#-memento)|
|[Singleton](#-singleton)|[Flyweight](#-flyweight)|[Observer](#-observer)|
||[Proxy](#-proxy)|[Visitor](#-visitor)|
|||[Strategy](#-strategy)|
|||[State](#-state)|
|||[Template Method](#-template-method)|

<br>

Introduction
=================

Design patterns are solutions to recurring problems; **guidelines on how to tackle certain problems**. They are not classes, packages or libraries that you can plug into your application and wait for the magic to happen. These are, rather, guidelines on how to tackle certain problems in certain situations.

> Design patterns are solutions to recurring problems; guidelines on how to tackle certain problems

Wikipedia describes them as

> In software engineering, a software design pattern is a general reusable solution to a commonly occurring problem within a given context in software design. It is not a finished design that can be transformed directly into source or machine code. It is a description or template for how to solve a problem that can be used in many different situations.

⚠️ Be Careful
-----------------
- Design patterns are not a silver bullet to all your problems.
- Do not try to force them; bad things are supposed to happen, if done so.
- Keep in mind that design patterns are solutions **to** problems, not solutions **finding** problems; so don't overthink.
- If used in a correct place in a correct manner, they can prove to be a savior; or else they can result in a horrible mess of a code.

> Also note that the code samples below are in C++17, however this shouldn't stop you because the concepts are same anyways.

Types of Design Patterns
-----------------

* [Creational](#creational-design-patterns)
* [Structural](#structural-design-patterns)
* [Behavioral](#behavioral-design-patterns)

Creational Design Patterns
==========================

In plain words
> Creational patterns are focused towards how to instantiate an object or group of related objects.

Wikipedia says
> In software engineering, creational design patterns are design patterns that deal with object creation mechanisms, trying to create objects in a manner suitable to the situation. The basic form of object creation could result in design problems or added complexity to the design. Creational design patterns solve this problem by somehow controlling this object creation.

 * [Simple Factory](#-simple-factory)
 * [Factory Method](#-factory-method)
 * [Abstract Factory](#-abstract-factory)
 * [Builder](#-builder)
 * [Prototype](#-prototype)
 * [Singleton](#-singleton)

🏠 Simple Factory
--------------
Real world example
> Consider, you are building a house and you need doors. You can either put on your carpenter clothes, bring some wood, glue, nails and all the tools required to build the door and start building it in your house or you can simply call the factory and get the built door delivered to you so that you don't need to learn anything about the door making or to deal with the mess that comes with making it.

In plain words
> Simple factory simply generates an instance for client without exposing any instantiation logic to the client

Wikipedia says
> In object-oriented programming (OOP), a factory is an object for creating other objects – formally a factory is a function or method that returns objects of a varying prototype or class from some method call, which is assumed to be "new".

**Programmatic Example**

First of all we have a door interface and the implementation
```cpp
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
```
Then we have our door factory that makes the door and returns it
```cpp
class DoorFactory
{
public:
    static std::shared_ptr<Door> makeDoor(float width, float height)
    {
        return std::make_shared<WoodenDoor>(width, height);
    }
};
```
And then it can be used as
```cpp
// Make me a door of 100x200
auto door = DoorFactory::makeDoor(100, 200);

std::cout << "Width: " << door->getWidth() << std::endl;
std::cout << "Height: " << door->getHeight() << std::endl;

// Make me a door of 50x100
auto door2 = DoorFactory::makeDoor(50, 100);
```

**When to Use?**

When creating an object is not just a few assignments and involves some logic, it makes sense to put it in a dedicated factory instead of repeating the same code everywhere.

🏭 Factory Method
--------------

Real world example
> Consider the case of a hiring manager. It is impossible for one person to interview for each of the positions. Based on the job opening, she has to decide and delegate the interview steps to different people.

In plain words
> It provides a way to delegate the instantiation logic to child classes.

Wikipedia says
> In class-based programming, the factory method pattern is a creational pattern that uses factory methods to deal with the problem of creating objects without having to specify the exact class of the object that will be created. This is done by creating objects by calling a factory method—either specified in an interface and implemented by child classes, or implemented in a base class and optionally overridden by derived classes—rather than by calling a constructor.

 **Programmatic Example**

Taking our hiring manager example above. First of all we have an interviewer interface and some implementations for it

```cpp
class Interviewer
{
public:
    virtual void askQuestions() const = 0;
};

class Developer : public Interviewer
{
public:
    void askQuestions() const override
    {
        std::cout << "Asking about design patterns!" << std::endl;
    }
};

class CommunityExecutive : public Interviewer
{
public:
    void askQuestions() const override
    {
        std::cout << "Asking about community building" << std::endl;
    }
};
```

Now let us create our `HiringManager`

```cpp
class HiringManager
{
protected:
    virtual std::unique_ptr<Interviewer> makeInterviewer() const = 0;

public:
    void takeInterview() const
    {
        std::unique_ptr<Interviewer> interviewer = makeInterviewer();
        interviewer->askQuestions();
    }
};

```
Now any child can extend it and provide the required interviewer
```cpp
class DevelopmentManager : public HiringManager
{
protected:
    std::unique_ptr<Interviewer> makeInterviewer() const override
    {
        return std::make_unique<Developer>();
    }
};

class MarketingManager : public HiringManager
{
protected:
    std::unique_ptr<Interviewer> makeInterviewer() const override
    {
        return std::make_unique<CommunityExecutive>();
    }
};
```
and then it can be used as

```cpp
DevelopmentManager devManager;
devManager.takeInterview(); // Output: Asking about design patterns!

MarketingManager marketingManager;
marketingManager.takeInterview(); // Output: Asking about community building.
```

**When to use?**

Useful when there is some generic processing in a class but the required sub-class is dynamically decided at runtime. Or putting it in other words, when the client doesn't know what exact sub-class it might need.

🔨 Abstract Factory
----------------

Real world example
> Extending our door example from Simple Factory. Based on your needs you might get a wooden door from a wooden door shop, iron door from an iron shop or a PVC door from the relevant shop. Plus you might need a guy with different kind of specialities to fit the door, for example a carpenter for wooden door, welder for iron door etc. As you can see there is a dependency between the doors now, wooden door needs carpenter, iron door needs a welder etc.

In plain words
> A factory of factories; a factory that groups the individual but related/dependent factories together without specifying their concrete classes.

Wikipedia says
> The abstract factory pattern provides a way to encapsulate a group of individual factories that have a common theme without specifying their concrete classes

**Programmatic Example**

Translating the door example above. First of all we have our `Door` interface and some implementation for it

```cpp
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
```

Then we have some fitting experts for each door type

```cpp
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
```

Now we have our abstract factory that would let us make family of related objects i.e. wooden door factory would create a wooden door and wooden door fitting expert and iron door factory would create an iron door and iron door fitting expert

```cpp
class DoorFactory
{
public:
    virtual std::unique_ptr<Door> makeDoor() const = 0;
    virtual std::unique_ptr<DoorFittingExpert> makeFittingExpert() const = 0;
};

// Wooden factory to return carpenter and wooden door
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

// Iron door factory to get iron door and the relevant fitting expert
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
```
And then it can be used as
```cpp
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
```

As you can see the wooden door factory has encapsulated the `carpenter` and the `wooden door` also iron door factory has encapsulated the `iron door` and `welder`. And thus it had helped us make sure that for each of the created door, we do not get a wrong fitting expert.

**When to use?**

When there are interrelated dependencies with not-that-simple creation logic involved

👷 Builder
--------------------------------------------
Real world example
> Imagine you need to send an email using a mail service, but the email creation logic involves multiple steps, such as specifying the sender, recipients, subject, and body. In such cases, the builder pattern comes to the rescue.

In plain words
> The builder pattern allows you to create different flavors of an object while avoiding constructor pollution. It is useful when there are multiple steps involved in creating an object or when there could be several variations of an object.

Wikipedia says
> The builder pattern is an object creation software design pattern with the intentions of finding a solution to the telescoping constructor anti-pattern.

The telescoping constructor anti-pattern occurs when a constructor has multiple parameters, and the number of parameters quickly gets out of hand. This makes it difficult to understand the parameter arrangement and can become problematic when you want to add more options in the future.

**Programmatic Example**

Let's demonstrate the builder pattern with an example of creating an email.

First, we have the `Email` class that represents an email with sender, recipients, subject, and body.

```cpp
class Email
{
private:
    std::string from;
    std::vector<std::string> to;
    std::string subject;
    std::string body;

public:
    Email(const std::string& from,
          const std::vector<std::string>& to,
          const std::string& subject,
          const std::string& body)
        : from(from), to(to), subject(subject), body(body)
    {
    }

    void show()
    {
        std::cout << "From: " << from << std::endl;
        std::cout << "To: ";
        for (const auto& recipient : to)
        {
            std::cout << recipient << " ";
        }
        std::cout << std::endl;
        std::cout << "Subject: " << subject << std::endl;
        std::cout << "Body: " << body << std::endl;
    }
};
```

Next, we have the `EmailBuilder` class that provides step-by-step methods to set the email details.

```cpp
class EmailBuilder
{
private:
    std::string from;
    std::vector<std::string> to;
    std::string subject;
    std::string body;

public:
    EmailBuilder& setFrom(const std::string& from)
    {
        this->from = from;
        return *this;
    }

    EmailBuilder& addTo(const std::string& to)
    {
        this->to.push_back(to);
        return *this;
    }

    EmailBuilder& setSubject(const std::string& subject)
    {
        this->subject = subject;
        return *this;
    }

    EmailBuilder& setBody(const std::string& body)
    {
        this->body = body;
        return *this;
    }

    Email build()
    {
        return Email(from, to, subject, body);
    }
};
```
Finally, we can use the builder pattern to create and send an email using a mail service.

```cpp
class MailService
{
public:
    void sendEmail(const Email& email)
    {
        std::cout << "Sending email..." << std::endl;
        email.show();
    }
};
```
main:
```cpp
MailService mailService;
Email email = EmailBuilder()
                    .setFrom("sender@example.com")
                    .addTo("recipient1@example.com")
                    .addTo("recipient2@example.com")
                    .setSubject("Hello")
                    .setBody("How are you?")
                    .build();

mailService.sendEmail(email);
```
In the example above, we have the Email class representing an email with its properties. The EmailBuilder class provides methods to set each detail of the email step by step. Finally, we use the builder to create an Email object and send it using the MailService class.

The builder pattern is suitable when there could be several variations or flavors of an object, and it helps to avoid the telescoping constructor anti-pattern. It provides a cleaner and more flexible way to construct complex objects by separating the construction logic into multiple steps.

**When to use?**

When there could be several flavors of an object and to avoid the constructor telescoping. The key difference from the factory pattern is that; factory pattern is to be used when the creation is a one step process while builder pattern is to be used when the creation is a multi step process.
