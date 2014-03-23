#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QTcpSocket>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT
    
public:
    explicit login(QWidget *parent = 0);
    ~login();
    void credentialsCheck();
    void debugOutputCheck(QString a);
     QString getCredentialResults();

signals:
    void signalForParent();


private:
    Ui::login *ui;
    void connectionToSocket();

    QAbstractItemModel *model;
    QAbstractItemView *listView;
    QTcpSocket* socket;
    QString credentialResults;
    QString uname;
    QString pw;

private slots:
    void on_pushButton_login_clicked();
    void readyRead();
    void displayItworkds();

};
#endif // LOGIN_H
