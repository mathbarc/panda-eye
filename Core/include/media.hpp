#ifndef MEDIA_HPP
#define MEDIA_HPP

#include <exception>
#include <stdexcept>
#include <string>

#include <QSharedPointer>

class MediaNotFound : public std::exception
{
  public:
    MediaNotFound(QString path);
    virtual const char *what() const noexcept;

  private:
    const std::string message;
};

enum class MediaType
{
    Image = 0,
    Video = 1
};

class Media
{
  public:
    Media(const std::string path);
    static Media *makeMedia(QString path);
    virtual const QImage &getThumbnail() = 0;
    virtual MediaType getType() = 0;

    static void setThumnailSize(int size);

  protected:
    const std::string path;
    static int thumbnailSize;
};

#endif // MEDIA_HPP
