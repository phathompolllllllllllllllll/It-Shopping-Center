#ifndef DESKTOP_H
#define DESKTOP_H

#include "../devices.h"

class Desktop : public Devices{
    private:
        std::string id_start = "BG";
        std::string cpu;
        std::string gpu;
        std::string memory;
        std::vector<std::string> storage;
        std::string os;
        std::string motherboard;
        std::string psu;
        std::string pc_case;
        std::string cooling;

    public:
        Desktop();
        Desktop(const int, const double);

        void setCPU(const std::string);
        void setGPU(const std::string);
        void setMemory(const std::string);
        void addStorage(const std::string);
        void clearStorage();
        void setOS(const std::string);
        void setMotherboard(const std::string);
        void setPSU(const std::string);
        void setPCCase(const std::string);
        void setCooling(const std::string);

        std::string getCPU() const;
        std::string getGPU() const;
        std::string getMemory() const;
        std::vector<std::string> getStorage() const;
        std::string getOS() const;
        std::string getMotherboard() const;
        std::string getPSU() const;
        std::string getPCCase() const;
        std::string getCooling() const;

        static std::vector<Desktop> desktop_vec;
        void generateId();
        static void updateVec(const Desktop);
        static void readData();
};

#endif
