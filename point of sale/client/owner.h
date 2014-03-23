#ifndef OWNER_H
#define OWNER_H

#include <QWidget>

namespace Ui {
class owner;
}

class owner : public QWidget
{
    Q_OBJECT
    
public:
    explicit owner(QWidget *parent = 0);
    ~owner();
    
private:
    Ui::owner *ui;
};

#endif // OWNER_H
