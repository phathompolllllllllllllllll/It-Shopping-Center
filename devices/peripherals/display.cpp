#include "display.h"

Display::Display(){}

Display::Display(const int q, const double p) : Peripherals(q, p) {
    resolution = std::make_tuple(0, 0);
    refresh_rate = 0;
    dimensions = std::make_tuple(0.0, 0.0);
    hdr_supported = false;
    response_time = 0;
    generateId();
}

void Display::setResolution(const int l, const int h) {
    resolution = std::make_tuple(l, h);
}

void Display::setRefreshRate(const int r) {
    refresh_rate = r;
}

void Display::setDimensions(const double w, const double h) {
    dimensions = std::make_tuple(w, h);
}

void Display::setHDR(const bool hdr) {
    hdr_supported = hdr;
}

void Display::setResponseTime(const int rt) {
    response_time = rt;
}

std::tuple<int, int> Display::getResolution() const {
    return resolution;
}

int Display::getRefreshRate() const {
    return refresh_rate;
}

std::tuple<double, double> Display::getDimensions() const {
    return dimensions;
}

bool Display::getHDR() const {
    return hdr_supported;
}

int Display::getResponseTime() const {
    return response_time;
}

void Display::generateId() {
    std::ifstream file_in("../txt_files/display.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Display display: display_vec){
            std::string id = display.getID(); // AZ0001
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
    display_vec.push_back(*this);
    std::ofstream file_out("../txt_files/display.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Display display: display_vec){
        file_out << display.getID() << "|";
        file_out << display.getDescription() << "|";
        file_out << display.getBrand() << "|";
        file_out << display.getModel() << "|";
        file_out << display.getPrice() << "|";
        file_out << display.getQuantity() << "|";
        file_out << display.getOnDisplay() << "|";
        file_out << std::get<0>(display.getResolution()) << "|";
        file_out << std::get<1>(display.getResolution()) << "|";
        file_out << display.getRefreshRate() << "|";
        file_out << std::get<0>(display.getDimensions()) << "|";
        file_out << std::get<1>(display.getDimensions()) << "|";
        file_out << display.getHDR() << "|";
        file_out << display.getResponseTime() << "|";
        file_out << display.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Display::updateVec(const Display dp_in) {
    for (Display& dp: display_vec){
        if (dp.getID() == dp_in.getID()){
            dp.setDescription(dp_in.getDescription());
            dp.setBrand(dp_in.getBrand());
            dp.setModel(dp_in.getModel());
            dp.setPrice(dp_in.getPrice());
            dp.setQuantity(dp_in.getQuantity());
            dp.setOnDisplay(dp_in.getOnDisplay());
            dp.setResolution(std::get<0>(dp_in.getResolution()), std::get<1>(dp_in.getResolution()));
            dp.setRefreshRate(dp_in.getRefreshRate());
            dp.setDimensions(std::get<0>(dp_in.getDimensions()), std::get<1>(dp_in.getDimensions()));
            dp.setHDR(dp_in.getHDR());
            dp.setResponseTime(dp_in.getResponseTime());
            dp.setImagePath(dp_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/display.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Display display: display_vec){
        file_out << display.getID() << "|";
        file_out << display.getDescription() << "|";
        file_out << display.getBrand() << "|";
        file_out << display.getModel() << "|";
        file_out << display.getPrice() << "|";
        file_out << display.getQuantity() << "|";
        file_out << display.getOnDisplay() << "|";
        file_out << std::get<0>(display.getResolution()) << "|";
        file_out << std::get<1>(display.getResolution()) << "|";
        file_out << display.getRefreshRate() << "|";
        file_out << std::get<0>(display.getDimensions()) << "|";
        file_out << std::get<1>(display.getDimensions()) << "|";
        file_out << display.getHDR() << "|";
        file_out << display.getResponseTime();
        file_out << display.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;    
}

void Display::readData() {
    std::ifstream file_in("../txt_files/display.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string resw;
    std::string resh;
    std::string refresh_rate;
    std::string w;
    std::string h;
    std::string hdr;
    std::string response_time;
    std::string image_path;
    std::array<std::string*, 15> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &resw, &resh, &refresh_rate, &w, &h, &hdr, &response_time, &image_path};
    
    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Display dp;
        dp.setID(id);
        dp.setDescription(description);
        dp.setBrand(brand);
        dp.setModel(model);
        dp.setPrice(std::stod(price));
        dp.setQuantity(std::stoi(quantity));
        dp.setOnDisplay(std::stoi(on_display));
        dp.setResolution(std::stoi(resw), std::stoi(resh));
        dp.setRefreshRate(std::stoi(refresh_rate));
        dp.setDimensions(std::stod(w), std::stod(h));
        dp.setHDR(std::stoi(hdr));
        dp.setResponseTime(std::stoi(response_time));
        dp.setImagePath(image_path);
        display_vec.push_back(dp);
    }
    file_in.close();
    return;
}