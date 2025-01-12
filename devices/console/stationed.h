#ifndef STATIONED_H
#define STATIONED_H

#include "console.h"

class Stationed : public Console {
    private:   
        std::string id_start = "BF";
        std::string ssd;
        std::string size;

    public:
        Stationed();
        Stationed(const int, const double);
        
        std::string getSSD() const;
        std::string getSize() const;

        void setSSD(const std::string);
        void setSize(const std::string);

        static std::vector<Stationed> stationed_vec;
        void generateId();
        static void updateVec(const Stationed);
        static void readData();
};

#endif