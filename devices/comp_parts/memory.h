#ifndef MEMORY_H
#define MEMORY_H

#include "comp_parts_parent.h"

class Memory : public ComputerParts{
    private:
        const std::string id_start = "AC";
        std::string type;
        int capacity;
        int frequency;
        int latency;
        std::string form_factor;
        double voltage;
        bool has_ecc;
        std::string compatible_with;
    public:
        Memory();
        Memory(const int, const double);
        
        void setType(const std::string);
        void setCapacity(const int);
        void setFrequency(const int);
        void setLatency(const int);
        void setFormFactor(const std::string);
        void setVoltage(const double);
        void setHasECC(const bool);
        void setCompatibleWith(const std::string);

        std::string getType() const;
        int getCapacity() const;
        int getFrequency() const;
        int getLatency() const;
        std::string getFormFactor() const;
        double getVoltage() const;
        bool getHasECC() const;
        std::string getCompatibleWith() const;

        static std::vector<Memory> memory_vec;
        void generateId();
        static void updateVec(const Memory);
        static void readData();
};

#endif