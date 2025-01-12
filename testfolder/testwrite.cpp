#include "../logic_classes.h"

std::vector<VR> VR::vr_vec;
double Devices::total_sales = 0;

int main(){
    VR vr1(1, 1000);
    vr1.setResolution(1920, 1080);
    vr1.setWithControllers(true);

    VR vr2(2, 2000);
    vr2.setResolution(2560, 1440);
    vr2.setWithControllers(false);

    VR::updateVec(vr1);
    VR::updateVec(vr2);

    return 0;
}