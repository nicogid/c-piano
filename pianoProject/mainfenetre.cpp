#include "mainfenetre.h"
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <readsong.h>
#include <formulaire.h>
#include <QMessageBox>
#include <windows.h>

#define C4 261 // DO
#define D4 293 // RE
#define E4 329 // MI
#define F4 349 // FA
#define G4 392 // SOL
#define A4 440 // LA
#define B4 493 // SI

MainFenetre::MainFenetre(QWidget *parent) : QMainWindow(parent)
{
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");

    QAction *actionQuitter = new QAction("&Quitter", this);
    menuFichier->addAction(actionQuitter);
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
    actionQuitter->setIcon(QIcon("quitter.png"));
    actionQuitter->setCheckable(true);

    QMenu *menuProjet = menuBar()->addMenu("&Projet");
    QAction *lancer_readsong = new QAction("&ReadSong", this);
    menuProjet->addAction(lancer_readsong);
    lancer_readsong->setCheckable(true);
    QAction *lancer_generer_code = new QAction("&GenererCode", this);
    menuProjet->addAction(lancer_generer_code);
    lancer_generer_code->setCheckable(true);
    QAction *lancer_lecture = new QAction("&Lire fichier", this);
    menuProjet->addAction(lancer_lecture);
    lancer_lecture->setCheckable(true);

    QMenu *menuHelp = menuBar()->addMenu("&Help");
    QAction *lancer_help = new QAction("&Infos", this);
    menuHelp->addAction(lancer_help);
    lancer_help->setCheckable(true);

    connect(actionQuitter, SIGNAL(triggered()),qApp, SLOT(quit()));
    connect(lancer_readsong, SIGNAL(triggered()),this, SLOT(ready_readsong()));
    connect(lancer_generer_code, SIGNAL(triggered()),this, SLOT(ready_generercode()));
    connect(lancer_help, SIGNAL(triggered()),this, SLOT(help()));
     connect(lancer_lecture, SIGNAL(triggered()),this, SLOT(lecture()));

}

void MainFenetre::ready_readsong(){
    ReadSong *fenetre = new ReadSong();
    fenetre->show();
    this->close();

}

void MainFenetre::ready_generercode(){
    Formulaire *fenetre = new Formulaire();
    fenetre->show();
    this->close();
}

void MainFenetre::help(){
    QMessageBox::information(this, "Info", "Projet des 4MOC1\n Nicolas Gidon\nNorbert Bila\nManuel Burgos");
}

void MainFenetre::lecture(){
    QString fileName = "C:/Users/gidon/Documents/c-piano/pianoProject/fichier.txt";
    QFile fichier(fileName);
    if(!fichier.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream flux(&fichier);

    QString code = flux.readAll();

    fichier.close();

    int position = code.lastIndexOf("Musique") + 10;
        QString musica = code.mid(position);
        if(musica.indexOf(":")==-1)
        {
            QMessageBox::critical(this, "Erreur", "Veuillez separer les note par (:) !");
            return;
        }

        int posSong(0);
        int tmp(0);
        std::vector<QString> tabSong;

        while (tmp<musica.size()){
            posSong=musica.indexOf(":");
            tabSong.push_back(musica.mid(tmp,posSong));
            posSong++;
            tmp+=posSong;
        }

        for(int i(0);i<tabSong.size();i++)
        {

            if(tabSong[i].compare("do")==0)
                break;
            if(tabSong[i].compare("re")==0)
                break;
            if(tabSong[i].compare("mi")==0)
                break;
            if(tabSong[i].compare("fa")==0)
                break;
            if(tabSong[i].compare("sol")==0)
                break;
            if(tabSong[i].compare("la")==0)
                break;
            if(tabSong[i].compare("si")==0)
                break;
            else{
                QMessageBox::critical(this, "Erreur",  tabSong[i] + " n'est pas une note !");
                return;
            }
        }

        std::vector<QString>::iterator it = tabSong.begin();
        while(it != tabSong.end())
        {

            if(it->compare("do")==0)
                note_do();
            if(it->compare("re")==0)
                note_re();
            if(it->compare("mi")==0)
                note_mi();
            if(it->compare("fa")==0)
                note_fa();
            if(it->compare("sol")==0)
                note_sol();
            if(it->compare("la")==0)
                note_la();
            if(it->compare("si")==0)
                note_si();
        it++;
        }

    QMessageBox::information(this, "Success",  code);

}

void MainFenetre::note_do(){
    Beep(C4, 250);
}

void MainFenetre::note_re(){
    Beep(D4, 250);
}

void MainFenetre::note_mi(){
    Beep(E4, 250);
}

void MainFenetre::note_fa(){
    Beep(F4, 250);
}

void MainFenetre::note_sol(){
    Beep(G4, 250);
}

void MainFenetre::note_la(){
    Beep(A4, 250);
}

void MainFenetre::note_si(){
    Beep(B4, 250);
}
