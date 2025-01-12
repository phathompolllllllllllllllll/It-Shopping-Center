#include "motherboard.h"

Motherboard::Motherboard(){}

Motherboard::Motherboard(const int q, const double p) : ComputerParts(q, p){
    form_factor = "-";
    socket = "-";
    memory = std::make_tuple("-", 0);
    chipset = "-";
    expansion_slots = {};
    connectivity = {};
    storage = {};
    audio = "-";
    multi_gpu = false;
    bios = "-";
    generateId();
}

void Motherboard::setFormFactor(const std::string ff){
    form_factor = ff;
}

void Motherboard::setSocket(const std::string s){
    socket = s;
}

void Motherboard::setMemory(const std::string t, const int c){
    memory = std::make_tuple(t, c);
}

void Motherboard::setChipset(const std::string c){
    chipset = c;
}

void Motherboard::addExpansionSlots(const std::string es){
    expansion_slots.push_back(es);
}

void Motherboard::clearExpansionSlots(){
    expansion_slots.clear();
}

void Motherboard::addConnectivity(const std::string c){
    connectivity.push_back(c);
}

void Motherboard::clearConnectivity(){
    connectivity.clear();
}

void Motherboard::addStorage(const std::string t, const int c){
    storage.push_back(std::make_tuple(t, c));
}

void Motherboard::clearStorage(){
    storage.clear();
}

void Motherboard::setAudio(const std::string a){
    audio = a;
}

void Motherboard::setMultiGPU(const bool mg){
    multi_gpu = mg;
}

void Motherboard::setBios(const std::string b){
    bios = b;
}

std::string Motherboard::getFormFactor() const{
    return form_factor;
}

std::string Motherboard::getSocket() const{
    return socket;
}

std::tuple<std::string, int> Motherboard::getMemory() const{
    return memory;
}

std::string Motherboard::getChipset() const{
    return chipset;
}

std::vector<std::string> Motherboard::getExpansionSlots() const{
    return expansion_slots;
}

std::vector<std::string> Motherboard::getConnectivity() const{
    return connectivity;
}

std::vector<std::tuple<std::string, int>> Motherboard::getStorage() const{
    return storage;
}

std::string Motherboard::getAudio() const{
    return audio;
}

bool Motherboard::getMultiGPU() const{
    return multi_gpu;
}

std::string Motherboard::getBios() const{
    return bios;
}

