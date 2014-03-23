#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QTcpSocket>

namespace Ui {
class admin;
}

class admin : public QWidget
{
    Q_OBJECT
    
public:
    explicit admin(QWidget *parent = 0);
    ~admin();
    
private slots:
     void readyRead();

    void on_pushButton_newUser_clicked();

    void on_pushButton_employeeList_clicked();

    void on_pushButton_disableUser_clicked();

    void on_pushButton_enableUser_clicked();

    void on_pushButton_logout_clicked();

    void on_pushButton_exit_clicked();
    void on_pushButton_submitButton_clicked();

private:
    Ui::admin *ui;
    QTcpSocket* socket;
    QString block;
    QString fromServer;
    QTextStream serializer;
    QString myResponse;
    QStringListModel* model;
    QStringList* stringlist;
};

#endif // ADMIN_H
