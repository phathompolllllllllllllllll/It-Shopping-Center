#include "remove_vr.h"
#include "ui_remove_vr.h"

Remove_vr::Remove_vr(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::Remove_vr)
{
    ui->setupUi(this);
    cata = cat;
}

Remove_vr::~Remove_vr()
{
    delete ui;
}

//ทำถึงนี่ ยังไม่ได้ทำ remove
std::string id_in_2;
void Remove_vr::on_ok_btn_clicked()
{
    if (cata == "VR") {
        id_in_2 = ui->ID_in->text().toStdString();
        // qDebug() << id_in_2;
        // for (VR i : VR::vr_vec) {
        //     if (i.getID() == id_in){

        //     }
        // }
        bool check = false;
        for(VR &i : VR::vr_vec){
            if(i.getID() == id_in_2){
                check = true;
            }
        }
        if(check == true){
            // for (auto it = VR::vr_vec.begin(); it != VR::vr_vec.end(); /* no increment here */) {
            //     if (it->getID() == id_in_2) {
            //         // Erasing the object from the vector and updating the iterator
            //         it = VR::vr_vec.erase(it);
            //         // No break here, it will automatically be incremented by erase
            //     } else {
            //         // Move to the next element if no erasure is done
            //         ++it;
            //     }
            // }

            std::vector<VR> newVec;
            for (VR& vr : VR::vr_vec){
                if (vr.getID() != id_in_2){
                    newVec.push_back(std::move(vr));
                }
            }
            VR::vr_vec = newVec;


            // try{
            //     VR::updateVec(VR::vr_vec[0]);
            // }catch (std::out_of_range& e){
            //     std::ofstream file("../txt_files/vr.txt", std::ios::trunc);
            //     file.close();
            // }

            std::ofstream file_out("../txt_files/vr.txt", std::ios::out);
            if (!file_out.is_open() || file_out.fail()){
                std::cerr << "File Error" << std::endl;
                return;
            }
            for (const VR &vr: newVec){
                 file_out << vr.getID() << "|";
                 file_out << vr.getDescription() << "|";
                 file_out << vr.getBrand() << "|";
                 file_out << vr.getModel() << "|";
                 file_out << vr.getPrice() << "|";
                 file_out << vr.getQuantity() << "|";
                 file_out << vr.getOnDisplay() << "|";
                 file_out << std::get<0>(vr.getResolution()) << "|";
                 file_out << std::get<1>(vr.getResolution()) << "|";
                 file_out << vr.getWithControllers() << "|";
                 file_out << vr.getDisplay() << "|";
                 file_out << vr.getHaveUsbCable() << "|";
                 file_out << vr.getRefreshRate() << "|";
                 file_out << vr.getFieldOfView() << "|";
                 file_out << vr.getSizeDisplayInch() << "|";
                 file_out << vr.getImagePath();
                 file_out << std::endl;
            }
            file_out.close();

        } else{
            QMessageBox::information(this, "Error", "Don't have this id");
        }

    }
    if (cata == "Phone") {
        id_in_2 = ui->ID_in->text().toStdString();
        // qDebug() << id_in_2;
        // for (VR i : VR::vr_vec) {
        //     if (i.getID() == id_in){

        //     }
        // }
        bool check = false;
        for(Smartphones &i : Smartphones::smartphones_vec){
            if(i.getID() == id_in_2){
                check = true;
            }
        }
        if(check == true){
            // for (auto it = VR::vr_vec.begin(); it != VR::vr_vec.end(); /* no increment here */) {
            //     if (it->getID() == id_in_2) {
            //         // Erasing the object from the vector and updating the iterator
            //         it = VR::vr_vec.erase(it);
            //         // No break here, it will automatically be incremented by erase
            //     } else {
            //         // Move to the next element if no erasure is done
            //         ++it;
            //     }
            // }

            std::vector<Smartphones> newVec;
            for (Smartphones &i : Smartphones::smartphones_vec){
                if (i.getID() != id_in_2){
                    newVec.push_back(std::move(i));
                }
            }
            Smartphones::smartphones_vec = newVec;


            // try{
            //     VR::updateVec(VR::vr_vec[0]);
            // }catch (std::out_of_range& e){
            //     std::ofstream file("../txt_files/vr.txt", std::ios::trunc);
            //     file.close();
            // }

            std::ofstream file_out("../txt_files/smartphones.txt", std::ios::out);
            if (!file_out.is_open() || file_out.fail()){
                std::cerr << "File Error" << std::endl;
                return;
            }
            for (const Smartphones &smartphone: newVec){
                file_out << smartphone.getID() << "|";
                file_out << smartphone.getDescription() << "|";
                file_out << smartphone.getBrand() << "|";
                file_out << smartphone.getModel() << "|";
                file_out << smartphone.getPrice() << "|";
                file_out << smartphone.getQuantity() << "|";
                file_out << smartphone.getOnDisplay() << "|";
                file_out << smartphone.getDisplay() << "|";
                file_out << std::get<0>(smartphone.getResolution()) << "|";
                file_out << std::get<1>(smartphone.getResolution()) << "|";
                file_out << smartphone.getProcessor() << "|";
                file_out << smartphone.getOS() << "|";
                file_out << smartphone.getCharger() << "|";
                file_out << smartphone.getCameraSpec() << "|";
                file_out << smartphone.getNumSim() << "|";
                file_out << std::get<0>(smartphone.getDimensions()) << "|";
                file_out << std::get<1>(smartphone.getDimensions()) << "|";
                file_out << std::get<2>(smartphone.getDimensions()) << "|";
                file_out << smartphone.getStorage() << "|";
                file_out << smartphone.getRefreshRate() << "|";
                file_out << smartphone.getWifi() << "|";
                file_out << smartphone.getBrightness() << "|";
                file_out << smartphone.getBluetooth() << "|";
                file_out << smartphone.getWeight() << "|";
                file_out << smartphone.getBattery() << "|";
                file_out << smartphone.getBiometrics()[0] << "|";
                file_out << smartphone.getBiometrics()[1] << "|";
                file_out << smartphone.getBiometrics()[2] << "|";
                file_out << smartphone.getDualSim() << "|";
                file_out << smartphone.getMicroSD() << "|";
                file_out << smartphone.getJack() << "|";
                file_out << smartphone.getHasPen() << "|";
                file_out << smartphone.getImagePath();
                file_out << std::endl;
            }
            file_out.close();


        } else{
            QMessageBox::information(this, "Error", "Don't have this id");
        }

    }

    if(cata == "Tablet"){
        id_in_2 = ui->ID_in->text().toStdString();
        bool check = false;
        for(Tablet &i : Tablet::tablet_vec){
            if(i.getID() == id_in_2){
                check = true;
            }
        }
        if(check == true){
            std::vector<Tablet> newVec;
            for (Tablet &i : Tablet::tablet_vec){
                if (i.getID() != id_in_2){
                    newVec.push_back(std::move(i));
                }
            }
            Tablet::tablet_vec = newVec;

            std::ofstream file_out("../txt_files/tablet.txt", std::ios::out);
            if (!file_out.is_open() || file_out.fail()){
                std::cerr << "File Error" << std::endl;
                return;
            }
            for (const Tablet &tablet: newVec){
                file_out << tablet.getID() << "|";
                file_out << tablet.getDescription() << "|";
                file_out << tablet.getBrand() << "|";
                file_out << tablet.getModel() << "|";
                file_out << tablet.getPrice() << "|";
                file_out << tablet.getQuantity() << "|";
                file_out << tablet.getDisplay() << "|";
                file_out << tablet.getDisplay() << "|";
                file_out << tablet.getProcessor() << "|";
                file_out << tablet.getOs() << "|";
                file_out << tablet.getStorage() << "|";
                file_out << tablet.getCamera() << "|";
                file_out << tablet.getBattery() << "|";
                file_out << tablet.getBluetooth() << "|";
                file_out << std::get<0>(tablet.getResolution()) << "|" << std::get<1>(tablet.getResolution()) << "|";
                file_out << std::get<0>(tablet.getDimensions()) << "|" << std::get<1>(tablet.getDimensions()) << "|" << std::get<2>(tablet.getDimensions()) << "|";
                file_out << tablet.getWeight() << "|";
                file_out << tablet.getBrightness() << "|";
                file_out << tablet.getWifi() << "|";
                file_out << tablet.getHavePen() << "|";
                file_out << tablet.getInternal_Memory() << "|";
                file_out << tablet.getExternal_Memory() << "|";
                file_out << tablet.getSpeaker() << "|";
                file_out << tablet.getBiometrics()[0] << "|" << tablet.getBiometrics()[1] << "|" << tablet.getBiometrics()[2] << "|";
                file_out << tablet.getIsWaterproof() << "|";
                file_out << tablet.getImagePath();
                file_out << std::endl;
            }
            file_out.close();

        } else {
            QMessageBox::information(this, "Error", "Don't have this id");
        }
    }
    if(cata == "Desktop"){
        id_in_2 = ui->ID_in->text().toStdString();
        bool check = false;
        for(Desktop &i : Desktop::desktop_vec){
            if(i.getID() == id_in_2){
                check = true;
            }
        }
        if(check == true){
            std::vector<Desktop> newVec;
            for (Desktop &i : Desktop::desktop_vec){
                if (i.getID() != id_in_2){
                    newVec.push_back(std::move(i));
                }
            }
            Desktop::desktop_vec = newVec;

            std::ofstream file_out("../txt_files/desktop.txt", std::ios::out);
            if (!file_out.is_open() || file_out.fail()){
                std::cerr << "File Error" << std::endl;
                return;
            }
            for (const Desktop &desktop: newVec){
                file_out << desktop.getID() << "|";
                file_out << desktop.getDescription() << "|";
                file_out << desktop.getBrand() << "|";
                file_out << desktop.getModel() << "|";
                file_out << desktop.getPrice() << "|";
                file_out << desktop.getQuantity() << "|";
                file_out << desktop.getOnDisplay() << "|";
                file_out << desktop.getCPU() << "|";
                file_out << desktop.getGPU() << "|";
                file_out << desktop.getMemory() << "|";
                for (std::string &storage: desktop.getStorage()){
                    file_out << storage << ",";
                }
                file_out << "|";
                file_out << desktop.getOS() << "|";
                file_out << desktop.getMotherboard() << "|";
                file_out << desktop.getPSU() << "|";
                file_out << desktop.getPCCase() << "|";
                file_out << desktop.getCooling() << "|";
                file_out << desktop.getImagePath();
                file_out << std::endl;
            }
            file_out.close();

        } else {
            QMessageBox::information(this, "Error", "Don't have this id");
        }
    }

    if(cata == "Laptop"){
        id_in_2 = ui->ID_in->text().toStdString();
        bool check = false;
        for(Laptop &i : Laptop::laptop_vec){
            if(i.getID() == id_in_2){
                check = true;
            }
        }
        if(check == true){
            std::vector<Laptop> newVec;
            for (Laptop &i : Laptop::laptop_vec){
                if (i.getID() != id_in_2){
                    newVec.push_back(std::move(i));
                }
            }
            Laptop::laptop_vec = newVec;

            std::ofstream file_out("../txt_files/laptop.txt", std::ios::out);
            if (!file_out.is_open() || file_out.fail()){
                std::cerr << "File Error" << std::endl;
                return;
            }
            for (const Laptop &laptop: newVec){
                file_out << laptop.getID() << "|";
                file_out << laptop.getDescription() << "|";
                file_out << laptop.getBrand() << "|";
                file_out << laptop.getModel() << "|";
                file_out << laptop.getPrice() << "|";
                file_out << laptop.getQuantity() << "|";
                file_out << laptop.getOnDisplay() << "|";
                file_out << laptop.getCPU() << "|";
                file_out << laptop.getGPU() << "|";
                file_out << laptop.getMemory() << "|";
                for (const std::string &s: laptop.getStorage()){
                    file_out << s << ",";
                }
                file_out << "|";
                file_out << laptop.getOS() << "|";
                file_out << laptop.getDisplay() << "|";
                file_out << std::get<0>(laptop.getBattery()) << "|";
                file_out << std::get<1>(laptop.getBattery()) << "|";
                file_out << std::get<0>(laptop.getDimensions()) << "|";
                file_out << std::get<1>(laptop.getDimensions()) << "|";
                file_out << std::get<2>(laptop.getDimensions()) << "|";
                file_out << std::get<3>(laptop.getDimensions()) << "|";
                file_out << laptop.getWeight() << "|";
                file_out << laptop.getTouchscreen() << "|";
                file_out << laptop.getGaming() << "|";
                file_out << laptop.getImagePath();
                file_out << std::endl;
            }
            file_out.close();

        } else {
            QMessageBox::information(this, "Error", "Don't have this id");
        }
    }

    if(cata == "Watch"){
        id_in_2 = ui->ID_in->text().toStdString();
        bool check = false;
        for(Smartwatch &i : Smartwatch::smartwatch_vec){
            if(i.getID() == id_in_2){
                check = true;
            }
        }
        if(check == true){
            std::vector<Smartwatch> newVec;
            for (Smartwatch &i : Smartwatch::smartwatch_vec){
                if (i.getID() != id_in_2){
                    newVec.push_back(std::move(i));
                }
            }
            Smartwatch::smartwatch_vec = newVec;

            std::ofstream file_out("../txt_files/smartwatch.txt", std::ios::out);
            if (!file_out.is_open() || file_out.fail()){
                std::cerr << "File Error" << std::endl;
                return;
            }
            for (const Smartwatch &smartwatch: newVec){
                file_out << smartwatch.getID() << "|";
                file_out << smartwatch.getDescription() << "|";
                file_out << smartwatch.getBrand() << "|";
                file_out << smartwatch.getModel() << "|";
                file_out << smartwatch.getPrice() << "|";
                file_out << smartwatch.getQuantity() << "|";
                file_out << smartwatch.getOnDisplay() << "|";
                file_out << smartwatch.getDisplay() << "|";
                file_out << smartwatch.getSim() << "|";
                file_out << smartwatch.getHaveBluetooth() << "|";
                file_out << smartwatch.getWifi() << "|";
                file_out << smartwatch.getCapacity() << "|";
                file_out << smartwatch.getScreenSize() << "|";
                file_out << smartwatch.getCaseSize() << "|";
                file_out << smartwatch.getBrightness() << "|";
                file_out << smartwatch.getWaterResistance() << "|";
                file_out << smartwatch.getBattery() << "|";
                file_out << smartwatch.getWeight() << "|";
                file_out << smartwatch.getHeartrateMonitoring() << "|";
                file_out << smartwatch.getHasMicrophones() << "|";
                file_out << smartwatch.getHasGps() << "|";
                file_out << smartwatch.getHasBloodOxygenSensor() << "|";
                file_out << smartwatch.getHasSpeaker() << "|";
                file_out << smartwatch.getImagePath();

                file_out << std::endl;
            }
            file_out.close();
        } else {
            QMessageBox::information(this, "Error", "Don't have this id");
        }
    }

    if(cata == "Console"){
        id_in_2 = ui->ID_in->text().toStdString();
        bool check1 = false;
        for(Handheld &i : Handheld::handheld_vec){
            if(i.getID() == id_in_2){
                check1 = true;
            }
        }
        bool check2 = false;
        for(Stationed &i : Stationed::stationed_vec){
            if(i.getID() == id_in_2){
                check2 = true;
            }
        }
        if(check1 == true && check2 == false){
            std::vector<Handheld> newVec;
            for (Handheld &i : Handheld::handheld_vec){
                if (i.getID() != id_in_2){
                    newVec.push_back(std::move(i));
                }
            }
            Handheld::handheld_vec = newVec;

            std::ofstream file_out("../txt_files/handheld.txt", std::ios::out);
            if (!file_out.is_open() || file_out.fail()){
                std::cerr << "File Error" << std::endl;
                return;
            }
            for (const Handheld handheld: newVec){
                file_out << handheld.getID() << "|";
                file_out << handheld.getDescription() << "|";
                file_out << handheld.getBrand() << "|";
                file_out << handheld.getModel() << "|";
                file_out << handheld.getPrice() << "|";
                file_out << handheld.getQuantity() << "|";
                file_out << handheld.getOnDisplay() << "|";
                file_out << std::get<0>(handheld.getResolution()) << "|";
                file_out << std::get<1>(handheld.getResolution()) << "|";
                file_out << handheld.getMainProcessor() << "|";
                file_out << handheld.getGraphicsProcessor() << "|";
                file_out << handheld.getStorageCapacity() << "|";
                file_out << handheld.getUSB() << "|";
                file_out << handheld.getDisplay() << "|";
                file_out << handheld.getInputOutputPort() << "|";
                file_out << handheld.getWifi() << "|";
                file_out << handheld.getWeight() << "|";
                file_out << handheld.getBluetooth() << "|";
                file_out << handheld.getPowerConsumption() << "|";
                file_out << handheld.getControllerVibration() << "|";
                file_out << handheld.getTVMode() << "|";
                file_out << handheld.getBattery() << "|";
                file_out << handheld.getPowerSupply() << "|";
                file_out << handheld.getHeadphoneJack() << "|";
                file_out << handheld.getMicroSDSlot() << "|";
                file_out << handheld.getSize() << "|";
                file_out << handheld.getImagePath();
                file_out << std::endl;
            }
            file_out.close();
        }

        if(check2 == true && check1 == false){
            std::vector<Stationed> newVec;
            for (Stationed &i : Stationed::stationed_vec){
                if (i.getID() != id_in_2){
                    newVec.push_back(std::move(i));
                }
            }
            Stationed::stationed_vec = newVec;

            std::ofstream file_out("../txt_files/stationed.txt", std::ios::out);
            if (!file_out.is_open() || file_out.fail()){
                std::cerr << "File Error" << std::endl;
                return;
            }
            for (const Stationed stationed: newVec){
                file_out << stationed.getID() << "|";
                file_out << stationed.getDescription() << "|";
                file_out << stationed.getBrand() << "|";
                file_out << stationed.getModel() << "|";
                file_out << stationed.getPrice() << "|";
                file_out << stationed.getQuantity() << "|";
                file_out << stationed.getOnDisplay() << "|";
                file_out << std::get<0>(stationed.getResolution()) << "|";
                file_out << std::get<1>(stationed.getResolution()) << "|";
                file_out << stationed.getMainProcessor() << "|";
                file_out << stationed.getGraphicsProcessor() << "|";
                file_out << stationed.getStorageCapacity() << "|";
                file_out << stationed.getUSB() << "|";
                file_out << stationed.getDisplay() << "|";
                file_out << stationed.getInputOutputPort() << "|";
                file_out << stationed.getWifi() << "|";
                file_out << stationed.getWeight() << "|";
                file_out << stationed.getBluetooth() << "|";
                file_out << stationed.getPowerConsumption() << "|";
                file_out << stationed.getControllerVibration() << "|";
                file_out << stationed.getTVMode() << "|";
                file_out << stationed.getSSD() << "|";
                file_out << stationed.getSize() << "|";
                file_out << stationed.getImagePath();
                file_out << std::endl;
            }
            file_out.close();
        }
        if(check2 == false && check1 == false){
            QMessageBox::information(this, "Error", "Don't have this id");
        }
    }


    this->close();

}

