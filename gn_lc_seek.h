#ifndef GN_LC_SEEK_H
#define GN_LC_SEEK_H

#include <QWidget>
namespace Ui {
class gn_lc_seek;
}

class gn_lc_seek : public QWidget
{
    Q_OBJECT

public:
    explicit gn_lc_seek(QWidget *parent = nullptr);
    ~gn_lc_seek();

private slots:
    void fh();
    void sc1(int a);

private:
    Ui::gn_lc_seek *ui;
};

#endif // GN_LC_SEEK_H
