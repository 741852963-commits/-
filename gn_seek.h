#ifndef GN_SEEK_H
#define GN_SEEK_H

#include <QWidget>

namespace Ui {
class gn_seek;
}

class gn_seek : public QWidget
{
    Q_OBJECT

public:
    explicit gn_seek(QWidget *parent = nullptr);
    ~gn_seek();

private slots:
    void fh();
    void sc(int a);

private:
    Ui::gn_seek *ui;
};

#endif // GN_SEEK_H
