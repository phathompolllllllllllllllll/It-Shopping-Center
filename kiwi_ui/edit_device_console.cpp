#include "edit_device_console.h"
#include "ui_edit_device_console.h"

edit_device_console::edit_device_console(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::edit_device_console)
{
    ui->setupUi(this);
    cata = cat;
}

edit_device_console::~edit_device_console()
{
    delete ui;
}

void edit_device_console::on_handheld_btn_clicked()
{
    bool c = false;
    for(Handheld h : Handheld::handheld_vec){
        if(h.getID() == cata){
            c = true;
        }
    }
    if(c == true){
        Edit_device_handheld device_handheld(this, cata);
        device_handheld.setModal(true);
        device_handheld.exec();
        this->close();
    } else {
        QMessageBox::information(this, "Error", "Don't have this id in handheld");
    }

}


void edit_device_console::on_Stationed_btn_clicked()
{
    bool c = false;
    for(Stationed h : Stationed::stationed_vec){
        if(h.getID() == cata){
            c = true;
        }
    }
    if(c == true){
        Edit_device_stationed device_stationed(this, cata);
        device_stationed.setModal(true);
        device_stationed.exec();
        this->close();
    } else {
        QMessageBox::information(this, "Error", "Don't have this id in Stationed");
    }

}

