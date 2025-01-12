#include "cooling_u.h"

CoolingUnit::CoolingUnit(){}

CoolingUnit::CoolingUnit(const int q, const double p) : ComputerParts(q, p){
        type = "-";
        form_factor = "-";
        cool_capacity = 0; // watts
        dimension = std::make_tuple(0.0, 0.0, 0.0);
        noise_level = 0; // dB
        fan_speed = 0;
        is_rgb = false;
        generateId();
}

void CoolingUnit::setType(const std::string t){
    type = t;
}

void CoolingUnit::setFormFactor(const std::string ff){
    form_factor = ff;
}

void CoolingUnit::setCoolCapacity(const int cc){
    cool_capacity = cc;
}

void CoolingUnit::setDimension(const double l, const double w, const double h){
    dimension = std::make_tuple(l, w, h);
}

void CoolingUnit::setNoiseLevel(const int nl){
    noise_level = nl;
}

void CoolingUnit::setFanSpeed(const int fs){
    fan_speed = fs;
}

void CoolingUnit::setIsRgb(const bool i_rgb){
    is_rgb = i_rgb;
}

std::string CoolingUnit::getType() const{
    return type;
}

std::string CoolingUnit::getFormFactor() const{
    return form_factor;
}

int CoolingUnit::getCoolCapacity() const{
    return cool_capacity;
}

std::tuple<double, double, double> CoolingUnit::getDimension() const{
    return dimension;
}

int CoolingUnit::getNoiseLevel() const{
    return noise_level;
}

int CoolingUnit::getFanSpeed() const{
    return fan_speed;
}

bool CoolingUnit::getIsRgb() const{
    return is_rgb;
}

void CoolingUnit::generateId(){
    std::ifstream file_in("../txt_files/cooling_u.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }

    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const CoolingUnit cu: cooling_unit_vec){
            std::string id = cu.getID(); // AZ0001
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
    cooling_unit_vec.push_back(*this);
    std::ofstream file_out("../txt_files/cooling_u.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const CoolingUnit cu: cooling_unit_vec){
        file_out << cu.getID() << "|";
        file_out << cu.getDescription() << "|";
        file_out << cu.getBrand() << "|";
        file_out << cu.getModel() << "|";
        file_out << cu.getPrice() << "|";
        file_out << cu.getQuantity() << "|";
        file_out << cu.getOnDisplay() << "|";
        file_out << cu.getType() << "|";
        file_out << cu.getFormFactor() << "|";
        file_out << cu.getCoolCapacity() << "|";
        file_out << std::get<0>(cu.getDimension()) << "|";
        file_out << std::get<1>(cu.getDimension()) << "|";
        file_out << std::get<2>(cu.getDimension()) << "|";
        file_out << cu.getNoiseLevel() << "|";
        file_out << cu.getFanSpeed() << "|";
        file_out << cu.getIsRgb() << "|";
        file_out << cu.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void CoolingUnit::updateVec(const CoolingUnit cu_in){
    for (CoolingUnit& cu: cooling_unit_vec){
        if (cu.getID() == cu_in.getID()){
            cu.setDescription(cu_in.getDescription());
            cu.setBrand(cu_in.getBrand());
            cu.setModel(cu_in.getModel());
            cu.setPrice(cu_in.getPrice());
            cu.setQuantity(cu_in.getQuantity());
            cu.setOnDisplay(cu_in.getOnDisplay());
            cu.setType(cu_in.getType());
            cu.setFormFactor(cu_in.getFormFactor());
            cu.setCoolCapacity(cu_in.getCoolCapacity());
            cu.setDimension(std::get<0>(cu_in.getDimension()),
                             std::get<1>(cu_in.getDimension()),
                             std::get<2>(cu_in.getDimension()));
            cu.setNoiseLevel(cu_in.getNoiseLevel());
            cu.setFanSpeed(cu_in.getFanSpeed());
            cu.setIsRgb(cu_in.getIsRgb());
            cu.setImagePath(cu_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/cooling_u.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const CoolingUnit cu: cooling_unit_vec){
        file_out << cu.getID() << "|";
        file_out << cu.getDescription() << "|";
        file_out << cu.getBrand() << "|";
        file_out << cu.getModel() << "|";
        file_out << cu.getPrice() << "|";
        file_out << cu.getQuantity() << "|";
        file_out << cu.getOnDisplay() << "|";
        file_out << cu.getType() << "|";
        file_out << cu.getFormFactor() << "|";
        file_out << cu.getCoolCapacity() << "|";
        file_out << std::get<0>(cu.getDimension()) << "|";
        file_out << std::get<1>(cu.getDimension()) << "|";
        file_out << std::get<2>(cu.getDimension()) << "|";
        file_out << cu.getNoiseLevel() << "|";
        file_out << cu.getFanSpeed() << "|";
        file_out << cu.getIsRgb() << "|";
        file_out << cu.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void CoolingUnit::readData(){
    std::ifstream file_in("../txt_files/cooling_u.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    std::string id, desc, brand, model, price, quantity, on_display;
    std::string type;
    std::string form_factor;
    std::string cool_capacity;
    std::string l, w, h;
    std::string noise_level;
    std::string fan_speed;
    std::string is_rgb;
    std::string image_path;
    std::array<std::string*, 17> data{&id, &desc, &brand, &model, &price, &quantity, &on_display, &type, &form_factor, &cool_capacity, &l, &w, &h, &noise_level, &fan_speed, &is_rgb, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream s_row(row);
        for (std::string* data_ptr: data){
            std::getline(s_row, *data_ptr, '|');
        }
        CoolingUnit cu;
        cu.setID(id);
        cu.setDescription(desc);
        cu.setBrand(brand);
        cu.setModel(model);
        cu.setPrice(std::stod(price));
        cu.setQuantity(std::stoi(quantity));
        cu.setOnDisplay(std::stoi(on_display));
        cu.setType(type);
        cu.setFormFactor(form_factor);
        cu.setCoolCapacity(std::stoi(cool_capacity));
        cu.setDimension(std::stod(l), std::stod(w), std::stod(h));
        cu.setNoiseLevel(std::stoi(noise_level));
        cu.setFanSpeed(std::stoi(fan_speed));
        cu.setIsRgb(std::stoi(is_rgb));
        cu.setImagePath(image_path);
        cooling_unit_vec.push_back(cu);
    }
    file_in.close();
    return;
}




