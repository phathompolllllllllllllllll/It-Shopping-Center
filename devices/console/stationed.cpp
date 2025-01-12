#include "stationed.h"

Stationed::Stationed(){}

Stationed::Stationed(const int q, const double p) : Console(q, p) {
    std::string ssd;
    size = "-";
    generateId();
}

std::string Stationed::getSSD() const {
    return ssd;
}

std::string Stationed::getSize() const {
    return size;
}

void Stationed::setSSD(const std::string s) {
    ssd = s;
}

void Stationed::setSize(const std::string s) {
    size = s;
}

void Stationed::generateId() {
    std::ifstream file_in("../txt_files/stationed.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Stationed stationed: stationed_vec){
            std::string id = stationed.getID(); // AZ0001
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
    stationed_vec.push_back(*this);
    std::ofstream file_out("../txt_files/stationed.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Stationed stationed: stationed_vec){
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
    return;
}

void Stationed::updateVec(const Stationed stationed_in) {
    for (Stationed& stationed: stationed_vec){
        if (stationed.getID() == stationed_in.getID()){
            stationed.setDescription(stationed_in.getDescription());
            stationed.setBrand(stationed_in.getBrand());
            stationed.setModel(stationed_in.getModel());
            stationed.setPrice(stationed_in.getPrice());
            stationed.setQuantity(stationed_in.getQuantity());
            stationed.setOnDisplay(stationed_in.getOnDisplay());
            stationed.setResolution(std::get<0>(stationed_in.getResolution()), std::get<1>(stationed_in.getResolution()));
            stationed.setMainProcessor(stationed_in.getMainProcessor());
            stationed.setGraphicsProcessor(stationed_in.getGraphicsProcessor());
            stationed.setStorageCapacity(stationed_in.getStorageCapacity());
            stationed.setUSB(stationed_in.getUSB());
            stationed.setDisplay(stationed_in.getDisplay());
            stationed.setInputOutputPort(stationed_in.getInputOutputPort());
            stationed.setWifi(stationed_in.getWifi());
            stationed.setWeight(stationed_in.getWeight());
            stationed.setBluetooth(stationed_in.getBluetooth());
            stationed.setPowerConsumption(stationed_in.getPowerConsumption());
            stationed.setControllerVibration(stationed_in.getControllerVibration());
            stationed.setTVMode(stationed_in.getTVMode());
            stationed.setSSD(stationed_in.getSSD());
            stationed.setSize(stationed_in.getSize());
            stationed.setImagePath(stationed_in.getImagePath());

            break;
        }
    }
    std::ofstream file_out("../txt_files/stationed.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Stationed stationed: stationed_vec){
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
    return;
}

void Stationed::readData(){
    std::ifstream file_in("../txt_files/stationed.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string resolution_x;
    std::string resolution_y;
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
    std::string ssd;
    std::string size;
    std::string image_path;
    std::array<std::string*, 24> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &resolution_x, &resolution_y, &main_processor, &graphics_processor, &storage_capacity, &usb, &display, &input_output_port, &wifi, &weight, &bluetooth, &power_consumption, &controller_vibration, &tv_mode, &ssd, &size, &image_path};

    std::string row;
    while(std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Stationed stationed;
        stationed.setID(id);
        stationed.setDescription(description);
        stationed.setBrand(brand);
        stationed.setModel(model);
        stationed.setPrice(std::stod(price));
        stationed.setQuantity(std::stoi(quantity));
        stationed.setOnDisplay(std::stoi(on_display));
        stationed.setResolution(std::stod(resolution_x), std::stod(resolution_y));
        stationed.setMainProcessor(main_processor);
        stationed.setGraphicsProcessor(graphics_processor);
        stationed.setStorageCapacity(std::stoi(storage_capacity));
        stationed.setUSB(usb);
        stationed.setDisplay(display);
        stationed.setInputOutputPort(input_output_port);
        stationed.setWifi(wifi);
        stationed.setWeight(std::stod(weight));
        stationed.setBluetooth(bluetooth);
        stationed.setPowerConsumption(std::stod(power_consumption));
        stationed.setControllerVibration(std::stoi(controller_vibration));
        stationed.setTVMode(std::stoi(tv_mode));
        stationed.setSSD(ssd);
        stationed.setSize(size);
        stationed.setImagePath(image_path);
        stationed_vec.push_back(stationed);
    }
    file_in.close();
    return;
}
