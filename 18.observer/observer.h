#pragma once
#include <string>
#include <vector>
#include <iostream>

class Observer
{
public:
    Observer();
    virtual void update(const std::string& message) = 0;
};

class ConcreteObserver : public Observer {
public:
    ConcreteObserver(const std::string& name) : name(name) {}

    void update(const std::string& message) override {
        std::cout << "Observer " << name << " received message: " << message << std::endl;
    }

private:
    std::string name;
};
