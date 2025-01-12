#include "all_list.h"
#include "ui_all_list.h"
#include "qpushbutton.h"

//declare static variables
std::vector<HDD> HDD::hdd_vec;
std::vector<SSD> SSD::ssd_vec;
std::vector<CoolingUnit> CoolingUnit::cooling_unit_vec;
std::vector<CPU> CPU::cpu_vec;
std::vector<GPU> GPU::gpu_vec;
std::vector<Memory> Memory::memory_vec;
std::vector<Motherboard> Motherboard::motherboard_vec;
std::vector<PCCase> PCCase::pc_case_vec;
std::vector<PSU> PSU::psu_vec;
std::vector<Handheld> Handheld::handheld_vec;
std::vector<Stationed> Stationed::stationed_vec;
std::vector<Desktop> Desktop::desktop_vec;
std::vector<Laptop> Laptop::laptop_vec;
std::vector<Earbuds> Earbuds::earbuds_vec;
std::vector<Earphones> Earphones::earphones_vec;
std::vector<Headphones> Headphones::headphones_vec;
std::vector<Headset> Headset::headset_vec;
std::vector<Microphone> Microphone::microphone_vec;
std::vector<Speakers> Speakers::speakers_vec;
std::vector<Display> Display::display_vec;
std::vector<Keyboard> Keyboard::keyboard_vec;
std::vector<Mouse> Mouse::mouse_vec;
std::vector<Portable_HDD> Portable_HDD::portable_hdd_vec;
std::vector<Printer> Printer::printer_vec;
std::vector<SdCard> SdCard::sd_card_vec;
std::vector<Touchpad> Touchpad::touchpad_vec;
std::vector<UsbDrive> UsbDrive::usb_drive_vec;
std::vector<Webcam> Webcam::webcam_vec;
std::vector<Wire> Wire::wire_vec;
std::vector<Smartphones> Smartphones::smartphones_vec;
std::vector<Smartwatch> Smartwatch::smartwatch_vec;
std::vector<Tablet> Tablet::tablet_vec;
std::vector<VR> VR::vr_vec;
double Devices::total_sales;

