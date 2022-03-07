#ifndef IMAGE_VIEW_WIDGET_HPP
#define IMAGE_VIEW_WIDGET_HPP

#include <QWidget>

namespace Ui {
class ImageViewWidget;
}

class ImageViewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ImageViewWidget(QWidget *parent = nullptr);
    ~ImageViewWidget();

public slots:
    void setImage(const QString& path);

private:

    void setImageOnScene(const QPixmap& pixmap);
    Ui::ImageViewWidget *ui;
};

#endif // IMAGE_VIEW_WIDGET_HPP
