#include "laptop.h"

Laptop::Laptop(){}

Laptop::Laptop(const int q, const double p) : Devices(q, p){
    cpu = "-";
    gpu = "-";
    memory = "-";
    storage = {};
    os = "-";
    display = "-";
    battery = std::make_tuple(0.0, 0);
    dimensions = std::make_tuple(0.0, 0.0, 0.0, 0.0);
    weight = 0.0;
    is_touchscreen = false;
    is_gaming = false;
    generateId();
}

void Laptop::setCPU(const std::string c){
    cpu = c;
}

void Laptop::setGPU(const std::string g){
    gpu = g;
}

void Laptop::setMemory(const std::string m){
    memory = m;
}

void Laptop::addStorage(const std::string s){
    storage.push_back(s);
}

void Laptop::clearStorage(){
    storage.clear();
}

void Laptop::setOS(const std::string o){
    os = o;
}

void Laptop::setDisplay(const std::string d){
    display = d;
}

void Laptop::setBattery(const double c, const int n){
    battery = std::make_tuple(c, n);
}

void Laptop::setDimensions(const double l, const double w, const double h, const double d){
    dimensions = std::make_tuple(l, w, h, d);
}

void Laptop::setWeight(const double w){
    weight = w;
}

void Laptop::setTouchscreen(const bool t){
    is_touchscreen = t;
}

void Laptop::setGaming(const bool g){
    is_gaming = g;
}

std::string Laptop::getCPU() const{
    return cpu;
}

std::string Laptop::getGPU() const{
    return gpu;
}

std::string Laptop::getMemory() const{
    return memory;
}

std::vector<std::string> Laptop::getStorage() const{
    return storage;
}

std::string Laptop::getOS() const{
    return os;
}

std::string Laptop::getDisplay() const{
    return display;
}

std::tuple<double, int> Laptop::getBattery() const{
    return battery;
}

std::tuple<double, double, double, double> Laptop::getDimensions() const{
    return dimensions;
}

double Laptop::getWeight() const{
    return weight;
}

bool Laptop::getTouchscreen() const{
    return is_touchscreen;
}

bool Laptop::getGaming() const{
    return is_gaming;
}

