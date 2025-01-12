#include "edit_main.h"
#include "ui_edit_main.h"

Edit_main::Edit_main(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::Edit_main)
{
    ui->setupUi(this);
    this->cata = cat;
}

Edit_main::~Edit_main()
{
    delete ui;
}

std::string id_in;
void Edit_main::on_ok_btn_clicked()
{
    if (cata == "VR") {
        id_in = ui->ID_in->text().toStdString();
        qDebug() << id_in;
        // for (VR i : VR::vr_vec) {
        //     if (i.getID() == id_in){

        //     }
        // }
        bool check = false;
        for(VR &i : VR::vr_vec){
            if(i.getID() == id_in){
                check = true;
            }
        }
        if(check == true){
            Edit_device edit_device_vr(this, id_in);
            edit_device_vr.setModal(true);
            edit_device_vr.exec();
        } else{
            QMessageBox::information(this, "Error", "Don't have this id");
        }

    }
    if (cata == "Phone") {
        id_in = ui->ID_in->text().toStdString();
        bool check = false;
        for(Smartphones &i : Smartphones::smartphones_vec){
            if(i.getID() == id_in){
                check = true;
            }
        }
        if(check == true){
            edit_device_phones edit_device_phone(this, id_in);
            edit_device_phone.setModal(true);
            edit_device_phone.exec();
        } else{
            QMessageBox::information(this, "Error", "Don't have this id");
        }
    }
    if(cata == "Tablet") {
        id_in = ui->ID_in->text().toStdString();
        bool check = false;
        for(Tablet &i : Tablet::tablet_vec){
            if(i.getID() == id_in){
                check = true;
            }
        }
        if(check == true){
            Edit_device_tablet edit_device_tablet(this, id_in);
            edit_device_tablet.setModal(true);
            edit_device_tablet.exec();
        } else{
            QMessageBox::information(this, "Error", "Don't have this id");
        }
    }
    if(cata == "Desktop") {
        id_in = ui->ID_in->text().toStdString();
        bool check = false;
        for(Desktop &i : Desktop::desktop_vec){
            if(i.getID() == id_in){
                check = true;
            }
        }
        if(check == true){
            edit_device_desktop edit_device_desktop(this, id_in);
            edit_device_desktop.setModal(true);
            edit_device_desktop.exec();
        } else{
            QMessageBox::information(this, "Error", "Don't have this id");
        }
    }
    if(cata == "Laptop"){
        id_in = ui->ID_in->text().toStdString();
        bool check = false;
        for(Laptop &i : Laptop::laptop_vec){
            if(i.getID() == id_in){
                check = true;
            }
        }
        if(check == true){
            edit_device_laptop edit_device_laptop(this, id_in);
            edit_device_laptop.setModal(true);
            edit_device_laptop.exec();
        } else{
            QMessageBox::information(this, "Error", "Don't have this id");
        }
    }
    if(cata == "Watch"){
        id_in = ui->ID_in->text().toStdString();
        bool check = false;
        for(Smartwatch &i : Smartwatch::smartwatch_vec){
            if(i.getID() == id_in){
                check = true;
            }
        }
        if(check == true){
            edit_device_watch edit_device_watch(this, id_in);
            edit_device_watch.setModal(true);
            edit_device_watch.exec();
        } else{
            QMessageBox::information(this, "Error", "Don't have this id");
        }
    }
    if(cata == "Console"){
        id_in = ui->ID_in->text().toStdString();
        bool check = false;
        for(Handheld &i : Handheld::handheld_vec){
            if(i.getID() == id_in){
                check = true;
            }
        }
        for(Stationed &i : Stationed::stationed_vec){
            if(i.getID() == id_in){
                check = true;
            }
        }
        if(check == true){
            edit_device_console edit_device_console(this, id_in);
            edit_device_console.setModal(true);
            edit_device_console.exec();
        } else{
            QMessageBox::information(this, "Error", "Don't have this id");
        }
    }

    this->close();

}

