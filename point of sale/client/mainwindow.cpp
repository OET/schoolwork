#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include "kitchen.h"
#include "login.h"
#include "manager.h"
#include "owner.h"
#include "waiter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    l = new login(this);
    this->setCentralWidget(l);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_chgWidget_clicked()
{
    login *l = new login();

    this->setCentralWidget(l);
}
void MainWindow::debugOutputCheck(QString a){
    QMessageBox msgBox;
    msgBox.setText(a);
    msgBox.exec();
}
void MainWindow::controlWidget(){
    QString wigetChoice;

    wigetChoice = l->getCredentialResults();
  // debugOutputCheck("controlWidget(): "+wigetChoice);

    //debugOutputCheck("controlWidget(): "+wigetChoice);


    if (wigetChoice != "0\n"){

        if (wigetChoice == "1\n"){
           waiter* w = new waiter(this);
           this->setCentralWidget(w);
        }
        if (wigetChoice ==  "2\n"){
            manager* m = new manager(this);
            this->setCentralWidget(m);
        }
        if (wigetChoice ==  "3\n"){
            kitchen* k = new kitchen(this);
            this->setCentralWidget(k);
        }
        if (wigetChoice ==  "4\n"){
            owner* o = new owner(this);
            this->setCentralWidget(o);
        }
        //setup Admin
    }
}
