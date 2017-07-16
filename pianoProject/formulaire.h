#ifndef FORMULAIRE_H
#define FORMULAIRE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QTextEdit>
#include <QGroupBox>

class Formulaire : public QWidget
{
    Q_OBJECT
public:
    explicit Formulaire();

private slots:
    void genererCode();

    private:
    QLineEdit *nom;
    QLineEdit *prenom;
    QLineEdit *title;
    QDateEdit *date;
    QTextEdit *music;
    QGroupBox *groupCommentaires;
    QPushButton *generer;
    QPushButton *quitter;

};

#endif // FORMULAIRE_H
