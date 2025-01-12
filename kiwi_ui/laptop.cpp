#include "laptop.h"
#include "ui_laptop.h"

Laptop::Laptop(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Laptop)
{
    ui->setupUi(this);
}

Laptop::~Laptop()
{
    delete ui;
}
