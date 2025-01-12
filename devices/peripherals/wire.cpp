#include "wire.h"

Wire::Wire(){}

Wire::Wire(const int q, const double p) : Peripherals(q, p) {
    length = 0;
    type = "-";
    generateId();
}

void Wire::setLength(const double l) {
    length = l;
}

void Wire::setType(const std::string t) {
    type = t;
}

double Wire::getLength() const{
    return length;
}

std::string Wire::getType() const{
    return type;
}

void Wire::generateId() {
    std::ifstream file_in("../txt_files/wire.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Wire wire: wire_vec){
            std::string id = wire.getID(); // AZ0001
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
    wire_vec.push_back(*this);
    std::ofstream file_out("../txt_files/wire.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Wire wire: wire_vec){
        file_out << wire.getID() << "|";
        file_out << wire.getDescription() << "|";
        file_out << wire.getBrand() << "|";
        file_out << wire.getModel() << "|";
        file_out << wire.getPrice() << "|";
        file_out << wire.getQuantity() << "|";
        file_out << wire.getOnDisplay() << "|";
        file_out << wire.getLength() << "|";
        file_out << wire.getType() << "|";
        file_out << wire.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Wire::updateVec(const Wire wire_in){
    for (Wire& wire: wire_vec){
        if (wire.getID() == wire_in.getID()){
            wire.setDescription(wire_in.getDescription());
            wire.setBrand(wire_in.getBrand());
            wire.setModel(wire_in.getModel());
            wire.setPrice(wire_in.getPrice());
            wire.setQuantity(wire_in.getQuantity());
            wire.setOnDisplay(wire_in.getOnDisplay());
            wire.setLength(wire_in.getLength());
            wire.setType(wire_in.getType());
            wire.setImagePath(wire_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/wire.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Wire wire: wire_vec){
        file_out << wire.getID() << "|";
        file_out << wire.getDescription() << "|";
        file_out << wire.getBrand() << "|";
        file_out << wire.getModel() << "|";
        file_out << wire.getPrice() << "|";
        file_out << wire.getQuantity() << "|";
        file_out << wire.getOnDisplay() << "|";
        file_out << wire.getLength() << "|";
        file_out << wire.getType() << "|";
        file_out << wire.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Wire::readData() {
    std::ifstream file_in("../txt_files/wire.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string length;
    std::string type;
    std::string image_path;
    std::array<std::string*, 10> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &length, &type, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');                   
        } 
        Wire wire;
        wire.setID(id);
        wire.setDescription(description);
        wire.setBrand(brand);
        wire.setModel(model);
        wire.setPrice(std::stod(price));
        wire.setQuantity(std::stoi(quantity));
        wire.setOnDisplay(std::stoi(on_display));
        wire.setLength(std::stod(length));
        wire.setType(type);
        wire.setImagePath(image_path);
        wire_vec.push_back(wire);
    }
    file_in.close();
    return;
}