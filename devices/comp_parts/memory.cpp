#include "memory.h"

Memory::Memory(){}

Memory::Memory(const int q, const double p) : ComputerParts(q, p){
    type = "-";
    capacity = 0;
    frequency = 0;
    latency = 0;
    form_factor = "-";
    voltage = 0.0;
    has_ecc = false;
    compatible_with = "any";
    generateId();
}

void Memory::setType(const std::string t){
    type = t;
}

void Memory::setCapacity(const int c){
    capacity = c;
}

void Memory::setFrequency(const int f){
    frequency = f;
}

void Memory::setLatency(const int l){
    latency = l;
}

void Memory::setFormFactor(const std::string ff){
    form_factor = ff;
}

void Memory::setVoltage(const double v){
    voltage = v;
}

void Memory::setHasECC(const bool he){
    has_ecc = he;
}

void Memory::setCompatibleWith(const std::string cw){
    compatible_with = cw;
}

std::string Memory::getType() const{
    return type;
}

int Memory::getCapacity() const{
    return capacity;
}

int Memory::getFrequency() const{
    return frequency;
}

int Memory::getLatency() const{
    return latency;
}

std::string Memory::getFormFactor() const{
    return form_factor;
}

double Memory::getVoltage() const{
    return voltage;
}

bool Memory::getHasECC() const{
    return has_ecc;
}

std::string Memory::getCompatibleWith() const{
    return compatible_with;
}

void Memory::generateId(){
    std::ifstream file_in("../txt_files/memory.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Memory mem: memory_vec){
            std::string id = mem.getID(); // AZ0001
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
    memory_vec.push_back(*this);
    std::ofstream file_out("../txt_files/memory.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
    }
    for (const Memory mem: memory_vec){
        file_out << mem.getID() << "|";
        file_out << mem.getDescription() << "|";
        file_out << mem.getBrand() << "|";
        file_out << mem.getModel() << "|";
        file_out << mem.getPrice() << "|";
        file_out << mem.getQuantity() << "|";
        file_out << mem.getOnDisplay() << "|";
        file_out << mem.getType() << "|";
        file_out << mem.getCapacity() << "|";
        file_out << mem.getFrequency() << "|";
        file_out << mem.getLatency() << "|";
        file_out << mem.getFormFactor() << "|";
        file_out << mem.getVoltage() << "|";
        file_out << mem.getHasECC() << "|";
        file_out << mem.getCompatibleWith() << "|";
        file_out << mem.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Memory::updateVec(const Memory mem_in){
    for (Memory& mem: memory_vec){
        if (mem.getID() == mem_in.getID()){
            mem.setDescription(mem_in.getDescription());
            mem.setBrand(mem_in.getBrand());
            mem.setModel(mem_in.getModel());
            mem.setPrice(mem_in.getPrice());
            mem.setQuantity(mem_in.getQuantity());
            mem.setOnDisplay(mem_in.getOnDisplay());
            mem.setType(mem_in.getType());
            mem.setCapacity(mem_in.getCapacity());
            mem.setFrequency(mem_in.getFrequency());
            mem.setLatency(mem_in.getLatency());
            mem.setFormFactor(mem_in.getFormFactor());
            mem.setVoltage(mem_in.getVoltage());
            mem.setHasECC(mem_in.getHasECC());
            mem.setCompatibleWith(mem_in.getCompatibleWith());
            mem.setImagePath(mem_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/memory.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Memory mem: memory_vec){
        file_out << mem.getID() << "|";
        file_out << mem.getDescription() << "|";
        file_out << mem.getBrand() << "|";
        file_out << mem.getModel() << "|";
        file_out << mem.getPrice() << "|";
        file_out << mem.getQuantity() << "|";
        file_out << mem.getOnDisplay() << "|";
        file_out << mem.getType() << "|";
        file_out << mem.getCapacity() << "|";
        file_out << mem.getFrequency() << "|";
        file_out << mem.getLatency() << "|";
        file_out << mem.getFormFactor() << "|";
        file_out << mem.getVoltage() << "|";
        file_out << mem.getHasECC() << "|";
        file_out << mem.getCompatibleWith();
        file_out << mem.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Memory::readData(){
    std::ifstream file_in("../txt_files/memory.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string type;
    std::string capacity;
    std::string frequency;
    std::string latency;
    std::string form_factor;
    std::string voltage;
    std::string has_ecc;
    std::string compatible_with;
    std::string image_path;
    std::array<std::string*, 16> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &type, &capacity, &frequency, &latency, &form_factor, &voltage, &has_ecc, &compatible_with, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream s_row(row);
        for (std::string* data_ptr: data){
            std::getline(s_row, *data_ptr, '|');
        }
        Memory mem;
        mem.setID(id);
        mem.setDescription(description);
        mem.setBrand(brand);
        mem.setModel(model);
        mem.setPrice(std::stod(price));
        mem.setQuantity(std::stoi(quantity));
        mem.setOnDisplay(std::stoi(on_display));
        mem.setType(type);
        mem.setCapacity(std::stoi(capacity));
        mem.setFrequency(std::stoi(frequency));
        mem.setLatency(std::stoi(latency));
        mem.setFormFactor(form_factor);
        mem.setVoltage(std::stod(voltage));
        mem.setHasECC(std::stoi(has_ecc));
        mem.setCompatibleWith(compatible_with);
        mem.setImagePath(image_path);
        memory_vec.push_back(mem);
    }
    file_in.close();
    return;
}