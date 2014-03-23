#include "login.h"
#include "ui_login.h"
#include <QtCore>
#include <QtGui>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    connect(this, SIGNAL( signalForParent()), this->parent(), SLOT(controlWidget()));
    connectionToSocket();
}

login::~login()
{
    delete ui;
}


void login::connectionToSocket(){
    socket=new QTcpSocket(this);

    //socket connection status
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(connectError()));

    socket->connectToHost("192.168.0.108",60000);


   if(!socket->waitForConnected()){
        QMessageBox msgBox;
        msgBox.setText(socket->errorString());
        msgBox.exec();
    }
}
void login::debugOutputCheck(QString a){
    QMessageBox msgBox;
    msgBox.setText(a);
    msgBox.exec();
}
void login::credentialsCheck(){

    QString block;
    QTextStream serializer(&block, QIODevice::ReadWrite);

    uname = ui->lineEdit_username->text();
    pw = ui->lineEdit_password->text();

    serializer <<uname<<" "<<pw<<endl;
    socket->write(block.toAscii());
}

void login::on_pushButton_login_clicked()
{
   credentialsCheck();
}
void login::readyRead(){

     credentialResults = socket->readAll();
     qDebug() <<"RoleID: "+credentialResults;
     if(credentialResults == "error\n"){
          ui->label__errorPrompt->setText("Error: Username / Password Unknown");
     }
    emit signalForParent();
    //debugOutputCheck("Exit readyRead()");
}
QString login::getCredentialResults(){
    return credentialResults;
}
void login::displayItworkds(){

      debugOutputCheck("Slot Called");
 }

