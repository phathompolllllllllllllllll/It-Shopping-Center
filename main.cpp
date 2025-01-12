#include <iostream>
#include "devices\vr\vr.h"
#include "devices\devices.h"
//declare all static vectors


std::vector<VR> VR::vr_vec;
double Devices::total_sales = 0;

int main() {
    VR vr(1, 1000);
    vr.setModel("Oculus Quest 2");
    VR::updateVec(vr);
    return 0;
}