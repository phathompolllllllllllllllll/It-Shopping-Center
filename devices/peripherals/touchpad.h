#ifndef TOUCHPAD_H
#define TOUCHPAD_H

#include "peri_parent.h"

class Touchpad : public Peripherals {
    private:
        const std::string id_start = "AM";
        std::string type; //Capacitive, Resistive, etc.
        std::tuple<double, double> dimensions; //(l, w) in cm
    public:
        Touchpad();
        Touchpad(const int, const double);

        void setType(const std::string);
        void setDimensions(const double, const double);

        std::string getType() const;
        std::tuple<double, double> getDimensions() const;

        static std::vector<Touchpad> touchpad_vec;
        void generateId();
        static void updateVec(const Touchpad);
        static void readData();
};

#endif