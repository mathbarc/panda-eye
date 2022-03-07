#include "image_view_widget.hpp"
#include "ui_image_view_widget.h"
#include "utils.hpp"

#include <QGraphicsScene>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>

ImageViewWidget::ImageViewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageViewWidget)
{
    ui->setupUi(this);
    this->ui->graphicsView->setScene(new QGraphicsScene());
}

ImageViewWidget::~ImageViewWidget()
{
    delete ui;
}


void ImageViewWidget::setImage(const QString& path)
{
    QImage img = utils::cvMatToQImage(cv::imread(path.toStdString()));

    this->setImageOnScene(QPixmap::fromImage(img));
}

void ImageViewWidget::setImageOnScene(const QPixmap& pixmap)
{
    this->ui->graphicsView->scene()->clear();
    this->ui->graphicsView->scene()->addPixmap(pixmap);
}
