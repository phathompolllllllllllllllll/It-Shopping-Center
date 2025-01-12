#include "webcam.h"

Webcam::Webcam(){}

Webcam::Webcam(const int q, const double p) : Peripherals(q, p) {
    resolution = std::make_tuple(0, 0);
    fps = "";
    field_of_view = 0;
    has_microphone = false;
    dimensions = std::make_tuple(0, 0, 0);
    generateId();
}

void Webcam::setResolution(int l, int h) {
    resolution = std::make_tuple(l, h);
}

void Webcam::setFps(const std::string f) {
    fps = f;
}

void Webcam::setFieldOfView(const int fov) {
    field_of_view = fov;
}

void Webcam::setHasMicrophone(const bool hm) {
    has_microphone = hm;
}

void Webcam::setDimensions(const double l, const double w, const double h) {
    dimensions = std::make_tuple(l, w, h);
}

std::tuple<int, int> Webcam::getResolution() const {
    return resolution;
}

std::string Webcam::getFps() const {
    return fps;
}

int Webcam::getFieldOfView() const {
    return field_of_view;
}

bool Webcam::getHasMicrophone() const {
    return has_microphone;
}

std::tuple<double, double, double> Webcam::getDimensions() const {
    return dimensions;
}

void Webcam::generateId() {
    std::ifstream file_in("../txt_files/webcam.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Webcam cam: webcam_vec){
            std::string id = cam.getID(); // AZ0001
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
    webcam_vec.push_back(*this);
    std::ofstream file_out("../txt_files/webcam.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Webcam cam: webcam_vec){
        file_out << cam.getID() << "|";
        file_out << cam.getDescription() << "|";
        file_out << cam.getBrand() << "|";
        file_out << cam.getModel() << "|";
        file_out << cam.getPrice() << "|";
        file_out << cam.getQuantity() << "|";
        file_out << cam.getOnDisplay() << "|";
        file_out << std::get<0>(cam.getResolution()) << "|";
        file_out << std::get<1>(cam.getResolution()) << "|";
        file_out << cam.getFps() << "|";
        file_out << cam.getFieldOfView() << "|";
        file_out << cam.getHasMicrophone() << "|";
        file_out << std::get<0>(cam.getDimensions()) << "|";
        file_out << std::get<1>(cam.getDimensions()) << "|";
        file_out << std::get<2>(cam.getDimensions()) << "|";
        file_out << cam.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Webcam::updateVec(const Webcam cam_in) {
    for (Webcam& cam: webcam_vec){
        if (cam.getID() == cam_in.getID()){
            cam.setDescription(cam_in.getDescription());
            cam.setBrand(cam_in.getBrand());
            cam.setModel(cam_in.getModel());
            cam.setPrice(cam_in.getPrice());
            cam.setQuantity(cam_in.getQuantity());
            cam.setOnDisplay(cam_in.getOnDisplay());
            cam.setResolution(std::get<0>(cam_in.getResolution()), std::get<1>(cam_in.getResolution()));
            cam.setFps(cam_in.getFps());
            cam.setFieldOfView(cam_in.getFieldOfView());
            cam.setHasMicrophone(cam_in.getHasMicrophone());
            cam.setDimensions(std::get<0>(cam_in.getDimensions()), 
                            std::get<1>(cam_in.getDimensions()), 
                            std::get<2>(cam_in.getDimensions()));
            cam.setImagePath(cam_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/webcam.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Webcam cam: webcam_vec){
        file_out << cam.getID() << "|";
        file_out << cam.getDescription() << "|";
        file_out << cam.getBrand() << "|";
        file_out << cam.getModel() << "|";
        file_out << cam.getPrice() << "|";
        file_out << cam.getQuantity() << "|";
        file_out << cam.getOnDisplay() << "|";
        file_out << std::get<0>(cam.getResolution()) << "|";
        file_out << std::get<1>(cam.getResolution()) << "|";
        file_out << cam.getFps() << "|";
        file_out << cam.getFieldOfView() << "|";
        file_out << cam.getHasMicrophone() << "|";
        file_out << std::get<0>(cam.getDimensions()) << "|";
        file_out << std::get<1>(cam.getDimensions()) << "|";
        file_out << std::get<2>(cam.getDimensions()) << "|";
        file_out << cam.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Webcam::readData(){
    std::ifstream file_in("../txt_files/webcam.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string resolution_w;
    std::string resolution_h;
    std::string fps;
    std::string fov;
    std::string has_mic;
    std::string dim_l;
    std::string dim_w;
    std::string dim_h;
    std::string image_path;
    std::array<std::string*, 16> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &resolution_w, &resolution_h, &fps, &fov, &has_mic, &dim_l, &dim_w, &dim_h, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');          
        }
        Webcam cam;
        cam.setID(id);
        cam.setDescription(description);
        cam.setBrand(brand);
        cam.setModel(model);
        cam.setPrice(std::stod(price));
        cam.setQuantity(std::stoi(quantity));
        cam.setOnDisplay(std::stoi(on_display));
        cam.setResolution(std::stoi(resolution_w), std::stoi(resolution_h));
        cam.setFps(fps);
        cam.setFieldOfView(std::stoi(fov));
        cam.setHasMicrophone(std::stoi(has_mic));
        cam.setDimensions(std::stod(dim_l), std::stod(dim_w), std::stod(dim_h));
        cam.setImagePath(image_path);
        webcam_vec.push_back(cam); 
    }
    file_in.close();
    return;
}