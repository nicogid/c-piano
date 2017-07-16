#ifndef FENETREREADSONG_H
#define FENETREREADSONG_H

#include <QtWidgets/QApplication>
#include <QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QFormLayout>
#include <QLabel>
#include <string>

class FenetreReadSong : public QWidget
{
    Q_OBJECT
public:
    FenetreReadSong(std::string info,std::map<int,std::string> &song);

private:
    std::string music;
    QLabel* m_music;
    QLabel* m_info;
    QPushButton* m_quit;

signals:

public slots:
    void info_quit();
};

#endif // FENETREREADSONG_H
