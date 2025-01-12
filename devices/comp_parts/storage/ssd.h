#ifndef SSD_H
#define SSD_H

#include "storage_parent.h"

class SSD : public Storage{
    private:
        const std::string id_start = "AH";
        int power_consumption;
    public:
        SSD();
        SSD(const int, const double);

        void setPowerConsumption(const int);

        int getPowerConsumption() const;
        
        static std::vector<SSD> ssd_vec;
        void generateId();
        static void updateVec(const SSD);
        static void readData();
};

#endif