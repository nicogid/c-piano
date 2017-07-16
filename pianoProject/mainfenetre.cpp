#include "mainfenetre.h"
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <readsong.h>
#include <formulaire.h>
#include <QMessageBox>

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

    QMenu *menuHelp = menuBar()->addMenu("&Help");
    QAction *lancer_help = new QAction("&Infos", this);
    menuHelp->addAction(lancer_help);
    lancer_help->setCheckable(true);

    connect(actionQuitter, SIGNAL(triggered()),qApp, SLOT(quit()));
    connect(lancer_readsong, SIGNAL(triggered()),this, SLOT(ready_readsong()));
    connect(lancer_generer_code, SIGNAL(triggered()),this, SLOT(ready_generercode()));
    connect(lancer_help, SIGNAL(triggered()),this, SLOT(help()));


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
