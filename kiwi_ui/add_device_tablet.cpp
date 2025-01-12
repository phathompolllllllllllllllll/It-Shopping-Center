#include "add_device_tablet.h"
#include "ui_add_device_tablet.h"

add_device_tablet::add_device_tablet(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::add_device_tablet)
{
    ui->setupUi(this);
    cata = cat;
}

add_device_tablet::~add_device_tablet()
{
    delete ui;
}

std::string brand_ta, model_ta, name_ta, display_ta, processor_ta;
std::string os_ta;
std::string storage_ta;
std::string camera_ta;
int quantity_ta;
double price_ta;
double battery_mAh_ta;
std::string bluetooth_ta;
int resolution_1_ta, resolution_2_ta;
double dimension_ta1, dimension_ta2, dimension_ta3;
double weight_ta;
double brightness_nits_ta;
std::string wifi_ta;
bool have_pen_ta = false;
std::string Internal_Memory_ta;
std::string External_Memory_ta;
std::string speaker_ta;
bool biometric_ta1 = false, biometric_ta2 = false, biometric_ta3 = false;
bool is_waterproof_ta = false;

void add_device_tablet::on_OK_btn_clicked()
{
    bool a, b, c, d, e, f, g, h, i, j;
    price_ta = ui->price_lineEdit->text().toDouble(&a);
    quantity_ta = ui->quantity_lineEdit->text().toInt(&b);
    brand_ta = ui->brand_lineEdit->text().toStdString();
    model_ta = ui->model_lineEdit->text().toStdString();
    name_ta = ui->des_lineEdit->text().toStdString();
    display_ta = ui->display_lineEdit->text().toStdString();
    resolution_1_ta = ui->resolution_lineEdit_1->text().toInt(&c);
    resolution_2_ta = ui->resolution_lineEdit_2->text().toInt(&d);
    processor_ta = ui->processor_lineEdit->text().toStdString();
    os_ta = ui->os_lineEdit->text().toStdString();
    camera_ta = ui->camera_spec_lineEdit->text().toStdString();
    storage_ta = ui->storage_lineEdit->text().toStdString();
    battery_mAh_ta = ui->battery_lineEdit->text().toDouble(&e);
    bluetooth_ta = ui->bluetooth_lineEdit->text().toStdString();
    dimension_ta1 = ui->dimension1_lineEdit->text().toDouble(&f);
    dimension_ta2 = ui->dimension2_lineEdit->text().toDouble(&g);
    dimension_ta3 = ui->dimension3_lineEdit->text().toDouble(&h);
    weight_ta = ui->weight_lineEdit->text().toDouble(&i);
    brightness_nits_ta = ui->brightness_lineEdit->text().toDouble(&j);
    wifi_ta = ui->wifi_lineEdit->text().toStdString();
    Internal_Memory_ta = ui->internal_Memory->text().toStdString();
    External_Memory_ta = ui->external_memory_lineEdit->text().toStdString();
    speaker_ta = ui->speaker_lineEdit->text().toStdString();


    if(ui->have_pen_with_controller->isChecked()){
        have_pen_ta = true;
    }
    if(ui->finger_with_controller->isChecked()){
        biometric_ta1 = true;
    }
    if(ui->face_with_controller->isChecked()){
        biometric_ta2 = true;
    }
    if(ui->iris_with_controller->isChecked()){
        biometric_ta3 = true;
    }
    if(ui->water_proof_with_controller->isChecked()){
        is_waterproof_ta = true;
    }
    if(a && b && c && d && e && f && g && h && i && j && price_ta >= 0 && quantity_ta > 0) {
        Tablet tablet(quantity_ta, price_ta);
        tablet.setDescription(name_ta);
        tablet.setBrand(brand_ta);
        tablet.setModel(model_ta);
        tablet.setOnDisplay(true);
        tablet.setDisplay(display_ta);
        tablet.setProcessor(processor_ta);
        tablet.setOs(os_ta);
        tablet.setStorage(storage_ta);
        tablet.setCamera(camera_ta);
        tablet.setBattery(battery_mAh_ta);
        tablet.setBluetooth(bluetooth_ta);
        tablet.setResolution(resolution_1_ta, resolution_2_ta);
        tablet.setDimensions(dimension_ta1, dimension_ta2, dimension_ta3);
        tablet.setWeight(weight_ta);
        tablet.setBrightness(brightness_nits_ta);
        tablet.setWifi(wifi_ta);
        tablet.setHavePen(have_pen_ta);
        tablet.setInternal_Memory(Internal_Memory_ta);
        tablet.setExternal_Memory(External_Memory_ta);
        tablet.setSpeaker(speaker_ta);
        tablet.setBiometrics(biometric_ta1, biometric_ta2, biometric_ta3);
        tablet.setIsWaterproof(is_waterproof_ta);

        Tablet::updateVec(tablet);
        this->close();
    } else {
        QMessageBox::warning(this, "Error", "Invalid type please try again.");
        ui->brand_lineEdit->clear();
        ui->model_lineEdit->clear();
        ui->quantity_lineEdit->clear();
        ui->resolution_lineEdit_1->clear();
        ui->resolution_lineEdit_2->clear();
        ui->price_lineEdit->clear();
        ui->des_lineEdit->clear();
        ui->processor_lineEdit->clear();
        ui->storage_lineEdit->clear();
        ui->os_lineEdit->clear();
        ui->camera_spec_lineEdit->clear();
        ui->display_lineEdit->clear();
        ui->battery_lineEdit->clear();
        ui->wifi_lineEdit->clear();
        ui->weight_lineEdit->clear();
        ui->bluetooth_lineEdit->clear();
        ui->dimension1_lineEdit->clear();
        ui->dimension2_lineEdit->clear();
        ui->dimension3_lineEdit->clear();
        ui->brightness_lineEdit->clear();
        ui->internal_Memory->clear();
        ui->external_memory_lineEdit->clear();
        ui->speaker_lineEdit->clear();
        ui->have_pen_with_controller->setChecked(false);
        ui->finger_with_controller->setChecked(false);
        ui->face_with_controller->setChecked(false);
        ui->iris_with_controller->setChecked(false);
        ui->water_proof_with_controller->setChecked(false);
    }


}

