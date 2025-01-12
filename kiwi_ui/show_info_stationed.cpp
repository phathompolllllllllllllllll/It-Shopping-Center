#include "show_info_stationed.h"
#include "ui_show_info_stationed.h"

Show_info_Stationed::Show_info_Stationed(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::Show_info_Stationed)
{
    ui->setupUi(this);
    cata = cat;

    for(Stationed &i : Stationed::stationed_vec){
        if(i.getID() == cata){
            ui->brand_lineEdit->setText(QString::fromStdString(i.getBrand()));
            ui->model_lineEdit->setText(QString::fromStdString(i.getModel()));
            ui->quantity_lineEdit->setText(QString::number(i.getQuantity()));
            ui->resolution_lineEdit_1->setText(QString::number(std::get<0>(i.getResolution())));
            ui->resolution_lineEdit_2->setText(QString::number(std::get<1>(i.getResolution())));
            ui->price_lineEdit->setText(QString::number(i.getPrice()));
            ui->des_lineEdit->setText(QString::fromStdString(i.getDescription()));
            ui->SSD->setText(QString::fromStdString(i.getSSD()));
            ui->size->setText(QString::fromStdString(i.getSize()));
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
        }
    }
}

Show_info_Stationed::~Show_info_Stationed()
{
    delete ui;
}
