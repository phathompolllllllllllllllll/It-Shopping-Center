#ifndef WEBCAM_H
#define WEBCAM_H

#include "peri_parent.h"

class Webcam : public Peripherals {
    private:
        const std::string id_start = "AV";
        std::tuple<int, int> resolution;
        std::string fps;
        int field_of_view; //degrees
        bool has_microphone;
        std::tuple<double, double, double> dimensions;
    public:
        Webcam();
        Webcam(const int, const double);

        void setResolution(const int, const int);
        void setFps(const std::string);
        void setFieldOfView(const int);
        void setHasMicrophone(const bool);
        void setDimensions(const double, const double, const double);

        std::tuple<int, int> getResolution() const;
        std::string getFps() const;
        int getFieldOfView() const;
        bool getHasMicrophone() const;
        std::tuple<double, double, double> getDimensions() const;

        static std::vector<Webcam> webcam_vec;
        void generateId();
        static void updateVec(const Webcam);
        static void readData();

};

#endif