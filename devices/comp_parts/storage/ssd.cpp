#include "ssd.h"

SSD::SSD(){}

SSD::SSD(const int q, const double p) : Storage(q, p){
    power_consumption = 0;
    generateId();
}

void SSD::setPowerConsumption(const int p){
    power_consumption = p;
}

int SSD::getPowerConsumption() const{
    return power_consumption;
}

void SSD::generateId(){
    std::ifstream file_in("../txt_files/ssd.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File not found" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const SSD ssd: ssd_vec){
            std::string id = ssd.getID(); // AZ0001
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
    ssd_vec.push_back(*this);
    std::ofstream file_out("../txt_files/ssd.txt", std::ios::out);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File not found" << std::endl;
        return;
    }
    for (const SSD ssd: ssd_vec){
        file_out << ssd.getID() << "|";
        file_out << ssd.getDescription() << "|";
        file_out << ssd.getBrand() << "|";
        file_out << ssd.getModel() << "|";
        file_out << ssd.getPrice() << "|";
        file_out << ssd.getQuantity() << "|";
        file_out << ssd.getOnDisplay() << "|";
        file_out << ssd.getStorageCapacity() << "|";
        file_out << ssd.getStorageSpeed() << "|";
        file_out << ssd.getInterface() << "|";
        file_out << ssd.getFormFactor() << "|";
        file_out << ssd.getPowerConsumption() << "|";
        file_out << ssd.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void SSD::updateVec(const SSD ssd_in){
    for (SSD& ssd: ssd_vec){
        if (ssd.getID() == ssd_in.getID()){
            ssd.setDescription(ssd_in.getDescription());
            ssd.setBrand(ssd_in.getBrand());
            ssd.setModel(ssd_in.getModel());
            ssd.setPrice(ssd_in.getPrice());
            ssd.setQuantity(ssd_in.getQuantity());
            ssd.setOnDisplay(ssd_in.getOnDisplay());
            ssd.setStorageCapacity(ssd_in.getStorageCapacity());
            ssd.setStorageSpeed(ssd_in.getStorageSpeed());
            ssd.setInterface(ssd_in.getInterface());
            ssd.setFormFactor(ssd_in.getFormFactor());
            ssd.setPowerConsumption(ssd_in.getPowerConsumption());
            ssd.setImagePath(ssd_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/ssd.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File not found" << std::endl;
        return;
    }
    for (const SSD ssd: ssd_vec){
        file_out << ssd.getID() << "|";
        file_out << ssd.getDescription() << "|";
        file_out << ssd.getBrand() << "|";
        file_out << ssd.getModel() << "|";
        file_out << ssd.getPrice() << "|";
        file_out << ssd.getQuantity() << "|";
        file_out << ssd.getOnDisplay() << "|";
        file_out << ssd.getStorageCapacity() << "|";
        file_out << ssd.getStorageSpeed() << "|";
        file_out << ssd.getInterface() << "|";
        file_out << ssd.getFormFactor() << "|";
        file_out << ssd.getPowerConsumption() << "|";
        file_out << ssd.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void SSD::readData(){
    std::ifstream file_in("../txt_files/ssd.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File not found" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        file_in.close();
        return;
    }
    std::string id, desc, brand, model, price, quantity, on_display;
    std::string storage_c;
    std::string storage_s;
    std::string interface;
    std::string form_factor;
    std::string power_consumption;
    std::string image_path;
    std::array<std::string*, 13> data = {&id, &desc, &brand, &model, &price, &quantity, &on_display, &storage_c, &storage_s, &interface, &form_factor, &power_consumption, &image_path};
    
    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        SSD ssd;
        ssd.setID(id);
        ssd.setDescription(desc);
        ssd.setBrand(brand);
        ssd.setModel(model);
        ssd.setPrice(std::stod(price));
        ssd.setQuantity(std::stoi(quantity));
        ssd.setOnDisplay(std::stoi(on_display));
        ssd.setStorageCapacity(std::stoi(storage_c));
        ssd.setStorageSpeed(std::stoi(storage_s));
        ssd.setInterface(interface);
        ssd.setFormFactor(form_factor);
        ssd.setPowerConsumption(std::stoi(power_consumption));
        ssd.setImagePath(image_path);
        ssd_vec.push_back(ssd);
    }
    file_in.close();
    return;
}

