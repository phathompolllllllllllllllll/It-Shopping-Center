#include "edit_device_watch.h"
#include "ui_edit_device_watch.h"

edit_device_watch::edit_device_watch(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::edit_device_watch)
{
    ui->setupUi(this);
    cata = cat;
}

edit_device_watch::~edit_device_watch()
{
    delete ui;
}

std::string brand_w_edit;
std::string model_w_edit;
std::string name_w_edit;
int quantity_w_edit;
double price_w_edit;
std::string display_w_edit;
bool has_sim_w_edit = false;
double bluetooth_w_edit;
double wifi_w_edit;
double capacity_GB_w_edit;
double screen_size_mm_w_edit;
double case_size_mm_w_edit;
double brightness_nits_w_edit;
double water_resistance_m_w_edit;
double battery_mAh_w_edit;
double weight_g_w_edit;
bool heartrate_monitoring_w_edit= false;
bool has_microphones_w_edit= false;
bool has_gps_w_edit= false;
bool has_blood_oxygen_sensor_w_edit= false;
bool has_speaker_w_edit= false;


void edit_device_watch::on_OK_btn_clicked()
{
    bool a, b, c, d, e, f, g, h, i, j, k;


    price_w_edit = ui->price_lineEdit->text().toDouble(&a);
    quantity_w_edit = ui->quantity_lineEdit->text().toInt(&b);
    brand_w_edit = ui->brand_lineEdit->text().toStdString();
    model_w_edit = ui->model_lineEdit->text().toStdString();
    name_w_edit = ui->des_lineEdit->text().toStdString();
    display_w_edit = ui->display_lineEdit->text().toStdString();
    if(ui->has_sim->isChecked()){
        has_sim_w_edit = true;
    }
    bluetooth_w_edit = ui->bluetooth_lineEdit->text().toDouble(&c);
    wifi_w_edit = ui->wifi_lineEdit->text().toDouble(&d);
    capacity_GB_w_edit = ui->capacity->text().toDouble(&e);
    screen_size_mm_w_edit = ui->screen_size->text().toDouble(&f);
    case_size_mm_w_edit = ui->case_size->text().toDouble(&g);
    brightness_nits_w_edit = ui->brightness_lineEdit->text().toDouble(&h);
    water_resistance_m_w_edit = ui->water_resistance->text().toDouble(&i);
    battery_mAh_w_edit = ui->battery_lineEdit->text().toDouble(&j);
    weight_g_w_edit = ui->weight_lineEdit->text().toDouble(&k);
    if(ui->has_heartrate_monitering->isChecked()){
        heartrate_monitoring_w_edit = true;
    }
    if(ui->has_mic->isChecked()){
        has_microphones_w_edit = true;
    }
    if(ui->has_gps->isChecked()){
        has_gps_w_edit = true;
    }
    if(ui->has_blood_O2_sensor->isChecked()){
        has_blood_oxygen_sensor_w_edit = true;
    }
    if(ui->has_speaker->isChecked()){
        has_speaker_w_edit = true;
    }
    if(a && b && c && d && e && f && g && h && i && j && k && price_w_edit >= 0 && quantity_w_edit > 0) {
        Smartwatch w;
        w.setID(cata);
        w.setDescription(name_w_edit);
        w.setBrand(brand_w_edit);
        w.setModel(model_w_edit);
        w.setPrice(price_w_edit);
        w.setQuantity(quantity_w_edit);
        w.setOnDisplay(true);
        w.setDisplay(display_w_edit);
        w.setBattery(battery_mAh_w_edit);
        w.setHaveBluetooth(bluetooth_w_edit);
        w.setScreenSize(screen_size_mm_w_edit);
        w.setCaseSize(case_size_mm_w_edit);
        w.setWeight(weight_g_w_edit);
        w.setBrightness(brightness_nits_w_edit);
        w.setWaterResistance(water_resistance_m_w_edit);
        w.setHeartrateMonitoring(heartrate_monitoring_w_edit);
        w.setHasMicrophones(has_microphones_w_edit);
        w.setWifi(wifi_w_edit);
        w.setCapacity(capacity_GB_w_edit);
        w.setHasGps(has_gps_w_edit);
        w.setHasBloodOxygenSensor(has_blood_oxygen_sensor_w_edit);
        w.setHasSpeaker(has_speaker_w_edit);
        w.setSim(has_sim_w_edit);

        Smartwatch::updateVec(w);

        this->close();
    } else {
        QMessageBox::warning(this, "Error", "Invalid type please try again.");
        ui->brand_lineEdit->clear();
        ui->model_lineEdit->clear();
        ui->quantity_lineEdit->clear();
        ui->price_lineEdit->clear();
        ui->des_lineEdit->clear();
        ui->display_lineEdit->clear();
        ui->bluetooth_lineEdit->clear();
        ui->wifi_lineEdit->clear();
        ui->capacity->clear();
        ui->screen_size->clear();
        ui->case_size->clear();
        ui->brightness_lineEdit->clear();
        ui->water_resistance->clear();
        ui->battery_lineEdit->clear();
        ui->weight_lineEdit->clear();
        ui->has_heartrate_monitering->setChecked(false);
        ui->has_mic->setChecked(false);
        ui->has_gps->setChecked(false);
        ui->has_blood_O2_sensor->setChecked(false);
        ui->has_speaker->setChecked(false);
    }

}

