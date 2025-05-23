#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <QImage>

#include "media.hpp"

class Image : public Media
{
  public:
    Image(QString path);
    virtual const QImage &getThumbnail();
    virtual MediaType getType();
    static const QStringList filters;

  private:
    QImage thumbnail;
};

#endif // IMAGE_HPP
