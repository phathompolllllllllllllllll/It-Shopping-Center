#include "cpu.h"

CPU::CPU(){}

CPU::CPU(const int q, const double p) : ComputerParts(q, p){
    socket = "-";
    form_factor = "-";
    core_no = 0;
    thread_no = 0;
    base_clock = 0.0;
    boost_clock = 0.0;
    has_overclock = false;
    memory_support = std::make_tuple("-", 0, 0);
    integrated_graphics = "-";
    generateId();
}

void CPU::setSocket(const std::string s){
    socket = s;
}

void CPU::setFormFactor(const std::string ff){
    form_factor = ff;
}

void CPU::setCoreNo(const int cn){
    core_no = cn;
}

void CPU::setThreadNo(const int tn){
    thread_no = tn;
}

void CPU::setBaseClock(const double basec){
    base_clock = basec;
}

void CPU::setBoostClock(const double boostc){
    boost_clock = boostc;
}

void CPU::setHasOverclock(const bool h_oc){
    has_overclock = h_oc;
}

void CPU::setMemorySupport(const std::string type, const int freq, const int no){
    memory_support = std::make_tuple(type, freq, no);
}

void CPU::setIntegratedGraphics(const std::string ig){
    integrated_graphics = ig;
}

std::string CPU::getSocket() const{
    return socket;
}

std::string CPU::getFormFactor() const{
    return form_factor;
}

int CPU::getCoreNo() const{
    return core_no;
}

int CPU::getThreadNo() const{
    return thread_no;
}

double CPU::getBaseClock() const{
    return base_clock;
}

double CPU::getBoostClock() const{
    return boost_clock;
}

bool CPU::getHasOverclock() const{
    return has_overclock;
}

std::tuple<std::string, int, int> CPU::getMemorySupport() const{
    return memory_support;
}

std::string CPU::getIntegratedGraphics() const{
    return integrated_graphics;
}

void CPU::generateId(){
    std::ifstream file_in("../txt_files/cpu.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const CPU cpu: cpu_vec){
            std::string id = cpu.getID(); // AZ0001
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
    cpu_vec.push_back(*this);
    std::ofstream file_out("../txt_files/cpu.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const CPU cpu: cpu_vec){
        file_out << cpu.getID() << "|";
        file_out << cpu.getDescription() << "|";
        file_out << cpu.getBrand() << "|";
        file_out << cpu.getModel() << "|";
        file_out << cpu.getPrice() << "|";
        file_out << cpu.getQuantity() << "|";
        file_out << cpu.getOnDisplay() << "|";
        file_out << cpu.getSocket() << "|";
        file_out << cpu.getFormFactor() << "|";
        file_out << cpu.getCoreNo() << "|";
        file_out << cpu.getThreadNo() << "|";
        file_out << cpu.getBaseClock() << "|";
        file_out << cpu.getBoostClock() << "|";
        file_out << cpu.getHasOverclock() << "|";
        file_out << std::get<0>(cpu.getMemorySupport()) << "|"; 
        file_out << std::get<1>(cpu.getMemorySupport()) << "|"; 
        file_out << std::get<2>(cpu.getMemorySupport()) << "|";
        file_out << cpu.getIntegratedGraphics() << "|";
        file_out << cpu.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void CPU::updateVec(const CPU cpu_in){
    for (CPU& cpu: cpu_vec){
        if (cpu.getID() == cpu_in.getID()){
            cpu.setDescription(cpu_in.getDescription());
            cpu.setBrand(cpu_in.getBrand());
            cpu.setModel(cpu_in.getModel());
            cpu.setPrice(cpu_in.getPrice());
            cpu.setQuantity(cpu_in.getQuantity());
            cpu.setOnDisplay(cpu_in.getOnDisplay());
            cpu.setSocket(cpu_in.getSocket());
            cpu.setFormFactor(cpu_in.getFormFactor());
            cpu.setCoreNo(cpu_in.getCoreNo());
            cpu.setThreadNo(cpu_in.getThreadNo());
            cpu.setBaseClock(cpu_in.getBaseClock());
            cpu.setBoostClock(cpu_in.getBoostClock());
            cpu.setHasOverclock(cpu_in.getHasOverclock());
            cpu.setMemorySupport(std::get<0>(cpu_in.getMemorySupport()),
                                 std::get<1>(cpu_in.getMemorySupport()),
                                 std::get<2>(cpu_in.getMemorySupport()));
            cpu.setIntegratedGraphics(cpu_in.getIntegratedGraphics());
            cpu.setImagePath(cpu_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/cpu.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const CPU cpu: cpu_vec){
        file_out << cpu.getID() << "|";
        file_out << cpu.getDescription() << "|";
        file_out << cpu.getBrand() << "|";
        file_out << cpu.getModel() << "|";
        file_out << cpu.getPrice() << "|";
        file_out << cpu.getQuantity() << "|";
        file_out << cpu.getOnDisplay() << "|";
        file_out << cpu.getSocket() << "|";
        file_out << cpu.getFormFactor() << "|";
        file_out << cpu.getCoreNo() << "|";
        file_out << cpu.getThreadNo() << "|";
        file_out << cpu.getBaseClock() << "|";
        file_out << cpu.getBoostClock() << "|";
        file_out << cpu.getHasOverclock() << "|";
        file_out << std::get<0>(cpu.getMemorySupport()) << "|"; 
        file_out << std::get<1>(cpu.getMemorySupport()) << "|"; 
        file_out << std::get<2>(cpu.getMemorySupport()) << "|";
        file_out << cpu.getIntegratedGraphics() << "|";
        file_out << cpu.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void CPU::readData(){
    std::ifstream file_in("../txt_files/cpu.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::string id, desc, brand, model, price, quantity, on_display;
    std::string socket;
    std::string form_factor;
    std::string core_no;
    std::string thread_no;
    std::string base_clock;
    std::string boost_clock;
    std::string has_overclock;
    std::string type;
    std::string freq;
    std::string no;
    std::string integrated_graphics;
    std::string image_path;
    std::array<std::string*, 19> data{&id, &desc, &brand, &model, &price, &quantity, &on_display, &socket, &form_factor, &core_no, &thread_no, &base_clock, &boost_clock, &has_overclock, &type, &freq, &no, &integrated_graphics, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream s_row(row);
        for (std::string* data_ptr: data){
            std::getline(s_row, *data_ptr, '|');
        }
        CPU cpu;
        cpu.setID(id);
        cpu.setDescription(desc);
        cpu.setBrand(brand);
        cpu.setModel(model);
        cpu.setPrice(std::stod(price));
        cpu.setQuantity(std::stoi(quantity));
        cpu.setOnDisplay(std::stoi(on_display));
        cpu.setSocket(socket);
        cpu.setFormFactor(form_factor);
        cpu.setCoreNo(std::stoi(core_no));
        cpu.setThreadNo(std::stoi(thread_no));
        cpu.setBaseClock(std::stod(base_clock));
        cpu.setBoostClock(std::stod(boost_clock));
        cpu.setHasOverclock(std::stoi(has_overclock));
        cpu.setMemorySupport(type, std::stoi(freq), std::stoi(no));
        cpu.setIntegratedGraphics(integrated_graphics);
        cpu.setImagePath(image_path);
        cpu_vec.push_back(cpu);
    }
    file_in.close();
    return;
}