#ifndef HDD_H
#define HDD_H

#include "storage_parent.h"

class HDD : public Storage{
    private:
        const std::string id_start = "AI";
        int rotation_speed; //rpm
        int cache; //MB
        std::tuple<double, double, double> power_consumption; //idle, read, write
    public:
        HDD();
        HDD(const int, const double);

        void setRotationSpeed(const int);
        void setCache(const int);
        void setPowerConsumption(const double, const double, const double);
        
        int getRotationSpeed() const;
        int getCache() const;
        std::tuple<double, double, double> getPowerConsumption() const;
        
        static std::vector<HDD> hdd_vec;
        void generateId();
        static void updateVec(const HDD);
        static void readData();          
};
#endif