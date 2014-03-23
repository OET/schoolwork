#ifndef KITCHEN_H
#define KITCHEN_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QTcpSocket>

namespace Ui {
class kitchen;
}

class kitchen : public QWidget
{
    Q_OBJECT
    
public:
    explicit kitchen(QWidget *parent = 0);
    ~kitchen();
    void connectToServer();
    
private slots:

    void readyRead();


   void on_pushButton_updateStatus_clicked();

   void on_pushButton_listPendOrders_clicked();

   void on_pushButton_exit_clicked();

   void on_pushButton_logout_clicked();

  // void on_pushButton_orderContent_clicked();

   void on_pushButton_submitButton_clicked();

private:
    Ui::kitchen *ui;
    QTcpSocket* socket;
    QString block;
    QString fromServer;
    QTextStream serializer;
    QString myResponse;
    QStringListModel* model;
    QStringList* stringlist;
};

#endif // KITCHEN_H
