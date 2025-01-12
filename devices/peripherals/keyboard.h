#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "peri_parent.h"

class Keyboard : public Peripherals {
    private:
        const std::string id_start = "AL";
        std::string type; //Mechanical, Membrane, etc.
        std::string layout; //QWERTY, AZERTY, etc.
        bool is_backlit;
        bool is_wireless;
        std::string key_switch; //Cherry MX, Romer-G, etc.
    public:
        Keyboard();
        Keyboard(const int, const double);

        void setType(const std::string);
        void setLayout(const std::string);
        void setBacklit(const bool);
        void setWireless(const bool);
        void setKeySwitch(const std::string);

        std::string getType() const;
        std::string getLayout() const;
        bool getBacklit() const;
        bool getWireless() const;
        std::string getKeySwitch() const;

        static std::vector<Keyboard> keyboard_vec;        
        void generateId();
        static void updateVec(const Keyboard);
        static void readData();
};

#endif