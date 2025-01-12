#include "printer.h"

Printer::Printer(){}

Printer::Printer(const int q, const double p) : Peripherals(q, p) {
    type = "-";
    has_scanner = false;
    is_wireless = false;
    speed = 0;
    max_res = 0;
    is_duplex = false;
    ink_or_toner = std::make_tuple("-", 0);
    dimensions = std::make_tuple(0.0, 0.0, 0.0);
    weight = 0;
    generateId();
}

void Printer::setType(const std::string t) {
    type = t;
}

void Printer::setHasScanner(const bool hs) {
    has_scanner = hs;
}

void Printer::setWireless(const bool w) {
    is_wireless = w;
}

void Printer::setSpeed(const int s) {
    speed = s;
}

void Printer::setMaxRes(const int mr) {
    max_res = mr;
}

void Printer::setDuplex(const bool d) {
    is_duplex = d;
}

void Printer::setInkOrToner(const std::string iot, const int py) {
    ink_or_toner = std::make_tuple(iot, py);
}

void Printer::setDimensions(const double l, const double w, const double h) {
    dimensions = std::make_tuple(l, w, h);
}

void Printer::setWeight(const double w) {
    weight = w;
}

std::string Printer::getType() const {
    return type;
}

bool Printer::getHasScanner() const {
    return has_scanner;
}

bool Printer::getWireless() const {
    return is_wireless;
}

int Printer::getSpeed() const {
    return speed;
}

int Printer::getMaxRes() const {
    return max_res;
}

bool Printer::getDuplex() const {
    return is_duplex;
}

std::tuple<std::string, int> Printer::getInkOrToner() const {
    return ink_or_toner;
}

std::tuple<double, double, double> Printer::getDimensions() const {
    return dimensions;
}

double Printer::getWeight() const {
    return weight;
}

void Printer::generateId() {
    std::ifstream file_in("../txt_files/printer.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Printer printer: printer_vec){
            std::string id = printer.getID(); // AZ0001
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
    printer_vec.push_back(*this);
    std::ofstream file_out("../txt_files/printer.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Printer printer: printer_vec){
        file_out << printer.getID() << "|";
        file_out << printer.getDescription() << "|";
        file_out << printer.getBrand() << "|";
        file_out << printer.getModel() << "|";
        file_out << printer.getPrice() << "|";
        file_out << printer.getQuantity() << "|";
        file_out << printer.getOnDisplay() << "|";
        file_out << printer.getType() << "|";
        file_out << printer.getHasScanner() << "|";
        file_out << printer.getWireless() << "|";
        file_out << printer.getSpeed() << "|";
        file_out << printer.getMaxRes() << "|";
        file_out << printer.getDuplex() << "|";
        file_out << std::get<0>(printer.getInkOrToner()) << "|";
        file_out << std::get<1>(printer.getInkOrToner()) << "|";
        file_out << std::get<0>(printer.getDimensions()) << "|";
        file_out << std::get<1>(printer.getDimensions()) << "|";
        file_out << std::get<2>(printer.getDimensions()) << "|";
        file_out << printer.getWeight();
        file_out << printer.getImagePath();
        file_out << std::endl;        
    }
    file_out.close();
    return;
}

void Printer::updateVec(const Printer pr_in){
    for (Printer& pr: printer_vec){
        if (pr.getID() == pr_in.getID()){
            pr.setDescription(pr_in.getDescription());
            pr.setBrand(pr_in.getBrand());
            pr.setModel(pr_in.getModel());
            pr.setPrice(pr_in.getPrice());
            pr.setQuantity(pr_in.getQuantity());
            pr.setOnDisplay(pr_in.getOnDisplay());
            pr.setType(pr_in.getType());
            pr.setHasScanner(pr_in.getHasScanner());
            pr.setWireless(pr_in.getWireless());
            pr.setSpeed(pr_in.getSpeed());
            pr.setMaxRes(pr_in.getMaxRes());
            pr.setDuplex(pr_in.getDuplex());
            pr.setInkOrToner(std::get<0>(pr_in.getInkOrToner()), std::get<1>(pr_in.getInkOrToner()));
            pr.setDimensions(std::get<0>(pr_in.getDimensions()), std::get<1>(pr_in.getDimensions()), std::get<2>(pr_in.getDimensions()));
            pr.setWeight(pr_in.getWeight());
            pr.setImagePath(pr_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/printer.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Printer printer: printer_vec){
        file_out << printer.getID() << "|";
        file_out << printer.getDescription() << "|";
        file_out << printer.getBrand() << "|";
        file_out << printer.getModel() << "|";
        file_out << printer.getPrice() << "|";
        file_out << printer.getQuantity() << "|";
        file_out << printer.getOnDisplay() << "|";
        file_out << printer.getType() << "|";
        file_out << printer.getHasScanner() << "|";
        file_out << printer.getWireless() << "|";
        file_out << printer.getSpeed() << "|";
        file_out << printer.getMaxRes() << "|";
        file_out << printer.getDuplex() << "|";
        file_out << std::get<0>(printer.getInkOrToner()) << "|";
        file_out << std::get<1>(printer.getInkOrToner()) << "|";
        file_out << std::get<0>(printer.getDimensions()) << "|";
        file_out << std::get<1>(printer.getDimensions()) << "|";
        file_out << std::get<2>(printer.getDimensions()) << "|";
        file_out << printer.getWeight() << "|";
        file_out << printer.getImagePath();
        file_out << std::endl;        
    }
    file_out.close();
    return;
}

void Printer::readData() {
    std::ifstream file_in("../txt_files/printer.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        file_in.close();
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string type;
    std::string has_scanner;
    std::string is_wireless;
    std::string speed;
    std::string max_res;
    std::string is_duplex;
    std::string iot_type;
    std::string est_page_yield;
    std::string length;
    std::string width;
    std::string height;
    std::string weight;
    std::string image_path;
    std::array<std::string*, 20> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &type, &has_scanner, &is_wireless, &speed, &max_res, &is_duplex, &iot_type, &est_page_yield, &length, &width, &height, &weight, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');                 
        }
        Printer pr;
        pr.setID(id);
        pr.setDescription(description);
        pr.setBrand(brand);
        pr.setModel(model);
        pr.setPrice(std::stod(price));
        pr.setQuantity(std::stoi(quantity));
        pr.setOnDisplay(std::stoi(on_display));
        pr.setType(type);
        pr.setHasScanner(std::stoi(has_scanner));
        pr.setWireless(std::stoi(is_wireless));
        pr.setSpeed(std::stoi(speed));
        pr.setMaxRes(std::stoi(max_res));
        pr.setDuplex(std::stoi(is_duplex));
        pr.setInkOrToner(iot_type, std::stoi(est_page_yield));
        pr.setDimensions(std::stod(length), std::stod(width), std::stod(height));
        pr.setWeight(std::stod(weight));
        pr.setImagePath(image_path);
        printer_vec.push_back(pr);
    }
    file_in.close();
    return;
}