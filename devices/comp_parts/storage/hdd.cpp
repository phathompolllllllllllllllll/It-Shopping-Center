#include "hdd.h"

HDD::HDD(){}

HDD::HDD(const int q, const double p) : Storage(q, p){
    rotation_speed = 0;
    cache = 0;
    power_consumption = std::make_tuple(0, 0, 0);
    generateId();
}

void HDD::setRotationSpeed(const int r){
    rotation_speed = r;
}

void HDD::setCache(const int c){
    cache = c;
}

void HDD::setPowerConsumption(const double i, const double r, const double w){
    power_consumption = std::make_tuple(i, r, w);
}

int HDD::getRotationSpeed() const{
    return rotation_speed;
}

int HDD::getCache() const{
    return cache;
}

std::tuple<double, double, double> HDD::getPowerConsumption() const{
    return power_consumption;
}

void HDD::generateId(){
    std::ifstream file_in("../txt_files/hdd.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const HDD hdd: hdd_vec){
            std::string id = hdd.getID(); // AZ0001
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
    hdd_vec.push_back(*this);
    std::ofstream file_out("../txt_files/hdd.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const HDD hdd: hdd_vec){
        file_out << hdd.getID() << "|";
        file_out << hdd.getDescription() << "|";
        file_out << hdd.getBrand() << "|";
        file_out << hdd.getModel() << "|";
        file_out << hdd.getPrice() << "|";
        file_out << hdd.getQuantity() << "|";
        file_out << hdd.getOnDisplay() << "|";
        file_out << hdd.getStorageCapacity() << "|";
        file_out << hdd.getStorageSpeed() << "|";
        file_out << hdd.getInterface() << "|";
        file_out << hdd.getFormFactor() << "|";
        file_out << hdd.getRotationSpeed() << "|";
        file_out << hdd.getCache() << "|";
        file_out << std::get<0>(hdd.getPowerConsumption()) << "|";
        file_out << std::get<1>(hdd.getPowerConsumption()) << "|";
        file_out << std::get<2>(hdd.getPowerConsumption()) << "|";
        file_out << hdd.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void HDD::updateVec(const HDD hdd_in){
    for (HDD& hdd: hdd_vec){
        if(hdd.getID() == hdd_in.getID()){
            hdd.setDescription(hdd_in.getDescription());
            hdd.setBrand(hdd_in.getBrand());
            hdd.setModel(hdd_in.getModel());
            hdd.setPrice(hdd_in.getPrice());
            hdd.setQuantity(hdd_in.getQuantity());
            hdd.setOnDisplay(hdd_in.getOnDisplay());
            hdd.setStorageCapacity(hdd_in.getStorageCapacity());
            hdd.setStorageSpeed(hdd_in.getStorageSpeed());
            hdd.setInterface(hdd_in.getInterface());
            hdd.setFormFactor(hdd_in.getFormFactor());
            hdd.setRotationSpeed(hdd_in.getRotationSpeed());
            hdd.setCache(hdd_in.getCache());
            hdd.setPowerConsumption(std::get<0>(hdd_in.getPowerConsumption()),
                                     std::get<1>(hdd_in.getPowerConsumption()),
                                     std::get<2>(hdd_in.getPowerConsumption()));
            hdd.setImagePath(hdd_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/hdd.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const HDD hdd: hdd_vec){
        file_out << hdd.getID() << "|";
        file_out << hdd.getDescription() << "|";
        file_out << hdd.getBrand() << "|";
        file_out << hdd.getModel() << "|";
        file_out << hdd.getPrice() << "|";
        file_out << hdd.getQuantity() << "|";
        file_out << hdd.getOnDisplay() << "|";
        file_out << hdd.getStorageCapacity() << "|";
        file_out << hdd.getStorageSpeed() << "|";
        file_out << hdd.getInterface() << "|";
        file_out << hdd.getFormFactor() << "|";
        file_out << hdd.getRotationSpeed() << "|";
        file_out << hdd.getCache() << "|";
        file_out << std::get<0>(hdd.getPowerConsumption()) << "|";
        file_out << std::get<1>(hdd.getPowerConsumption()) << "|";
        file_out << std::get<2>(hdd.getPowerConsumption()) << "|";
        file_out << hdd.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void HDD::readData(){
    std::ifstream file_in("../txt_files/hdd.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string storage_c;
    std::string storage_s;
    std::string interface;
    std::string form_factor;
    std::string rotation_speed;
    std::string cache;
    std::string idle_power;
    std::string read_power;
    std::string write_power;
    std::string image_path;
    std::array<std::string*, 17> data = {&id, &description, &brand, &model, &price, &quantity, &on_display, &storage_c, &storage_s, &interface, &form_factor, &rotation_speed, &cache, &idle_power, &read_power, &write_power, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        HDD hdd;
        hdd.setID(id);
        hdd.setDescription(description);
        hdd.setBrand(brand);
        hdd.setModel(model);
        hdd.setPrice(std::stod(price));
        hdd.setQuantity(std::stoi(quantity));
        hdd.setOnDisplay(std::stoi(on_display));
        hdd.setStorageCapacity(std::stoi(storage_c));
        hdd.setStorageSpeed(std::stoi(storage_s));
        hdd.setInterface(interface);
        hdd.setFormFactor(form_factor);
        hdd.setRotationSpeed(std::stoi(rotation_speed));
        hdd.setCache(std::stoi(cache));
        hdd.setPowerConsumption(std::stod(idle_power), std::stod(read_power), std::stod(write_power));
        hdd.setImagePath(image_path);
        hdd_vec.push_back(hdd);
    }
    file_in.close();
    return;
}
