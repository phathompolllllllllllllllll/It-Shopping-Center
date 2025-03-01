#include "show_info_laptop.h"
#include "ui_show_info_laptop.h"

Show_info_laptop::Show_info_laptop(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::Show_info_laptop)
{
    ui->setupUi(this);
    cata = cat;

    for(Laptop &i : Laptop::laptop_vec){
        if(i.getID() == cata){
            ui->brand_lineEdit->setText(QString::fromStdString(i.getBrand()));
            ui->model_lineEdit->setText(QString::fromStdString(i.getModel()));
            ui->quantity_lineEdit->setText(QString::number(i.getQuantity()));
            ui->price_lineEdit->setText(QString::number(i.getPrice()));
            ui->des_lineEdit->setText(QString::fromStdString(i.getDescription()));
            ui->cpu->setText(QString::fromStdString(i.getCPU()));
            ui->gpu->setText(QString::fromStdString(i.getGPU()));
            ui->memory->setText(QString::fromStdString(i.getMemory()));
            ui->os_lineEdit->setText(QString::fromStdString(i.getOS()));
            ui->display->setText(QString::fromStdString(i.getDisplay()));
            ui->battery_watt->setText(QString::number(std::get<0>(i.getBattery())));
            ui->battery_cell->setText(QString::number(std::get<1>(i.getBattery())));
            ui->dimension1_lineEdit->setText(QString::number(std::get<0>(i.getDimensions())));
            ui->dimension2_lineEdit->setText(QString::number(std::get<1>(i.getDimensions())));
            ui->dimension3_lineEdit->setText(QString::number(std::get<2>(i.getDimensions())));
            ui->dimension4_lineEdit_2->setText(QString::number(std::get<3>(i.getDimensions())));
            ui->weight->setText(QString::number(i.getWeight()));
            ui->touchscreen->setChecked(i.getTouchscreen());
            ui->gaming->setChecked(i.getGaming());
        }
    }
}

Show_info_laptop::~Show_info_laptop()
{
    delete ui;
}
