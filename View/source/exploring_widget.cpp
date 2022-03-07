#include "exploring_widget.hpp"
#include "ui_exploring_widget.h"

#include <QFileSystemModel>
#include <QSortFilterProxyModel>
#include <QStyle>

#include "media_item_model.hpp"
#include "media_cache.hpp"

ExploringWidget::ExploringWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExploringWidget)
{
    ui->setupUi(this);


    QFileSystemModel* model = new QFileSystemModel();
    QSortFilterProxyModel* sortedModel = new QSortFilterProxyModel();
    sortedModel->setSourceModel(model);

    model->setRootPath(QDir::currentPath());
    model->setFilter(QDir::Dirs|QDir::NoDotAndDotDot);


    this->ui->treeView->setModel(sortedModel);
    this->ui->treeView->hideColumn(1);
    this->ui->treeView->hideColumn(2);
    this->ui->treeView->hideColumn(3);
    this->ui->treeView->setCurrentIndex(sortedModel->mapFromSource(model->index(QDir::currentPath())));

    MediaItemModel* mediaModel = new MediaItemModel();
    this->ui->listView->setModel(mediaModel);
    mediaModel->setCurrentDir(QDir::currentPath());

    sortedModel->sort(0, Qt::AscendingOrder);


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

void ExploringWidget::on_listView_doubleClicked(const QModelIndex &index)
{

    QString path = index.data(MediaItemModel::FilePathRole).toString();

    if(index.data(MediaItemModel::FileTypeRole).toInt() == int(MediaType::Image))
    {
        emit openImage(path);
    }
    else if(index.data(MediaItemModel::FileTypeRole).toInt() == int(MediaType::Video))
    {
        emit openVideo(path);
    }
}
