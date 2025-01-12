#ifndef SD_CARD_H
#define SD_CARD_H

#include "peri_parent.h"

class SdCard : public Peripherals {
    private:
        const std::string id_start = "AY";
        std::string type; //SD, MicroSD, etc.
        std::string capacity; //GB
        std::string speed; //MB/s
        std::string class_rating; //Class 4, UHS-I, etc.
        std::string form_factor; //Standard, Mini, Micro, etc.

    public:
        SdCard();
        SdCard(const int, const double);

        void setType(const std::string);
        void setCapacity(const std::string);
        void setSpeed(const std::string);
        void setClassRating(const std::string);
        void setFormFactor(const std::string);

        std::string getType() const;
        std::string getCapacity() const;
        std::string getSpeed() const;
        std::string getClassRating() const;
        std::string getFormFactor() const;

        static std::vector<SdCard> sd_card_vec;
        void generateId();
        static void updateVec(const SdCard);
        static void readData();
};

#endif