#include "headphones.h"

Headphones::Headphones(){}

Headphones::Headphones(const int q, const double p) : Peripherals(q, p){
    has_anc = false;
    is_wireless = false;
    surround_sound = false;
    generateId();
}


void Headphones::setANC(const bool a){
    has_anc = a;
}

void Headphones::setWireless(const bool w){
    is_wireless = w;
}

void Headphones::setSurroundSound(const bool s){
    surround_sound = s;
}

bool Headphones::getANC() const{
    return has_anc;
}

bool Headphones::getWireless() const{
    return is_wireless;
}

bool Headphones::getSurroundSound() const{
    return surround_sound;
}

void Headphones::generateId(){
    std::ifstream file_in("../txt_files/headphones.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Headphones headphone: headphones_vec){
            std::string id = headphone.getID();
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
    headphones_vec.push_back(*this);
    std::ofstream file_out("../txt_files/headphones.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Headphones headphones: headphones_vec){
        file_out << headphones.getID() << "|";
        file_out << headphones.getDescription() << "|";
        file_out << headphones.getBrand() << "|";
        file_out << headphones.getModel() << "|";
        file_out << headphones.getPrice() << "|";
        file_out << headphones.getQuantity() << "|";
        file_out << headphones.getOnDisplay() << "|";
        file_out << headphones.getANC() << "|";
        file_out << headphones.getWireless() << "|";
        file_out << headphones.getSurroundSound() << "|";
        file_out << headphones.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Headphones::updateVec(const Headphones hp_in){
    for (Headphones& hp: headphones_vec){
        if (hp.getID() == hp_in.getID()){
            hp.setDescription(hp_in.getDescription());
            hp.setBrand(hp_in.getBrand());
            hp.setModel(hp_in.getModel());
            hp.setPrice(hp_in.getPrice());
            hp.setQuantity(hp_in.getQuantity());
            hp.setOnDisplay(hp_in.getOnDisplay());
            hp.setANC(hp_in.getANC());
            hp.setWireless(hp_in.getWireless());
            hp.setSurroundSound(hp_in.getSurroundSound());
            hp.setImagePath(hp_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/headphones.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Headphones headphones: headphones_vec){
        file_out << headphones.getID() << "|";
        file_out << headphones.getDescription() << "|";
        file_out << headphones.getBrand() << "|";
        file_out << headphones.getModel() << "|";
        file_out << headphones.getPrice() << "|";
        file_out << headphones.getQuantity() << "|";
        file_out << headphones.getOnDisplay() << "|";
        file_out << headphones.getANC() << "|";
        file_out << headphones.getWireless() << "|";
        file_out << headphones.getSurroundSound() << "|";
        file_out << headphones.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Headphones::readData() {
    std::ifstream file_in("../txt_files/headphones.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string anc;
    std::string wireless;
    std::string surround_sound;
    std::string image_path;
    std::array<std::string*, 11> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &anc, &wireless, &surround_sound, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Headphones hp;
        hp.setID(id);
        hp.setDescription(description);
        hp.setBrand(brand);
        hp.setModel(model);
        hp.setPrice(std::stod(price));
        hp.setQuantity(std::stoi(quantity));
        hp.setOnDisplay(std::stoi(on_display));
        hp.setANC(std::stoi(anc));
        hp.setWireless(std::stoi(wireless));
        hp.setSurroundSound(std::stoi(surround_sound));
        hp.setImagePath(image_path);
        headphones_vec.push_back(hp);
    }
    file_in.close();
    return;
}