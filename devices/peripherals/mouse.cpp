#include "mouse.h"

Mouse::Mouse() {}

Mouse::Mouse(int q, double p) : Peripherals(q, p) {
    type = "-";
    sensor = "-";
    is_wireless = false;
    sensitivity = std::make_tuple(0, 0);
    weight = 0;
    battery_life = 0;
    is_rechargeable = false;
    generateId();
}

void Mouse::setType(const std::string t) {
    type = t;
}

void Mouse::setSensor(const std::string s) {
    sensor = s;
}

void Mouse::setWireless(const bool w) {
    is_wireless = w;
}

void Mouse::setSensitivity(const int min, const int max) {
    sensitivity = std::make_tuple(min, max);
}

void Mouse::setWeight(const double w) {
    weight = w;
}

void Mouse::setBatteryLife(const double bl) {
    battery_life = bl;
}

void Mouse::setRechargeable(const bool r) {
    is_rechargeable = r;
}

std::string Mouse::getType() const {
    return type;
}

std::string Mouse::getSensor() const {
    return sensor;
}

bool Mouse::getWireless() const {
    return is_wireless;
}

std::tuple<int, int> Mouse::getSensitivity() const {
    return sensitivity;
}

double Mouse::getWeight() const {
    return weight;
}

double Mouse::getBatteryLife() const {
    return battery_life;
}

bool Mouse::getRechargeable() const {
    return is_rechargeable;
}

void Mouse::generateId() {
    std::ifstream file_in("../txt_files/mouse.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Mouse mouse: mouse_vec){
            std::string id = mouse.getID(); // AZ0001
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
    mouse_vec.push_back(*this);
    std::ofstream file_out("../txt_files/mouse.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Mouse mouse: mouse_vec){
        file_out << mouse.getID() << "|";
        file_out << mouse.getDescription() << "|";
        file_out << mouse.getBrand() << "|";
        file_out << mouse.getModel() << "|";
        file_out << mouse.getPrice() << "|";
        file_out << mouse.getQuantity() << "|";
        file_out << mouse.getOnDisplay() << "|";
        file_out << mouse.getType() << "|";
        file_out << mouse.getSensor() << "|";
        file_out << mouse.getWireless() << "|";
        file_out << std::get<0>(mouse.getSensitivity()) << "|";
        file_out << std::get<1>(mouse.getSensitivity()) << "|";
        file_out << mouse.getWeight() << "|";
        file_out << mouse.getBatteryLife() << "|";
        file_out << mouse.getRechargeable() << "|";
        file_out << mouse.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Mouse::updateVec(const Mouse mouse_in){
    for (Mouse& mouse: mouse_vec){
        if (mouse.getID() == mouse_in.getID()){
            mouse.setDescription(mouse_in.getDescription());
            mouse.setBrand(mouse_in.getBrand());
            mouse.setModel(mouse_in.getModel());
            mouse.setPrice(mouse_in.getPrice());
            mouse.setQuantity(mouse_in.getQuantity());
            mouse.setOnDisplay(mouse_in.getOnDisplay());
            mouse.setType(mouse_in.getType());
            mouse.setSensor(mouse_in.getSensor());
            mouse.setWireless(mouse_in.getWireless());
            mouse.setSensitivity(std::get<0>(mouse_in.getSensitivity()), std::get<1>(mouse_in.getSensitivity()));
            mouse.setWeight(mouse_in.getWeight());
            mouse.setBatteryLife(mouse_in.getBatteryLife());
            mouse.setRechargeable(mouse_in.getRechargeable());
            mouse.setImagePath(mouse_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/mouse.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Mouse mouse: mouse_vec){
        file_out << mouse.getID() << "|";
        file_out << mouse.getDescription() << "|";
        file_out << mouse.getBrand() << "|";
        file_out << mouse.getModel() << "|";
        file_out << mouse.getPrice() << "|";
        file_out << mouse.getQuantity() << "|";
        file_out << mouse.getOnDisplay() << "|";
        file_out << mouse.getType() << "|";
        file_out << mouse.getSensor() << "|";
        file_out << mouse.getWireless() << "|";
        file_out << std::get<0>(mouse.getSensitivity()) << "|";
        file_out << std::get<1>(mouse.getSensitivity()) << "|";
        file_out << mouse.getWeight() << "|";
        file_out << mouse.getBatteryLife() << "|";
        file_out << mouse.getRechargeable() << "|";
        file_out << mouse.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Mouse::readData() {
    std::ifstream file_in("../txt_files/mouse.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string type;
    std::string sensor;
    std::string wireless;
    std::string sensitivity_min;
    std::string sensitivity_max;
    std::string weight;
    std::string battery_life;
    std::string rechargeable;
    std::string image_path;
    std::array<std::string*, 16> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &type, &sensor, &wireless, &sensitivity_min, &sensitivity_max, &weight, &battery_life, &rechargeable, &image_path};
    
    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Mouse mouse;
        mouse.setID(id);
        mouse.setDescription(description);
        mouse.setBrand(brand);
        mouse.setModel(model);
        mouse.setPrice(std::stod(price));
        mouse.setQuantity(std::stoi(quantity));
        mouse.setOnDisplay(std::stoi(on_display));
        mouse.setType(type);
        mouse.setSensor(sensor);
        mouse.setWireless(std::stoi(wireless));
        mouse.setSensitivity(std::stoi(sensitivity_min), std::stoi(sensitivity_max));
        mouse.setWeight(std::stod(weight));
        mouse.setBatteryLife(std::stod(battery_life));
        mouse.setRechargeable(std::stoi(rechargeable));
        mouse.setImagePath(image_path);
        mouse_vec.push_back(mouse);
    }
    file_in.close();
    return;
}