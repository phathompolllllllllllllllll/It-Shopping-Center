#include "headset.h"

Headset::Headset(){}

Headset::Headset(const int q, const double p) : Peripherals(q, p){
    is_wireless = false;
    has_anc = false;
    is_rgb = false;
    surround_sound = false;
    generateId();
}

void Headset::setANC(const bool a){
    has_anc = a;
}

void Headset::setWireless(const bool w){
    is_wireless = w;
}

void Headset::setRGB(const bool r){
    is_rgb = r;
}

void Headset::setSurroundSound(const bool s){
    surround_sound = s;
}

bool Headset::getANC() const{
    return has_anc;
}

bool Headset::getWireless() const{
    return is_wireless;
}

bool Headset::getRGB() const{
    return is_rgb;
}

bool Headset::getSurroundSound() const{
    return surround_sound;
}

void Headset::generateId(){
    std::ifstream file_in("../txt_files/headset.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Headset headset: headset_vec){
            std::string id = headset.getID();
            std::string id_num = id.substr(2);
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
    headset_vec.push_back(*this);
    std::ofstream file_out("../txt_files/headset.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Headset headset: headset_vec){
        file_out << headset.getID() << "|";
        file_out << headset.getDescription() << "|";
        file_out << headset.getBrand() << "|";
        file_out << headset.getModel() << "|";
        file_out << headset.getPrice() << "|";
        file_out << headset.getQuantity() << "|";
        file_out << headset.getOnDisplay() << "|";
        file_out << headset.getWireless() << "|";
        file_out << headset.getANC() << "|";
        file_out << headset.getRGB() << "|";
        file_out << headset.getSurroundSound() << "|";
        file_out << headset.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Headset::updateVec(const Headset headset_in){
    for (Headset& headset: headset_vec){
        if (headset.getID() == headset_in.getID()){
            headset.setDescription(headset_in.getDescription());
            headset.setBrand(headset_in.getBrand());
            headset.setModel(headset_in.getModel());
            headset.setPrice(headset_in.getPrice());
            headset.setQuantity(headset_in.getQuantity());
            headset.setOnDisplay(headset_in.getOnDisplay());
            headset.setWireless(headset_in.getWireless());
            headset.setANC(headset_in.getANC());
            headset.setRGB(headset_in.getRGB());
            headset.setSurroundSound(headset_in.getSurroundSound());
            headset.setImagePath(headset_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/headset.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Headset headset: headset_vec){
        file_out << headset.getID() << "|";
        file_out << headset.getDescription() << "|";
        file_out << headset.getBrand() << "|";
        file_out << headset.getModel() << "|";
        file_out << headset.getPrice() << "|";
        file_out << headset.getQuantity() << "|";
        file_out << headset.getOnDisplay() << "|";
        file_out << headset.getWireless() << "|";
        file_out << headset.getANC() << "|";
        file_out << headset.getRGB() << "|";
        file_out << headset.getSurroundSound() << "|";
        file_out << headset.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Headset::readData() {
    std::ifstream file_in("../txt_files/headset.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "No data" << std::endl;
        return;
    }

    std::string id, description, brand, model, price, quantity, on_display;
    std::string wireless;
    std::string anc;
    std::string rgb;
    std::string surround_sound;
    std::string image_path;
    std::array<std::string*, 12> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &wireless, &anc, &rgb, &surround_sound, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::stringstream rowstream{row};
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }        
        Headset headset;
        headset.setID(id);
        headset.setDescription(description);
        headset.setBrand(brand);
        headset.setModel(model);
        headset.setPrice(std::stod(price));
        headset.setQuantity(std::stoi(quantity));
        headset.setOnDisplay(std::stoi(on_display));
        headset.setWireless(std::stoi(wireless));
        headset.setANC(std::stoi(anc));
        headset.setRGB(std::stoi(rgb));
        headset.setSurroundSound(std::stoi(surround_sound));
        headset.setImagePath(image_path);
        headset_vec.push_back(headset);
    }
    file_in.close();
    return;
}