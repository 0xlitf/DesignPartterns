#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <memory>
#include <tuple>
#include <string>
#include <stdexcept>
#include <set>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    auto&& appFilePath = QCoreApplication::applicationFilePath();
    qDebug() << "starting " << appFilePath;

    return a.exec();
}
