#ifndef PCCASE_H
#define PCCASE_H

#include "comp_parts_parent.h"

class PCCase : public ComputerParts{
    private:
        const std::string id_start = "AE";
        std::string form_factor;
        std::tuple<double, double, double> dimension;
        std::string cooling_type;
        double max_gpu_length;
        double max_cpu_height;
        std::array<std::tuple<std::string, int>, 3> fan_support; //(size, noise)
    public:
        PCCase();
        PCCase(const int, const double);

        void setFormFactor(const std::string);
        void setDimension(const double, const double, const double);
        void setCoolingType(const std::string);
        void setMaxGPULength(const double);
        void setMaxCPUHeight(const double);
        void setFanSupport(const int, const std::string, const int);

        std::string getFormFactor() const;
        std::tuple<double, double, double> getDimension() const;
        std::string getCoolingType() const;
        double getMaxGPULength() const;
        double getMaxCPUHeight() const;
        std::array<std::tuple<std::string, int>, 3> getFanSupport() const;

        static std::vector<PCCase> pc_case_vec;
        void generateId();
        static void updateVec(const PCCase);
        static void readData();
};

#endif