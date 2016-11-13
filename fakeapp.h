#ifndef FAKEAPP_H
#define FAKEAPP_H

#include <QThread>
#include <QTimer>

class FakeApp : public QThread
{
    Q_OBJECT
public:
    explicit FakeApp(QObject *parent = 0);

signals:

protected:
    virtual void run();
    QTimer* test;
private slots:
    void testout();
public:
    int argc;
    char **argv;

};

#endif // FAKEAPP_H
