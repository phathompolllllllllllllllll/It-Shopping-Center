#include "speakers.h"

Speakers::Speakers(){}

Speakers::Speakers(int q, double p) : Peripherals(q, p){
    power_output = 0;
    configuration = 0;
    is_wireless = false;
    battery_life = 0;
    generateId();
}

void Speakers::setPowerOutput(const double p){
    power_output = p;
}

void Speakers::setConfiguration(const double c){
    configuration = c;
}

void Speakers::setWireless(const bool w){
    is_wireless = w;
}

void Speakers::setBatteryLife(double b){
    battery_life = b;
}

double Speakers::getPowerOutput() const{
    return power_output;
}

double Speakers::getConfiguration() const{
    return configuration;
}

bool Speakers::getWireless() const{
    return is_wireless;
}

double Speakers::getBatteryLife() const{
    return battery_life;
}

void Speakers::generateId(){
    std::ifstream file_in("../txt_files/speakers.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Speakers speaker: speakers_vec){
            std::string id = speaker.getID();
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
    speakers_vec.push_back(*this);
    std::ofstream file_out("../txt_files/speakers.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Speakers speaker: speakers_vec){
        file_out << speaker.getID() << "|";
        file_out << speaker.getDescription() << "|";
        file_out << speaker.getBrand() << "|";
        file_out << speaker.getModel() << "|";
        file_out << speaker.getPrice() << "|";
        file_out << speaker.getQuantity() << "|";
        file_out << speaker.getOnDisplay() << "|";
        file_out << speaker.getPowerOutput() << "|";
        file_out << speaker.getConfiguration() << "|";
        file_out << speaker.getWireless() << "|";
        file_out << speaker.getBatteryLife() << "|";
        file_out << speaker.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Speakers::updateVec(const Speakers speaker_in) {
    for (Speakers& speaker: speakers_vec){
        if (speaker.getID() == speaker_in.getID()){
            speaker.setDescription(speaker_in.getDescription());
            speaker.setBrand(speaker_in.getBrand());
            speaker.setModel(speaker_in.getModel());
            speaker.setPrice(speaker_in.getPrice());
            speaker.setQuantity(speaker_in.getQuantity());
            speaker.setOnDisplay(speaker_in.getOnDisplay());
            speaker.setPowerOutput(speaker_in.getPowerOutput());
            speaker.setConfiguration(speaker_in.getConfiguration());
            speaker.setWireless(speaker_in.getWireless());
            speaker.setBatteryLife(speaker_in.getBatteryLife());
            speaker.setImagePath(speaker_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/speakers.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Speakers speaker: speakers_vec){
        file_out << speaker.getID() << "|";
        file_out << speaker.getDescription() << "|";
        file_out << speaker.getBrand() << "|";
        file_out << speaker.getModel() << "|";
        file_out << speaker.getPrice() << "|";
        file_out << speaker.getQuantity() << "|";
        file_out << speaker.getOnDisplay() << "|";
        file_out << speaker.getPowerOutput() << "|";
        file_out << speaker.getConfiguration() << "|";
        file_out << speaker.getWireless() << "|";
        file_out << speaker.getBatteryLife() << "|";
        file_out << speaker.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Speakers::readData() {
    std::ifstream file_in("../txt_files/speakers.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string power_o;
    std::string config;
    std::string wireless;
    std::string battery_l;
    std::string image_path;
    std::array<std::string*, 12> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &power_o, &config, &wireless, &battery_l, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream{row};
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Speakers speaker;
        speaker.setID(id);
        speaker.setDescription(description);
        speaker.setBrand(brand);
        speaker.setModel(model);
        speaker.setPrice(std::stod(price));
        speaker.setQuantity(std::stoi(quantity));
        speaker.setOnDisplay(std::stoi(on_display));
        speaker.setPowerOutput(std::stod(power_o));
        speaker.setConfiguration(std::stod(config));
        speaker.setWireless(std::stoi(wireless));
        speaker.setBatteryLife(std::stod(battery_l));
        speaker.setImagePath(image_path);
        speakers_vec.push_back(speaker);
    }
    file_in.close();
    return;
}
