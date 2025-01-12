#include "show_info_phone.h"
#include "ui_show_info_phone.h"

Show_info_phone::Show_info_phone(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::Show_info_phone)
{
    ui->setupUi(this);
    cata = cat;

    for(Smartphones &i : Smartphones::smartphones_vec){
        if(i.getID() == cata){
            ui->brand_lineEdit->setText(QString::fromStdString(i.getBrand()));
            ui->model_lineEdit->setText(QString::fromStdString(i.getModel()));
            ui->quantity_lineEdit->setText(QString::number(i.getQuantity()));
            ui->resolution_lineEdit_1->setText(QString::number(std::get<0>(i.getResolution())));
            ui->resolution_lineEdit_2->setText(QString::number(std::get<1>(i.getResolution())));
            ui->price_lineEdit->setText(QString::number(i.getPrice()));
            ui->des_lineEdit->setText(QString::fromStdString(i.getDescription()));
            ui->processor_lineEdit->setText(QString::fromStdString(i.getProcessor()));
            ui->os_lineEdit->setText(QString::fromStdString(i.getOS()));
            ui->charger_lineEdit->setText(QString::fromStdString(i.getCharger()));
            ui->camera_spec_lineEdit->setText(QString::fromStdString(i.getCameraSpec()));
            ui->number_sim_lineEdit->setText(QString::number(i.getNumSim()));
            ui->dimension1_lineEdit->setText(QString::number(std::get<0>(i.getDimensions())));
            ui->dimension2_lineEdit->setText(QString::number(std::get<1>(i.getDimensions())));
            ui->dimension3_lineEdit->setText(QString::number(std::get<2>(i.getDimensions())));
            ui->storage_lineEdit->setText(QString::number(i.getStorage()));
            ui->refresh_rate_lineEdit->setText(QString::number(i.getRefreshRate()));
            ui->wifi_lineEdit->setText(QString::number(i.getWifi()));
            ui->brightness_lineEdit->setText(QString::number(i.getBrightness()));
            ui->bluetooth_lineEdit->setText(QString::number(i.getBluetooth()));
            ui->weight_lineEdit->setText(QString::number(i.getWeight()));
            ui->battery_lineEdit->setText(QString::number(i.getBattery()));
            ui->finger_with_controller->setChecked(std::get<0>(i.getBiometrics()));
            ui->face_with_controller->setChecked(std::get<1>(i.getBiometrics()));
            ui->iris_with_controller->setChecked(std::get<2>(i.getBiometrics()));
            ui->have_dual_sim_with_controller->setChecked(i.getDualSim());
            ui->have_micro_sim_with_controller->setChecked(i.getMicroSD());
            ui->have_jack_with_controller->setChecked(i.getJack());
            ui->has_pen_with_controller->setChecked(i.getHasPen());
        }
    }
}

Show_info_phone::~Show_info_phone()
{
    delete ui;
}
