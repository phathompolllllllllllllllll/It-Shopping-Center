#ifndef ADD_VR_H
#define ADD_VR_H

#include <QDialog>

namespace Ui {
class Add_vr;
}

class Add_vr : public QDialog
{
    Q_OBJECT

public:
    explicit Add_vr(QWidget *parent = nullptr);
    ~Add_vr();

private:
    Ui::Add_vr *ui;
};

#endif // ADD_VR_H
