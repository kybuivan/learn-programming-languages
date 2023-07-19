#include <iostream>
#include <memory>

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

int main()
{
    DevelopmentManager devManager;
    devManager.takeInterview(); // Output: Asking about design patterns!

    MarketingManager marketingManager;
    marketingManager.takeInterview(); // Output: Asking about community building.

    return 0;
}
