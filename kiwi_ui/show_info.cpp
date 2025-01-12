#include "show_info.h"
#include "ui_show_info.h"
#include <QMessageBox>

Show_info::Show_info(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Show_info)
{
    ui->setupUi(this);
}

Show_info::~Show_info()
{
    delete ui;
}

std::string id_in_show;
void Show_info::on_ok_btn_clicked()
{
    id_in_show = ui->ID_in->text().toStdString();
    bool check_vr = false;
    bool check_phone = false;
    bool check_tablet = false;
    bool check_desktop = false;
    bool check_laptop = false;
    bool check_watch = false;
    bool check_handheld = false;
    bool check_stationed = false;
    for(VR &i : VR::vr_vec){
        if(i.getID() == id_in_show){
            check_vr = true;
        }
    }
    for(Smartphones &i : Smartphones::smartphones_vec){
        if(i.getID() == id_in_show){
            check_phone = true;
        }
    }
    for(Tablet &i : Tablet::tablet_vec){
        if(i.getID() == id_in_show){
            check_tablet = true;
        }
    }
    for(Desktop &i : Desktop::desktop_vec){
        if(i.getID() == id_in_show){
            check_desktop = true;
        }
    }
    for(Laptop &i : Laptop::laptop_vec){
        if(i.getID() == id_in_show){
            check_laptop = true;
        }
    }
    for(Smartwatch &i : Smartwatch::smartwatch_vec){
        if(i.getID() == id_in_show){
            check_watch = true;
        }
    }
    for(Handheld &i : Handheld::handheld_vec){
        if(i.getID() == id_in_show){
            check_handheld = true;
        }
    }
    for(Stationed &i : Stationed::stationed_vec){
        if(i.getID() == id_in_show){
            check_stationed = true;
        }
    }

    if (check_vr == true){
        Show_info_VR show_vr(this, id_in_show);
        show_vr.setModal(true);
        show_vr.exec();
    }
    else if (check_phone == true){
        Show_info_phone show_phone(this, id_in_show);
        show_phone.setModal(true);
        show_phone.exec();
    }
    else if (check_tablet == true){
        Show_info_tablet show_tablet(this, id_in_show);
        show_tablet.setModal(true);
        show_tablet.exec();
    }
    else if (check_desktop == true){
        Show_info_Destop show_desktop(this, id_in_show);
        show_desktop.setModal(true);
        show_desktop.exec();
    }
    else if (check_laptop == true){
        Show_info_laptop show_laptop(this, id_in_show);
        show_laptop.setModal(true);
        show_laptop.exec();
    }
    else if (check_watch == true){
        Show_info_Watch show_watch(this, id_in_show);
        show_watch.setModal(true);
        show_watch.exec();

    }
    else if (check_handheld == true){
        Show_info_Handheld show_held(this, id_in_show);
        show_held.setModal(true);
        show_held.exec();
    }
    else if (check_stationed == true){
        Show_info_Stationed show_stationed(this, id_in_show);
        show_stationed.setModal(true);
        show_stationed.exec();
    } else {
        QMessageBox::information(this, "Error", "Invalid ID");
    }

    this->close();
}

