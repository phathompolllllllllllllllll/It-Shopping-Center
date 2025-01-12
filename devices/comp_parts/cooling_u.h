#ifndef COOLING_U_H
#define COOLING_U_H


#include "comp_parts_parent.h"

class CoolingUnit : public ComputerParts{
    private:
        const std::string id_start = "AD";
        std::string form_factor;
        std::string type; // air? liquid?
        int cool_capacity; // watts
        std::tuple<double, double, double> dimension; // 123x123x123
        int noise_level; // dB
        int fan_speed; // rpm
        bool is_rgb;
    public:
        CoolingUnit();
        CoolingUnit(const int q, const double p);
        
        void setType(const std::string);
        void setCoolCapacity(const int);
        void setFormFactor(const std::string);
        void setDimension(const double, const double, const double);
        void setNoiseLevel(const int);
        void setFanSpeed(const int);
        void setIsRgb(const bool);
        
        std::string getType() const;
        int getCoolCapacity() const;
        std::string getFormFactor() const;
        std::tuple<double, double, double> getDimension() const;
        int getNoiseLevel() const;
        int getFanSpeed() const;
        bool getIsRgb() const;

        static std::vector<CoolingUnit> cooling_unit_vec;
        void generateId();
        static void updateVec(const CoolingUnit);
        static void readData();
};
#endif