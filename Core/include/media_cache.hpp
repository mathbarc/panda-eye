#ifndef MEDIACACHE_HPP
#define MEDIACACHE_HPP

#include <QCache>
#include <QSharedPointer>

#include "media.hpp"

class MediaCache
{
  public:
    Media *operator[](const QString path);
    Media *at(const QString path);

    static QSharedPointer<MediaCache> getInstance();
    static void setThumbnailsSize(int size);

  private:
    QCache<QString, Media> mediaCache;

    MediaCache(int maxSize = 200);

    static QSharedPointer<MediaCache> instance;
};

#endif // MEDIACACHE_HPP
