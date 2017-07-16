#ifndef MAINFENETRE_H
#define MAINFENETRE_H

#include <QMainWindow>

class MainFenetre : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainFenetre(QWidget *parent = 0);

signals:

public slots:
    void ready_readsong();
    void ready_generercode();
    void help();
};

#endif // MAINFENETRE_H
