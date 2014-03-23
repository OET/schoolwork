#ifndef WAITER_H
#define WAITER_H

#include <QWidget>
#include <QTcpSocket>
#include <QtCore>
#include <QtGui>


namespace Ui {
class waiter;
}

class waiter : public QWidget
{
    Q_OBJECT
    
public:
    explicit waiter(QWidget *parent = 0);
    ~waiter();
    void displayFromServer();

signals:
    void signalForParent();

private slots:
    void on_pushButton_newOrder_clicked();
    void on_pushButton_orderStatus_clicked();
    void on_pushButton_listPendOrders_clicked();
    void on_pushButton_calBill_clicked();
    void on_pushButton_logout_clicked();
    void on_pushButton_exit_clicked();
    void readyRead();

    void on_pushButton_submitButton_clicked();

    void on_pushButton_calTotal_clicked();

private:
    Ui::waiter *ui;
    QTcpSocket* socket;
    QString block;
    QString response;
    QString fromServer;
    QStringListModel* model;
    QStringList* stringlist;

};

#endif // WAITER_H
