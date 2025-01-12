#include "add_vr.h"
#include "ui_add_vr.h"

Add_device::Add_device(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::Add_device)
{
    ui->setupUi(this);
    cata = cat;
}

Add_device::~Add_device()
{
    delete ui;
}


std::string brand, model, name, display, type_usb;
int quantity, resolution1, resolution2, max_refreshrate;
double price, field_view, size_display;
bool have_controller = false, have = false;
