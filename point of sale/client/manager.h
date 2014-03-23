#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QTcpSocket>


namespace Ui {
class manager;
}

class manager : public QWidget
{
    Q_OBJECT
    
public:
    explicit manager(QWidget *parent = 0);
    ~manager();
    
private slots:
    void readyRead();
  //  void on_pushButton_newUser_clicked();

    void on_pushButton_currentEmployees_clicked();

    void on_pushButton_RTSorders_clicked();

    void on_pushButton_pendingOrders_clicked();

    void on_pushButton_logout_clicked();

    void on_pushButton_exit_clicked();

    void on_pushButton_submitButton_clicked();

    void on_pushButton_openbutton_clicked();

    void on_pushButton_closed_clicked();

    void on_pushButton_addToMenu_clicked();

    void on_pushButton_deactivateMenuItem_clicked();

    void on_pushButton_activateMenuItem_clicked();

    void on_pushButton_itemsOnMenu_clicked();

private:
    Ui::manager *ui;
    QTcpSocket* socket;
    QString block;
    QString fromServer;
    QTextStream serializer;
    QString myResponse;
    QStringListModel* model;
    QStringList* stringlist;
};

#endif // MANAGER_H
