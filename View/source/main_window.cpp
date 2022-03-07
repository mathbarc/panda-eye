#include "main_window.hpp"
#include "ui_main_window.h"
#include "image_view_widget.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->exploring_widget, SIGNAL(openImage(QString)), this, SLOT(openImage(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openImage(const QString& path)
{

    ImageViewWidget* imgView = new ImageViewWidget();
    this->ui->tabWidget->addTab(imgView, path);
    imgView->setImage(path);
    this->ui->tabWidget->setCurrentWidget(imgView);
}

void MainWindow::openVideo(const QString& path)
{

}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    if(index!=0)
    {
        this->ui->tabWidget->widget(index)->deleteLater();
        this->ui->tabWidget->removeTab(index);
    }
}
