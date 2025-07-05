#ifndef XL_SEEK_H
#define XL_SEEK_H

#include <QWidget>

namespace Ui {
class xl_seek;
}

class xl_seek : public QWidget
{
    Q_OBJECT

public:
    explicit xl_seek(QWidget *parent = nullptr);
    ~xl_seek();
private slots:
    void fh();
    void sc();


private:
    Ui::xl_seek *ui;
};

#endif // XL_SEEK_H
