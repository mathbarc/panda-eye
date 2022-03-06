#include "media_cache.hpp"


QSharedPointer<MediaCache> MediaCache::instance;

MediaCache::MediaCache(int maxSize)
    : mediaCache(maxSize)
{

}

Media* MediaCache::operator[](const QString path)
{
    return this->at(path);
}

Media* MediaCache::at(const QString path)
{
    if(mediaCache.contains(path))
        return mediaCache[path];

    Media* media =  Media::makeMedia(path);
    this->mediaCache.insert(path, media);
    return media;
}

QSharedPointer<MediaCache> MediaCache::getInstance()
{
    if(MediaCache::instance.isNull())
        MediaCache::instance = QSharedPointer<MediaCache>(new MediaCache());
    return MediaCache::instance;

}

void MediaCache::setThumbnailsSize(int size)
{
    Media::setThumnailSize(size);
    if(!MediaCache::instance.isNull())
        MediaCache::instance->mediaCache.clear();
}
