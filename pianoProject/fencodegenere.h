#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QTextEdit>
#include <QString>


class FenCodeGenere : public QDialog
{
    Q_OBJECT
    public:
    FenCodeGenere(QString &code);
    void note_do();
    void note_re();
    void note_mi();
    void note_fa();
    void note_sol();
    void note_la();
    void note_si();
    void readsong(QString code);
    void save(QString code);
    private:
    QTextEdit *codeGenere;
    QPushButton *fermer;
    QPushButton *lire;
    QPushButton *enrgistrer;
    QLabel* testlabel;
    public slots:
    void read();
    void newfile();
};

#endif // FENCODEGENERE_H
