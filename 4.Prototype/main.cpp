#include <QCoreApplication>
#include <iostream>
#include <memory>
#include <set>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void printInfo() const = 0;
    virtual ~Prototype() {}
};

// 具体原型 A
class ConcretePrototypeA : public Prototype {
public:
    ConcretePrototypeA(int data, const std::string& info) : m_data(data), m_info(info) {}

    Prototype* clone() const override {
        return new ConcretePrototypeA(*this); // 调用复制构造函数
    }

    void printInfo() const override {
        std::cout << "ConcretePrototypeA: Data - " << m_data << ", Info - " << m_info << std::endl;
    }

private:
    int m_data;
    std::string m_info;
};

// 具体原型 B
class ConcretePrototypeB : public Prototype {
public:
    ConcretePrototypeB(double value, const std::string& description) : m_value(value), m_description(description) {}

    Prototype* clone() const override {
        return new ConcretePrototypeB(*this); // 调用复制构造函数
    }

    void printInfo() const override {
        std::cout << "ConcretePrototypeB: Value - " << m_value << ", Description - " << m_description << std::endl;
    }

private:
    double m_value;
    std::string m_description;
};

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);
    auto&& appFilePath = QCoreApplication::applicationFilePath();
    qDebug() << "starting " << appFilePath;

    ConcretePrototypeA prototypeA(42, "Prototype A");
    ConcretePrototypeB prototypeB(3.14, "Prototype B");

    Prototype* cloneA = prototypeA.clone();
    Prototype* cloneB = prototypeB.clone();

    // 输出克隆对象的信息
    cloneA->printInfo();
    cloneB->printInfo();

    // 释放克隆对象的内存
    delete cloneA;
    delete cloneB;

    return a.exec();
}
