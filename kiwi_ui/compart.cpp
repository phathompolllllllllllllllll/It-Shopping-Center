#include "compart.h"
#include "ui_compart.h"

Compart::Compart(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Compart)
{
    ui->setupUi(this);
}

Compart::~Compart()
{
    delete ui;
}
