#ifndef SPEAKERS_H
#define SPEAKERS_H

#include "../peri_parent.h"

class Speakers : public Peripherals{
    private:
        const std::string id_start = "AS";
        double power_output; // watts
        double configuration; // 2.1, 5.1, 7.1, etc
        bool is_wireless;
        double battery_life; // hours
    public:
        Speakers();
        Speakers(const int, const double);

        void setPowerOutput(const double);
        void setConfiguration(const double);
        void setWireless(const bool);
        void setBatteryLife(const double);

        double getPowerOutput() const;
        double getConfiguration() const;
        bool getWireless() const;
        double getBatteryLife() const;

        static std::vector<Speakers> speakers_vec;
        void generateId();
        static void updateVec(const Speakers);
        static void readData();

};

#endif