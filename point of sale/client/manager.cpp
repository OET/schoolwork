#include "manager.h"
#include "ui_manager.h"
#include <QtCore>
#include <QTcpSocket>

manager::manager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manager)
{
    ui->setupUi(this);
    qDebug() <<"Manager Constructor";
    model=new QStringListModel(this);
    stringlist=new QStringList();
    socket=new QTcpSocket(this);
   //socket->connectToHost("192.168.0.108",60000);
   socket->connectToHost("192.168.0.111",60000);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    ui->pushButton_submitButton->hide();
    ui->lineEdit_response->hide();
    socket->write("chrpau game\n"); //TS
}

manager::~manager()
{
    delete ui;
}
//*************************************************************

void manager::readyRead()
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

//**************************************************************
/*
void manager::on_pushButton_newUser_clicked()
{
    block.clear();
    stringlist->clear();

    ui->pushButton_submitButton->show();
    ui->lineEdit_response->show();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"0"<<endl;
    socket->write(block.toAscii());
}*/

void manager::on_pushButton_currentEmployees_clicked()
{
    block.clear();
    stringlist->clear();

    ui->pushButton_submitButton->hide();
    ui->lineEdit_response->hide();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"0"<<endl;
    socket->write(block.toAscii());
}

void manager::on_pushButton_openbutton_clicked()
{
    block.clear();
    stringlist->clear();

    ui->pushButton_submitButton->hide();
    ui->lineEdit_response->hide();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"1"<<endl;
    socket->write(block.toAscii());

}
void manager::on_pushButton_RTSorders_clicked()
{
    block.clear();
    stringlist->clear();

    ui->pushButton_submitButton->hide();
    ui->lineEdit_response->hide();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"2"<<endl;
    socket->write(block.toAscii());

}

void manager::on_pushButton_pendingOrders_clicked()
{
    block.clear();
    stringlist->clear();

    ui->pushButton_submitButton->hide();
    ui->lineEdit_response->hide();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"3"<<endl;
    socket->write(block.toAscii());
}

void manager::on_pushButton_closed_clicked()
{
    block.clear();
    stringlist->clear();

    ui->pushButton_submitButton->hide();
    ui->lineEdit_response->hide();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"4"<<endl;
    socket->write(block.toAscii());
}
void manager::on_pushButton_itemsOnMenu_clicked()
{
    block.clear();
    stringlist->clear();

    ui->pushButton_submitButton->hide();
    ui->lineEdit_response->hide();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"5"<<endl;
    socket->write(block.toAscii());
}

void manager::on_pushButton_addToMenu_clicked()
{
    block.clear();
    stringlist->clear();

    ui->pushButton_submitButton->show();
    ui->lineEdit_response->show();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"6"<<endl;
    socket->write(block.toAscii());

}
void manager::on_pushButton_deactivateMenuItem_clicked()
{
    block.clear();
    stringlist->clear();

    ui->pushButton_submitButton->show();
    ui->lineEdit_response->show();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"7"<<endl;
    socket->write(block.toAscii());
}
void manager::on_pushButton_activateMenuItem_clicked()
{
    block.clear();
    stringlist->clear();

    ui->pushButton_submitButton->show();
    ui->lineEdit_response->show();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"8"<<endl;
    socket->write(block.toAscii());
}
void manager::on_pushButton_logout_clicked()
{
    block.clear();
    stringlist->clear();

    ui->pushButton_submitButton->hide();
    ui->lineEdit_response->hide();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"9"<<endl;
    socket->write(block.toAscii());
}

void manager::on_pushButton_exit_clicked()
{
    block.clear();
    stringlist->clear();

    ui->pushButton_submitButton->hide();
    ui->lineEdit_response->hide();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"10"<<endl;
    socket->write(block.toAscii());
}

void manager::on_pushButton_submitButton_clicked()
{
    block.clear();

    QTextStream serializer(&block, QIODevice::ReadWrite);

    myResponse = ui->lineEdit_response->text();
    qDebug() <<"To Server: "+myResponse;

    serializer <<myResponse<<endl;
    socket->write(block.toAscii());
    ui->lineEdit_response->clear();
}


