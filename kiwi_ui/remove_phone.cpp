#include "remove_phone.h"
#include "ui_remove_phone.h"

Remove_phone::Remove_phone(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::Remove_phone)
{
    ui->setupUi(this);
    cata = cat;
}

Remove_phone::~Remove_phone()
{
    delete ui;
}

std::string id_in_3;
void Remove_phone::on_ok_btn_clicked()
{

}