All_list::All_list(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::All_list)
{
    cata = cat;
    ui->setupUi(this);

    if (cat == "VR"){
        //?
        // VR::readData();
        ///
        // std::vector<VR> updatev;
        // std::set<std::string> duplicate;
        // for(int j = 0; j < VR::vr_vec.size(); j++){
        //     if(duplicate.count(VR::vr_vec[j].getID()) > 0) {
        //         continue;
        //     }
        //     duplicate.insert(VR::vr_vec[j].getID());
        //     updatev.push_back(VR::vr_vec[j]);
        // }
        // VR::vr_vec = updatev;
        //?
        ///
        // ?std::vector<VR> check;
        // QScrollArea::addWidget(ui->PanelButtonGridLayout);
        QScrollArea *scrollArea = new QScrollArea(this);
        scrollArea->setGeometry(120, 120, 1050, 550);
        QWidget *scrollWidget = new QWidget(scrollArea);
        QVBoxLayout *layout = new QVBoxLayout(scrollWidget);

        // dynamicScroll.append(scrollArea);
        // dynamicQWidget.append(scrollWidget);
        // dynamicQVBoxLayout.append(layout);

        // layout->addWidget(button1);
        // layout->addWidget(button2);
        // std::set<std::string> seenElements;
        // qDebug() << VR::vr_vec.size();
        for (int i = 0; i < VR::vr_vec.size(); i++)
        {
            //? if (seenElements.count(VR::vr_vec[i].getID()) > 0) {
            //     continue;
            //? }
            QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(VR::vr_vec[i].getBrand()) + QString("    Model:  ") + QString::fromStdString(VR::vr_vec[i].getModel()) + QString("    Description:  ") + QString::fromStdString(VR::vr_vec[i].getDescription()) + QString("    Price:  ") + QString::number(VR::vr_vec[i].getPrice()) + QString("    Quantity:  ") + QString::number(VR::vr_vec[i].getQuantity()) + QString("    ID:  ") + QString::fromStdString(VR::vr_vec[i].getID()));

            // Additional properties or customization for the label can be added here
            panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
            panelLabel->setFixedSize(1000, 100);
            layout->addWidget(panelLabel);

            // dynamicLabels.append(panelLabel);
            //? seenElements.insert(VR::vr_vec[i].getID());
            //? check.push_back(VR::vr_vec[i]);


        }
        // Set the scroll area's widget
        scrollArea->setWidget(scrollWidget);



        // for(VR& i : VR::vr_vec){
        //     qDebug() << i.getID();
        // }
        // qDebug() << " ";

        //? VR::vr_vec = check;
        // for(VR& i : check){
        //     qDebug() << i.getID();
        // }
        //? qDebug() << " ";


    } else if (cat == "Phone"){
        // Smartphones::readData();
        ///
        // std::vector<Smartphones> updatev;
        // std::set<std::string> duplicate;
        // for(int j = 0; j < Smartphones::smartphones_vec.size(); j++){
        //     if(duplicate.count(Smartphones::smartphones_vec[j].getID()) > 0) {
        //         continue;
        //     }
        //     duplicate.insert(Smartphones::smartphones_vec[j].getID());
        //     updatev.push_back(Smartphones::smartphones_vec[j]);
        // }
        // Smartphones::smartphones_vec = updatev;
        // ///
        // std::vector<Smartphones> check;
        // QScrollArea::addWidget(ui->PanelButtonGridLayout);
        QScrollArea *scrollArea = new QScrollArea(this);
        scrollArea->setGeometry(120, 120, 1050, 550);
        QWidget *scrollWidget = new QWidget(scrollArea);
        QVBoxLayout *layout = new QVBoxLayout(scrollWidget);

        // dynamicScroll.append(scrollArea);
        // dynamicQWidget.append(scrollWidget);
        // dynamicQVBoxLayout.append(layout);

        // layout->addWidget(button1);
        // layout->addWidget(button2);
        // std::set<std::string> seenElements2;
        // qDebug() << Smartphones::smartphones_vec.size();
        // qDebug() << "Love u ";
        for (int i = 0; i < Smartphones::smartphones_vec.size(); i++)
        {
            // if (seenElements2.count(Smartphones::smartphones_vec[i].getID()) > 0) {
            //     continue;
            // }
            QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Smartphones::smartphones_vec[i].getBrand()) + QString("    Modal:  ") + QString::fromStdString(Smartphones::smartphones_vec[i].getModel()) +  QString("    Description:  ") + QString::fromStdString(Smartphones::smartphones_vec[i].getDescription()) + QString("    Price:  ") + QString::number(Smartphones::smartphones_vec[i].getPrice()) + QString("    Quantity:  ") + QString::number(Smartphones::smartphones_vec[i].getQuantity()) + QString("    ID:  ") + QString::fromStdString(Smartphones::smartphones_vec[i].getID()));

            // Additional properties or customization for the label can be added here
            panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
            panelLabel->setFixedSize(1000, 100);
            layout->addWidget(panelLabel);

            // dynamicLabels.append(panelLabel);
            // seenElements2.insert(Smartphones::smartphones_vec[i].getID());
            // check.push_back(Smartphones::smartphones_vec[i]);



        }
        // Set the scroll area's widget
        scrollArea->setWidget(scrollWidget);

        // for(Smartphones& i : Smartphones::smartphones_vec){
        //     qDebug() << i.getID();
        // }
        // qDebug() << " ";

        // Smartphones::smartphones_vec = check;
        // for(Smartphones& i : Smartphones::smartphones_vec){
        //     qDebug() << i.getID();
        // }
        // qDebug() << " ";

    } else if (cat == "Tablet"){
        // Tablet::readData();
        ///
        // std::vector<Tablet> updatev;
        // std::set<std::string> duplicate;
        // for(int j = 0; j < Tablet::tablet_vec.size(); j++){
        //     if(duplicate.count(Tablet::tablet_vec[j].getID()) > 0) {
        //         continue;
        //     }
        //     duplicate.insert(Tablet::tablet_vec[j].getID());
        //     updatev.push_back(Tablet::tablet_vec[j]);
        // }
        // Tablet::tablet_vec = updatev;
        // ///
        // std::vector<Tablet> check;
        // QScrollArea::addWidget(ui->PanelButtonGridLayout);
        QScrollArea *scrollArea = new QScrollArea(this);
        scrollArea->setGeometry(120, 120, 1050, 550);
        QWidget *scrollWidget = new QWidget(scrollArea);
        QVBoxLayout *layout = new QVBoxLayout(scrollWidget);

        // layout->addWidget(button1);
        // layout->addWidget(button2);
        // dynamicScroll.append(scrollArea);
        // dynamicQWidget.append(scrollWidget);
        // dynamicQVBoxLayout.append(layout);

        // std::set<std::string> seenElements;
        // qDebug() << Tablet::tablet_vec.size();

        for (int i = 0; i < Tablet::tablet_vec.size(); i++)
        {
            // if (seenElements.count(Tablet::tablet_vec[i].getID()) > 0) {
            //     continue;
            // }
            QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Tablet::tablet_vec[i].getBrand()) + QString("    Modal:  ") + QString::fromStdString(Tablet::tablet_vec[i].getModel())+ QString("    Description:  ") + QString::fromStdString(Tablet::tablet_vec[i].getDescription()) + QString("    Price:  ") + QString::number(Tablet::tablet_vec[i].getPrice()) + QString("    Quantity:  ") + QString::number(Tablet::tablet_vec[i].getQuantity()) + QString("    ID:  ") + QString::fromStdString(Tablet::tablet_vec[i].getID()));

            // Additional properties or customization for the label can be added here
            panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
            panelLabel->setFixedSize(1000, 100);
            layout->addWidget(panelLabel);

            // dynamicLabels.append(panelLabel);
            // seenElements.insert(Tablet::tablet_vec[i].getID());
            // check.push_back(Tablet::tablet_vec[i]);



        }
        // Set the scroll area's widget
        scrollArea->setWidget(scrollWidget);

        // for(Tablet& i : Tablet::tablet_vec){
        //     qDebug() << i.getID();
        // }
        // qDebug() << " ";

        // Tablet::tablet_vec = check;
        // for(Tablet& i : check){
        //     qDebug() << i.getID();
        // }
        // qDebug() << " ";

    } else if (cat == "Desktop"){
        // Desktop::readData();
        // std::vector<Desktop> updatev;
        // std::set<std::string> duplicate;
        // for(int j = 0; j < Desktop::desktop_vec.size(); j++){
        //     if(duplicate.count(Desktop::desktop_vec[j].getID()) > 0) {
        //         continue;
        //     }
        //     duplicate.insert(Desktop::desktop_vec[j].getID());
        //     updatev.push_back(Desktop::desktop_vec[j]);
        // }
        // Desktop::desktop_vec = updatev;
        // ///
        // std::vector<Desktop> check;
        // QScrollArea::addWidget(ui->PanelButtonGridLayout);
        QScrollArea *scrollArea = new QScrollArea(this);
        scrollArea->setGeometry(120, 120, 1050, 550);
        QWidget *scrollWidget = new QWidget(scrollArea);
        QVBoxLayout *layout = new QVBoxLayout(scrollWidget);

        // layout->addWidget(button1);
        // layout->addWidget(button2);
        // dynamicScroll.append(scrollArea);
        // dynamicQWidget.append(scrollWidget);
        // dynamicQVBoxLayout.append(layout);

        // std::set<std::string> seenElements;
        // qDebug() << Desktop::desktop_vec.size();

        for (int i = 0; i < Desktop::desktop_vec.size(); i++)
        {
            // if (seenElements.count(Desktop::desktop_vec[i].getID()) > 0) {
            //     continue;
            // }
            QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Desktop::desktop_vec[i].getBrand()) + QString("    Model:  ") + QString::fromStdString(Desktop::desktop_vec[i].getModel()) + QString("    Description:  ") + QString::fromStdString(Desktop::desktop_vec[i].getDescription()) + QString("    Price:  ") + QString::number(Desktop::desktop_vec[i].getPrice()) + QString("    Quantity:  ") + QString::number(Desktop::desktop_vec[i].getQuantity()) + QString("    ID:  ") + QString::fromStdString(Desktop::desktop_vec[i].getID()));

            // Additional properties or customization for the label can be added here
            panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
            panelLabel->setFixedSize(1000, 100);
            layout->addWidget(panelLabel);

            // dynamicLabels.append(panelLabel);
            // seenElements.insert(Desktop::desktop_vec[i].getID());
            // check.push_back(Desktop::desktop_vec[i]);



        }
        // Set the scroll area's widget
        scrollArea->setWidget(scrollWidget);

        // for(Desktop& i : Desktop::desktop_vec){
        //     qDebug() << i.getID();
        // }
        // qDebug() << " ";

        // Desktop::desktop_vec = check;
        // for(Desktop& i : check){
        //     qDebug() << i.getID();
        // }
        // qDebug() << " ";

    } else if (cat == "Laptop"){
        // Laptop::readData();
        // std::vector<Laptop> updatev;
        // std::set<std::string> duplicate;
        // for(int j = 0; j < Laptop::laptop_vec.size(); j++){
        //     if(duplicate.count(Laptop::laptop_vec[j].getID()) > 0) {
        //         continue;
        //     }
        //     duplicate.insert(Laptop::laptop_vec[j].getID());
        //     updatev.push_back(Laptop::laptop_vec[j]);
        // }
        // Laptop::laptop_vec = updatev;
        // ///
        // std::vector<Laptop> check;
        // QScrollArea::addWidget(ui->PanelButtonGridLayout);
        QScrollArea *scrollArea = new QScrollArea(this);
        scrollArea->setGeometry(120, 120, 1050, 550);
        QWidget *scrollWidget = new QWidget(scrollArea);
        QVBoxLayout *layout = new QVBoxLayout(scrollWidget);

        // layout->addWidget(button1);
        // layout->addWidget(button2);
        // dynamicScroll.append(scrollArea);
        // dynamicQWidget.append(scrollWidget);
        // dynamicQVBoxLayout.append(layout);

        // std::set<std::string> seenElements;
        // qDebug() << Laptop::laptop_vec.size();

        for (int i = 0; i < Laptop::laptop_vec.size(); i++)
        {
            // if (seenElements.count(Laptop::laptop_vec[i].getID()) > 0) {
            //     continue;
            // }
            QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Laptop::laptop_vec[i].getBrand()) + QString("    Model:  ") + QString::fromStdString(Laptop::laptop_vec[i].getModel()) + QString("    Description:  ") + QString::fromStdString(Laptop::laptop_vec[i].getDescription()) + QString("    Price:  ") + QString::number(Laptop::laptop_vec[i].getPrice()) + QString("    Quantity:  ") + QString::number(Laptop::laptop_vec[i].getQuantity()) + QString("    ID:  ") + QString::fromStdString(Laptop::laptop_vec[i].getID()));

            // Additional properties or customization for the label can be added here
            panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
            panelLabel->setFixedSize(1000, 100);
            layout->addWidget(panelLabel);

            // dynamicLabels.append(panelLabel);
            // seenElements.insert(Laptop::laptop_vec[i].getID());
            // check.push_back(Laptop::laptop_vec[i]);



        }
        // Set the scroll area's widget
        scrollArea->setWidget(scrollWidget);

        // for(Laptop& i : Laptop::laptop_vec){
        //     qDebug() << i.getID();
        // }
        // qDebug() << " ";

        // Laptop::laptop_vec = check;
        // for(Laptop& i : check){
        //     qDebug() << i.getID();
        // }
        // qDebug() << " ";

    } else if (cat == "Watch"){
        // Smartwatch::readData();
        // std::vector<Smartwatch> updatev;
        // std::set<std::string> duplicate;
        // for(int j = 0; j < Smartwatch::smartwatch_vec.size(); j++){
        //     if(duplicate.count(Smartwatch::smartwatch_vec[j].getID()) > 0) {
        //         continue;
        //     }
        //     duplicate.insert(Smartwatch::smartwatch_vec[j].getID());
        //     updatev.push_back(Smartwatch::smartwatch_vec[j]);
        // }
        // Smartwatch::smartwatch_vec = updatev;
        // ///
        // std::vector<Smartwatch> check;
        // QScrollArea::addWidget(ui->PanelButtonGridLayout);
        QScrollArea *scrollArea = new QScrollArea(this);
        scrollArea->setGeometry(120, 120, 1050, 550);
        QWidget *scrollWidget = new QWidget(scrollArea);
        QVBoxLayout *layout = new QVBoxLayout(scrollWidget);

        // layout->addWidget(button1);
        // layout->addWidget(button2);
        // dynamicScroll.append(scrollArea);
        // dynamicQWidget.append(scrollWidget);
        // dynamicQVBoxLayout.append(layout);

        // std::set<std::string> seenElements;
        // qDebug() << Smartwatch::smartwatch_vec.size();

        for (int i = 0; i < Smartwatch::smartwatch_vec.size(); i++)
        {
            // if (seenElements.count(Smartwatch::smartwatch_vec[i].getID()) > 0) {
            //     continue;
            // }
            QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Smartwatch::smartwatch_vec[i].getBrand()) + QString("    Model:  ") + QString::fromStdString(Smartwatch::smartwatch_vec[i].getModel()) + QString("    Description:  ") + QString::fromStdString(Smartwatch::smartwatch_vec[i].getDescription()) + QString("    Price:  ") + QString::number(Smartwatch::smartwatch_vec[i].getPrice()) + QString("    Quantity:  ") + QString::number(Smartwatch::smartwatch_vec[i].getQuantity()) + QString("    ID:  ") + QString::fromStdString(Smartwatch::smartwatch_vec[i].getID()));

            // Additional properties or customization for the label can be added here
            panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
            panelLabel->setFixedSize(1000, 100);
            layout->addWidget(panelLabel);

            // dynamicLabels.append(panelLabel);
            // seenElements.insert(Smartwatch::smartwatch_vec[i].getID());
            // check.push_back(Smartwatch::smartwatch_vec[i]);

        }
        // Set the scroll area's widget
        scrollArea->setWidget(scrollWidget);

        // for(Smartwatch& i : Smartwatch::smartwatch_vec){
        //     qDebug() << i.getID();
        // }
        // qDebug() << " ";

        // Smartwatch::smartwatch_vec = check;
        // for(Smartwatch& i : check){
        //     qDebug() << i.getID();
        // }
        // qDebug() << " ";

    }  else if (cat == "Console"){
        QScrollArea *scrollArea = new QScrollArea(this);
        scrollArea->setGeometry(120, 120, 1050, 550);
        QWidget *scrollWidget = new QWidget(scrollArea);
        QVBoxLayout *layout = new QVBoxLayout(scrollWidget);
        // std::set<std::string> seenElements;
        // qDebug() << VR::vr_vec.size();
        for (int i = 0; i < Handheld::handheld_vec.size(); i++)
        {
            //? if (seenElements.count(VR::vr_vec[i].getID()) > 0) {
            //     continue;
            //? }
            QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Handheld::handheld_vec[i].getBrand()) + QString("    Model:  ") + QString::fromStdString(Handheld::handheld_vec[i].getModel()) + QString("    Description:  ") + QString::fromStdString(Handheld::handheld_vec[i].getDescription()) + QString("    Price:  ") + QString::number(Handheld::handheld_vec[i].getPrice()) + QString("    Quantity:  ") + QString::number(Handheld::handheld_vec[i].getQuantity()) + QString("    ID:  ") + QString::fromStdString(Handheld::handheld_vec[i].getID()));

            // Additional properties or customization for the label can be added here
            panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
            panelLabel->setFixedSize(1000, 100);
            layout->addWidget(panelLabel);

            // dynamicLabels.append(panelLabel);
            //? seenElements.insert(VR::vr_vec[i].getID());
            //? check.push_back(VR::vr_vec[i]);


        }
        for (int j = 0; j < Stationed::stationed_vec.size(); j++)
        {
            QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Stationed::stationed_vec[j].getBrand()) + QString("    Model:  ") + QString::fromStdString(Stationed::stationed_vec[j].getModel()) + QString("    Description:  ") + QString::fromStdString(Stationed::stationed_vec[j].getDescription()) + QString("    Price:  ") + QString::number(Stationed::stationed_vec[j].getPrice()) + QString("    Quantity:  ") + QString::number(Stationed::stationed_vec[j].getQuantity()) + QString("    ID:  ") + QString::fromStdString(Stationed::stationed_vec[j].getID()));
            panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
            panelLabel->setFixedSize(1000, 100);
            layout->addWidget(panelLabel);
        }
        // Set the scroll area's widget
        scrollArea->setWidget(scrollWidget);



        // for(VR& i : VR::vr_vec){
        //     qDebug() << i.getID();
        // }
        // qDebug() << " ";

    }



    connect(this, &All_list::destroyed, this, [this]() {
        qDebug() << "Cleaning up...";

        // Destroy dynamically created labels
        for (QLabel *label : dynamicLabels)
        {
            delete label;
        }
        for (QScrollArea *scroll : dynamicScroll)
        {
            delete scroll;
        }
        for (QWidget *widget : dynamicQWidget)
        {
            delete widget;
        }
        for (QVBoxLayout *layout: dynamicQVBoxLayout)
        {
            delete layout;
        }
    });


}

