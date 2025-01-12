#include "delete_thing_incart.h"
#include "ui_delete_thing_incart.h"

Delete_thing_inCart::Delete_thing_inCart(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Delete_thing_inCart)
{
    ui->setupUi(this);
}

Delete_thing_inCart::~Delete_thing_inCart()
{
    delete ui;
}

std::string delete_ob;
int quantityyy;
void Delete_thing_inCart::on_ok_btn_clicked()
{
    bool a;
    delete_ob = ui->ID_in->text().toStdString();
    quantityyy = ui->Quantity->text().toInt(&a);
    bool check = false;
    std::vector<std::tuple<std::string, int>> newv;

    // for(std::tuple<std::string, int>& i : Add_to_Cart::id_in_cart) {
    //     if (std::get<0>(i) == delete_ob && quantityyy > std::get<1>(i)){
    //         QMessageBox::warning(this, "Error", "Invalid quantity please try again.");
    //     }
    // }
    bool have = false;
    for(std::tuple<std::string, int>& i : Add_to_Cart::id_in_cart) {
        if(delete_ob == std::get<0>(i)){
            have = true;
        }
    }
    if(have == false) {
        QMessageBox::warning(this, "Error", "Invalid ID to delete please try again.");
        this->close();
    }

    if(a && quantityyy > 0){
        for(std::tuple<std::string, int>& i : Add_to_Cart::id_in_cart){
            if (std::get<0>(i) == delete_ob && quantityyy <= std::get<1>(i)){
                newv.push_back(std::tuple(delete_ob, std::get<1>(i) - quantityyy));

            } else if(std::get<0>(i) == delete_ob && quantityyy > std::get<1>(i)) {
                QMessageBox::warning(this, "Error", "Invalid quantity please try again.");
                this->close();
            } else {
                newv.push_back(i);
            }

        }
        Add_to_Cart::id_in_cart = newv;

        this->close();
    } else {
            QMessageBox::warning(this, "Error", "Invalid quantity please try again.");
            ui->Quantity->clear();
            ui->ID_in->clear();
    }



}

