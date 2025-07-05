#ifndef LC_ZJ_H
#define LC_ZJ_H

#include <QWidget>

namespace Ui {
class lc_zj;
}

class lc_zj : public QWidget
{
    Q_OBJECT

public:
    explicit lc_zj(QWidget *parent = nullptr);
    ~lc_zj();
private slots:
    void baocun();
    void fh();

private:
    Ui::lc_zj *ui;
};

#endif // LC_ZJ_H
