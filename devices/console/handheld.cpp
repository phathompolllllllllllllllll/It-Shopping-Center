#include "handheld.h"

Handheld::Handheld(){}

Handheld::Handheld(const int q, const double p) : Console(q, p) {
    battery = "-";
    power_supply = "-";
    headphone_jack = "-";
    microSD_slot = 0;
    size = "-";
    generateId();
}


std::string Handheld::getBattery() const {
    return battery;
}

std::string Handheld::getPowerSupply() const {
    return power_supply;
}

std::string Handheld::getHeadphoneJack() const {
    return headphone_jack;
}

int Handheld::getMicroSDSlot() const {
    return microSD_slot;
}

std::string Handheld::getSize() const {
    return size;
}

void Handheld::setBattery(const std::string b) {
    battery = b;
}

void Handheld::setPowerSupply(const std::string p) {
    power_supply = p;
}

void Handheld::setHeadphoneJack(const std::string h) {
    headphone_jack = h;
}

void Handheld::setMicroSDSlot(const int m) {
    microSD_slot = m;
}

void Handheld::setSize(const std::string s) {
    size = s;
}

void Handheld::generateId() {
    std::ifstream file_in("../txt_files/handheld.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Handheld handheld: handheld_vec){
            std::string id = handheld.getID(); // AZ0001
            std::string id_num = id.substr(2); // 0001
            unsigned int id_num_int = std::stoi(id_num);
            if (id_num_int > max_id){
                max_id = id_num_int;
            }
        }
        unsigned int no_of_zeros = 4 - std::to_string(max_id).length();
        std::string id = id_start;
        for (unsigned int i = 0; i < no_of_zeros; i++){
            id += "0";
        }
        id += std::to_string(max_id + 1);
        setID(id);
    }
    file_in.close();
    handheld_vec.push_back(*this);
    std::ofstream file_out("../txt_files/handheld.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Handheld handheld: handheld_vec){
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
    return;
}

void Handheld::updateVec(const Handheld handheld_in) {
    for (Handheld& handheld: handheld_vec){
        if (handheld.getID() == handheld_in.getID()){
            handheld.setDescription(handheld_in.getDescription());
            handheld.setBrand(handheld_in.getBrand());
            handheld.setModel(handheld_in.getModel());
            handheld.setPrice(handheld_in.getPrice());
            handheld.setQuantity(handheld_in.getQuantity());
            handheld.setOnDisplay(handheld_in.getOnDisplay());
            handheld.setResolution(std::get<0>(handheld_in.getResolution()), std::get<1>(handheld_in.getResolution()));
            handheld.setMainProcessor(handheld_in.getMainProcessor());
            handheld.setGraphicsProcessor(handheld_in.getGraphicsProcessor());
            handheld.setStorageCapacity(handheld_in.getStorageCapacity());
            handheld.setUSB(handheld_in.getUSB());
            handheld.setDisplay(handheld_in.getDisplay());
            handheld.setInputOutputPort(handheld_in.getInputOutputPort());
            handheld.setWifi(handheld_in.getWifi());
            handheld.setWeight(handheld_in.getWeight());
            handheld.setBluetooth(handheld_in.getBluetooth());
            handheld.setPowerConsumption(handheld_in.getPowerConsumption());
            handheld.setControllerVibration(handheld_in.getControllerVibration());
            handheld.setTVMode(handheld_in.getTVMode());
            handheld.setBattery(handheld_in.getBattery());
            handheld.setPowerSupply(handheld_in.getPowerSupply());
            handheld.setHeadphoneJack(handheld_in.getHeadphoneJack());
            handheld.setMicroSDSlot(handheld_in.getMicroSDSlot());
            handheld.setSize(handheld_in.getSize());
            handheld.setImagePath(handheld_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/handheld.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Handheld handheld: handheld_vec){
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
    return;
}

void Handheld::readData() {
    std::ifstream file_in("../txt_files/handheld.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string resx;
    std::string resy;
    std::string main_processor;
    std::string graphics_processor;
    std::string storage_capacity;
    std::string usb;
    std::string display;
    std::string input_output_port;
    std::string wifi;
    std::string weight;
    std::string bluetooth;
    std::string power_consumption;
    std::string controller_vibration;
    std::string tv_mode;
    std::string battery;
    std::string power_supply;
    std::string headphone_jack;
    std::string microSD_slot;
    std::string size;
    std::string image_path;
    std::array<std::string*, 27> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &resx, &resy, &main_processor, &graphics_processor, &storage_capacity, &usb, &display, &input_output_port, &wifi, &weight, &bluetooth, &power_consumption, &controller_vibration, &tv_mode, &battery, &power_supply, &headphone_jack, &microSD_slot, &size, &image_path};

    std::string row;
    while(std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Handheld handheld;
        handheld.setID(id);
        handheld.setDescription(description);
        handheld.setBrand(brand);
        handheld.setModel(model);
        handheld.setPrice(std::stod(price));
        handheld.setQuantity(std::stoi(quantity));
        handheld.setOnDisplay(std::stoi(on_display));
        handheld.setResolution(std::stoi(resx), std::stoi(resy));
        handheld.setMainProcessor(main_processor);
        handheld.setGraphicsProcessor(graphics_processor);
        handheld.setStorageCapacity(std::stoi(storage_capacity));
        handheld.setUSB(usb);
        handheld.setDisplay(display);
        handheld.setInputOutputPort(input_output_port);
        handheld.setWifi(wifi);
        handheld.setWeight(std::stod(weight));
        handheld.setBluetooth(bluetooth);
        handheld.setPowerConsumption(std::stod(power_consumption));
        handheld.setControllerVibration(std::stoi(controller_vibration));
        handheld.setTVMode(std::stoi(tv_mode));
        handheld.setBattery(battery);
        handheld.setPowerSupply(power_supply);
        handheld.setHeadphoneJack(headphone_jack);
        handheld.setMicroSDSlot(std::stoi(microSD_slot));
        handheld.setSize(size);
        handheld.setImagePath(image_path);
        handheld_vec.push_back(handheld);
    }
    file_in.close();
    return;
}