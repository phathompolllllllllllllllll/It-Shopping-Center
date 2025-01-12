#include "buy_obcart.h"
#include "ui_buy_obcart.h"

Buy_obCart::Buy_obCart(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Buy_obCart)
{
    ui->setupUi(this);
}

Buy_obCart::~Buy_obCart()
{
    delete ui;
}
