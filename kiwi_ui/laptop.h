#ifndef LAPTOP_H
#define LAPTOP_H

#include <QDialog>

namespace Ui {
class Laptop;
}

class Laptop : public QDialog
{
    Q_OBJECT

public:
    explicit Laptop(QWidget *parent = nullptr);
    ~Laptop();

private:
    Ui::Laptop *ui;
};

#endif // LAPTOP_H
