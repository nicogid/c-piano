#include "formulaire.h"
#include "fenCodeGenere.h"
#include <QApplication>
#include <QGroupBox>
#include <QVBoxLayout>

Formulaire::Formulaire()
{
    // Groupe : Définition de la classe
    nom = new QLineEdit;
    prenom = new QLineEdit;



    QFormLayout *definitionLayout = new QFormLayout;
    definitionLayout->addRow("&Nom :", nom);
    definitionLayout->addRow("&Prenom :", prenom);

    QGroupBox *groupDefinition = new QGroupBox("Definition de l'auteur");
    groupDefinition->setLayout(definitionLayout);

    // Groupe : Commentaires

    title = new QLineEdit;
    date = new QDateEdit;
    date->setDate(QDate::currentDate());
    music = new QTextEdit;

    QFormLayout *commentairesLayout = new QFormLayout;
    commentairesLayout->addRow("&Title :", title);
    commentairesLayout->addRow("Da&te de creation :", date);
    commentairesLayout->addRow("&Musique", music);

    groupCommentaires = new QGroupBox("Ajouter des commentaires");
    groupCommentaires->setCheckable(true);
    groupCommentaires->setChecked(false);
    groupCommentaires->setLayout(commentairesLayout);


    // Layout : boutons du bas (g�n�rer, quitter...)
    generer = new QPushButton("&Generer !");
    quitter = new QPushButton("&Quitter");

    QHBoxLayout *boutonsLayout = new QHBoxLayout;
    boutonsLayout->setAlignment(Qt::AlignRight);

    boutonsLayout->addWidget(generer);
    boutonsLayout->addWidget(quitter);


    // D�finition du layout principal, du titre de la fen�tre, etc.

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(groupDefinition);
    layoutPrincipal->addWidget(groupCommentaires);
    layoutPrincipal->addLayout(boutonsLayout);

    setLayout(layoutPrincipal);
    setWindowTitle("Music Class Generator");
    //setWindowIcon(QIcon("icone.png"));
    resize(400, 450);


    // Connexions des signaux et des slots
    connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(generer, SIGNAL(clicked()), this, SLOT(genererCode()));

}


void Formulaire::genererCode()
{
// On v�rifie que le nom de la classe n'est pas vide, sinon on arr�te
if (nom->text().isEmpty()||prenom->text().isEmpty())
{
    QMessageBox::critical(this, "Erreur", "Veuillez entrer tout les champs");
    return; // Arr�t de la m�thode
}

// Si tout va bien, on g�n�re le code
QString code;

    code += "Nom " + nom->text() + "\n";
    code += "Prenom " + nom->text() + "\n";
    code += "Titre : " + title->text() + "\n";
    code += "Date de cr�ation : " + date->date().toString() + "\n\n";
    code += "Musique :\n" + music->toPlainText();



// On cr�e puis affiche la fen�tre qui affichera le code g�n�r�, qu'on lui envoie en param�tre
FenCodeGenere *fenetreCode = new FenCodeGenere(code);
fenetreCode->show();
}
