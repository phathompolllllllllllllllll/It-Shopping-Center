#include "show_info_destop.h"
#include "ui_show_info_destop.h"

Show_info_Destop::Show_info_Destop(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::Show_info_Destop)
{
    ui->setupUi(this);
    cata = cat;

    for(Desktop &i : Desktop::desktop_vec){
        if(i.getID() == cata){
            ui->brand_lineEdit->setText(QString::fromStdString(i.getBrand()));
            ui->model_lineEdit->setText(QString::fromStdString(i.getModel()));
            ui->des_lineEdit->setText(QString::fromStdString(i.getDescription()));
            ui->price_lineEdit->setText(QString::number(i.getPrice()));
            ui->quantity_lineEdit->setText(QString::number(i.getQuantity()));
            ui->cpu->setText(QString::fromStdString(i.getCooling()));
            ui->gpu->setText(QString::fromStdString(i.getGPU()));
            ui->memory->setText(QString::fromStdString(i.getMemory()));
            ui->os_lineEdit->setText(QString::fromStdString(i.getOS()));
            ui->motherboard->setText(QString::fromStdString(i.getMotherboard()));
            ui->psu->setText(QString::fromStdString(i.getPSU()));
            ui->pc_case->setText(QString::fromStdString(i.getPCCase()));
            ui->cooling->setText(QString::fromStdString(i.getCooling()));

        }
    }

}

Show_info_Destop::~Show_info_Destop()
{
    delete ui;
}

