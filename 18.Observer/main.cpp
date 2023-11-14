#include "observer.h"
#include "subject.h"
#include <QCoreApplication>
#include <iostream>
#include <memory>
#include <set>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);
    auto&& appFilePath = QCoreApplication::applicationFilePath();
    qDebug() << "starting " << appFilePath;

    ConcreteSubject subject;

    ConcreteObserver observer1("Observer 1");
    ConcreteObserver observer2("Observer 2");

    subject.addObserver(&observer1);
    subject.addObserver(&observer2);

    subject.notifyObservers("subject notify Observers: 1");

    subject.removeObserver(&observer1);

    subject.notifyObservers("subject notify Observers: 2");

    return a.exec();
}
