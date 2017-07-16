#include "fenetrereadsong.h"
#include <string>
#include <map>



FenetreReadSong::FenetreReadSong(std::string info,std::map<int,std::string> &song) : QWidget()
{
    setFixedSize(300, 150);

        music = "";
        std::map<int,std::string>::iterator it = song.begin();
        while(it != song.end())
        {
            music += it->second;
        it++;
        }


        m_info = new QLabel(QString::fromStdString(info),this);
        m_music = new QLabel(QString::fromStdString(music),this);
        m_music->move(30, 0);

        m_quit = new QPushButton("Annuler", this);

        m_quit->setToolTip("Annuler");
        m_quit->setCursor(Qt::PointingHandCursor);
        m_quit->move(30, 95);

        QObject::connect(m_quit, SIGNAL(clicked()), this, SLOT(info_quit()));

}

void FenetreReadSong::info_quit(){
    this->close();
}
