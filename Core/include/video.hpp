#ifndef VIDEO_HPP
#define VIDEO_HPP

#include <QPixmap>

#include "media.hpp"

class Video : public Media
{
public:
    Video(QString filePath);
    virtual const QImage& getThumbnail();
    virtual MediaType getType();
    static const QStringList filters;

private:
    QImage thumbnail;
};

#endif // VIDEO_HPP
