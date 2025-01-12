#ifndef HEADPHONES_H
#define HEADPHONES_H

#include "../peri_parent.h"

class Headphones : public Peripherals{
    private:
        const std::string id_start = "AR";
        bool has_anc;
        bool is_wireless;
        bool surround_sound;
    public:
        Headphones();
        Headphones(const int, const double);

        void setANC(const bool);
        void setWireless(const bool);
        void setSurroundSound(const bool);

        bool getANC() const;
        bool getWireless() const;
        bool getSurroundSound() const;

        static std::vector<Headphones> headphones_vec;        
        void generateId();
        static void updateVec(const Headphones);
        static void readData();
};

#endif