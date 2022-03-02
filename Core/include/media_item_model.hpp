#ifndef MEDIAITEMMODEL_H
#define MEDIAITEMMODEL_H

#include <QAbstractItemModel>

class MediaItemModel : public QAbstractItemModel
{
        Q_OBJECT

    public:
        explicit MediaItemModel(QObject *parent = nullptr);


        // Header:
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

        // Basic functionality:
        QModelIndex index(int row, int column,
                          const QModelIndex &parent = QModelIndex()) const override;
        QModelIndex parent(const QModelIndex &index) const override;


        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        int columnCount(const QModelIndex &parent = QModelIndex()) const override;

        // Fetch data dynamically:
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

        /*
        // Add data:
        bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
        bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

        // Remove data:
        bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
        bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;
        */


    public slots:
        void setCurrentDir(const QString& dir);
        void setCurrentDir(const QModelIndex& index);

    private:
        QStringList paths;

};

#endif // MEDIAITEMMODEL_H
