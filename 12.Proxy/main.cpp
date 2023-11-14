#include <QCoreApplication>
#include <iostream>
#include <memory>
#include <set>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

// 抽象主题
class Subject {
public:
    virtual void request() const = 0;
};

// 真实主题
class RealSubject1 : public Subject {
public:
    void request() const override {
        std::cout << "RealSubject handles the request." << std::endl;
    }
};

class RealSubject2 : public Subject {
public:
    void request() const override {
        std::cout << "RealSubject handles the request." << std::endl;
    }
};

// 代理
class Proxy : public Subject {
private:
    RealSubject1 realSubject;

public:
    void request() const override {
        preRequest();
        realSubject.request();
        postRequest();
    }

private:
    void preRequest() const {
        std::cout << "Proxy handles preRequest." << std::endl;
    }

    void postRequest() const {
        std::cout << "Proxy handles postRequest." << std::endl;
    }
};

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);
    auto&& appFilePath = QCoreApplication::applicationFilePath();
    qDebug() << "starting " << appFilePath;

    Proxy proxy;
    proxy.request();

    return a.exec();
}
