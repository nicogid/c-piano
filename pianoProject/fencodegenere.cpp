#include "fencodegenere.h"
#include <vector>
#include <windows.h>
#include <QFile>
#include    <QTextStream>
#include <QIODevice>

#define C4 261 // DO
#define D4 293 // RE
#define E4 329 // MI
#define F4 349 // FA
#define G4 392 // SOL
#define A4 440 // LA
#define B4 493 // SI

FenCodeGenere::FenCodeGenere(QString &code): QDialog()
{
    codeGenere = new QTextEdit();
    codeGenere->setPlainText(code);
    codeGenere->setReadOnly(true);
    codeGenere->setFont(QFont("Courier"));
    codeGenere->setLineWrapMode(QTextEdit::NoWrap);

    fermer = new QPushButton("Fermer");
    lire =new QPushButton("Lire le son");
    enrgistrer =new QPushButton("Enregistrer");

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(codeGenere);
    layoutPrincipal->addWidget(fermer);
    layoutPrincipal->addWidget(lire);
    layoutPrincipal->addWidget(enrgistrer);


    resize(350, 450);
    setLayout(layoutPrincipal);


    connect(fermer, SIGNAL(clicked()), this, SLOT(accept()));
    connect(lire, SIGNAL(clicked()), this, SLOT(read()));
    connect(enrgistrer, SIGNAL(clicked()), this, SLOT(newfile()));
}

void FenCodeGenere::readsong(QString code){

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
}

void FenCodeGenere::save(QString code){

    // Création d'un objet QFile
    // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
    QFile file("C:/Users/gidon/Documents/c-piano/pianoProject/fichier.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
      return;


    // Création d'un objet QTextStream à partir de notre objet QFile
    QTextStream flux(&file);
    // On choisit le codec correspondant au jeu de caractères que l'on souhaite ; ici, UTF-8
    flux.setCodec("UTF-8");
    // Écriture des différentes lignes dans le fichier
    flux << code << endl;

    file.close();
    QMessageBox::information(this, "Success",  "morceau enregistré");
    return;

}

void FenCodeGenere::read(){
    readsong(codeGenere->toPlainText());
}

void FenCodeGenere::newfile(){
    save(codeGenere->toPlainText());
}

void FenCodeGenere::note_do(){
    Beep(C4, 250);
}

void FenCodeGenere::note_re(){
    Beep(D4, 250);
}

void FenCodeGenere::note_mi(){
    Beep(E4, 250);
}

void FenCodeGenere::note_fa(){
    Beep(F4, 250);
}

void FenCodeGenere::note_sol(){
    Beep(G4, 250);
}

void FenCodeGenere::note_la(){
    Beep(A4, 250);
}

void FenCodeGenere::note_si(){
    Beep(B4, 250);
}
