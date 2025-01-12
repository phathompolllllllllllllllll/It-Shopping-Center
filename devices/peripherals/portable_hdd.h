#ifndef P_HDD_H
#define P_HDD_H

#include "peri_parent.h"

class Portable_HDD : public Peripherals {
    private:
        const std::string id_start = "AX";
        int capacity; //GB
        std::string interface;
        double transfer_speed; //MB/s
        std::tuple<double, double, double> dimensions; //cm
        double weight; //kg
    public:
        Portable_HDD();
        Portable_HDD(const int, const double);

        void setCapacity(const int);
        void setInterface(const std::string);
        void setTransferSpeed(const double);
        void setDimensions(const double, const double, const double);
        void setWeight(const double);

        int getCapacity() const;
        std::string getInterface() const;
        double getTransferSpeed() const;
        std::tuple<double, double, double> getDimensions() const;
        double getWeight() const;

        static std::vector<Portable_HDD> portable_hdd_vec;
        void generateId();
        static void updateVec(const Portable_HDD);
        static void readData();
};

#endif