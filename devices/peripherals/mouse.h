#ifndef MOUSE_H
#define MOUSE_H

#include "peri_parent.h"

class Mouse: public Peripherals {
    private:
        const std::string id_start = "AK";
        std::string type; //Gaming, Office, etc.
        std::string sensor; //Optical, Laser, etc.
        bool is_wireless;
        std::tuple<int, int> sensitivity; //(min, max) DPI
        double weight; //g
        double battery_life; //hours
        bool is_rechargeable;

    public:
        Mouse();
        Mouse(const int, const double);

        void setType(const std::string);
        void setSensor(const std::string);
        void setWireless(const bool);
        void setSensitivity(const int, const int);
        void setWeight(const double);
        void setBatteryLife(const double);
        void setRechargeable(const bool);

        std::string getType() const;
        std::string getSensor() const;
        bool getWireless() const;
        std::tuple<int, int> getSensitivity() const;
        double getWeight() const;
        double getBatteryLife() const;
        bool getRechargeable() const;

        static std::vector<Mouse> mouse_vec;
        void generateId();
        static void updateVec(const Mouse);
        static void readData();
};

#endif