#include "image_view_widget.hpp"
#include "ui_image_view_widget.h"
#include "utils.hpp"

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>

ImageViewWidget::ImageViewWidget(QWidget *parent) : QWidget(parent), ui(new Ui::ImageViewWidget)
{
    ui->setupUi(this);
    this->ui->graphicsView->setScene(new QGraphicsScene());
}

ImageViewWidget::~ImageViewWidget()
{
    this->ui->graphicsView->scene()->clear();

    delete ui;
}

void ImageViewWidget::setImage(const QString &path)
{
    cv::Mat mat;
    if(path.contains(".tiff"))
    {
        cv::Mat originalImg = cv::imread(path.toStdString(), cv::IMREAD_ANYCOLOR | cv::IMREAD_ANYDEPTH);

        if(originalImg.type() == CV_32FC3)
            originalImg.convertTo(mat, CV_8UC3);
        else if(originalImg.type() == CV_32F)
        {
            double min, max;
            cv::minMaxIdx(originalImg, &min, &max);
            originalImg.convertTo(mat, CV_8U, 255. / (max - min), 255. * (-min) / (max - min));
        }
        else
            mat = originalImg;
    }
    else
        mat = cv::imread(path.toStdString());

    QImage img = utils::cvMatToQImage(mat);

    this->setImageOnScene(QPixmap::fromImage(img));
}

void ImageViewWidget::setImageOnScene(const QPixmap &pixmap)
{
    this->ui->graphicsView->scene()->clear();
    QGraphicsPixmapItem *item = this->ui->graphicsView->scene()->addPixmap(pixmap);
    this->ui->graphicsView->fitInView(dynamic_cast<QGraphicsItem *>(item), Qt::KeepAspectRatio);
}
