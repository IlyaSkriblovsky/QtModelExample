#ifndef BOOK_H
#define BOOK_H

struct Book
{
    QString name;
    QString imageUrl;
    QString bookUrl;


    Book(const QString& name, const QString& imageUrl, const QString& bookUrl)
        : name(name), imageUrl(imageUrl), bookUrl(bookUrl)
    {
    }
};

#endif
