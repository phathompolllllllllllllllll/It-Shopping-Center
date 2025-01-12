#include "develop_page.h"
#include "ui_develop_page.h"
// #include <QPixmap>





develop_page::develop_page(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::develop_page)
{
    std::string total;
    std::ifstream file_in("../txt_files/total_sell.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::getline(file_in, total);
    ui->setupUi(this);
    ui->lineEdit_sale->setText(QString::fromStdString(total));
    file_in.close();

    // QPixmap pix("C:/Users/adam/OneDrive - KMITL/Documents/GitHub/kiwi/dev_visual_im/compart.jpg");
    // int width = ui->compart_im->width();
    // int height = ui->compart_im->height();
    // ui->compart_im->setPixmap(pix.scaled(width, height, Qt::KeepAspectRatio));

}

develop_page::~develop_page()
{
    delete ui;
}



void develop_page::on_vr_btn_clicked()
{
    All_list all(this, "VR");
    all.setModal(true);
    all.exec();

    // Vr vr;
    // vr.setModal(true);
    // vr.exec();
}


void develop_page::on_back_btn_clicked()
{
    this->close();
    parentWidget()->show();
}


void develop_page::on_console_btn_clicked()
{
    All_list all(this, "Console");
    all.setModal(true);
    all.exec();
}


void develop_page::on_desktop_btn_clicked()
{
    All_list all(this, "Desktop");
    all.setModal(true);
    all.exec();
}


void develop_page::on_laptop_btn_clicked()
{
    All_list all(this, "Laptop");
    all.setModal(true);
    all.exec();
}


void develop_page::on_phone_btn_clicked()
{
    All_list all(this, "Phone");
    all.setModal(true);
    all.exec();
}


void develop_page::on_watch_btn_clicked()
{
    All_list all(this, "Watch");
    all.setModal(true);
    all.exec();
}


void develop_page::on_tablet_btn_clicked()
{
    All_list all(this, "Tablet");
    all.setModal(true);
    all.exec();
}


