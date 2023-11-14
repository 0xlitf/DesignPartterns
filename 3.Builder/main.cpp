#include <QCoreApplication>
#include <iostream>
#include <memory>
#include <set>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

class Computer {
public:
    void setCPU(const std::string& cpu) {
        m_cpu = cpu;
    }

    void setMemory(const std::string& memory) {
        m_memory = memory;
    }

    void setHardDisk(const std::string& hardDisk) {
        m_hardDisk = hardDisk;
    }

    void showInfo() const {
        std::cout << "Computer Info: CPU - " << m_cpu
                  << ", Memory - " << m_memory
                  << ", Hard Disk - " << m_hardDisk << std::endl;
    }

private:
    std::string m_cpu;
    std::string m_memory;
    std::string m_hardDisk;
};

class Builder {
public:
    virtual void buildCPU() = 0;
    virtual void buildMemory() = 0;
    virtual void buildHardDisk() = 0;
    virtual Computer getResult() const = 0;
    virtual ~Builder() {}
};

class ConcreteBuilderA : public Builder {
public:
    void buildCPU() override {
        m_computer.setCPU("Intel Core i5");
    }

    void buildMemory() override {
        m_computer.setMemory("8GB DDR4");
    }

    void buildHardDisk() override {
        m_computer.setHardDisk("256GB SSD");
    }

    Computer getResult() const override {
        return m_computer;
    }

private:
    Computer m_computer;
};

class ConcreteBuilderB : public Builder {
public:
    void buildCPU() override {
        m_computer.setCPU("AMD Ryzen 7");
    }

    void buildMemory() override {
        m_computer.setMemory("16GB DDR4");
    }

    void buildHardDisk() override {
        m_computer.setHardDisk("1TB HDD");
    }

    Computer getResult() const override {
        return m_computer;
    }

private:
    Computer m_computer;
};

class Director {
public:
    Director(Builder* builder) : m_builder(builder) {}

    void construct() {
        m_builder->buildCPU();
        m_builder->buildMemory();
        m_builder->buildHardDisk();
    }

private:
    Builder* m_builder;
};

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);
    auto&& appFilePath = QCoreApplication::applicationFilePath();
    qDebug() << "starting " << appFilePath;

    ConcreteBuilderA builderA;
    ConcreteBuilderB builderB;

    Director directorA(&builderA);
    directorA.construct();
    Computer computerA = builderA.getResult();
    computerA.showInfo();

    Director directorB(&builderB);
    directorB.construct();
    Computer computerB = builderB.getResult();
    computerB.showInfo();

    return a.exec();
}
