#ifndef GONGN_H
#define GONGN_H

#include <QWidget>

namespace Ui {
class gongn;
}

class gongn : public QWidget
{
    Q_OBJECT

public:
    explicit gongn(QWidget *parent = nullptr);
    ~gongn();

private slots:
    void onXTpB();

    void onSJpB();

    void onYCpB();

private:
    Ui::gongn *ui;
};

#endif // GONGN_H
