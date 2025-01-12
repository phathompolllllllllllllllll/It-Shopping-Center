#include "portable_hdd.h"

Portable_HDD::Portable_HDD() {}

Portable_HDD::Portable_HDD(int q, double p) : Peripherals(q, p) {
    capacity = 0;
    interface = "-";
    transfer_speed = 0;
    dimensions = std::make_tuple(0, 0, 0);
    weight = 0;
}

void Portable_HDD::setCapacity(int c) {
    capacity = c;
}

void Portable_HDD::setInterface(std::string i) {
    interface = i;
}

void Portable_HDD::setTransferSpeed(double ts) {
    transfer_speed = ts;
}

void Portable_HDD::setDimensions(double l, double w, double h) {
    dimensions = std::make_tuple(l, w, h);
}

void Portable_HDD::setWeight(double w) {
    weight = w;
}

int Portable_HDD::getCapacity() const {
    return capacity;
}

std::string Portable_HDD::getInterface() const {
    return interface;
}

double Portable_HDD::getTransferSpeed() const {
    return transfer_speed;
}

std::tuple<double, double, double> Portable_HDD::getDimensions() const {
    return dimensions;
}

double Portable_HDD::getWeight() const {
    return weight;
}

void Portable_HDD::generateId() {
    std::ifstream file_in("../txt_files/portable_hdd.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Portable_HDD p_hdd: portable_hdd_vec){
            std::string id = p_hdd.getID(); // AZ0001
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
    portable_hdd_vec.push_back(*this);
    std::ofstream file_out("../txt_files/portable_hdd.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Portable_HDD p_hdd: portable_hdd_vec){
        file_out << p_hdd.getID() << "|";
        file_out << p_hdd.getDescription() << "|";
        file_out << p_hdd.getBrand() << "|";
        file_out << p_hdd.getModel() << "|";
        file_out << p_hdd.getPrice() << "|";
        file_out << p_hdd.getQuantity() << "|";
        file_out << p_hdd.getOnDisplay() << "|";
        file_out << p_hdd.getCapacity() << "|";
        file_out << p_hdd.getInterface() << "|";
        file_out << p_hdd.getTransferSpeed() << "|";
        file_out << std::get<0>(p_hdd.getDimensions()) << "|";
        file_out << std::get<1>(p_hdd.getDimensions()) << "|";
        file_out << std::get<2>(p_hdd.getDimensions()) << "|";
        file_out << p_hdd.getWeight() << "|";
        file_out << p_hdd.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Portable_HDD::updateVec(const Portable_HDD p_hdd_in){
    for (Portable_HDD& p_hdd: portable_hdd_vec){
        if (p_hdd.getID() == p_hdd_in.getID()){
            p_hdd.setDescription(p_hdd_in.getDescription());
            p_hdd.setBrand(p_hdd_in.getBrand());
            p_hdd.setModel(p_hdd_in.getModel());
            p_hdd.setPrice(p_hdd_in.getPrice());
            p_hdd.setQuantity(p_hdd_in.getQuantity());
            p_hdd.setOnDisplay(p_hdd_in.getOnDisplay());
            p_hdd.setCapacity(p_hdd_in.getCapacity());
            p_hdd.setInterface(p_hdd_in.getInterface());
            p_hdd.setTransferSpeed(p_hdd_in.getTransferSpeed());
            p_hdd.setDimensions(std::get<0>(p_hdd_in.getDimensions()), std::get<1>(p_hdd_in.getDimensions()), std::get<2>(p_hdd_in.getDimensions()));
            p_hdd.setWeight(p_hdd_in.getWeight());
            p_hdd.setImagePath(p_hdd_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/portable_hdd.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Portable_HDD p_hdd: portable_hdd_vec){
        file_out << p_hdd.getID() << "|";
        file_out << p_hdd.getDescription() << "|";
        file_out << p_hdd.getBrand() << "|";
        file_out << p_hdd.getModel() << "|";
        file_out << p_hdd.getPrice() << "|";
        file_out << p_hdd.getQuantity() << "|";
        file_out << p_hdd.getOnDisplay() << "|";
        file_out << p_hdd.getOnDisplay() << "|";
        file_out << p_hdd.getCapacity() << "|";
        file_out << p_hdd.getInterface() << "|";
        file_out << p_hdd.getTransferSpeed() << "|";
        file_out << std::get<0>(p_hdd.getDimensions()) << "|";
        file_out << std::get<1>(p_hdd.getDimensions()) << "|";
        file_out << std::get<2>(p_hdd.getDimensions()) << "|";
        file_out << p_hdd.getWeight() << "|";
        file_out << p_hdd.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Portable_HDD::readData(){
    std::ifstream file_in("../txt_files/portable_hdd.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string capacity;
    std::string interface;
    std::string transfer_speed;
    std::string length;
    std::string width;
    std::string height;
    std::string weight;
    std::string image_path;
    std::array<std::string*, 15> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &capacity, &interface, &transfer_speed, &length, &width, &height, &weight, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Portable_HDD p_hdd;
        p_hdd.setID(id);
        p_hdd.setDescription(description);
        p_hdd.setBrand(brand);
        p_hdd.setModel(model);
        p_hdd.setPrice(std::stod(price));
        p_hdd.setQuantity(std::stoi(quantity));
        p_hdd.setOnDisplay(std::stoi(on_display));
        p_hdd.setCapacity(std::stoi(capacity));
        p_hdd.setInterface(interface);
        p_hdd.setTransferSpeed(std::stod(transfer_speed));
        p_hdd.setDimensions(std::stod(length), std::stod(width), std::stod(height));
        p_hdd.setWeight(std::stod(weight));
        p_hdd.setImagePath(image_path);
        portable_hdd_vec.push_back(p_hdd);
    }
    file_in.close();
    return;    
}