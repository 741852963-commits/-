#ifndef LCGL_H
#define LCGL_H

#include <QWidget>

namespace Ui {
class lcgl;
}

class lcgl : public QWidget
{
    Q_OBJECT

public:
    explicit lcgl(QWidget *parent = nullptr);
    ~lcgl();
private slots:
    void seek();
    void xiaye(int a);
    void shangye(int a);
    void baocun();
    void zengjia();
    void sx();
private:
    Ui::lcgl *ui;
};

#endif // LCGL_H