void Motherboard::generateId(){
    std::ifstream file_in("../txt_files/motherboard.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Motherboard motb: motherboard_vec){
            std::string id = motb.getID(); // AZ0001
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
    motherboard_vec.push_back(*this);
    std::ofstream file_out("../txt_files/motherboard.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Motherboard motb: motherboard_vec){
        file_out << motb.getID() << "|";
        file_out << motb.getDescription() << "|";
        file_out << motb.getBrand() << "|";
        file_out << motb.getModel() << "|";
        file_out << motb.getPrice() << "|";
        file_out << motb.getQuantity() << "|";
        file_out << motb.getOnDisplay() << "|";
        file_out << motb.getFormFactor() << "|";
        file_out << motb.getSocket() << "|";
        file_out << std::get<0>(motb.getMemory()) << "|";
        file_out << std::get<1>(motb.getMemory()) << "|";
        file_out << motb.getChipset() << "|";
        for (std::string es: motb.getExpansionSlots()){
            file_out << es << ",";
        }
        file_out << "|";
        for (std::string c: motb.getConnectivity()){
            file_out << c << ",";
        }
        file_out << "|";
        for (std::tuple<std::string, int> s: motb.getStorage()){
            file_out << std::get<0>(s) << ",";
            file_out << std::get<1>(s) << ",";
        }
        file_out << "|";
        file_out << motb.getAudio() << "|";
        file_out << motb.getMultiGPU() << "|";
        file_out << motb.getBios() << "|";
        file_out << motb.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Motherboard::updateVec(const Motherboard mb_in){
    for (Motherboard& motb: motherboard_vec){
        if (motb.getID() == mb_in.getID()){
            motb.setDescription(mb_in.getDescription());
            motb.setBrand(mb_in.getBrand());
            motb.setModel(mb_in.getModel());
            motb.setPrice(mb_in.getPrice());
            motb.setQuantity(mb_in.getQuantity());
            motb.setOnDisplay(mb_in.getOnDisplay());
            motb.setFormFactor(mb_in.getFormFactor());
            motb.setSocket(mb_in.getSocket());
            motb.setMemory(std::get<0>(mb_in.getMemory()), std::get<1>(mb_in.getMemory()));
            motb.setChipset(mb_in.getChipset());
            motb.clearExpansionSlots();
            for (std::string es: mb_in.getExpansionSlots()){
                motb.addExpansionSlots(es);
            }
            motb.clearConnectivity();
            for (std::string c: mb_in.getConnectivity()){
                motb.addConnectivity(c);
            }
            motb.clearStorage();
            for (std::tuple<std::string, int> s: mb_in.getStorage()){
                motb.addStorage(std::get<0>(s), std::get<1>(s));
            }
            motb.setAudio(mb_in.getAudio());
            motb.setMultiGPU(mb_in.getMultiGPU());
            motb.setBios(mb_in.getBios());
            motb.setImagePath(mb_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/motherboard.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Motherboard motb: motherboard_vec){
        file_out << motb.getID() << "|";
        file_out << motb.getDescription() << "|";
        file_out << motb.getBrand() << "|";
        file_out << motb.getModel() << "|";
        file_out << motb.getPrice() << "|";
        file_out << motb.getQuantity() << "|";
        file_out << motb.getOnDisplay() << "|";
        file_out << motb.getFormFactor() << "|";
        file_out << motb.getSocket() << "|";
        file_out << std::get<0>(motb.getMemory()) << "|";
        file_out << std::get<1>(motb.getMemory()) << "|";
        file_out << motb.getChipset() << "|";
        for (std::string es: motb.getExpansionSlots()){
            file_out << es << ",";
        }
        file_out << "|";
        for (std::string c: motb.getConnectivity()){
            file_out << c << ",";
        }
        file_out << "|";
        for (std::tuple<std::string, int> s: motb.getStorage()){
            file_out << std::get<0>(s) << ",";
            file_out << std::get<1>(s) << ",";
        }
        file_out << "|";
        file_out << motb.getAudio() << "|";
        file_out << motb.getMultiGPU() << "|";
        file_out << motb.getBios() << "|";
        file_out << motb.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Motherboard::readData(){
    std::ifstream file_in("../txt_files/motherboard.txt", std::ios::in);
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
    std::string socket;
    std::string memory_type;
    std::string memory_capacity;
    std::string chipset;
    std::string expansion_slots;
    std::string connectivity;
    std::string storage;
    std::string audio;
    std::string multi_gpu;
    std::string bios;
    std::string image_path;
    std::array<std::string*, 19> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &form_factor, &socket, &memory_type, &memory_capacity, &chipset, &expansion_slots, &connectivity, &storage, &audio, &multi_gpu, &bios, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Motherboard motb;
        motb.setID(id);
        motb.setDescription(description);
        motb.setBrand(brand);
        motb.setModel(model);
        motb.setPrice(std::stod(price));
        motb.setQuantity(std::stoi(quantity));
        motb.setOnDisplay(std::stoi(on_display));
        motb.setFormFactor(form_factor);
        motb.setSocket(socket);
        motb.setMemory(memory_type, std::stoi(memory_capacity));
        motb.setChipset(chipset);
        std::istringstream es_stream(expansion_slots);
        std::string es;
        while (std::getline(es_stream, es, ',')){
            motb.addExpansionSlots(es);
        }
        std::istringstream c_stream(connectivity);
        std::string c;
        while (std::getline(c_stream, c, ',')){
            motb.addConnectivity(c);
        }
        std::istringstream s_stream(storage);
        std::string s;
        while (std::getline(s_stream, s, ',')){
            std::string t;
            std::getline(s_stream, t, ',');
            motb.addStorage(s, std::stoi(t));
        }
        motb.setAudio(audio);
        motb.setMultiGPU(std::stoi(multi_gpu));
        motb.setBios(bios);
        motb.setImagePath(image_path);
        motherboard_vec.push_back(motb);
    }
    file_in.close();
    return;
}