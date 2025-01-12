#include "earbuds.h"

Earbuds::Earbuds(){}

Earbuds::Earbuds(const int q, const double p) : Peripherals(q, p){
    battery_life = 0;
    has_anc = false;
    water_resistant = false;
    generateId();
}

void Earbuds::setBatteryLife(const double b){
    battery_life = b;
}

void Earbuds::setANC(const bool a){
    has_anc = a;
}

void Earbuds::setWaterResistant(const bool w){
    water_resistant = w;
}

double Earbuds::getBatteryLife() const{
    return battery_life;
}

bool Earbuds::getANC() const{
    return has_anc;
}

bool Earbuds::getWaterResistant() const{
    return water_resistant;
}

void Earbuds::generateId(){
    std::ifstream file_in("../txt_files/earbuds.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Earbuds earbud: earbuds_vec){
            std::string id = earbud.getID();
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
    earbuds_vec.push_back(*this);
    std::ofstream file_out("../txt_files/earbuds.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Earbuds earbud: earbuds_vec){
        file_out << earbud.getID() << "|";
        file_out << earbud.getDescription() << "|";
        file_out << earbud.getBrand() << "|";
        file_out << earbud.getModel() << "|";
        file_out << earbud.getPrice() << "|";
        file_out << earbud.getQuantity() << "|";
        file_out << earbud.getOnDisplay() << "|";
        file_out << earbud.getBatteryLife() << "|";
        file_out << earbud.getANC() << "|";
        file_out << earbud.getWaterResistant() << "|";
        file_out << earbud.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Earbuds::updateVec(const Earbuds eb_in){
    for (Earbuds& eb: earbuds_vec){
        if (eb.getID() == eb_in.getID()){
            eb.setDescription(eb_in.getDescription());
            eb.setBrand(eb_in.getBrand());
            eb.setModel(eb_in.getModel());
            eb.setPrice(eb_in.getPrice());
            eb.setQuantity(eb_in.getQuantity());
            eb.setOnDisplay(eb_in.getOnDisplay());
            eb.setBatteryLife(eb_in.getBatteryLife());
            eb.setANC(eb_in.getANC());
            eb.setWaterResistant(eb_in.getWaterResistant());
            eb.setImagePath(eb_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/earbuds.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Earbuds earbud: earbuds_vec){
        file_out << earbud.getID() << "|";
        file_out << earbud.getDescription() << "|";
        file_out << earbud.getBrand() << "|";
        file_out << earbud.getModel() << "|";
        file_out << earbud.getPrice() << "|";
        file_out << earbud.getQuantity() << "|";
        file_out << earbud.getOnDisplay() << "|";
        file_out << earbud.getBatteryLife() << "|";
        file_out << earbud.getANC() << "|";
        file_out << earbud.getWaterResistant() << "|";
        file_out << earbud.getImagePath(); 
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Earbuds::readData(){
    std::ifstream file_in("../txt_files/earbuds.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string battery_l;
    std::string anc;
    std::string water_r;
    std::string image_path;
    std::array<std::string*, 11> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &battery_l, &anc, &water_r, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream{row};
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Earbuds earbud;
        earbud.setID(id);
        earbud.setDescription(description);
        earbud.setBrand(brand);
        earbud.setModel(model);
        earbud.setPrice(std::stod(price));
        earbud.setQuantity(std::stoi(quantity));
        earbud.setOnDisplay(std::stoi(on_display));
        earbud.setBatteryLife(std::stod(battery_l));
        earbud.setANC(std::stoi(anc));
        earbud.setWaterResistant(std::stoi(water_r));
        earbud.setImagePath(image_path);
        earbuds_vec.push_back(earbud);
    }
    file_in.close();
    return;
}