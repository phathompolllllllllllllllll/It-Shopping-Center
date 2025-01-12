#include "desktop.h"

Desktop::Desktop(){}

Desktop::Desktop(const int q, const double p) : Devices(q, p){
    cpu = "-";
    gpu = "-";
    memory = "-";
    storage = {};
    os = "-";
    motherboard = "-";
    psu = "-";
    pc_case = "-";
    cooling = "-";
    generateId();
}

void Desktop::setCPU(const std::string c){
    cpu = c;
}

void Desktop::setGPU(const std::string g){
    gpu = g;
}

void Desktop::setMemory(const std::string m){
    memory = m;
}

void Desktop::addStorage(const std::string s){
    storage.push_back(s);
}

void Desktop::clearStorage(){
    storage.clear();
}

void Desktop::setOS(const std::string o){
    os = o;
}

void Desktop::setMotherboard(const std::string mb){
    motherboard = mb;
}

void Desktop::setPSU(const std::string p){
    psu = p;
}

void Desktop::setPCCase(const std::string pc){
    pc_case = pc;
}

void Desktop::setCooling(const std::string c){
    cooling = c;
}

std::string Desktop::getCPU() const{
    return cpu;
}

std::string Desktop::getGPU() const{
    return gpu;
}

std::string Desktop::getMemory() const{
    return memory;
}

std::vector<std::string> Desktop::getStorage() const{
    return storage;
}

std::string Desktop::getOS() const{
    return os;
}

std::string Desktop::getMotherboard() const{
    return motherboard;
}

std::string Desktop::getPSU() const{
    return psu;
}

std::string Desktop::getPCCase() const{
    return pc_case;
}

std::string Desktop::getCooling() const{
    return cooling;
}

void Desktop::generateId(){
    std::ifstream file_in("../txt_files/desktop.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Desktop desktop: desktop_vec){
            std::string id = desktop.getID(); // AZ0001
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
    desktop_vec.push_back(*this);
    std::ofstream file_out("../txt_files/desktop.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Desktop desktop: desktop_vec){
        file_out << desktop.getID() << "|";
        file_out << desktop.getDescription() << "|";
        file_out << desktop.getBrand() << "|";
        file_out << desktop.getModel() << "|";
        file_out << desktop.getPrice() << "|";
        file_out << desktop.getQuantity() << "|";
        file_out << desktop.getOnDisplay() << "|";
        file_out << desktop.getCPU() << "|";
        file_out << desktop.getGPU() << "|";
        file_out << desktop.getMemory() << "|";
        for (std::string storage: desktop.getStorage()){
            file_out << storage << ",";
        }
        file_out << "|";
        file_out << desktop.getOS() << "|";
        file_out << desktop.getMotherboard() << "|";
        file_out << desktop.getPSU() << "|";
        file_out << desktop.getPCCase() << "|";
        file_out << desktop.getCooling() << "|";
        file_out << desktop.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Desktop::updateVec(const Desktop dt_in){
    for (Desktop& dt: desktop_vec){
        if (dt.getID() == dt_in.getID()){
            dt.setDescription(dt_in.getDescription());
            dt.setBrand(dt_in.getBrand());
            dt.setModel(dt_in.getModel());
            dt.setPrice(dt_in.getPrice());
            dt.setQuantity(dt_in.getQuantity());
            dt.setOnDisplay(dt_in.getOnDisplay());
            dt.setCPU(dt_in.getCPU());
            dt.setGPU(dt_in.getGPU());
            dt.setMemory(dt_in.getMemory());
            dt.clearStorage();
            for (const std::string storage: dt_in.getStorage()){
                dt.addStorage(storage);
            }
            dt.setOS(dt_in.getOS());
            dt.setMotherboard(dt_in.getMotherboard());
            dt.setPSU(dt_in.getPSU());
            dt.setPCCase(dt_in.getPCCase());
            dt.setCooling(dt_in.getCooling());
            dt.setImagePath(dt_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/desktop.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Desktop desktop: desktop_vec){
        file_out << desktop.getID() << "|";
        file_out << desktop.getDescription() << "|";
        file_out << desktop.getBrand() << "|";
        file_out << desktop.getModel() << "|";
        file_out << desktop.getPrice() << "|";
        file_out << desktop.getQuantity() << "|";
        file_out << desktop.getOnDisplay() << "|";
        file_out << desktop.getCPU() << "|";
        file_out << desktop.getGPU() << "|";
        file_out << desktop.getMemory() << "|";
        for (const std::string storage: desktop.getStorage()){
            file_out << storage << ",";
        }
        file_out << "|";
        file_out << desktop.getOS() << "|";
        file_out << desktop.getMotherboard() << "|";
        file_out << desktop.getPSU() << "|";
        file_out << desktop.getPCCase() << "|";
        file_out << desktop.getCooling() << "|";
        file_out << desktop.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Desktop::readData(){
    std::ifstream file_in("../txt_files/desktop.txt", std::ios::in);
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
    std::string motherboard;
    std::string psu;
    std::string pc_case;
    std::string cooling;
    std::string image_path;
    std::array<std::string*, 17> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &cpu, &gpu, &memory, &storage, &os, &motherboard, &psu, &pc_case, &cooling, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Desktop dt;
        dt.setID(id);
        dt.setDescription(description);
        dt.setBrand(brand);
        dt.setModel(model);
        dt.setPrice(std::stod(price));
        dt.setQuantity(std::stoi(quantity));
        dt.setOnDisplay(std::stoi(on_display));
        dt.setCPU(cpu);
        dt.setGPU(gpu);
        dt.setMemory(memory);
        std::stringstream s_storage(storage);
        std::string storage_type;
        while (std::getline(s_storage, storage_type, ',')){
            dt.addStorage(storage_type);
        }
        dt.setOS(os);
        dt.setMotherboard(motherboard);
        dt.setPSU(psu);
        dt.setPCCase(pc_case);
        dt.setCooling(cooling);
        dt.setImagePath(image_path);
        desktop_vec.push_back(dt);
    }
    file_in.close();
    return;
}