All_list::~All_list()
{
    for (QLabel *label : dynamicLabels) {
        delete label;
    }

}

void All_list::closeEvent(QCloseEvent *event) {
    event->ignore();
    close();
}

void All_list::on_add_btn_clicked()
{
    if (cata == "VR"){
        Add_device_vr device_vr(this, "VR");
        device_vr.setModal(true);
        device_vr.exec();
    }
    if (cata == "Phone"){
        add_device_phone device_phone(this, "Phone");
        device_phone.setModal(true);
        device_phone.exec();
    }
    if (cata == "Tablet"){
        add_device_tablet device_tablet(this, "Tablet");
        device_tablet.setModal(true);
        device_tablet.exec();

    }
    if (cata == "Desktop"){
        Add_device_desktop device_desktop(this, "Desktop");
        device_desktop.setModal(true);
        device_desktop.exec();
    }
    if (cata == "Laptop"){
        add_device_laptop device_laptop(this, "Laptop");
        device_laptop.setModal(true);
        device_laptop.exec();
    }
    if (cata == "Watch"){
        add_device_watch device_watch(this, "Watch");
        device_watch.setModal(true);
        device_watch.exec();
    }
    if (cata == "Console"){
        add_device_console device_console(this, "Console");
        device_console.setModal(true);
        device_console.exec();
    }

}


