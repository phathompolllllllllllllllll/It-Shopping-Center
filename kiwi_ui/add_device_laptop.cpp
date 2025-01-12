#include "add_device_laptop.h"
#include "ui_add_device_laptop.h"

add_device_laptop::add_device_laptop(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::add_device_laptop)
{
    ui->setupUi(this);
    cata = cat;
}

add_device_laptop::~add_device_laptop()
{
    delete ui;
}

std::string brand_la;
std::string model_la;
int quantity_la;
double price_la;
std::string name_la;
std::string cpu_la;
std::string gpu_la;
std::string memory_la;
std::string os_la;
std::string display_la;
double battery1_la;
int battery2_la;
double dimensions1_la, dimensions2_la, dimensions3_la, dimensions4_la;
double weight_la; // in kg
bool is_touchscreen_la = false;
bool is_gaming_la = false;

void add_device_laptop::on_OK_btn_clicked()
{
    bool a, b, c, d, e, f, g, h, i;
    brand_la = ui->brand_lineEdit->text().toStdString();
    model_la = ui->model_lineEdit->text().toStdString();
    quantity_la = ui->quantity_lineEdit->text().toInt(&a);
    price_la = ui->price_lineEdit->text().toInt(&b);
    name_la = ui->des_lineEdit->text().toStdString();
    cpu_la = ui->cpu->text().toStdString();
    gpu_la = ui->gpu->text().toStdString();
    memory_la = ui->memory->text().toStdString();
    os_la = ui->os_lineEdit->text().toStdString();
    display_la = ui->display->text().toStdString();
    battery1_la = ui->battery_watt->text().toDouble(&c);
    battery2_la = ui->battery_cell->text().toInt(&d);
    dimensions1_la = ui->dimension1_lineEdit->text().toDouble(&e);
    dimensions2_la = ui->dimension2_lineEdit->text().toDouble(&f);
    dimensions3_la = ui->dimension3_lineEdit->text().toDouble(&g);
    dimensions4_la = ui->dimension4_lineEdit_2->text().toDouble(&h);
    weight_la = ui->weight->text().toDouble(&i);
    if(ui->touchscreen->isChecked()){
        is_touchscreen_la = true;
    }
    if(ui->gaming->isChecked()){
        is_gaming_la = true;
    }

    if(a && b && c && d && e && f && g && i && h && price_la >= 0 && quantity_la > 0) {
        Laptop laptop1(quantity_la, price_la);
        laptop1.setDescription(name_la);
        laptop1.setBrand(brand_la);
        laptop1.setModel(model_la);
        laptop1.setPrice(price_la);
        laptop1.setQuantity(quantity_la);
        laptop1.setOnDisplay(true);
        laptop1.setCPU(cpu_la);
        laptop1.setGPU(gpu_la);
        laptop1.setMemory(memory_la);
        laptop1.setOS(os_la);
        laptop1.setDisplay(display_la);
        laptop1.setBattery(battery1_la, battery2_la);
        laptop1.setDimensions(dimensions1_la, dimensions2_la, dimensions3_la, dimensions4_la);
        laptop1.setWeight(weight_la);
        laptop1.setTouchscreen(is_touchscreen_la);
        laptop1.setGaming(is_gaming_la);

        Laptop::updateVec(laptop1);

        this->close();
    } else {
        QMessageBox::warning(this, "Error", "Invalid type please try again.");
        ui->brand_lineEdit->clear();
        ui->model_lineEdit->clear();
        ui->des_lineEdit->clear();
        ui->price_lineEdit->clear();
        ui->quantity_lineEdit->clear();
        ui->cpu->clear();
        ui->gpu->clear();
        ui->memory->clear();
        ui->os_lineEdit->clear();
        ui->display->clear();
        ui->battery_watt->clear();
        ui->battery_cell->clear();
        ui->dimension1_lineEdit->clear();
        ui->dimension2_lineEdit->clear();
        ui->dimension3_lineEdit->clear();
        ui->dimension4_lineEdit_2->clear();
        ui->weight->clear();
        ui->touchscreen->setChecked(false);
        ui->gaming->setChecked(false);

    }

}