void Laptop::generateId(){
    std::ifstream file_in("../txt_files/laptop.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Laptop laptop: laptop_vec){
            std::string id = laptop.getID();
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
    laptop_vec.push_back(*this);
    std::ofstream file_out("../txt_files/laptop.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Laptop laptop: laptop_vec){
        file_out << laptop.getID() << "|";
        file_out << laptop.getDescription() << "|";
        file_out << laptop.getBrand() << "|";
        file_out << laptop.getModel() << "|";
        file_out << laptop.getPrice() << "|";
        file_out << laptop.getQuantity() << "|";
        file_out << laptop.getOnDisplay() << "|";
        file_out << laptop.getCPU() << "|";
        file_out << laptop.getGPU() << "|";
        file_out << laptop.getMemory() << "|";
        for (const std::string s: laptop.getStorage()){
            file_out << s << ",";
        }
        file_out << "|";
        file_out << laptop.getOS() << "|";
        file_out << laptop.getDisplay() << "|";
        file_out << std::get<0>(laptop.getBattery()) << "|"; 
        file_out << std::get<1>(laptop.getBattery()) << "|";
        file_out << std::get<0>(laptop.getDimensions()) << "|";
        file_out << std::get<1>(laptop.getDimensions()) << "|";
        file_out << std::get<2>(laptop.getDimensions()) << "|";
        file_out << std::get<3>(laptop.getDimensions()) << "|";
        file_out << laptop.getWeight() << "|";
        file_out << laptop.getTouchscreen() << "|";
        file_out << laptop.getGaming() << "|";
        file_out << laptop.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Laptop::updateVec(const Laptop lap_in){
    for (Laptop &lap: laptop_vec){
        if (lap.getID() == lap_in.getID()){
            lap.setDescription(lap_in.getDescription());
            lap.setBrand(lap_in.getBrand());
            lap.setModel(lap_in.getModel());
            lap.setPrice(lap_in.getPrice());
            lap.setQuantity(lap_in.getQuantity());
            lap.setOnDisplay(lap_in.getOnDisplay());
            lap.setCPU(lap_in.getCPU());
            lap.setGPU(lap_in.getGPU());
            lap.setMemory(lap_in.getMemory());
            lap.clearStorage();
            for (const std::string storage: lap_in.getStorage()){
                lap.addStorage(storage);
            }
            lap.setOS(lap_in.getOS());
            lap.setDisplay(lap_in.getDisplay());
            lap.setBattery(std::get<0>(lap_in.getBattery()), std::get<1>(lap_in.getBattery()));
            lap.setDimensions(std::get<0>(lap_in.getDimensions()), 
                            std::get<1>(lap_in.getDimensions()), 
                            std::get<2>(lap_in.getDimensions()), 
                            std::get<3>(lap_in.getDimensions()));
            lap.setWeight(lap_in.getWeight());
            lap.setTouchscreen(lap_in.getTouchscreen());
            lap.setGaming(lap_in.getGaming());
            lap.setImagePath(lap_in.getImagePath());
            break;            
        }
    }
    std::ofstream file_out("../txt_files/laptop.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Laptop laptop: laptop_vec){
        file_out << laptop.getID() << "|";
        file_out << laptop.getDescription() << "|";
        file_out << laptop.getBrand() << "|";
        file_out << laptop.getModel() << "|";
        file_out << laptop.getPrice() << "|";
        file_out << laptop.getQuantity() << "|";
        file_out << laptop.getOnDisplay() << "|";
        file_out << laptop.getCPU() << "|";
        file_out << laptop.getGPU() << "|";
        file_out << laptop.getMemory() << "|";
        for (const std::string s: laptop.getStorage()){
            file_out << s << ",";
        }
        file_out << "|";
        file_out << laptop.getOS() << "|";
        file_out << laptop.getDisplay() << "|";
        file_out << std::get<0>(laptop.getBattery()) << "|"; 
        file_out << std::get<1>(laptop.getBattery()) << "|";
        file_out << std::get<0>(laptop.getDimensions()) << "|";
        file_out << std::get<1>(laptop.getDimensions()) << "|";
        file_out << std::get<2>(laptop.getDimensions()) << "|";
        file_out << std::get<3>(laptop.getDimensions()) << "|";
        file_out << laptop.getWeight() << "|";
        file_out << laptop.getTouchscreen() << "|";
        file_out << laptop.getGaming() << "|";
        file_out << laptop.getImagePath();
        file_out << std::endl;
    }
}

void Laptop::readData(){
    std::ifstream file_in("../txt_files/laptop.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string cpu;
    std::string gpu;
    std::string memory;
    std::string storage;
    std::string os;
    std::string display;
    std::string battery_capacity;
    std::string battery_no_cells;
    std::string length;
    std::string width;
    std::string height;
    std::string diagonal;
    std::string weight;
    std::string touchscreen;
    std::string gaming;
    std::string image_path;
    std::array<std::string*, 24> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &cpu, &gpu, &memory, &storage, &os, &display, &battery_capacity, &battery_no_cells, &length, &width, &height, &diagonal, &weight, &touchscreen, &gaming, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Laptop lap;
        lap.setID(id);
        lap.setDescription(description);
        lap.setBrand(brand);
        lap.setModel(model);
        lap.setPrice(std::stod(price));
        lap.setQuantity(std::stoi(quantity));
        lap.setOnDisplay(std::stoi(on_display));
        lap.setCPU(cpu);
        lap.setGPU(gpu);
        lap.setMemory(memory);
        std::stringstream s_storage(storage);
        std::string storage_type;
        while (std::getline(s_storage, storage_type, ',')){
            lap.addStorage(storage_type);
        }
        lap.setOS(os);
        lap.setDisplay(display);
        lap.setBattery(std::stod(battery_capacity), std::stoi(battery_no_cells));
        lap.setDimensions(std::stod(length), std::stod(width), std::stod(height), std::stod(diagonal));
        lap.setWeight(std::stod(weight));
        lap.setTouchscreen(std::stoi(touchscreen));
        lap.setGaming(std::stoi(gaming));
        lap.setImagePath(image_path);
        laptop_vec.push_back(lap);
    }
    file_in.close();
    return;
}