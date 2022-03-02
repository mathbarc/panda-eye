#ifndef MEDIACACHE_HPP
#define MEDIACACHE_HPP

#include "media.hpp"

#include <QCache>
#include <QSharedPointer>

class MediaCache
{
    public:
        Media* operator[](const QString path);
        Media* at(const QString path);

        static QSharedPointer<MediaCache> getInstance();

    private:
        QCache< QString, Media> mediaCache;

        MediaCache(int maxSize=100);

        static QSharedPointer<MediaCache> instance;

};

#endif // MEDIACACHE_HPP