void All_list::on_edit_btn_clicked()
{
    if (cata == "VR"){
        Edit_main edit_main(this, "VR");
        edit_main.setModal(true);
        edit_main.exec();
    }
    if (cata == "Phone"){
        Edit_main editmain(this, "Phone");
        editmain.setModal(true);
        editmain.exec();
    }
    if (cata == "Tablet"){
        Edit_main editmain(this, "Tablet");
        editmain.setModal(true);
        editmain.exec();
    }
    if (cata == "Desktop"){
        Edit_main editmain(this, "Desktop");
        editmain.setModal(true);
        editmain.exec();
    }
    if (cata == "Laptop"){
        Edit_main editmain(this, "Laptop");
        editmain.setModal(true);
        editmain.exec();
    }
    if (cata == "Watch"){
        Edit_main editmain(this, "Watch");
        editmain.setModal(true);
        editmain.exec();
    }
    if (cata == "Console"){
        Edit_main editmain(this, "Console");
        editmain.setModal(true);
        editmain.exec();
    }

}



void All_list::on_remove_btn_clicked()
{
    // for(VR& i : VR::vr_vec){
    //     qDebug() << i.getID();
    // }
    if (cata == "VR"){
        Remove_vr remove_vr(this, "VR");
        remove_vr.setModal(true);
        remove_vr.exec();
    }
    if (cata == "Phone"){
        Remove_vr remove_phone(this, "Phone");
        remove_phone.setModal(true);
        remove_phone.exec();
    }
    if (cata == "Tablet"){
        Remove_vr remove_tablet(this, "Tablet");
        remove_tablet.setModal(true);
        remove_tablet.exec();
    }
    if (cata == "Desktop"){
        Remove_vr remove_desktop(this, "Desktop");
        remove_desktop.setModal(true);
        remove_desktop.exec();
    }
    if (cata == "Laptop"){
        Remove_vr remove_laptop(this, "Laptop");
        remove_laptop.setModal(true);
        remove_laptop.exec();
    }
    if (cata == "Watch"){
        Remove_vr remove_watch(this, "Watch");
        remove_watch.setModal(true);
        remove_watch.exec();
    }
    if (cata == "Console"){
        Remove_vr remove_watch(this, "Console");
        remove_watch.setModal(true);
        remove_watch.exec();
    }
}

