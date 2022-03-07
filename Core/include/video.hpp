#ifndef VIDEO_HPP
#define VIDEO_HPP

#include "media.hpp"
#include <QPixmap>

#include <opencv2/videoio/videoio.hpp>

class Video : public Media
{
public:
    Video(QString filePath);
    virtual const QPixmap& getThumbnail();
    virtual MediaType getType();
    static const QStringList filters;

private:
    QPixmap thumbnail;
};

#endif // VIDEO_HPP
