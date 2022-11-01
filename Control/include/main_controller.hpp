#ifndef MAINCONTROLLER_HPP
#define MAINCONTROLLER_HPP

#include <QObject>
#include "main_window.hpp"

class MainController : public QObject
{
    Q_OBJECT
    public:
        MainController();
        void start();
        void openFile(QString file = QString());
    private:
        MainWindow mainWindow;


};

#endif // MAINCONTROLLER_HPP
