#ifndef HEADSET_H
#define HEADSET_H

#include "../peri_parent.h"

class Headset : public Peripherals{
    private:
        const std::string id_start = "AQ";
        bool is_wireless;
        bool has_anc;
        bool is_rgb;
        bool surround_sound;
    public:
        Headset();
        Headset(const int, const double);

        void setANC(const bool);
        void setWireless(const bool);
        void setRGB(const bool);
        void setSurroundSound(const bool);

        bool getANC() const;
        bool getWireless() const;
        bool getRGB() const;
        bool getSurroundSound() const;

        static std::vector<Headset> headset_vec;
        void generateId();
        static void updateVec(const Headset);
        static void readData();
};

#endif