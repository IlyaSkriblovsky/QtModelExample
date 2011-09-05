#include <QApplication>

#include <QDeclarativeView>
#include <QDeclarativeContext>

#include <QSortFilterProxyModel>

#include "BookModel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    BookModel bookModel;

    QSortFilterProxyModel proxy;
    proxy.setSourceModel(&bookModel);

    proxy.setFilterRole(BookModel::NameRole);
    proxy.setFilterCaseSensitivity(Qt::CaseInsensitive);

    proxy.setSortRole(BookModel::NameRole);
    proxy.setDynamicSortFilter(true);
    proxy.sort(0);


    QDeclarativeView view;
    view.rootContext()->setContextProperty("bookModel", &proxy);
    view.setSource(QUrl::fromLocalFile("main.qml"));
    view.show();

    return app.exec();
}
