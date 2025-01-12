#include "sd_card.h"

SdCard::SdCard(){}

SdCard::SdCard(const int q, const double p) : Peripherals(q, p) {
    type = "-";
    capacity = "-";
    speed = "-";
    class_rating = "-";
    form_factor = "-";
    generateId();
}

void SdCard::setType(const std::string t) {
    type = t;
}

void SdCard::setCapacity(const std::string c) {
    capacity = c;
}

void SdCard::setSpeed(const std::string s) {
    speed = s;
}

void SdCard::setClassRating(const std::string cr) {
    class_rating = cr;
}

void SdCard::setFormFactor(const std::string ff) {
    form_factor = ff;
}

std::string SdCard::getType() const {
    return type;
}

std::string SdCard::getCapacity() const {
    return capacity;
}

std::string SdCard::getSpeed() const {
    return speed;
}

std::string SdCard::getClassRating() const {
    return class_rating;
}

std::string SdCard::getFormFactor() const {
    return form_factor;
}

void SdCard::generateId() {
    std::ifstream file_in("../txt_files/sd_card.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const SdCard sd: sd_card_vec){
            std::string id = sd.getID(); // AZ0001
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
    sd_card_vec.push_back(*this);
    std::ofstream file_out("../txt_files/sd_card.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const SdCard sd: sd_card_vec){
        file_out << sd.getID() << "|";
        file_out << sd.getDescription() << "|";
        file_out << sd.getBrand() << "|";
        file_out << sd.getModel() << "|";
        file_out << sd.getPrice() << "|";
        file_out << sd.getQuantity() << "|";
        file_out << sd.getOnDisplay() << "|";
        file_out << sd.getType() << "|";
        file_out << sd.getCapacity() << "|";
        file_out << sd.getSpeed() << "|";
        file_out << sd.getClassRating() << "|";
        file_out << sd.getFormFactor() << "|";
        file_out << sd.getImagePath();
    }
    file_out.close();
    return;
}

void SdCard::updateVec(const SdCard sd_in){
    for (SdCard& sd: sd_card_vec){
        if (sd.getID() == sd_in.getID()){
            sd.setDescription(sd_in.getDescription());
            sd.setBrand(sd_in.getBrand());
            sd.setModel(sd_in.getModel());
            sd.setPrice(sd_in.getPrice());
            sd.setQuantity(sd_in.getQuantity());
            sd.setOnDisplay(sd_in.getOnDisplay());
            sd.setType(sd_in.getType());
            sd.setCapacity(sd_in.getCapacity());
            sd.setSpeed(sd_in.getSpeed());
            sd.setClassRating(sd_in.getClassRating());
            sd.setFormFactor(sd_in.getFormFactor());
            sd.setImagePath(sd_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/sd_card.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const SdCard sd: sd_card_vec){
        file_out << sd.getID() << "|";
        file_out << sd.getDescription() << "|";
        file_out << sd.getBrand() << "|";
        file_out << sd.getModel() << "|";
        file_out << sd.getPrice() << "|";
        file_out << sd.getQuantity() << "|";
        file_out << sd.getOnDisplay() << "|";
        file_out << sd.getType() << "|";
        file_out << sd.getCapacity() << "|";
        file_out << sd.getSpeed() << "|";
        file_out << sd.getClassRating() << "|";
        file_out << sd.getFormFactor() << "|";
        file_out << sd.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void SdCard::readData() {
    std::ifstream file_in("../txt_files/sd_card.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string type;
    std::string capacity;
    std::string speed;
    std::string class_rating;
    std::string form_factor;
    std::string image_path;
    std::array<std::string*, 13> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &type, &capacity, &speed, &class_rating, &form_factor, &image_path};

    std::string row;
    while (std::getline(file_in, row)) {
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        SdCard sd;
        sd.setID(id);
        sd.setDescription(description);
        sd.setBrand(brand);
        sd.setModel(model);
        sd.setPrice(std::stod(price));
        sd.setQuantity(std::stoi(quantity));
        sd.setOnDisplay(std::stoi(on_display));
        sd.setType(type);
        sd.setCapacity(capacity);
        sd.setSpeed(speed);
        sd.setClassRating(class_rating);
        sd.setFormFactor(form_factor);
        sd.setImagePath(image_path);
        sd_card_vec.push_back(sd);        
    }
    file_in.close();
    return;
}