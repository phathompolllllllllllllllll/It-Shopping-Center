#ifndef MICROPHONE_H
#define MICROPHONE_H

#include "../peri_parent.h"

class Microphone : public Peripherals{
    private:
        const std::string id_start = "AT";
        std::string directionality;
        bool has_usb;
        bool has_xlr;
    public:
        Microphone();
        Microphone(const int, const double);

        void setDirectionality(const std::string);
        void setUSB(const bool);
        void setXLR(const bool);

        std::string getDirectionality() const;
        bool getUSB() const;
        bool getXLR() const;

        static std::vector<Microphone> microphone_vec;
        void generateId();
        static void updateVec(const Microphone);
        static void readData();        
};

#endif