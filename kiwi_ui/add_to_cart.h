#ifndef ADD_TO_CART_H
#define ADD_TO_CART_H

#include <QDialog>
#include "all_list.h"
#include <QMessageBox>

namespace Ui {
class Add_to_Cart;
}

class Add_to_Cart : public QDialog
{
    Q_OBJECT

public:
    explicit Add_to_Cart(QWidget *parent = nullptr);
    ~Add_to_Cart();
    static std::vector<std::tuple<std::string, int>> id_in_cart;

private slots:
    void on_ok_btn_clicked();

private:
    Ui::Add_to_Cart *ui;
};

#endif // ADD_TO_CART_H
