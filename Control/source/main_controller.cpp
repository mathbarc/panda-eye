#include "main_controller.hpp"
#include <QFileInfo>
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
        QFileInfo fileInfo(file);
        if(!fileInfo.isDir())
        {
            this->mainWindow.openFile(file);
        }
    }
}
