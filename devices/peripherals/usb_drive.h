#ifndef USB_DRIVE_H
#define USB_DRIVE_H

#include "peri_parent.h"

class UsbDrive : public Peripherals {
    private:
        const std::string id_start = "AW";
        std::string capacity; //GB
        std::string interface; //USB 2.0, USB 3.0, etc.
        int transfer_speed; //MB/s
    public:
        UsbDrive();
        UsbDrive(const int, const double);

        void setCapacity(const std::string);
        void setInterface(const std::string);
        void setTransferSpeed(const int);

        std::string getCapacity() const;
        std::string getInterface() const;
        int getTransferSpeed() const;

        static std::vector<UsbDrive> usb_drive_vec;
        void generateId();
        static void updateVec(const UsbDrive);
        static void readData();
};

#endif