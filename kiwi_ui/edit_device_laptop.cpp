#include "edit_device_laptop.h"
#include "ui_edit_device_laptop.h"

edit_device_laptop::edit_device_laptop(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::edit_device_laptop)
{
    ui->setupUi(this);
    cata = cat;
}

edit_device_laptop::~edit_device_laptop()
{
    delete ui;
}

std::string brand_la_edit;
std::string model_la_edit;
int quantity_la_edit;
double price_la_edit;
std::string name_la_edit;
std::string cpu_la_edit;
std::string gpu_la_edit;
std::string memory_la_edit;
std::string os_la_edit;
std::string display_la_edit;
double battery1_la_edit;
int battery2_la_edit;
double dimensions1_la_edit, dimensions2_la_edit, dimensions3_la_edit, dimensions4_la_edit;
double weight_la_edit; // in kg
bool is_touchscreen_la_edit = false;
bool is_gaming_la_edit = false;


void edit_device_laptop::on_OK_btn_clicked()
{
    bool a, b, c, d, e, f, g, h, i;

    brand_la_edit = ui->brand_lineEdit->text().toStdString();
    model_la_edit = ui->model_lineEdit->text().toStdString();
    quantity_la_edit = ui->quantity_lineEdit->text().toInt(&a);
    price_la_edit = ui->price_lineEdit->text().toInt(&b);
    name_la_edit = ui->des_lineEdit->text().toStdString();
    cpu_la_edit = ui->cpu->text().toStdString();
    gpu_la_edit = ui->gpu->text().toStdString();
    memory_la_edit = ui->memory->text().toStdString();
    os_la_edit = ui->os_lineEdit->text().toStdString();
    display_la_edit = ui->display->text().toStdString();
    battery1_la_edit = ui->battery_watt->text().toDouble(&c);
    battery2_la_edit = ui->battery_cell->text().toInt(&d);
    dimensions1_la_edit = ui->dimension1_lineEdit->text().toDouble(&e);
    dimensions2_la_edit = ui->dimension2_lineEdit->text().toDouble(&f);
    dimensions3_la_edit = ui->dimension3_lineEdit->text().toDouble(&g);
    dimensions4_la_edit = ui->dimension4_lineEdit_2->text().toDouble(&h);
    weight_la_edit = ui->weight->text().toDouble(&i);

    if(ui->touchscreen->isChecked()){
        is_touchscreen_la_edit = true;
    }
    if(ui->gaming->isChecked()){
        is_gaming_la_edit = true;
    }

    if(a && b && c && d && e && f && g && i && h && price_la_edit >= 0 && quantity_la_edit > 0) {
        Laptop laptop1;
        laptop1.setID(cata);
        laptop1.setDescription(name_la_edit);
        laptop1.setBrand(brand_la_edit);
        laptop1.setModel(model_la_edit);
        laptop1.setPrice(price_la_edit);
        laptop1.setQuantity(quantity_la_edit);
        laptop1.setOnDisplay(true);
        laptop1.setCPU(cpu_la_edit);
        laptop1.setGPU(gpu_la_edit);
        laptop1.setMemory(memory_la_edit);
        laptop1.setOS(os_la_edit);
        laptop1.setDisplay(display_la_edit);
        laptop1.setBattery(battery1_la_edit, battery2_la_edit);
        laptop1.setDimensions(dimensions1_la_edit, dimensions2_la_edit, dimensions3_la_edit, dimensions4_la_edit);
        laptop1.setWeight(weight_la_edit);
        laptop1.setTouchscreen(is_touchscreen_la_edit);
        laptop1.setGaming(is_gaming_la_edit);

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

