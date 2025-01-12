#include "pc_case.h"

PCCase::PCCase(){}

PCCase::PCCase(const int q, const double p) : ComputerParts(q, p){
    form_factor = "-";
    dimension = std::make_tuple(0.0, 0.0, 0.0);
    cooling_type = "-";
    max_gpu_length = 0.0;
    max_cpu_height = 0.0;
    fan_support = {};
    generateId();
}

void PCCase::setFormFactor(const std::string ff){
    form_factor = ff;
}

void PCCase::setDimension(const double l, const double w, const double h){
    dimension = std::make_tuple(l, w, h);
}

void PCCase::setCoolingType(const std::string ct){
    cooling_type = ct;
}

void PCCase::setMaxGPULength(const double mgl){
    max_gpu_length = mgl;
}

void PCCase::setMaxCPUHeight(const double mch){
    max_cpu_height = mch;
}

void PCCase::setFanSupport(const int pos, const std::string fs, const int q){
    fan_support[pos] = std::make_tuple(fs, q);
}

std::string PCCase::getFormFactor() const{
    return form_factor;
}

std::tuple<double, double, double> PCCase::getDimension() const{
    return dimension;
}

std::string PCCase::getCoolingType() const{
    return cooling_type;
}

double PCCase::getMaxGPULength() const{
    return max_gpu_length;
}

double PCCase::getMaxCPUHeight() const{
    return max_cpu_height;
}

std::array<std::tuple<std::string, int>, 3> PCCase::getFanSupport() const{
    return fan_support;
}

void PCCase::generateId(){
    std::ifstream file_in("../txt_files/pc_case.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const PCCase pc_case: pc_case_vec){
            std::string id = pc_case.getID(); // AZ0001
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
    pc_case_vec.push_back(*this);
    std::ofstream file_out("../txt_files/pc_case.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const PCCase pc_case: pc_case_vec){
        file_out << pc_case.getID() << "|";
        file_out << pc_case.getDescription() << "|";
        file_out << pc_case.getBrand() << "|";
        file_out << pc_case.getModel() << "|";
        file_out << pc_case.getPrice() << "|";
        file_out << pc_case.getQuantity() << "|";
        file_out << pc_case.getOnDisplay() << "|";
        file_out << pc_case.getFormFactor() << "|";
        file_out << std::get<0>(pc_case.getDimension()) << ",";
        file_out << std::get<1>(pc_case.getDimension()) << ",";
        file_out << std::get<2>(pc_case.getDimension()) << "|";
        file_out << pc_case.getCoolingType() << "|";
        file_out << pc_case.getMaxGPULength() << "|";
        file_out << pc_case.getMaxCPUHeight() << "|";
        for (std::tuple<std::string, int> fs: pc_case.getFanSupport()){
            file_out << std::get<0>(fs) << "|";
            file_out << std::get<1>(fs) << "|";
        }
        file_out << pc_case.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void PCCase::updateVec(const PCCase case_in){
    for (PCCase& pc_case: pc_case_vec){
        if (pc_case.getID() == case_in.getID()){
            pc_case.setDescription(case_in.getDescription());
            pc_case.setBrand(case_in.getBrand());
            pc_case.setModel(case_in.getModel());
            pc_case.setPrice(case_in.getPrice());
            pc_case.setQuantity(case_in.getQuantity());
            pc_case.setOnDisplay(case_in.getOnDisplay());
            pc_case.setFormFactor(case_in.getFormFactor());
            pc_case.setDimension(std::get<0>(case_in.getDimension()), std::get<1>(case_in.getDimension()), std::get<2>(case_in.getDimension()));
            pc_case.setCoolingType(case_in.getCoolingType());
            pc_case.setMaxGPULength(case_in.getMaxGPULength());
            pc_case.setMaxCPUHeight(case_in.getMaxCPUHeight());
            for (int i = 0; i < 3; i++){
                pc_case.setFanSupport(i, std::get<0>(case_in.getFanSupport()[i]), std::get<1>(case_in.getFanSupport()[i]));
            }
            pc_case.setImagePath(case_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/pc_case.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const PCCase pc_case: pc_case_vec){
        file_out << pc_case.getID() << "|";
        file_out << pc_case.getDescription() << "|";
        file_out << pc_case.getBrand() << "|";
        file_out << pc_case.getModel() << "|";
        file_out << pc_case.getPrice() << "|";
        file_out << pc_case.getQuantity() << "|";
        file_out << pc_case.getOnDisplay() << "|";
        file_out << pc_case.getFormFactor() << "|";
        file_out << std::get<0>(pc_case.getDimension()) << ",";
        file_out << std::get<1>(pc_case.getDimension()) << ",";
        file_out << std::get<2>(pc_case.getDimension()) << "|";
        file_out << pc_case.getCoolingType() << "|";
        file_out << pc_case.getMaxGPULength() << "|";
        file_out << pc_case.getMaxCPUHeight() << "|";
        for (std::tuple<std::string, int> fs: pc_case.getFanSupport()){
            file_out << std::get<0>(fs) << "|";
            file_out << std::get<1>(fs) << "|";
        }
        file_out << pc_case.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void PCCase::readData(){
    std::ifstream file_in("../txt_files/pc_case.txt", std::ios::in);
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
    std::string length, width, height;
    std::string cooling_type;
    std::string max_gpu_length;
    std::string max_cpu_height;
    std::string fan_size1;
    std::string fan_noise1;
    std::string fan_size2;
    std::string fan_noise2;
    std::string fan_size3;
    std::string fan_noise3;
    std::string image_path;
    std::array<std::string*, 21> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &form_factor, &length, &width, &height, &cooling_type, &max_gpu_length, &max_cpu_height, &fan_size1, &fan_noise1, &fan_size2, &fan_noise2, &fan_size3, &fan_noise3, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        PCCase pc_case;
        pc_case.setID(id);
        pc_case.setDescription(description);
        pc_case.setBrand(brand);
        pc_case.setModel(model);
        pc_case.setPrice(std::stod(price));
        pc_case.setQuantity(std::stoi(quantity));
        pc_case.setOnDisplay(std::stoi(on_display));
        pc_case.setFormFactor(form_factor);
        pc_case.setDimension(std::stod(length), std::stod(width), std::stod(height));
        pc_case.setCoolingType(cooling_type);
        pc_case.setMaxGPULength(std::stod(max_gpu_length));
        pc_case.setMaxCPUHeight(std::stod(max_cpu_height));
        pc_case.setFanSupport(0, fan_size1, std::stoi(fan_noise1));
        pc_case.setFanSupport(1, fan_size2, std::stoi(fan_noise2));
        pc_case.setFanSupport(2, fan_size3, std::stoi(fan_noise3));
        pc_case.setImagePath(image_path);
        pc_case_vec.push_back(pc_case);
    }
    file_in.close();
    return;
}   
