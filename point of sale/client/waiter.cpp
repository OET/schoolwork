#include "waiter.h"
#include "ui_waiter.h"
#include <QtCore>

waiter::waiter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::waiter)
{
    ui->setupUi(this);
    model=new QStringListModel(this);
    stringlist=new QStringList();
    socket=new QTcpSocket(this);
    //socket->connectToHost("192.168.0.108",60000);
    socket->connectToHost("192.168.0.111",60000);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    ui->pushButton_submitButton->hide();
    ui->pushButton_calTotal->hide();
    ui->lineEdit_response->hide();
    socket->write("carhuc game\n"); //TS
}

waiter::~waiter()
{
    delete ui;
}

void waiter::on_pushButton_newOrder_clicked()
{
    block.clear();
    stringlist->clear();
    ui->pushButton_submitButton->show();
    ui->pushButton_calTotal->show();
    ui->lineEdit_response->show();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"0"<<endl;
    socket->write(block.toAscii());
}
void waiter::on_pushButton_orderStatus_clicked()
{
    block.clear();
    stringlist->clear();
    ui->pushButton_submitButton->hide();
    ui->pushButton_calTotal->hide();
    ui->lineEdit_response->hide();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"1"<<endl;
    socket->write(block.toAscii());

}
void waiter::on_pushButton_listPendOrders_clicked()
{
    block.clear();
    stringlist->clear();
    ui->pushButton_submitButton->hide();
    ui->pushButton_calTotal->hide();
    ui->lineEdit_response->hide();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"2"<<endl;
    socket->write(block.toAscii());

}
void waiter::on_pushButton_calBill_clicked()
{
    block.clear();
    ui->pushButton_submitButton->show();
    ui->pushButton_calTotal->hide();
    ui->lineEdit_response->show();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"4"<<endl;
    socket->write(block.toAscii());

}
void waiter::on_pushButton_logout_clicked()
{
    block.clear();
    ui->pushButton_submitButton->hide();
    ui->pushButton_calTotal->hide();
    ui->lineEdit_response->hide();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"5"<<endl;
    socket->write(block.toAscii());
}
void waiter::on_pushButton_exit_clicked()
{
    block.clear();
    ui->pushButton_submitButton->hide();
    ui->pushButton_calTotal->hide();
    ui->lineEdit_response->hide();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"6"<<endl;
    socket->write(block.toAscii());

}
void waiter::readyRead()
{
    block.clear();


    fromServer.clear();
    while(socket->canReadLine()){
        fromServer = socket->readLine();
        *stringlist << fromServer;
        model->setStringList(*stringlist);
        ui->listView_waiterDisplay->setModel(model);
    }

    qDebug() <<"From Server: "+fromServer;
    socket->flush();
    fromServer.clear();
}
void waiter::displayFromServer(){
    //ui->label_waiterDisplay->setText(fromServer);
}

void waiter::on_pushButton_submitButton_clicked()
{
    block.clear();
    QTextStream serializer(&block, QIODevice::ReadWrite);

    response = ui->lineEdit_response->text();
    qDebug() <<"To Server: "+response;

    serializer <<response<<endl;
    socket->write(block.toAscii());
    ui->lineEdit_response->clear();
}

void waiter::on_pushButton_calTotal_clicked()
{
    block.clear();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"3"<<endl;
    socket->write(block.toAscii());
}
