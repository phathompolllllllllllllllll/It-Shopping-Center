#include "add_device_stationed.h"
#include "ui_add_device_stationed.h"

add_device_stationed::add_device_stationed(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::add_device_stationed)
{
    ui->setupUi(this);
    cata = cat;
}

add_device_stationed::~add_device_stationed()
{
    delete ui;
}

std::string brand_st;
std::string model_st;
int quantity_st, resolution_1_st, resolution_2_st;
double price_st;
std::string name_st;
std::string ssd_st;
std::string size_st;
std::string main_processor_st;
std::string graphics_processor_st;
int storage_capacity_st;
std::string USB_st;
std::string display_st;
std::string input_output_port_st;
std::string wifi_st;
double weight_st;
std::string bluetooth_st;
double power_consumption_st;
bool controller_vibration_st = false;
bool TV_mode_st = false;

void add_device_stationed::on_OK_btn_clicked()
{
    bool a, b, c, d, e, f, g;
    brand_st = ui->brand_lineEdit->text().toStdString();
    model_st = ui->model_lineEdit->text().toStdString();
    quantity_st = ui->quantity_lineEdit->text().toInt(&a);
    resolution_1_st = ui->resolution_lineEdit_1->text().toInt(&b);
    resolution_2_st = ui->resolution_lineEdit_2->text().toInt(&c);
    price_st = ui->price_lineEdit->text().toDouble(&d);
    name_st = ui->des_lineEdit->text().toStdString();
    ssd_st = ui->SSD->text().toStdString();
    size_st = ui->size->text().toStdString();
    main_processor_st = ui->main_processor_lineEdit->text().toStdString();
    graphics_processor_st = ui->graphiv_processor_lineEdit->text().toStdString();
    storage_capacity_st = ui->storage_lineEdit->text().toInt(&e);
    USB_st = ui->USB_lineEdit->text().toStdString();
    display_st = ui->display_lineEdit->text().toStdString();
    input_output_port_st = ui->input_output_port->text().toStdString();
    wifi_st = ui->wifi_lineEdit->text().toStdString();
    weight_st = ui->weight_lineEdit->text().toDouble(&f);
    bluetooth_st = ui->bluetooth_lineEdit->text().toStdString();
    power_consumption_st = ui->power_consum->text().toDouble(&g);
    if(ui->controller_vibra->isChecked()){
        controller_vibration_st = true;
    }
    if(ui->have_tv_mode->isChecked()){
        TV_mode_st = true;
    }

    if(a && b && c && d && e && f && g && price_st >= 0 && quantity_st > 0) {
        Stationed stationed1(quantity_st, price_st);

        stationed1.setDescription(name_st);
        stationed1.setBrand(brand_st);
        stationed1.setModel(model_st);
        stationed1.setOnDisplay(true);
        stationed1.setResolution(resolution_1_st, resolution_2_st);
        stationed1.setMainProcessor(main_processor_st);
        stationed1.setGraphicsProcessor(graphics_processor_st);
        stationed1.setStorageCapacity(storage_capacity_st);
        stationed1.setUSB(USB_st);
        stationed1.setDisplay(display_st);
        stationed1.setInputOutputPort(input_output_port_st);
        stationed1.setWifi(wifi_st);
        stationed1.setWeight(weight_st);
        stationed1.setBluetooth(bluetooth_st);
        stationed1.setPowerConsumption(power_consumption_st);
        stationed1.setControllerVibration(controller_vibration_st);
        stationed1.setTVMode(TV_mode_st);
        stationed1.setSSD(ssd_st);
        stationed1.setSize(size_st);

        Stationed::updateVec(stationed1);

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
        ui->SSD->clear();
        ui->size->clear();
        ui->main_processor_lineEdit->clear();
        ui->graphiv_processor_lineEdit->clear();
        ui->storage_lineEdit->clear();
        ui->USB_lineEdit->clear();
        ui->display_lineEdit->clear();
        ui->input_output_port->clear();
        ui->wifi_lineEdit->clear();
        ui->weight_lineEdit->clear();
        ui->bluetooth_lineEdit->clear();
        ui->power_consum->clear();
        ui->controller_vibra->setChecked(false);
        ui->have_tv_mode->setChecked(false);
    }


}


