#include <QApplication>
#include "readsong.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("Piano");

    ReadSong readsong;
    readsong.show();

    return app.exec();
};
