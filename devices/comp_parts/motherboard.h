#ifndef MOTHERBOARD_H
#define MOTHERBOARD_H

#include "comp_parts_parent.h"

class Motherboard : public ComputerParts{
    private:
        const std::string id_start = "AF";
        std::string form_factor;
        std::string socket;
        std::tuple<std::string, int> memory; //(type, capacity)
        std::string chipset;
        std::vector<std::string> expansion_slots;
        std::vector<std::string> connectivity;
        std::vector<std::tuple<std::string, int>> storage; //list of (type, capacity)
        std::string audio;
        bool multi_gpu;
        std::string bios;
    public:
        Motherboard();
        Motherboard(const int q, const double p);
        
        void setFormFactor(const std::string ff);
        void setSocket(const std::string s);
        void setMemory(const std::string t, const int c);
        void setChipset(const std::string c);
        void addExpansionSlots(const std::string es);
        void clearExpansionSlots();
        void addConnectivity(const std::string c);
        void clearConnectivity();
        void addStorage(const std::string t, const int c);
        void clearStorage();
        void setAudio(const std::string a);
        void setMultiGPU(const bool mg);
        void setBios(const std::string b);
        
        std::string getFormFactor() const;
        std::string getSocket() const;
        std::tuple<std::string, int> getMemory() const;
        std::string getChipset() const;
        std::vector<std::string> getExpansionSlots() const;
        std::vector<std::string> getConnectivity() const;
        std::vector<std::tuple<std::string, int>> getStorage() const;
        std::string getAudio() const;
        bool getMultiGPU() const;
        std::string getBios() const;

        static std::vector<Motherboard> motherboard_vec;
        void generateId();
        static void updateVec(Motherboard);
        static void readData();
};

#endif