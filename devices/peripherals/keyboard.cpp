#include "keyboard.h"

Keyboard::Keyboard() {}

Keyboard::Keyboard(const int q, const double p) : Peripherals(q, p) {
    type = "-";
    layout = "-";
    is_backlit = false;
    is_wireless = false;
    key_switch = "-";
    generateId();
}

void Keyboard::setType(const std::string t) {
    type = t;
}

void Keyboard::setLayout(const std::string l) {
    layout = l;
}

void Keyboard::setBacklit(const bool b) {
    is_backlit = b;
}

void Keyboard::setWireless(const bool w) {
    is_wireless = w;
}

void Keyboard::setKeySwitch(const std::string ks) {
    key_switch = ks;
}

std::string Keyboard::getType() const {
    return type;
}

std::string Keyboard::getLayout() const {
    return layout;
}

bool Keyboard::getBacklit() const {
    return is_backlit;
}

bool Keyboard::getWireless() const {
    return is_wireless;
}

std::string Keyboard::getKeySwitch() const {
    return key_switch;
}

void Keyboard::generateId() {
    std::ifstream file_in("../txt_files/keyboard.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Keyboard kb: keyboard_vec){
            std::string id = kb.getID(); // AZ0001
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
    keyboard_vec.push_back(*this);
    std::ofstream file_out("../txt_files/keyboard.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Keyboard kb: keyboard_vec){
        file_out << kb.getID() << "|";
        file_out << kb.getDescription() << "|";
        file_out << kb.getBrand() << "|";
        file_out << kb.getModel() << "|";
        file_out << kb.getPrice() << "|";
        file_out << kb.getQuantity() << "|";
        file_out << kb.getOnDisplay() << "|";
        file_out << kb.getType() << "|";
        file_out << kb.getLayout() << "|";
        file_out << kb.getBacklit() << "|";
        file_out << kb.getWireless() << "|";
        file_out << kb.getKeySwitch() << "|";
        file_out << kb.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Keyboard::updateVec(const Keyboard kb_in){
    for (Keyboard& kb: keyboard_vec){
        if (kb.getID() == kb_in.getID()){
            kb.setDescription(kb_in.getDescription());
            kb.setBrand(kb_in.getBrand());
            kb.setModel(kb_in.getModel());
            kb.setPrice(kb_in.getPrice());
            kb.setQuantity(kb_in.getQuantity());
            kb.setOnDisplay(kb_in.getOnDisplay());
            kb.setType(kb_in.getType());
            kb.setLayout(kb_in.getLayout());
            kb.setBacklit(kb_in.getBacklit());
            kb.setWireless(kb_in.getWireless());
            kb.setKeySwitch(kb_in.getKeySwitch());
            kb.setImagePath(kb_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/keyboard.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Keyboard kb: keyboard_vec){
        file_out << kb.getID() << "|";
        file_out << kb.getDescription() << "|";
        file_out << kb.getBrand() << "|";
        file_out << kb.getModel() << "|";
        file_out << kb.getPrice() << "|";
        file_out << kb.getQuantity() << "|";
        file_out << kb.getOnDisplay() << "|";
        file_out << kb.getType() << "|";
        file_out << kb.getLayout() << "|";
        file_out << kb.getBacklit() << "|";
        file_out << kb.getWireless() << "|";
        file_out << kb.getKeySwitch() << "|";
        file_out << kb.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Keyboard::readData() {
    std::ifstream file_in("../txt_files/keyboard.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string type;
    std::string layout;
    std::string backlit;
    std::string wireless;
    std::string key_switch;
    std::string image_path;
    std::array<std::string*, 13> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &type, &layout, &backlit, &wireless, &key_switch, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Keyboard kb;
        kb.setID(id);
        kb.setDescription(description);
        kb.setBrand(brand);
        kb.setModel(model);
        kb.setPrice(std::stod(price));
        kb.setQuantity(std::stoi(quantity));
        kb.setOnDisplay(std::stoi(on_display));
        kb.setType(type);
        kb.setLayout(layout);
        kb.setBacklit(std::stoi(backlit));
        kb.setWireless(std::stoi(wireless));
        kb.setKeySwitch(key_switch);
        kb.setImagePath(image_path);
        keyboard_vec.push_back(kb);
    }
    file_in.close();
    return;
}