#ifndef ZDGL_H
#define ZDGL_H

#include <QWidget>

namespace Ui {
class zdgl;
}

class zdgl : public QWidget
{
    Q_OBJECT

public:
    explicit zdgl(QWidget *parent = nullptr);
    ~zdgl();
private slots:
    void seek();
    void xiaye(int a);
    void shangye(int a);
    void baocun();
    void zengjia();
    void sx();


private:
    Ui::zdgl *ui;
};

#endif // ZDGL_H
