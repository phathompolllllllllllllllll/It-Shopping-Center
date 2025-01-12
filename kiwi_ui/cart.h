#ifndef CART_H
#define CART_H

#include <QDialog>
#include "all_list.h"
#include <vector>
#include <any>
#include "show_info.h"
#include "add_to_cart.h"
#include "../logic_classes.h"
#include <variant>
#include "delete_thing_incart.h"
#include <fstream>

using DevicesType = std::tuple<std::variant<
    Handheld*,
    Stationed*,
    Laptop*,
    Desktop*,
    Smartphones*,
    Smartwatch*,
    Tablet*,
    VR*>, int>;

namespace Ui {
class Cart;
}

class Cart : public QDialog
{
    Q_OBJECT

public:
    explicit Cart(QWidget *parent = nullptr);
    ~Cart();

private slots:


    void on_delete_btn_clicked();

    void on_Buy_btn_clicked();

private:
    Ui::Cart *ui;
    std::vector<DevicesType> cart;
};

#endif // CART_H
