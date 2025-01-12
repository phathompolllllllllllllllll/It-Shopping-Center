#ifndef BUY_OBCART_H
#define BUY_OBCART_H

#include <QDialog>

namespace Ui {
class Buy_obCart;
}

class Buy_obCart : public QDialog
{
    Q_OBJECT

public:
    explicit Buy_obCart(QWidget *parent = nullptr);
    ~Buy_obCart();

private:
    Ui::Buy_obCart *ui;
};

#endif // BUY_OBCART_H
