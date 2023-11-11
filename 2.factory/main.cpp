#include <QCoreApplication>
#include <iostream>
#include <memory>
#include <set>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

class Product {
public:
    virtual void operation() = 0;
    virtual ~Product() {}
};

class ConcreteProductA : public Product {
public:
    void operation() override {
        // 具体产品 A 的操作
    }
};

class ConcreteProductB : public Product {
public:
    void operation() override {
        // 具体产品 B 的操作
    }
};

class Creator {
public:
    virtual Product* factoryMethod() = 0;
    virtual ~Creator() {}
};

class ConcreteCreatorA : public Creator {
public:
    Product* factoryMethod() override {
        return new ConcreteProductA();
    }
};

class ConcreteCreatorB : public Creator {
public:
    Product* factoryMethod() override {
        return new ConcreteProductB();
    }
};

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);
    auto&& appFilePath = QCoreApplication::applicationFilePath();
    qDebug() << "starting " << appFilePath;

    return a.exec();
}
