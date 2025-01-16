#include "exploring_widget.hpp"
#include "ui_exploring_widget.h"

#include <QFile>
#include <QFileSystemModel>
#include <QSortFilterProxyModel>
#include <QStyle>

#include "media_cache.hpp"
#include "media_item_model.hpp"

ExploringWidget::ExploringWidget(QWidget *parent) : QWidget(parent), ui(new Ui::ExploringWidget)
{
    ui->setupUi(this);
    this->ui->tabWidget->setHidden(true);

    QFileSystemModel *model = new QFileSystemModel();
    QSortFilterProxyModel *sortedModel = new QSortFilterProxyModel();
    sortedModel->setSourceModel(model);
    sortedModel->setFilterCaseSensitivity(Qt::CaseInsensitive);

    model->setRootPath(QDir::rootPath());
    model->setFilter(QDir::Dirs | QDir::NoDotAndDotDot);

    this->ui->treeView->setModel(sortedModel);
    this->ui->treeView->hideColumn(1);
    this->ui->treeView->hideColumn(2);
    this->ui->treeView->hideColumn(3);
    this->ui->treeView->setCurrentIndex(sortedModel->mapFromSource(model->index(QDir::currentPath())));

    MediaItemModel *mediaModel = new MediaItemModel();
    this->ui->listView->setModel(mediaModel);
    mediaModel->setCurrentDir(QDir::currentPath());

    sortedModel->sort(0, Qt::AscendingOrder);

    connect(this->ui->treeView, SIGNAL(clicked(QModelIndex)), mediaModel, SLOT(setCurrentDir(QModelIndex)));
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

void ExploringWidget::setCurrentDir(const QString &path)
{
    QFileInfo file(path);
    QString dir = file.dir().absolutePath();
    QSortFilterProxyModel *proxyModel = dynamic_cast<QSortFilterProxyModel *>(this->ui->treeView->model());
    QFileSystemModel *model = dynamic_cast<QFileSystemModel *>(proxyModel->sourceModel());
    this->ui->treeView->setCurrentIndex(proxyModel->mapFromSource(model->index(dir)));

    MediaItemModel *mediaModel = dynamic_cast<MediaItemModel *>(this->ui->listView->model());
    mediaModel->setCurrentDir(dir);
}
