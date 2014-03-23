#include "admin.h"
#include "ui_admin.h"

admin::admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    qDebug() <<"Admin Constructor";
    model=new QStringListModel(this);
    stringlist=new QStringList();
    socket=new QTcpSocket(this);
    //socket->connectToHost("192.168.0.108",60000);
    socket->connectToHost("192.168.0.111",60000);
     //socket->connectToHost("localhost",60001); //pdc server
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    ui->pushButton_submitButton->hide();
    ui->lineEdit_response->hide();
    socket->write("tomchu2 game\n"); //TS
}

admin::~admin()
{
    delete ui;
}


 void admin::readyRead()
 {
     block.clear();

     fromServer.clear();
    // socket->waitForReadyRead(3000);
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

void admin::on_pushButton_newUser_clicked()
{
    block.clear();
    stringlist->clear();

    ui->pushButton_submitButton->show();
    ui->lineEdit_response->show();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"0"<<endl;
    socket->write(block.toAscii());

}

void admin::on_pushButton_employeeList_clicked()
{
    block.clear();
    stringlist->clear();

    ui->pushButton_submitButton->hide();
    ui->lineEdit_response->hide();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"1"<<endl;
    socket->write(block.toAscii());
}

void admin::on_pushButton_disableUser_clicked()
{
    block.clear();
    stringlist->clear();

    ui->pushButton_submitButton->show();
    ui->lineEdit_response->show();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"2"<<endl;
    socket->write(block.toAscii());
}

void admin::on_pushButton_enableUser_clicked()
{

    block.clear();
    stringlist->clear();

    ui->pushButton_submitButton->show();
    ui->lineEdit_response->show();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"3"<<endl;
    socket->write(block.toAscii());

}

void admin::on_pushButton_logout_clicked()
{
    block.clear();
    stringlist->clear();

    ui->pushButton_submitButton->hide();
    ui->lineEdit_response->hide();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"4"<<endl;
    socket->write(block.toAscii());
}

void admin::on_pushButton_exit_clicked()
{
    block.clear();
    stringlist->clear();

    ui->pushButton_submitButton->hide();
    ui->lineEdit_response->hide();
    QTextStream serializer(&block, QIODevice::ReadWrite);
    serializer <<"5"<<endl;
    socket->write(block.toAscii());
}

void admin::on_pushButton_submitButton_clicked()
{
    block.clear();

    QTextStream serializer(&block, QIODevice::ReadWrite);

    myResponse = ui->lineEdit_response->text();
    qDebug() <<"To Server: "+myResponse;

    serializer <<myResponse<<endl;
    socket->write(block.toAscii());
    ui->lineEdit_response->clear();
}
