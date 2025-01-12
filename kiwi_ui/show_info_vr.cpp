#include "show_info_vr.h"
#include "ui_show_info_vr.h"

Show_info_VR::Show_info_VR(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::Show_info_VR)
{
    ui->setupUi(this);
    cata = cat;

    for(VR &i : VR::vr_vec){
        if(i.getID() == cata){
            ui->brand_lineEdit->setText(QString::fromStdString(i.getBrand()));
            ui->model_lineEdit->setText(QString::fromStdString(i.getModel()));
            ui->quantity_lineEdit->setText(QString::number(i.getQuantity()));
            ui->resolution_lineEdit_1->setText(QString::number(std::get<0>(i.getResolution())));
            ui->resolution_lineEdit_2->setText(QString::number(std::get<1>(i.getResolution())));
            ui->price_lineEdit->setText(QString::number(i.getPrice()));
            ui->des_lineEdit->setText(QString::fromStdString(i.getDescription()));
            ui->display_lineEdit->setText(QString::fromStdString(i.getDisplay()));
            ui->usb_lineEdit->setText(QString::fromStdString(i.getHaveUsbCable()));
            ui->max_refreah_lineEdit->setText(QString::number(i.getRefreshRate()));
            ui->field_v_lineEdit->setText(QString::number(i.getFieldOfView()));
            ui->size_lineEdit->setText(QString::number(i.getSizeDisplayInch()));
            ui->with_controller->setChecked(i.getWithControllers());

        }
    }
}

Show_info_VR::~Show_info_VR()
{
    delete ui;
}
