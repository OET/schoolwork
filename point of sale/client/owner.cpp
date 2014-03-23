#include "owner.h"
#include "ui_owner.h"

owner::owner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::owner)
{
    ui->setupUi(this);
}

owner::~owner()
{
    delete ui;
}
