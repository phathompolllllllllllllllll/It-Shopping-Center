#include "show_info_handheld.h"
#include "ui_show_info_handheld.h"

Show_info_Handheld::Show_info_Handheld(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::Show_info_Handheld)
{
    ui->setupUi(this);
    cata = cat;

    for(Handheld &i : Handheld::handheld_vec){
        if(i.getID() == cata){
            ui->brand_lineEdit->setText(QString::fromStdString(i.getBrand()));
            ui->model_lineEdit->setText(QString::fromStdString(i.getModel()));
            ui->quantity_lineEdit->setText(QString::number(i.getQuantity()));
            ui->resolution_lineEdit_1->setText(QString::number(std::get<0>(i.getResolution())));
            ui->resolution_lineEdit_2->setText(QString::number(std::get<1>(i.getResolution())));
            ui->price_lineEdit->setText(QString::number(i.getPrice()));
            ui->des_lineEdit->setText(QString::fromStdString(i.getDescription()));
            ui->main_processor_lineEdit->setText(QString::fromStdString(i.getMainProcessor()));
            ui->graphiv_processor_lineEdit->setText(QString::fromStdString(i.getGraphicsProcessor()));
            ui->storage_lineEdit->setText(QString::number(i.getStorageCapacity()));
            ui->USB_lineEdit->setText(QString::fromStdString(i.getUSB()));
            ui->display_lineEdit->setText(QString::fromStdString(i.getDisplay()));
            ui->input_output_port->setText(QString::fromStdString(i.getInputOutputPort()));
            ui->wifi_lineEdit->setText(QString::fromStdString(i.getWifi()));
            ui->weight_lineEdit->setText(QString::number(i.getWeight()));
            ui->bluetooth_lineEdit->setText(QString::fromStdString(i.getBluetooth()));
            ui->power_consum->setText(QString::number(i.getPowerConsumption()));
            ui->controller_vibra->setChecked(i.getControllerVibration());
            ui->have_tv_mode->setChecked(i.getTVMode());
            ui->battery_lineEdit->setText(QString::fromStdString(i.getBattery()));
            ui->power_supply->setText(QString::fromStdString(i.getPowerSupply()));
            ui->headphone_jack->setText(QString::fromStdString(i.getHeadphoneJack()));
            ui->microSD_slot->setText(QString::number(i.getMicroSDSlot()));
            ui->size->setText(QString::fromStdString(i.getSize()));
        }
    }
}

Show_info_Handheld::~Show_info_Handheld()
{
    delete ui;
}
