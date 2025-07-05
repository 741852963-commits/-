#ifndef XTGL_XL_H
#define XTGL_XL_H

#include <QWidget>

namespace Ui {
class xtgl_xl;
}

class xtgl_xl : public QWidget
{
    Q_OBJECT

public:
    explicit xtgl_xl(QWidget *parent = nullptr);
    ~xtgl_xl();
private slots:
    void shangye(int a);
    void xiaye(int a);
    void sx();
    void seek();
    void zengjia();
    void qh();
private:
    Ui::xtgl_xl *ui;
};

#endif // XTGL_XL_H
