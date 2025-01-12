#include "add_device_console.h"
#include "ui_add_device_console.h"

add_device_console::add_device_console(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::add_device_console)
{
    ui->setupUi(this);
    cata = cat;
}

add_device_console::~add_device_console()
{
    delete ui;
}

void add_device_console::on_handheld_btn_clicked()
{
    add_device_handheld device_handheld(this, "Handheld");
    device_handheld.setModal(true);
    device_handheld.exec();
    this->close();
}


void add_device_console::on_Stationed_btn_clicked()
{
    add_device_stationed device_stationed(this, "Stationed");
    device_stationed.setModal(true);
    device_stationed.exec();
    this->close();
}

