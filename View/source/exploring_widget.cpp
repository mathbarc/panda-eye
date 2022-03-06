#include "exploring_widget.hpp"
#include "ui_exploring_widget.h"

#include <QFileSystemModel>
#include <QStyle>

#include "media_item_model.hpp"
#include "media_cache.hpp"

ExploringWidget::ExploringWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExploringWidget)
{
    ui->setupUi(this);


    QFileSystemModel* model = new QFileSystemModel();
    model->setRootPath(QDir::currentPath());
    model->setFilter(QDir::Dirs|QDir::NoDotAndDotDot);
    this->ui->treeView->setModel(model);
    this->ui->treeView->hideColumn(1);
    this->ui->treeView->hideColumn(2);
    this->ui->treeView->hideColumn(3);
    this->ui->treeView->setCurrentIndex(model->index(QDir::currentPath()));

    MediaItemModel* mediaModel = new MediaItemModel();
    this->ui->listView->setModel(mediaModel);
    mediaModel->setCurrentDir(QDir::currentPath());

    connect(this->ui->treeView, SIGNAL(clicked(QModelIndex)), mediaModel, SLOT(setCurrentDir(QModelIndex)));
    this->ui->listView->setResizeMode(QListView::Adjust);

}

ExploringWidget::~ExploringWidget()
{
    delete ui;
}

void ExploringWidget::on_horizontalSlider_valueChanged(int value)
{
    MediaCache::setThumbnailsSize(value);
    this->ui->listView->reset();
}
