#ifndef EXPLORING_WIDGET_HPP
#define EXPLORING_WIDGET_HPP

#include <QWidget>

namespace Ui {
    class ExploringWidget;
}

class ExploringWidget : public QWidget
{
        Q_OBJECT

    public:
        explicit ExploringWidget(QWidget *parent = nullptr);
        ~ExploringWidget();

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
        Ui::ExploringWidget *ui;
};

#endif // EXPLORING_WIDGET_HPP
