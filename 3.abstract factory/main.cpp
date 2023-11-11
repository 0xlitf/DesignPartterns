#include <QCoreApplication>
#include <iostream>
#include <memory>
#include <set>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

// 抽象产品 A
class AbstractProductA {
public:
    virtual void operationA() = 0;
    virtual ~AbstractProductA() {}
};

// 具体产品 A1
class ConcreteProductA1 : public AbstractProductA {
public:
    void operationA() override {
        // 具体产品 A1 的操作
    }
};

// 具体产品 A2
class ConcreteProductA2 : public AbstractProductA {
public:
    void operationA() override {
        // 具体产品 A2 的操作
    }
};

// 抽象产品 B
class AbstractProductB {
public:
    virtual void operationB() = 0;
    virtual ~AbstractProductB() {}
};

// 具体产品 B1
class ConcreteProductB1 : public AbstractProductB {
public:
    void operationB() override {
        // 具体产品 B1 的操作
    }
};

// 具体产品 B2
class ConcreteProductB2 : public AbstractProductB {
public:
    void operationB() override {
        // 具体产品 B2 的操作
    }
};

// 抽象工厂
class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
    virtual ~AbstractFactory() {}
};

// 具体工厂 1
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB1();
    }
};

// 具体工厂 2
class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA2();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB2();
    }
};

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);
    auto&& appFilePath = QCoreApplication::applicationFilePath();
    qDebug() << "starting " << appFilePath;

    return a.exec();
}
