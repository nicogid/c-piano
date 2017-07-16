#ifndef MAINFENETRE_H
#define MAINFENETRE_H

#include <QMainWindow>

class MainFenetre : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainFenetre(QWidget *parent = 0);

    void note_do();
    void note_re();
    void note_mi();
    void note_fa();
    void note_sol();
    void note_la();
    void note_si();

signals:

public slots:
    void ready_readsong();
    void ready_generercode();
    void help();
    void lecture();
};

#endif // MAINFENETRE_H
