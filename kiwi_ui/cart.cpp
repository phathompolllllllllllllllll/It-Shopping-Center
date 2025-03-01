#include "cart.h"
#include "ui_cart.h"

// using DevicesType = std::variant<
//     Handheld*,
//     Stationed*,
//     Laptop*,
//     Desktop*,
//     Smartphones*,
//     Smartwatch*,
//     Tablet*,
//     VR*>;



Cart::Cart(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Cart)
{
    ui->setupUi(this);
    // std::vector<DevicesType> cart;
    for(std::tuple<std::string, int>& ob : Add_to_Cart::id_in_cart){
        for(Handheld& device : Handheld::handheld_vec){
            if (device.getID() == std::get<0>(ob)){
                cart.push_back(std::tuple(&device, std::get<1>(ob)));

            }
        }
        for (Stationed& device : Stationed::stationed_vec){
            if (device.getID() == std::get<0>(ob)){
                cart.push_back(std::tuple(&device, std::get<1>(ob)));

            }
        }
        for (Laptop& device : Laptop::laptop_vec){
            if (device.getID() == std::get<0>(ob)){
                cart.push_back(std::tuple(&device, std::get<1>(ob)));

            }
        }
        for (Desktop& device : Desktop::desktop_vec){
            if (device.getID() == std::get<0>(ob)){
                cart.push_back(std::tuple(&device, std::get<1>(ob)));

            }
        }
        for (Smartphones& device : Smartphones::smartphones_vec){
            if (device.getID() == std::get<0>(ob)){
                cart.push_back(std::tuple(&device, std::get<1>(ob)));

            }
        }
        for (Smartwatch& device : Smartwatch::smartwatch_vec){
            if (device.getID() == std::get<0>(ob)){
                cart.push_back(std::tuple(&device, std::get<1>(ob)));

            }
        }
        for (Tablet& device : Tablet::tablet_vec){
            if (device.getID() == std::get<0>(ob)){
                cart.push_back(std::tuple(&device, std::get<1>(ob)));

            }
        }
        for (VR& device : VR::vr_vec){
            if (device.getID() == std::get<0>(ob)){
                cart.push_back(std::tuple(&device, std::get<1>(ob)));

            }
        }
    }

    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setGeometry(120, 120, 1050, 550);
    QWidget *scrollWidget = new QWidget(scrollArea);
    QVBoxLayout *layout = new QVBoxLayout(scrollWidget);
    // QGridLayout *layout = new QGridLayout(scrollWidget);
    for (DevicesType& ob : cart) {
        std::string id = std::visit([](auto& arg) { return arg->getID(); }, std::get<0>(ob));

        for(int j = 0; j < VR::vr_vec.size(); j++){
            if(VR::vr_vec[j].getID() == id){
                QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(VR::vr_vec[j].getBrand()) + QString("    Model:  ") + QString::fromStdString(VR::vr_vec[j].getModel()) + QString("    Description:  ") + QString::fromStdString(VR::vr_vec[j].getDescription()) + QString("    Price:  ") + QString::number(VR::vr_vec[j].getPrice()) + QString("    Amount:  ") + QString::number(std::get<1>(ob)) + QString("    ID:  ") + QString::fromStdString(VR::vr_vec[j].getID()));
                panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
                panelLabel->setFixedSize(1000, 100);
                layout->addWidget(panelLabel);
            }

        }

        for(int k = 0; k < Smartphones::smartphones_vec.size(); k++){
            if(Smartphones::smartphones_vec[k].getID() == id){
                QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Smartphones::smartphones_vec[k].getBrand()) + QString("    Model:  ") + QString::fromStdString(Smartphones::smartphones_vec[k].getModel()) + QString("    Description:  ") + QString::fromStdString(Smartphones::smartphones_vec[k].getDescription()) + QString("    Price:  ") + QString::number(Smartphones::smartphones_vec[k].getPrice()) + QString("    Amount:  ") + QString::number(std::get<1>(ob)) + QString("    ID:  ") + QString::fromStdString(Smartphones::smartphones_vec[k].getID()));
                panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
                panelLabel->setFixedSize(1000, 100);
                layout->addWidget(panelLabel);
            }

        }

        for(int l = 0; l < Tablet::tablet_vec.size(); l++){
            if(Tablet::tablet_vec[l].getID() == id){
                QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Tablet::tablet_vec[l].getBrand()) + QString("    Model:  ") + QString::fromStdString(Tablet::tablet_vec[l].getModel()) + QString("    Description:  ") + QString::fromStdString(Tablet::tablet_vec[l].getDescription()) + QString("    Price:  ") + QString::number(Tablet::tablet_vec[l].getPrice()) + QString("    Amount:  ") + QString::number(std::get<1>(ob)) + QString("    ID:  ") + QString::fromStdString(Tablet::tablet_vec[l].getID()));
                panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
                panelLabel->setFixedSize(1000, 100);
                layout->addWidget(panelLabel);
            }

        }

        for(int m = 0; m < Desktop::desktop_vec.size(); m++){
            if(Desktop::desktop_vec[m].getID() == id){
                QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Desktop::desktop_vec[m].getBrand()) + QString("    Model:  ") + QString::fromStdString(Desktop::desktop_vec[m].getModel()) + QString("    Description:  ") + QString::fromStdString(Desktop::desktop_vec[m].getDescription()) + QString("    Price:  ") + QString::number(Desktop::desktop_vec[m].getPrice()) + QString("    Amount:  ") + QString::number(std::get<1>(ob)) + QString("    ID:  ") + QString::fromStdString(Desktop::desktop_vec[m].getID()));
                panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
                panelLabel->setFixedSize(1000, 100);
                layout->addWidget(panelLabel);
            }

        }

        for(int n = 0; n < Laptop::laptop_vec.size(); n++){
            if(Laptop::laptop_vec[n].getID() == id){
                QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Laptop::laptop_vec[n].getBrand()) + QString("    Model:  ") + QString::fromStdString(Laptop::laptop_vec[n].getModel()) + QString("    Description:  ") + QString::fromStdString(Laptop::laptop_vec[n].getDescription()) + QString("    Price:  ") + QString::number(Laptop::laptop_vec[n].getPrice()) + QString("    Amount:  ") + QString::number(std::get<1>(ob)) + QString("    ID:  ") + QString::fromStdString(Laptop::laptop_vec[n].getID()));
                panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
                panelLabel->setFixedSize(1000, 100);
                layout->addWidget(panelLabel);
            }

        }

        for(int q = 0; q < Smartwatch::smartwatch_vec.size(); q++){
            if(Smartwatch::smartwatch_vec[q].getID() == id){
                QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Smartwatch::smartwatch_vec[q].getBrand()) + QString("    Model:  ") + QString::fromStdString(Smartwatch::smartwatch_vec[q].getModel()) + QString("    Description:  ") + QString::fromStdString(Smartwatch::smartwatch_vec[q].getDescription()) + QString("    Price:  ") + QString::number(Smartwatch::smartwatch_vec[q].getPrice()) + QString("    Amount:  ") + QString::number(std::get<1>(ob)) + QString("    ID:  ") + QString::fromStdString(Smartwatch::smartwatch_vec[q].getID()));
                panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
                panelLabel->setFixedSize(1000, 100);
                layout->addWidget(panelLabel);
            }

        }

        for(int r = 0; r < Handheld::handheld_vec.size(); r++){
            if(Handheld::handheld_vec[r].getID() == id){
                QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Handheld::handheld_vec[r].getBrand()) + QString("    Model:  ") + QString::fromStdString(Handheld::handheld_vec[r].getModel()) + QString("    Description:  ") + QString::fromStdString(Handheld::handheld_vec[r].getDescription()) + QString("    Price:  ") + QString::number(Handheld::handheld_vec[r].getPrice()) + QString("    Amount:  ") + QString::number(std::get<1>(ob)) + QString("    ID:  ") + QString::fromStdString(Handheld::handheld_vec[r].getID()));
                panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
                panelLabel->setFixedSize(1000, 100);
                layout->addWidget(panelLabel);
            }

        }

        for(int g = 0; g < Stationed::stationed_vec.size(); g++){
            if(Stationed::stationed_vec[g].getID() == id){
                QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Stationed::stationed_vec[g].getBrand()) + QString("    Model:  ") + QString::fromStdString(Stationed::stationed_vec[g].getModel()) + QString("    Description:  ") + QString::fromStdString(Stationed::stationed_vec[g].getDescription()) + QString("    Price:  ") + QString::number(Stationed::stationed_vec[g].getPrice()) + QString("    Amount:  ") + QString::number(std::get<1>(ob)) + QString("    ID:  ") + QString::fromStdString(Stationed::stationed_vec[g].getID()));
                panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
                panelLabel->setFixedSize(1000, 100);
                layout->addWidget(panelLabel);
            }

        }
    }

    scrollArea->setWidget(scrollWidget);
}

