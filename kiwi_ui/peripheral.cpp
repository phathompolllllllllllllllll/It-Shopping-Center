#include "peripheral.h"
#include "ui_peripheral.h"

Peripheral::Peripheral(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Peripheral)
{
    ui->setupUi(this);
}

Peripheral::~Peripheral()
{
    delete ui;
}
