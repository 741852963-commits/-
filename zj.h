#ifndef ZJ_H
#define ZJ_H

#include <QWidget>

namespace Ui {
class zj;
}

class zj : public QWidget
{
    Q_OBJECT

public:
    explicit zj(QWidget *parent = nullptr);
    ~zj();
private slots:
    void baocun();
    void fh();

private:
    Ui::zj *ui;
};

#endif // ZJ_H
