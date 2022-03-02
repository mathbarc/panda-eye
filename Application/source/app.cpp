#include <QApplication>
#include "main_controller.hpp"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MainController controller;
    controller.start();

    return app.exec();
}
