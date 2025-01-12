#include "show_info_watch.h"
#include "ui_show_info_watch.h"

Show_info_Watch::Show_info_Watch(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::Show_info_Watch)
{
    ui->setupUi(this);
    cata = cat;

    for(Smartwatch &i : Smartwatch::smartwatch_vec){
        if(i.getID() == cata){
            ui->brand_lineEdit_2->setText(QString::fromStdString(i.getBrand()));
            ui->model_lineEdit_2->setText(QString::fromStdString(i.getModel()));
            ui->quantity_lineEdit_2->setText(QString::number(i.getQuantity()));
            ui->price_lineEdit_2->setText(QString::number(i.getPrice()));
            ui->des_lineEdit_2->setText(QString::fromStdString(i.getDescription()));
            ui->display_lineEdit_2->setText(QString::fromStdString(i.getDisplay()));
            ui->has_sim_2->setChecked(i.getSim());
            ui->bluetooth_lineEdit_2->setText(QString::number(i.getHaveBluetooth()));
            ui->wifi_lineEdit_2->setText(QString::number(i.getWifi()));
            ui->capacity_2->setText(QString::number(i.getCapacity()));
            ui->screen_size_2->setText(QString::number(i.getScreenSize()));
            ui->case_size_2->setText(QString::number(i.getCaseSize()));
            ui->brightness_lineEdit_2->setText(QString::number(i.getBrightness()));
            ui->water_resistance_2->setText(QString::number(i.getWaterResistance()));
            ui->weight_lineEdit_2->setText(QString::number(i.getWeight()));
            ui->battery_lineEdit_2->setText(QString::number(i.getBattery()));
            ui->has_heartrate_monitering_2->setChecked(i.getHeartrateMonitoring());
            ui->has_mic_2->setChecked(i.getHasMicrophones());
            ui->has_gps_2->setChecked(i.getHasGps());
            ui->has_blood_O2_sensor_2->setChecked(i.getHasBloodOxygenSensor());
            ui->has_speaker_2->setChecked(i.getHasSpeaker());

        }
    }


}

Show_info_Watch::~Show_info_Watch()
{
    delete ui;
}
