#ifndef HANDHELD_H
#define HANDHELD_H


#include "console.h"

class Handheld : public Console {
    private:
        std::string id_start = "BC";
        std::string battery;
        std::string power_supply;
        std::string headphone_jack;
        int microSD_slot;
        std::string size;
    public:
        Handheld();
        Handheld(const int, const double);
        
        std::string getBattery() const;
        std::string getPowerSupply() const;
        std::string getHeadphoneJack() const;
        int getMicroSDSlot() const;
        std::string getSize() const;

        void setBattery(const std::string);
        void setPowerSupply(const std::string);
        void setHeadphoneJack(const std::string);
        void setMicroSDSlot(const int);
        void setSize(const std::string);

        static std::vector<Handheld> handheld_vec;
        void generateId();
        static void updateVec(Handheld);
        static void readData();
};
        
#endif