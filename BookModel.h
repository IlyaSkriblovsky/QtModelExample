#ifndef BOOK_MODEL_H
#define BOOK_MODEL_H

#include <QAbstractListModel>

#include <QList>

#include "Book.h"

class BookModel: public QAbstractListModel
{
    public:
        enum Roles
        {
            NameRole = Qt::UserRole+1,
            ImageUrlRole,
            BookUrlRole
        };

        BookModel(QObject* parent = 0);

        virtual int rowCount(const QModelIndex& parent = QModelIndex()) const;
        virtual QVariant data(const QModelIndex& parent, int role = Qt::DisplayRole) const;


    private:
        QList<Book> _books;
};

#endif
