#include "add_device_watch.h"
#include "ui_add_device_watch.h"

add_device_watch::add_device_watch(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::add_device_watch)
{
    ui->setupUi(this);
    cata = cat;
}

add_device_watch::~add_device_watch()
{
    delete ui;
}

std::string brand_w;
std::string model_w;
std::string name_w;
int quantity_w;
double price_w;
std::string display_w;
bool has_sim_w = false;
double bluetooth_w;
double wifi_w;
double capacity_GB_w;
double screen_size_mm_w;
double case_size_mm_w;
double brightness_nits_w;
double water_resistance_m_w;
double battery_mAh_w;
double weight_g_w;
bool heartrate_monitoring_w= false;
bool has_microphones_w= false;
bool has_gps_w= false;
bool has_blood_oxygen_sensor_w= false;
bool has_speaker_w= false;

void add_device_watch::on_OK_btn_clicked()
{
    bool a, b, c, d, e, f, g, h, i, j, k;
    price_w = ui->price_lineEdit->text().toDouble(&a);
    quantity_w = ui->quantity_lineEdit->text().toInt(&b);
    brand_w = ui->brand_lineEdit->text().toStdString();
    model_w = ui->model_lineEdit->text().toStdString();
    name_w = ui->des_lineEdit->text().toStdString();
    display_w = ui->display_lineEdit->text().toStdString();
    if(ui->has_sim->isChecked()){
        has_sim_w = true;
    }
    bluetooth_w = ui->bluetooth_lineEdit->text().toDouble(&c);
    wifi_w = ui->wifi_lineEdit->text().toDouble(&d);
    capacity_GB_w = ui->capacity->text().toDouble(&e);
    screen_size_mm_w = ui->screen_size->text().toDouble(&f);
    case_size_mm_w = ui->case_size->text().toDouble(&g);
    brightness_nits_w = ui->brightness_lineEdit->text().toDouble(&h);
    water_resistance_m_w = ui->water_resistance->text().toDouble(&i);
    battery_mAh_w = ui->battery_lineEdit->text().toDouble(&j);
    weight_g_w = ui->weight_lineEdit->text().toDouble(&k);
    if(ui->has_heartrate_monitering->isChecked()){
        heartrate_monitoring_w = true;
    }
    if(ui->has_mic->isChecked()){
        has_microphones_w = true;
    }
    if(ui->has_gps->isChecked()){
        has_gps_w = true;
    }
    if(ui->has_blood_O2_sensor->isChecked()){
        has_blood_oxygen_sensor_w = true;
    }
    if(ui->has_speaker->isChecked()){
        has_speaker_w = true;
    }
    if(a && b && c && d && e && f && g && h && i && j && k && price_w >= 0 && quantity_w > 0){
        Smartwatch watch(quantity_w, price_w);
        watch.setDescription(name_w);
        watch.setBrand(brand_w);
        watch.setModel(model_w);
        watch.setPrice(price_w);
        watch.setQuantity(quantity_w);
        watch.setOnDisplay(true);
        watch.setDisplay(display_w);
        watch.setBattery(battery_mAh_w);
        watch.setHaveBluetooth(bluetooth_w);
        watch.setScreenSize(screen_size_mm_w);
        watch.setCaseSize(case_size_mm_w);
        watch.setWeight(weight_g_w);
        watch.setBrightness(brightness_nits_w);
        watch.setWaterResistance(water_resistance_m_w);
        watch.setHeartrateMonitoring(heartrate_monitoring_w);
        watch.setHasMicrophones(has_microphones_w);
        watch.setWifi(wifi_w);
        watch.setCapacity(capacity_GB_w);
        watch.setHasGps(has_gps_w);
        watch.setHasBloodOxygenSensor(has_blood_oxygen_sensor_w);
        watch.setHasSpeaker(has_speaker_w);
        watch.setSim(has_sim_w);

        Smartwatch::updateVec(watch);
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

