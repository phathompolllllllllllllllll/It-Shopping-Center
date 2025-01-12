#include "desktop.h"
#include "ui_desktop.h"

desktop::desktop(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::desktop)
{
    ui->setupUi(this);
}

desktop::~desktop()
{
    delete ui;
}
