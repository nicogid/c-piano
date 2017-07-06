#ifndef READSONG_H
#define READSONG_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QUrl>
#include <QMediaPlayer>
#include <QApplication>
#include <QKeyEvent>

class ReadSong : public QWidget
{
    void keyPressEvent(QKeyEvent *event);

    Q_OBJECT
public:
    ReadSong();
    ~ReadSong();

signals:

public slots:
    void playMusic();
    void stopMusic();
    void pauseMusic();
    void readMusic();
    void note_do();
    void note_re();
    void note_mi();
    void note_fa();
    void note_sol();
    void note_la();
    void note_si();

private:
    QPushButton* m_read;
    QPushButton* m_stop;
    QPushButton* m_play;
    QPushButton* m_pause;

    QPushButton* m_do;
    QPushButton* m_re;
    QPushButton* m_mi;
    QPushButton* m_fa;
    QPushButton* m_sol;
    QPushButton* m_la;
    QPushButton* m_si;

    QMediaPlayer* player;
};

#endif // READSONG_H
