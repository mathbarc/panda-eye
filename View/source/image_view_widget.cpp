#include "image_view_widget.hpp"
#include "ui_image_view_widget.h"
#include "utils.hpp"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
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
    this->ui->graphicsView->scene()->clear();

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
    QGraphicsPixmapItem* item = this->ui->graphicsView->scene()->addPixmap(pixmap);
    this->ui->graphicsView->fitInView(dynamic_cast<QGraphicsItem*>(item),Qt::KeepAspectRatio);
}
