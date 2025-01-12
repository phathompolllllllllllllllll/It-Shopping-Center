#include "signin.h"
#include "./ui_signin.h"
#include <QMessageBox>

const std::string dev_username = "bew";
const std::string dev_password = "1";

Signin::Signin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Signin)
{
    ui->setupUi(this);
    HDD::readData();
    SSD::readData();
    CoolingUnit::readData();
    CPU::readData();
    GPU::readData();
    Memory::readData();
    Motherboard::readData();
    PCCase::readData();
    PSU::readData();
    Handheld::readData();
    Stationed::readData();
    Desktop::readData();
    Laptop::readData();
    Earbuds::readData();
    Earphones::readData();
    Headphones::readData();
    Headset::readData();
    Microphone::readData();
    Speakers::readData();
    Display::readData();
    Keyboard::readData();
    Mouse::readData();
    Portable_HDD::readData();
    Printer::readData();
    SdCard::readData();
    Touchpad::readData();
    UsbDrive::readData();
    Webcam::readData();
    Wire::readData();
    Smartphones::readData();
    Smartwatch::readData();
    Tablet::readData();
    VR::readData();
}

Signin::~Signin()
{
    delete ui;
}

void Signin::on_btn_login_dev_clicked()
{
    std::string u_input, p_input;
    u_input = ui->user_entry->text().toStdString();
    p_input = ui->user_password->text().toStdString();
    if (u_input == dev_username && p_input == dev_password) {
        this->hide();
        develop_page develop_obj(this);
        develop_obj.setModal(true);
        develop_obj.exec();
        //hide old pages and open new pages
    } else {
        QMessageBox::information(this, "Login", "Invalid credentials.");
    }
}


void Signin::on_btn_customer_clicked()
{
    this->hide();
    customer_page customer_obj(this);
    customer_obj.setModal(true);
    customer_obj.exec();
}

