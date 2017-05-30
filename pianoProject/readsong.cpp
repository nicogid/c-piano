#include "readsong.h"
#include <QFileDialog>
#include <QString>
#include <QBoxLayout>
#include <windows.h>

#define C4 261 // DO
#define D4 293 // RE
#define E4 329 // MI
#define F4 349 // FA
#define G4 392 // SOL
#define A4 440 // LA
#define B4 493 // SI


ReadSong::ReadSong()
{
    //setFixedSize(300,300);

    m_read = new QPushButton("Selectionnez le morceau",this);
    m_read->setFont(QFont("Comic Sans MS"));
    m_read->setCursor(Qt::PointingHandCursor);
    m_stop = new QPushButton("Stop",this);
    m_stop->setFont(QFont("Comic Sans MS"));
    m_stop->setCursor(Qt::PointingHandCursor);
    m_play = new QPushButton("play",this);
    m_play->setFont(QFont("Comic Sans MS"));
    m_play->setCursor(Qt::PointingHandCursor);
    m_pause = new QPushButton("pause",this);
    m_pause->setFont(QFont("Comic Sans MS"));
    m_pause->setCursor(Qt::PointingHandCursor);

    QHBoxLayout *layoutH1 = new QHBoxLayout;
    layoutH1->addWidget(m_read);
    layoutH1->addWidget(m_play);
    layoutH1->addWidget(m_pause);
    layoutH1->addWidget(m_stop);

    m_do = new QPushButton("DO",this);
    m_do->setFont(QFont("Comic Sans MS"));
    m_do->setCursor(Qt::PointingHandCursor);
    m_re = new QPushButton("RE",this);
    m_re->setFont(QFont("Comic Sans MS"));
    m_re->setCursor(Qt::PointingHandCursor);
    m_mi = new QPushButton("MI",this);
    m_mi->setFont(QFont("Comic Sans MS"));
    m_mi->setCursor(Qt::PointingHandCursor);
    m_fa = new QPushButton("FA",this);
    m_fa->setFont(QFont("Comic Sans MS"));
    m_fa->setCursor(Qt::PointingHandCursor);
    m_sol = new QPushButton("SOL",this);
    m_sol->setFont(QFont("Comic Sans MS"));
    m_sol->setCursor(Qt::PointingHandCursor);
    m_la = new QPushButton("LA",this);
    m_la->setFont(QFont("Comic Sans MS"));
    m_la->setCursor(Qt::PointingHandCursor);
    m_si = new QPushButton("SI",this);
    m_si->setFont(QFont("Comic Sans MS"));
    m_si->setCursor(Qt::PointingHandCursor);

    QHBoxLayout *layoutH2 = new QHBoxLayout;
    layoutH2->addWidget(m_do);
    layoutH2->addWidget(m_re);
    layoutH2->addWidget(m_mi);
    layoutH2->addWidget(m_fa);
    layoutH2->addWidget(m_sol);
    layoutH2->addWidget(m_la);
    layoutH2->addWidget(m_si);

    QVBoxLayout *layoutV1 = new QVBoxLayout;
    layoutV1->addLayout(layoutH1);
    layoutV1->addLayout(layoutH2);

    setLayout(layoutV1);

    player = new QMediaPlayer(this);

    QObject::connect(m_read,SIGNAL(clicked(bool)),this,SLOT(readMusic()));
    QObject::connect(m_stop,SIGNAL(clicked(bool)),this,SLOT(stopMusic()));
    QObject::connect(m_play,SIGNAL(clicked(bool)),this,SLOT(playMusic()));
    QObject::connect(m_pause,SIGNAL(clicked(bool)),this,SLOT(pauseMusic()));

    QObject::connect(m_do,SIGNAL(clicked(bool)),this,SLOT(note_do()));
    QObject::connect(m_re,SIGNAL(clicked(bool)),this,SLOT(note_re()));
    QObject::connect(m_mi,SIGNAL(clicked(bool)),this,SLOT(note_mi()));
    QObject::connect(m_fa,SIGNAL(clicked(bool)),this,SLOT(note_fa()));
    QObject::connect(m_sol,SIGNAL(clicked(bool)),this,SLOT(note_sol()));
    QObject::connect(m_la,SIGNAL(clicked(bool)),this,SLOT(note_la()));
    QObject::connect(m_si,SIGNAL(clicked(bool)),this,SLOT(note_si()));
}

void ReadSong::readMusic(){
    QString file = QFileDialog::getOpenFileName(this);
    //load the file
    player->setMedia(QUrl::fromLocalFile(file));
    player->setVolume(50);
    player->play();
}

void ReadSong::stopMusic(){
    player->stop();
}

void ReadSong::pauseMusic(){
    player->pause();
}

void ReadSong::playMusic(){
    player->play();
}

void ReadSong::note_do(){
    Beep(C4, 250);
}

void ReadSong::note_re(){
    Beep(D4, 250);
}

void ReadSong::note_mi(){
    Beep(E4, 250);
}

void ReadSong::note_fa(){
    Beep(F4, 250);
}

void ReadSong::note_sol(){
    Beep(G4, 250);
}

void ReadSong::note_la(){
    Beep(A4, 250);
}

void ReadSong::note_si(){
    Beep(B4, 250);
}

ReadSong::~ReadSong(){
    delete m_play;
    delete m_read;
    delete m_stop;
}
