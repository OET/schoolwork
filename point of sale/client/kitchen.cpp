#include "kitchen.h"
#include "ui_kitchen.h"
#include <QtCore>
#include <QTcpSocket>

kitchen::kitchen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kitchen)
{
    ui->setupUi(this);
    qDebug() <<"Kitchen Constructor";
    model=new QStringListModel(this);
    stringlist=new QStringList();
    socket=new QTcpSocket(this);
   // socket->connectToHost("192.168.0.108",60000);
    socket->connectToHost("192.168.0.111",60000);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    ui->pushButton_submitButton->hide();
    ui->lineEdit_response->hide();
    socket->write("lemcra7 gast\n"); //TS
}

kitchen::~kitchen()
{
    delete ui;
}

void kitchen::readyRead()
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

//********************************************************

void kitchen::on_pushButton_updateStatus_clicked()
{
    block.clear();
    stringlist->clear();
    qDebug() << "checkking"<<endl;

    ui->pushButton_submitButton->show();
    ui->lineEdit_response->show();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"0"<<endl;
    socket->write(block.toAscii());

}
void kitchen::on_pushButton_submitButton_clicked()
{
    block.clear();

    QTextStream serializer(&block, QIODevice::ReadWrite);

    myResponse = ui->lineEdit_response->text();
    qDebug() <<"To Server: "+myResponse;

    serializer <<myResponse<<endl;
    socket->write(block.toAscii());
    ui->lineEdit_response->clear();
}


//***********************************************************


void kitchen::on_pushButton_listPendOrders_clicked()
{
    block.clear();
    stringlist->clear();
    ui->pushButton_submitButton->hide();
    ui->lineEdit_response->hide();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"1"<<endl;
    socket->write(block.toAscii());
}
/*
void kitchen::on_pushButton_orderContent_clicked()
{
    block.clear();
    stringlist->clear();
    ui->pushButton_submitButton->show();
    ui->lineEdit_response->show();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"2"<<endl;
    socket->write(block.toAscii());

}
*/
void kitchen::on_pushButton_exit_clicked()
{
    block.clear();
    stringlist->clear();
    ui->pushButton_submitButton->hide();
    ui->lineEdit_response->hide();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"3"<<endl;
    socket->write(block.toAscii());
}

void kitchen::on_pushButton_logout_clicked()
{
    block.clear();
    stringlist->clear();
    ui->pushButton_submitButton->hide();
    ui->lineEdit_response->hide();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"4"<<endl;
    socket->write(block.toAscii());
}




