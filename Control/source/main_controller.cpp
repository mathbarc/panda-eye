#include "main_controller.hpp"


MainController::MainController()
{


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
