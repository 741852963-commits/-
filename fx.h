#ifndef FX_H
#define FX_H

#include <QWidget>

namespace Ui {
class fx;
}

class fx : public QWidget
{
    Q_OBJECT

public:
    explicit fx(QWidget *parent = nullptr);
    ~fx();
private slots:
    void lc_kl();
    void sx_kl();
    void zd_kl();
    void xia();
    void shang();
    void sx();

private:
    Ui::fx *ui;
};

#endif // FX_H
