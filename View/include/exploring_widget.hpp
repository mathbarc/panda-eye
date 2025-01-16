#ifndef EXPLORING_WIDGET_HPP
#define EXPLORING_WIDGET_HPP

#include <QWidget>

namespace Ui
{
    class ExploringWidget;
}

class ExploringWidget : public QWidget
{
    Q_OBJECT

  public:
    explicit ExploringWidget(QWidget *parent = nullptr);
    ~ExploringWidget();

  signals:
    void openImage(QString path);
    void openVideo(QString path);

  public slots:
    void setCurrentDir(const QString &path);

  private slots:
    void on_horizontalSlider_valueChanged(int value);
    void on_listView_doubleClicked(const QModelIndex &index);

  private:
    Ui::ExploringWidget *ui;
};

#endif // EXPLORING_WIDGET_HPP
