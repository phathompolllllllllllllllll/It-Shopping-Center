#ifndef DELETE_THING_INCART_H
#define DELETE_THING_INCART_H

#include <QDialog>
#include "cart.h"
#include "add_to_cart.h"

namespace Ui {
class Delete_thing_inCart;
}

class Delete_thing_inCart : public QDialog
{
    Q_OBJECT

public:
    explicit Delete_thing_inCart(QWidget *parent = nullptr);
    ~Delete_thing_inCart();

private slots:
    void on_ok_btn_clicked();

private:
    Ui::Delete_thing_inCart *ui;
};

#endif // DELETE_THING_INCART_H
