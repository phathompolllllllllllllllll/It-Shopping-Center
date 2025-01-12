#ifndef EARBUDS_H
#define EARBUDS_H

#include "../peri_parent.h"

class Earbuds : public Peripherals
{
    private:
        const std::string id_start = "AO";
        double battery_life;
        bool has_anc;
        bool water_resistant;
    public:
        Earbuds();
        Earbuds(const int, const double);

        void setBatteryLife(const double);
        void setANC(const bool);
        void setWaterResistant(const bool);

        double getBatteryLife() const;
        bool getANC() const;
        bool getWaterResistant() const;

        static std::vector<Earbuds> earbuds_vec;
        void generateId();
        static void updateVec(const Earbuds);
        static void readData();
};

#endif 