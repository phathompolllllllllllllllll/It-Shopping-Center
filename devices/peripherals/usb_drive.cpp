#include "usb_drive.h"

UsbDrive::UsbDrive(){}

UsbDrive::UsbDrive(const int q, const double p) : Peripherals(q, p) {
    capacity = "-";
    interface = "-";
    transfer_speed = 0;
    generateId();
}

void UsbDrive::setCapacity(const std::string c) {
    capacity = c;
}

void UsbDrive::setInterface(const std::string i) {
    interface = i;
}

void UsbDrive::setTransferSpeed(const int s) {
    transfer_speed = s;
}

std::string UsbDrive::getCapacity() const {
    return capacity;
}

std::string UsbDrive::getInterface() const {
    return interface;
}

int UsbDrive::getTransferSpeed() const {
    return transfer_speed;
}

void UsbDrive::generateId() {
    std::ifstream file_in("../txt_files/usb_drive.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const UsbDrive usb: usb_drive_vec){
            std::string id = usb.getID(); // AZ0001
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
    usb_drive_vec.push_back(*this);
    std::ofstream file_out("../txt_files/usb_drive.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const UsbDrive usb: usb_drive_vec){
        file_out << usb.getID() << "|";
        file_out << usb.getDescription() << "|";
        file_out << usb.getBrand() << "|";
        file_out << usb.getModel() << "|";
        file_out << usb.getPrice() << "|";
        file_out << usb.getQuantity() << "|";
        file_out << usb.getOnDisplay() << "|";
        file_out << usb.getCapacity() << "|";
        file_out << usb.getInterface() << "|";
        file_out << usb.getTransferSpeed() << "|";
        file_out << usb.getImagePath(); 
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void UsbDrive::updateVec(const UsbDrive usb_in){
    for (UsbDrive& usb: usb_drive_vec){
        if (usb.getID() == usb_in.getID()){
            usb.setDescription(usb_in.getDescription());
            usb.setBrand(usb_in.getBrand());
            usb.setModel(usb_in.getModel());
            usb.setPrice(usb_in.getPrice());
            usb.setQuantity(usb_in.getQuantity());
            usb.setOnDisplay(usb_in.getOnDisplay());
            usb.setCapacity(usb_in.getCapacity());
            usb.setInterface(usb_in.getInterface());
            usb.setTransferSpeed(usb_in.getTransferSpeed());
            usb.setImagePath(usb_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/usb_drive.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const UsbDrive usb: usb_drive_vec){
        file_out << usb.getID() << "|";
        file_out << usb.getDescription() << "|";
        file_out << usb.getBrand() << "|";
        file_out << usb.getModel() << "|";
        file_out << usb.getPrice() << "|";
        file_out << usb.getQuantity() << "|";
        file_out << usb.getOnDisplay() << "|";
        file_out << usb.getCapacity() << "|";
        file_out << usb.getInterface() << "|";
        file_out << usb.getTransferSpeed() << "|";
        file_out << usb.getImagePath(); 
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void UsbDrive::readData() {
    std::ifstream file_in("../txt_files/usb_drive.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string capacity;
    std::string interface;
    std::string transfer_speed;
    std::string image_path;
    std::array<std::string*, 11> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &capacity, &interface, &transfer_speed, &image_path};

    std::string row;
    while (std::getline(file_in, row)) {
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data) {
            std::getline(rowstream, *data_ptr, '|');
        }
        UsbDrive usb;
        usb.setID(id);
        usb.setDescription(description);
        usb.setBrand(brand);
        usb.setModel(model);
        usb.setPrice(std::stod(price));
        usb.setQuantity(std::stoi(quantity));
        usb.setOnDisplay(std::stoi(on_display));
        usb.setCapacity(capacity);
        usb.setInterface(interface);
        usb.setTransferSpeed(std::stoi(transfer_speed));
        usb.setImagePath(image_path);
        usb_drive_vec.push_back(usb);  
    }    
    file_in.close();
    return;
}