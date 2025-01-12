#include "psu.h"

PSU::PSU(){}

PSU::PSU(const int q, const double p) : ComputerParts(q, p){
    form_factor = "-";
    efficiency = "-";
    modular = "-";
    wattage = 0;
    fan = std::make_tuple("-", 0);
    dimension = std::make_tuple(0.0, 0.0, 0.0);
    generateId();
}

void PSU::setFormFactor(const std::string ff){
    form_factor = ff;
}

void PSU::setEfficiency(const std::string e){
    efficiency = e;
}

void PSU::setModular(const std::string m){
    modular = m;
}

void PSU::setWattage(const int w){
    wattage = w;
}

void PSU::setFan(const std::string size, const int noise){
    fan = std::make_tuple(size, noise);
}

void PSU::setDimension(const double l, const double w, const double h){
    dimension = std::make_tuple(l, w, h);
}

std::string PSU::getFormFactor() const{
    return form_factor;
}

std::string PSU::getEfficiency() const{
    return efficiency;
}

std::string PSU::getModular() const{
    return modular;
}

int PSU::getWattage() const{
    return wattage;
}

std::tuple<std::string, int> PSU::getFan() const{
    return fan;
}

std::tuple<double, double, double> PSU::getDimension() const{
    return dimension;
}

void PSU::generateId(){
    std::ifstream file_in("../txt_files/psu.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const PSU psu: psu_vec){
            std::string id = psu.getID(); // AZ0001
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
    psu_vec.push_back(*this);
    std::ofstream file_out("../txt_files/psu.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const PSU psu: psu_vec){
        file_out << psu.getID() << "|";
        file_out << psu.getBrand() << "|";
        file_out << psu.getModel() << "|";
        file_out << psu.getPrice() << "|";        
        file_out << psu.getQuantity() << "|";
        file_out << psu.getOnDisplay() << "|";
        file_out << psu.getFormFactor() << "|";
        file_out << psu.getEfficiency() << "|";
        file_out << psu.getModular() << "|";
        file_out << psu.getWattage() << "|";
        file_out << std::get<0>(psu.getFan()) << "|";
        file_out << std::get<1>(psu.getFan()) << "|";
        file_out << std::get<0>(psu.getDimension()) << "|";
        file_out << std::get<1>(psu.getDimension()) << "|";
        file_out << std::get<2>(psu.getDimension()) << "|";
        file_out << psu.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void PSU::updateVec(const PSU psu_in){
    for (PSU& psu: psu_vec){
        if (psu.getID() == psu_in.getID()){
            psu.setDescription(psu_in.getDescription());
            psu.setBrand(psu_in.getBrand());
            psu.setModel(psu_in.getModel());
            psu.setPrice(psu_in.getPrice());
            psu.setQuantity(psu_in.getQuantity());
            psu.setOnDisplay(psu_in.getOnDisplay());
            psu.setFormFactor(psu_in.getFormFactor());
            psu.setEfficiency(psu_in.getEfficiency());
            psu.setModular(psu_in.getModular());
            psu.setWattage(psu_in.getWattage());
            psu.setFan(std::get<0>(psu_in.getFan()), std::get<1>(psu_in.getFan()));
            psu.setDimension(std::get<0>(psu_in.getDimension()), 
                            std::get<1>(psu_in.getDimension()), 
                            std::get<2>(psu_in.getDimension()));
            psu.setImagePath(psu_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/psu.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const PSU psu: psu_vec){
        file_out << psu.getID() << "|";
        file_out << psu.getBrand() << "|";
        file_out << psu.getModel() << "|";
        file_out << psu.getPrice() << "|";        
        file_out << psu.getQuantity() << "|";
        file_out << psu.getOnDisplay() << "|";
        file_out << psu.getFormFactor() << "|";
        file_out << psu.getEfficiency() << "|";
        file_out << psu.getModular() << "|";
        file_out << psu.getWattage() << "|";
        file_out << std::get<0>(psu.getFan()) << "|";
        file_out << std::get<1>(psu.getFan()) << "|";
        file_out << std::get<0>(psu.getDimension()) << "|";
        file_out << std::get<1>(psu.getDimension()) << "|";
        file_out << std::get<2>(psu.getDimension()) << "|";
        file_out << psu.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void PSU::readData(){
    std::ifstream file_in("../txt_files/psu.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string form_factor;
    std::string efficiency;
    std::string modular;
    std::string wattage;
    std::string fan_size;
    std::string fan_noise;
    std::string length;
    std::string width;
    std::string height;
    std::string image_path;
    std::array<std::string*, 17> data{&id, &brand, &model, &price, &quantity, &on_display, &form_factor, &efficiency, &modular, &wattage, &fan_size, &fan_noise, &length, &width, &height, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        PSU psu;
        psu.setID(id);
        psu.setDescription(description);
        psu.setBrand(brand);
        psu.setModel(model);
        psu.setPrice(std::stod(price));
        psu.setQuantity(std::stoi(quantity));
        psu.setOnDisplay(std::stoi(on_display));
        psu.setFormFactor(form_factor);
        psu.setEfficiency(efficiency);
        psu.setModular(modular);
        psu.setWattage(std::stoi(wattage));
        psu.setFan(fan_size, std::stoi(fan_noise));
        psu.setDimension(std::stod(length), std::stod(width), std::stod(height));
        psu.setImagePath(image_path);
        psu_vec.push_back(psu);
    }
    file_in.close();
    return;
}