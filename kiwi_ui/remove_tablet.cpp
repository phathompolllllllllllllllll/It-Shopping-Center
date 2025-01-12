#include "remove_tablet.h"
#include "ui_remove_tablet.h"

Remove_tablet::Remove_tablet(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Remove_tablet)
{
    ui->setupUi(this);
}

Remove_tablet::~Remove_tablet()
{
    delete ui;
}
