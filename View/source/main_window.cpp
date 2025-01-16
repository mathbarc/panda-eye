#include "main_window.hpp"
#include "image_view_widget.hpp"
#include "ui_main_window.h"

#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->exploring_widget, SIGNAL(openImage(QString)), this, SLOT(openImage(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openImage(const QString &path)
{
    ImageViewWidget *imgView = new ImageViewWidget();
    this->ui->tabWidget->addTab(imgView, path);
    this->ui->tabWidget->setCurrentWidget(imgView);
    imgView->setImage(path);
}

void MainWindow::openVideo(const QString &path)
{
}

void MainWindow::openFile(const QString &path)
{
    this->ui->exploring_widget->setCurrentDir(path);
    this->openImage(path);
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    if(index != 0)
    {
        QWidget *wid = this->ui->tabWidget->widget(index);
        this->ui->tabWidget->removeTab(index);
        delete wid;
    }
}
