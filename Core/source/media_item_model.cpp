#include "media_item_model.hpp"
#include <QDir>
#include <iostream>

#include <QFileSystemModel>

#include "media_cache.hpp"

#include "image.hpp"
#include "video.hpp"

MediaItemModel::MediaItemModel(QObject *parent)
    : QAbstractItemModel(parent)
{
}


QVariant MediaItemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    if( role != Qt::DisplayRole )
        return QVariant();
    return section+1;
}

QModelIndex MediaItemModel::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
    if(row >= 0 && row < this->paths.size() && column == 0)
        return this->createIndex(row, column, parent.internalPointer());
    else return QModelIndex();
}

QModelIndex MediaItemModel::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
    return QModelIndex();
}

int MediaItemModel::rowCount(const QModelIndex &parent) const
{
//    if (!parent.isValid())
//        return 0;

    return this->paths.size();

    // FIXME: Implement me!
}

int MediaItemModel::columnCount(const QModelIndex &parent) const
{
//    if (!parent.isValid())
//        return 0;

    return 1;

    // FIXME: Implement me!
}

QVariant MediaItemModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();



    if(role == Qt::DecorationRole)
    {
        Media* thumbnail = MediaCache::getInstance()->at(this->paths[index.row()]);
        if(thumbnail != nullptr)
            return thumbnail->getThumbnail();
        else
            return QVariant();
    }
    else if(role == MediaItemModel::FilePathRole)
    {
        return this->paths[index.row()];
    }
    else if(role == MediaItemModel::FileTypeRole)
    {
        return int(MediaCache::getInstance()->at(this->paths[index.row()])->getType());
    }
    else return QVariant();

}


/*
bool MediaItemModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endInsertRows();
}

bool MediaItemModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endInsertColumns();
}

bool MediaItemModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
}

bool MediaItemModel::removeColumns(int column, int count, const QModelIndex &parent)
{
    beginRemoveColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endRemoveColumns();
}

*/
void MediaItemModel::setCurrentDir(const QString& dir)
{
    QDir directory(dir);
    QStringList newPaths = directory.entryList(Image::filters+Video::filters, QDir::Files);
    for(QString& filePath: newPaths)
    {
        filePath = dir+QDir::separator()+filePath;
    }


    int diff = newPaths.size() - this->paths.size();


    if(diff < 0)
    {
        QAbstractItemModel::removeRows(this->paths.size(), std::abs(diff));
    }

    this->paths = newPaths;

    if(diff > 0)
    {
        QAbstractItemModel::insertRows(this->paths.size(), diff);
    }

    QModelIndex start = this->index(0,0);
    QModelIndex end = this->index(this->rowCount(), this->columnCount());

    QAbstractItemModel::dataChanged(start, end);

}

void MediaItemModel::setCurrentDir(const QModelIndex& index)
{
    this->setCurrentDir(index.data(QFileSystemModel::FilePathRole).toString());
}


bool MediaItemModel::hasChildren(const QModelIndex &parent) const
{
    // FIXME: Implement me!
    return false;
}

bool MediaItemModel::canFetchMore(const QModelIndex &parent) const
{
    // FIXME: Implement me!
    return false;
}

void MediaItemModel::fetchMore(const QModelIndex &parent)
{
    // FIXME: Implement me!
}
