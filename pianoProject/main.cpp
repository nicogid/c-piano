#include <QApplication>
#include "readsong.h"
#include "mainfenetre.h"
#include "formulaire.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("Piano");

    MainFenetre fenetre;
    fenetre.show();
    //ReadSong readsong;
    //readsong.show();
    //Formulaire formulaire;
    //formulaire.show();


    return app.exec();
};
