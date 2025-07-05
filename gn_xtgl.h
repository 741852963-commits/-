#ifndef GN_XTGL_H
#define GN_XTGL_H

#include <QWidget>

namespace Ui {
class gn_xtgl;
}

class gn_xtgl : public QWidget
{
    Q_OBJECT

public:
    explicit gn_xtgl(QWidget *parent = nullptr);
    ~gn_xtgl();

private slots:
    void onPB1();

    void onPB2();

    void onPB3();

private:
    Ui::gn_xtgl *ui;
};

#endif // GN_XTGL_H
