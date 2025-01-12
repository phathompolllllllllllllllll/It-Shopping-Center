#include "microphone.h"

Microphone::Microphone(){}

Microphone::Microphone(const int q, const double p) : Peripherals(q, p){
    directionality = "-";
    has_usb = false;
    has_xlr = false;
    generateId();
}

void Microphone::setDirectionality(const std::string d){
    directionality = d;
}

void Microphone::setUSB(const bool u){
    has_usb = u;
}

void Microphone::setXLR(const bool x){
    has_xlr = x;
}

std::string Microphone::getDirectionality() const{
    return directionality;
}

bool Microphone::getUSB() const{
    return has_usb;
}

bool Microphone::getXLR() const{
    return has_xlr;
}

void Microphone::generateId(){
    std::ifstream file_in("../txt_files/microphone.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Microphone micro: microphone_vec){
            std::string id = micro.getID();
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
    microphone_vec.push_back(*this);
    std::ofstream file_out("../txt_files/microphone.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Microphone micro: microphone_vec){
        file_out << micro.getID() << "|";
        file_out << micro.getDescription() << "|";
        file_out << micro.getBrand() << "|";
        file_out << micro.getModel() << "|";
        file_out << micro.getPrice() << "|";
        file_out << micro.getQuantity() << "|";
        file_out << micro.getOnDisplay() << "|";
        file_out << micro.getDirectionality() << "|";
        file_out << micro.getUSB() << "|";
        file_out << micro.getXLR() << "|";
        file_out << micro.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Microphone::updateVec(const Microphone microphone_in){
    for (Microphone& microphone: microphone_vec){
        if (microphone.getID() == microphone_in.getID()){
            microphone.setDescription(microphone_in.getDescription());
            microphone.setBrand(microphone_in.getBrand());
            microphone.setModel(microphone_in.getModel());
            microphone.setPrice(microphone_in.getPrice());
            microphone.setQuantity(microphone_in.getQuantity());
            microphone.setOnDisplay(microphone_in.getOnDisplay());
            microphone.setDirectionality(microphone_in.getDirectionality());
            microphone.setUSB(microphone_in.getUSB());
            microphone.setXLR(microphone_in.getXLR());
            microphone.setImagePath(microphone_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/microphone.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Microphone micro: microphone_vec){
        file_out << micro.getID() << "|";
        file_out << micro.getDescription() << "|";
        file_out << micro.getBrand() << "|";
        file_out << micro.getModel() << "|";
        file_out << micro.getPrice() << "|";
        file_out << micro.getQuantity() << "|";
        file_out << micro.getOnDisplay() << "|";
        file_out << micro.getDirectionality() << "|";
        file_out << micro.getUSB() << "|";
        file_out << micro.getXLR() << "|";
        file_out << micro.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Microphone::readData() {
    std::ifstream file_in("../txt_files/microphone.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string directionality;
    std::string has_usb;
    std::string has_xlr;
    std::string image_path;
    std::array<std::string*, 11> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &directionality, &has_usb, &has_xlr, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream{row};
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Microphone micro;
        micro.setID(id);
        micro.setDescription(description);
        micro.setBrand(brand);
        micro.setModel(model);
        micro.setPrice(std::stod(price));
        micro.setQuantity(std::stoi(quantity));
        micro.setOnDisplay(std::stoi(on_display));
        micro.setDirectionality(directionality);
        micro.setUSB(std::stoi(has_usb));
        micro.setXLR(std::stoi(has_xlr));
        micro.setImagePath(image_path);
        microphone_vec.push_back(micro);
    }
    file_in.close();
    return;
}