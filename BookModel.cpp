#include "BookModel.h"

#include <QFile>
#include <QStringList>
#include <QDebug>

#include <QHash>


BookModel::BookModel(QObject* parent)
    : QAbstractListModel(parent)
{
    QFile data("data.txt");
    data.open(QIODevice::ReadOnly);

    QStringList lines = QString::fromUtf8(data.readAll()).split("\n");

    for (int i = 0; i < lines.size() / 3; i++)
        _books.append(Book(lines[3*i], lines[3*i+1], lines[3*i+2]));


    QHash<int, QByteArray> roleNames;
    roleNames[NameRole] = "name";
    roleNames[ImageUrlRole] = "imageUrl";
    roleNames[BookUrlRole] = "bookUrl";
    setRoleNames(roleNames);
}



int BookModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);

    return _books.size();
}


QVariant BookModel::data(const QModelIndex& index, int role) const
{
    if (index.row() < 0 || index.row() >= _books.size())
        return QVariant();

    switch (role)
    {
        case Qt::DisplayRole:
        case NameRole:
            return _books[index.row()].name;

        case ImageUrlRole:
            return _books[index.row()].imageUrl;

        case BookUrlRole:
            return _books[index.row()].bookUrl;

        default:
            return QVariant();
    }
}
