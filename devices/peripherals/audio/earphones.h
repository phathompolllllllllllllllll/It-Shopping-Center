#ifndef EARPHONES_H
#define EARPHONES_H

#include "../peri_parent.h"

class Earphones : public Peripherals{
    private:
        const std::string id_start = "AP";
        bool has_volume_control;
        bool water_resistant;
        double wire_length;
    public:
        Earphones();
        Earphones(const int, const double);

        void setVolumeControl(const bool);
        void setWaterResistant(const bool);
        void setWireLength(const double);

        bool getVolumeControl() const;
        bool getWaterResistant() const;
        double getWireLength() const;

        static std::vector<Earphones> earphones_vec;       
        void generateId();
        static void updateVec(const Earphones);
        static void readData();

};

#endif