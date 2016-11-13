#include "fakeapp.h"
#include <QCoreApplication>
#include <QDebug>

FakeApp::FakeApp(QObject *parent) : QThread(parent)
{
    moveToThread(this);
}

void FakeApp::run()
{
    QCoreApplication a(argc,argv);
//    qDebug()<<"fakeapp run";
    a.exec();
//    qDebug()<<"fakeapp done";
}

void FakeApp::testout()
{

}
