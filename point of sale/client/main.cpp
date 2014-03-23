#include <QtGui/QApplication>
#include "mainwindow.h"
#include "login.h"
#include "kitchen.h"
#include "waiter.h"
#include "manager.h"
#include "owner.h"
#include "admin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   //MainWindow w;
   // w.show();

    //l.show
    //login l;();

   // kitchen k;
   // k.show();

    waiter w;
    w.show();

   // manager man;
   // man.show();
//
   // admin ad;
  //  ad.show();



    return a.exec();
}
