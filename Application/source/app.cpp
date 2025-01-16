#include "main_controller.hpp"
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MainController controller;
    controller.start();

    if(argc > 1)
    {
        controller.openFile(argv[1]);
    }

    return app.exec();
}