Cart::~Cart()
{
    delete ui;
}

void Cart::on_delete_btn_clicked()
{
    Delete_thing_inCart de(this);
    de.setModal(true);
    de.exec();
}


void Cart::on_Buy_btn_clicked()
{
    std::vector<VR> newVec1;
    std::vector<Smartphones> newVec2;
    std::vector<Tablet> newVec3;
    std::vector<Desktop> newVec4;
    std::vector<Laptop> newVec5;
    std::vector<Smartwatch> newVec6;
    std::vector<Handheld> newVec7;
    std::vector<Stationed> newVec8;



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
    Devices::total_sales += std::stoi(total);
    file_in.close();

    for(int i = 0; i < Add_to_Cart::id_in_cart.size(); i++){
        Devices::total_sales += std::get<1>(Add_to_Cart::id_in_cart[i]);
    }

    std::ofstream file_out("../txt_files/total_sell.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    file_out << Devices::total_sales;
    file_out.close();




    for(std::tuple<std::string, int> &i: Add_to_Cart::id_in_cart){
        for (VR& vr : VR::vr_vec){
            if (vr.getID() == std::get<0>(i)){
                if(vr.getQuantity() - std::get<1>(i) > 0){
                    vr.setQuantity(vr.getQuantity() - std::get<1>(i));
                } else if(vr.getQuantity() - std::get<1>(i) <= 0){
                    continue;
                }

            }
            newVec1.push_back(vr);
        }
        VR::vr_vec = newVec1;


        for (Smartphones &p : Smartphones::smartphones_vec){
            if (p.getID() == std::get<0>(i)){
                if(p.getQuantity() - std::get<1>(i) > 0){
                    p.setQuantity(p.getQuantity() - std::get<1>(i));
                } else if(p.getQuantity() - std::get<1>(i) <= 0){
                    continue;
                }

            }
            newVec2.push_back(p);
        }
        Smartphones::smartphones_vec = newVec2;


        for (Tablet &t : Tablet::tablet_vec){
            if (t.getID() == std::get<0>(i)){
                if(t.getQuantity() - std::get<1>(i) > 0){
                    t.setQuantity(t.getQuantity() - std::get<1>(i));
                } else if(t.getQuantity() - std::get<1>(i) <= 0){
                    continue;
                }

            }
            newVec3.push_back(t);
        }
        Tablet::tablet_vec = newVec3;


        for (Desktop &d : Desktop::desktop_vec){
            if (d.getID() == std::get<0>(i)){
                if(d.getQuantity() - std::get<1>(i) > 0){
                    d.setQuantity(d.getQuantity() - std::get<1>(i));
                } else if(d.getQuantity() - std::get<1>(i) <= 0){
                    continue;
                }

            }
            newVec4.push_back(d);
        }
        Desktop::desktop_vec = newVec4;


        for (Laptop &l : Laptop::laptop_vec){
            if (l.getID() == std::get<0>(i)){
                if(l.getQuantity() - std::get<1>(i) > 0){
                    l.setQuantity(l.getQuantity() - std::get<1>(i));
                } else if(l.getQuantity() - std::get<1>(i) <= 0){
                    continue;
                }

            }
            newVec5.push_back(l);
        }
        Laptop::laptop_vec = newVec5;


        for (Smartwatch &s : Smartwatch::smartwatch_vec){
            if (s.getID() == std::get<0>(i)){
                if(s.getQuantity() - std::get<1>(i) > 0){
                    s.setQuantity(s.getQuantity() - std::get<1>(i));
                } else if(s.getQuantity() - std::get<1>(i) <= 0){
                    continue;
                }

            }
            newVec6.push_back(s);
        }
        Smartwatch::smartwatch_vec = newVec6;


        for (Handheld &h : Handheld::handheld_vec){
            if (h.getID() == std::get<0>(i)){
                if(h.getQuantity() - std::get<1>(i) > 0){
                    h.setQuantity(h.getQuantity() - std::get<1>(i));
                } else if(h.getQuantity() - std::get<1>(i) <= 0){
                    continue;
                }

            }
            newVec7.push_back(h);
        }
        Handheld::handheld_vec = newVec7;


        for (Stationed &s : Stationed::stationed_vec){
            if (s.getID() == std::get<0>(i)){
                if(s.getQuantity() - std::get<1>(i) > 0){
                    s.setQuantity(s.getQuantity() - std::get<1>(i));
                } else if(s.getQuantity() - std::get<1>(i) <= 0){
                    continue;
                }

            }
            newVec8.push_back(s);
        }
        Stationed::stationed_vec = newVec8;
    }

    std::ofstream file_out1("../txt_files/vr.txt", std::ios::out);
    if (!file_out1.is_open() || file_out1.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const VR &vr: newVec1){
        file_out1 << vr.getID() << "|";
        file_out1 << vr.getDescription() << "|";
        file_out1 << vr.getBrand() << "|";
        file_out1 << vr.getModel() << "|";
        file_out1 << vr.getPrice() << "|";
        file_out1 << vr.getQuantity() << "|";
        file_out1 << vr.getOnDisplay() << "|";
        file_out1 << std::get<0>(vr.getResolution()) << "|";
        file_out1 << std::get<1>(vr.getResolution()) << "|";
        file_out1 << vr.getWithControllers() << "|";
        file_out1 << vr.getDisplay() << "|";
        file_out1 << vr.getHaveUsbCable() << "|";
        file_out1 << vr.getRefreshRate() << "|";
        file_out1 << vr.getFieldOfView() << "|";
        file_out1 << vr.getSizeDisplayInch() << "|";
        file_out1 << vr.getImagePath();
        file_out1 << std::endl;
    }
    file_out1.close();

    std::ofstream file_out2("../txt_files/smartphones.txt", std::ios::out);
    if (!file_out2.is_open() || file_out2.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Smartphones &smartphone: newVec2){
        file_out2 << smartphone.getID() << "|";
        file_out2 << smartphone.getDescription() << "|";
        file_out2 << smartphone.getBrand() << "|";
        file_out2 << smartphone.getModel() << "|";
        file_out2 << smartphone.getPrice() << "|";
        file_out2 << smartphone.getQuantity() << "|";
        file_out2 << smartphone.getOnDisplay() << "|";
        file_out2 << smartphone.getDisplay() << "|";
        file_out2 << std::get<0>(smartphone.getResolution()) << "|";
        file_out2 << std::get<1>(smartphone.getResolution()) << "|";
        file_out2 << smartphone.getProcessor() << "|";
        file_out2 << smartphone.getOS() << "|";
        file_out2 << smartphone.getCharger() << "|";
        file_out2 << smartphone.getCameraSpec() << "|";
        file_out2 << smartphone.getNumSim() << "|";
        file_out2 << std::get<0>(smartphone.getDimensions()) << "|";
        file_out2 << std::get<1>(smartphone.getDimensions()) << "|";
        file_out2 << std::get<2>(smartphone.getDimensions()) << "|";
        file_out2 << smartphone.getStorage() << "|";
        file_out2 << smartphone.getRefreshRate() << "|";
        file_out2 << smartphone.getWifi() << "|";
        file_out2 << smartphone.getBrightness() << "|";
        file_out2 << smartphone.getBluetooth() << "|";
        file_out2 << smartphone.getWeight() << "|";
        file_out2 << smartphone.getBattery() << "|";
        file_out2 << smartphone.getBiometrics()[0] << "|";
        file_out2 << smartphone.getBiometrics()[1] << "|";
        file_out2 << smartphone.getBiometrics()[2] << "|";
        file_out2 << smartphone.getDualSim() << "|";
        file_out2 << smartphone.getMicroSD() << "|";
        file_out2 << smartphone.getJack() << "|";
        file_out2 << smartphone.getHasPen() << "|";
        file_out2 << smartphone.getImagePath();
        file_out2 << std::endl;
    }
    file_out2.close();

    std::ofstream file_out3("../txt_files/tablet.txt", std::ios::out);
    if (!file_out3.is_open() || file_out3.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Tablet &tablet: newVec3){
        file_out3 << tablet.getID() << "|";
        file_out3 << tablet.getDescription() << "|";
        file_out3 << tablet.getBrand() << "|";
        file_out3 << tablet.getModel() << "|";
        file_out3 << tablet.getPrice() << "|";
        file_out3 << tablet.getQuantity() << "|";
        file_out3 << tablet.getDisplay() << "|";
        file_out3 << tablet.getDisplay() << "|";
        file_out3 << tablet.getProcessor() << "|";
        file_out3 << tablet.getOs() << "|";
        file_out3 << tablet.getStorage() << "|";
        file_out3 << tablet.getCamera() << "|";
        file_out3 << tablet.getBattery() << "|";
        file_out3 << tablet.getBluetooth() << "|";
        file_out3 << std::get<0>(tablet.getResolution()) << "|" << std::get<1>(tablet.getResolution()) << "|";
        file_out3 << std::get<0>(tablet.getDimensions()) << "|" << std::get<1>(tablet.getDimensions()) << "|" << std::get<2>(tablet.getDimensions()) << "|";
        file_out3 << tablet.getWeight() << "|";
        file_out3 << tablet.getBrightness() << "|";
        file_out3 << tablet.getWifi() << "|";
        file_out3 << tablet.getHavePen() << "|";
        file_out3 << tablet.getInternal_Memory() << "|";
        file_out3 << tablet.getExternal_Memory() << "|";
        file_out3 << tablet.getSpeaker() << "|";
        file_out3 << tablet.getBiometrics()[0] << "|" << tablet.getBiometrics()[1] << "|" << tablet.getBiometrics()[2] << "|";
        file_out3 << tablet.getIsWaterproof() << "|";
        file_out3 << tablet.getImagePath();
        file_out3 << std::endl;
    }
    file_out3.close();

    std::ofstream file_out4("../txt_files/desktop.txt", std::ios::out);
    if (!file_out4.is_open() || file_out4.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Desktop &desktop: newVec4){
        file_out4 << desktop.getID() << "|";
        file_out4 << desktop.getDescription() << "|";
        file_out4 << desktop.getBrand() << "|";
        file_out4 << desktop.getModel() << "|";
        file_out4 << desktop.getPrice() << "|";
        file_out4 << desktop.getQuantity() << "|";
        file_out4 << desktop.getOnDisplay() << "|";
        file_out4 << desktop.getCPU() << "|";
        file_out4 << desktop.getGPU() << "|";
        file_out4 << desktop.getMemory() << "|";
        for (std::string &storage: desktop.getStorage()){
            file_out4 << storage << ",";
        }
        file_out4 << "|";
        file_out4 << desktop.getOS() << "|";
        file_out4 << desktop.getMotherboard() << "|";
        file_out4 << desktop.getPSU() << "|";
        file_out4 << desktop.getPCCase() << "|";
        file_out4 << desktop.getCooling() << "|";
        file_out4 << desktop.getImagePath();
        file_out4 << std::endl;
    }
    file_out4.close();

    std::ofstream file_out5("../txt_files/laptop.txt", std::ios::out);
    if (!file_out5.is_open() || file_out5.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Laptop &laptop: newVec5){
        file_out5 << laptop.getID() << "|";
        file_out5 << laptop.getDescription() << "|";
        file_out5 << laptop.getBrand() << "|";
        file_out5 << laptop.getModel() << "|";
        file_out5 << laptop.getPrice() << "|";
        file_out5 << laptop.getQuantity() << "|";
        file_out5 << laptop.getOnDisplay() << "|";
        file_out5 << laptop.getCPU() << "|";
        file_out5 << laptop.getGPU() << "|";
        file_out5 << laptop.getMemory() << "|";
        for (const std::string &s: laptop.getStorage()){
            file_out5 << s << ",";
        }
        file_out5 << "|";
        file_out5 << laptop.getOS() << "|";
        file_out5 << laptop.getDisplay() << "|";
        file_out5 << std::get<0>(laptop.getBattery()) << "|";
        file_out5 << std::get<1>(laptop.getBattery()) << "|";
        file_out5 << std::get<0>(laptop.getDimensions()) << "|";
        file_out5 << std::get<1>(laptop.getDimensions()) << "|";
        file_out5 << std::get<2>(laptop.getDimensions()) << "|";
        file_out5 << std::get<3>(laptop.getDimensions()) << "|";
        file_out5 << laptop.getWeight() << "|";
        file_out5 << laptop.getTouchscreen() << "|";
        file_out5 << laptop.getGaming() << "|";
        file_out5 << laptop.getImagePath();
        file_out5 << std::endl;
    }
    file_out5.close();

    std::ofstream file_out6("../txt_files/smartwatch.txt", std::ios::out);
    if (!file_out6.is_open() || file_out6.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Smartwatch &smartwatch: newVec6){
        file_out6 << smartwatch.getID() << "|";
        file_out6 << smartwatch.getDescription() << "|";
        file_out6 << smartwatch.getBrand() << "|";
        file_out6 << smartwatch.getModel() << "|";
        file_out6 << smartwatch.getPrice() << "|";
        file_out6 << smartwatch.getQuantity() << "|";
        file_out6 << smartwatch.getOnDisplay() << "|";
        file_out6 << smartwatch.getDisplay() << "|";
        file_out6 << smartwatch.getSim() << "|";
        file_out6 << smartwatch.getHaveBluetooth() << "|";
        file_out6 << smartwatch.getWifi() << "|";
        file_out6 << smartwatch.getCapacity() << "|";
        file_out6 << smartwatch.getScreenSize() << "|";
        file_out6 << smartwatch.getCaseSize() << "|";
        file_out6 << smartwatch.getBrightness() << "|";
        file_out6 << smartwatch.getWaterResistance() << "|";
        file_out6 << smartwatch.getBattery() << "|";
        file_out6 << smartwatch.getWeight() << "|";
        file_out6 << smartwatch.getHeartrateMonitoring() << "|";
        file_out6 << smartwatch.getHasMicrophones() << "|";
        file_out6 << smartwatch.getHasGps() << "|";
        file_out6 << smartwatch.getHasBloodOxygenSensor() << "|";
        file_out6 << smartwatch.getHasSpeaker() << "|";
        file_out6 << smartwatch.getImagePath();

        file_out6 << std::endl;
    }
    file_out6.close();

    std::ofstream file_out7("../txt_files/handheld.txt", std::ios::out);
    if (!file_out7.is_open() || file_out7.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Handheld &handheld: newVec7){
        file_out7 << handheld.getID() << "|";
        file_out7 << handheld.getDescription() << "|";
        file_out7 << handheld.getBrand() << "|";
        file_out7 << handheld.getModel() << "|";
        file_out7 << handheld.getPrice() << "|";
        file_out7 << handheld.getQuantity() << "|";
        file_out7 << handheld.getOnDisplay() << "|";
        file_out7 << std::get<0>(handheld.getResolution()) << "|";
        file_out7 << std::get<1>(handheld.getResolution()) << "|";
        file_out7 << handheld.getMainProcessor() << "|";
        file_out7 << handheld.getGraphicsProcessor() << "|";
        file_out7 << handheld.getStorageCapacity() << "|";
        file_out7 << handheld.getUSB() << "|";
        file_out7 << handheld.getDisplay() << "|";
        file_out7 << handheld.getInputOutputPort() << "|";
        file_out7 << handheld.getWifi() << "|";
        file_out7 << handheld.getWeight() << "|";
        file_out7 << handheld.getBluetooth() << "|";
        file_out7 << handheld.getPowerConsumption() << "|";
        file_out7 << handheld.getControllerVibration() << "|";
        file_out7 << handheld.getTVMode() << "|";
        file_out7 << handheld.getBattery() << "|";
        file_out7 << handheld.getPowerSupply() << "|";
        file_out7 << handheld.getHeadphoneJack() << "|";
        file_out7 << handheld.getMicroSDSlot() << "|";
        file_out7 << handheld.getSize() << "|";
        file_out7 << handheld.getImagePath();
        file_out7 << std::endl;
    }
    file_out7.close();

    std::ofstream file_out8("../txt_files/stationed.txt", std::ios::out);
    if (!file_out8.is_open() || file_out8.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Stationed &stationed: newVec8){
        file_out8 << stationed.getID() << "|";
        file_out8 << stationed.getDescription() << "|";
        file_out8 << stationed.getBrand() << "|";
        file_out8 << stationed.getModel() << "|";
        file_out8 << stationed.getPrice() << "|";
        file_out8 << stationed.getQuantity() << "|";
        file_out8 << stationed.getOnDisplay() << "|";
        file_out8 << std::get<0>(stationed.getResolution()) << "|";
        file_out8 << std::get<1>(stationed.getResolution()) << "|";
        file_out8 << stationed.getMainProcessor() << "|";
        file_out8 << stationed.getGraphicsProcessor() << "|";
        file_out8 << stationed.getStorageCapacity() << "|";
        file_out8 << stationed.getUSB() << "|";
        file_out8 << stationed.getDisplay() << "|";
        file_out8 << stationed.getInputOutputPort() << "|";
        file_out8 << stationed.getWifi() << "|";
        file_out8 << stationed.getWeight() << "|";
        file_out8 << stationed.getBluetooth() << "|";
        file_out8 << stationed.getPowerConsumption() << "|";
        file_out8 << stationed.getControllerVibration() << "|";
        file_out8 << stationed.getTVMode() << "|";
        file_out8 << stationed.getSSD() << "|";
        file_out8 << stationed.getSize() << "|";
        file_out8 << stationed.getImagePath();
        file_out8 << std::endl;
    }
    file_out8.close();

    Add_to_Cart::id_in_cart.clear();
    cart.clear();

    this->close();
}

