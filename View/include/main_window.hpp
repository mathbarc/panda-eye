#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        void openImage(const QString& path);
        void openVideo(const QString& path);



        void on_tabWidget_tabCloseRequested(int index);

private:
        Ui::MainWindow *ui;

};

#endif // MAIN_WINDOW_HPP
