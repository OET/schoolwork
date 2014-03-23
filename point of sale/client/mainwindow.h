#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include "login.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void debugOutputCheck(QString a);

public slots:
     void controlWidget();

private slots:
    void on_pushButton_chgWidget_clicked();


private:
    Ui::MainWindow *ui;
    login *l;
    QString wigetChoice;

};

#endif // MAINWINDOW_H
