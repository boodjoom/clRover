//#include <QCoreApplication>
#include <QTextStream>
#include "fakeapp.h"
#include "rover.h"
#include "iostream"
#include <QSettings>
#include <QThread>

int main(int argc, char *argv[])
{
    FakeApp* app = new FakeApp();
    app->argc=argc;
    app->argv=argv;
    app->start();

    Rover* rover = new Rover();
    QTextStream in(stdin);
    while(1)
    {
        QString cmd = in.readLine();
        if(cmd.compare("init")==0)
        {
            QSettings sett("rover.ini",QSettings::IniFormat);
            rover->init(sett);
        } else
        if(cmd.compare("conn")==0)
        {
            rover->connect();
        } else
        if(cmd.compare("disc")==0)
        {
            rover->disconnect();
        } else
        if(cmd.compare("fwd")==0)
        {
            rover->setRefSpeed(1.0);
        } else
        if(cmd.compare("bkw")==0)
        {
            rover->setRefSpeed(-1.0);
        } else
        if(cmd.compare("stop")==0)
        {
            rover->setRefSpeed(0.0);
        }
    }
}
