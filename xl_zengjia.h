#ifndef XL_ZENGJIA_H
#define XL_ZENGJIA_H

#include <QWidget>

namespace Ui {
class xl_zengjia;
}

class xl_zengjia : public QWidget
{
    Q_OBJECT

public:
    explicit xl_zengjia(QWidget *parent = nullptr);
    ~xl_zengjia();
private slots:
    void baocun();
    void fh();
private:
    Ui::xl_zengjia *ui;
};

#endif // XL_ZENGJIA_H
