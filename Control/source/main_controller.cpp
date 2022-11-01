#include "main_controller.hpp"
#include <QResource>

MainController::MainController()
{
    Q_INIT_RESOURCE(resource);
}


void MainController::start()
{
    this->mainWindow.showMaximized();
}

void MainController::openFile(QString file)
{
    if(!file.isEmpty())
    {
        this->mainWindow.openFile(file);
    }
}
