#include "show_info_tablet.h"
#include "ui_show_info_tablet.h"

Show_info_tablet::Show_info_tablet(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::Show_info_tablet)
{
    ui->setupUi(this);
    cata = cat;

    for(Tablet &i : Tablet::tablet_vec){
        if(i.getID() == cata){
            ui->brand_lineEdit->setText(QString::fromStdString(i.getBrand()));
            ui->model_lineEdit->setText(QString::fromStdString(i.getModel()));
            ui->quantity_lineEdit->setText(QString::number(i.getQuantity()));
            ui->resolution_lineEdit_1->setText(QString::number(std::get<0>(i.getResolution())));
            ui->resolution_lineEdit_2->setText(QString::number(std::get<1>(i.getResolution())));
            ui->price_lineEdit->setText(QString::number(i.getPrice()));
            ui->des_lineEdit->setText(QString::fromStdString(i.getDescription()));
            ui->processor_lineEdit->setText(QString::fromStdString(i.getProcessor()));
            ui->display_lineEdit->setText(QString::fromStdString(i.getDisplay()));
            ui->os_lineEdit->setText(QString::fromStdString(i.getOs()));
            ui->camera_spec_lineEdit->setText(QString::fromStdString(i.getCamera()));
            ui->storage_lineEdit->setText(QString::fromStdString(i.getStorage()));
            ui->battery_lineEdit->setText(QString::number(i.getBattery()));
            ui->bluetooth_lineEdit->setText(QString::fromStdString(i.getBluetooth()));
            ui->dimension1_lineEdit->setText(QString::number(std::get<0>(i.getDimensions())));
            ui->dimension2_lineEdit->setText(QString::number(std::get<1>(i.getDimensions())));
            ui->dimension3_lineEdit->setText(QString::number(std::get<2>(i.getDimensions())));
            ui->weight_lineEdit->setText(QString::number(i.getWeight()));
            ui->brightness_lineEdit->setText(QString::number(i.getBrightness()));
            ui->wifi_lineEdit->setText(QString::fromStdString(i.getWifi()));
            ui->internal_Memory->setText(QString::fromStdString(i.getInternal_Memory()));
            ui->external_memory_lineEdit->setText(QString::fromStdString(i.getExternal_Memory()));
            ui->speaker_lineEdit->setText(QString::fromStdString(i.getSpeaker()));
            ui->have_pen_with_controller->setChecked(i.getHavePen());
            ui->finger_with_controller->setChecked(std::get<0>(i.getBiometrics()));
            ui->face_with_controller->setChecked(std::get<1>(i.getBiometrics()));
            ui->iris_with_controller->setChecked(std::get<2>(i.getBiometrics()));
            ui->water_proof_with_controller->setChecked(i.getIsWaterproof());

        }
    }
}

Show_info_tablet::~Show_info_tablet()
{
    delete ui;
}
