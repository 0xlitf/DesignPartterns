#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "observer.h"

class Subject {
public:
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers(const std::string& message) = 0;
};

class ConcreteSubject : public Subject {
public:
    void addObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notifyObservers(const std::string& message) override {
        for (auto observer : observers) {
            observer->update(message);
        }
    }

private:
    std::vector<Observer*> observers;
};
