#ifndef DESKTOP_H
#define DESKTOP_H

#include <QDialog>

namespace Ui {
class desktop;
}

class desktop : public QDialog
{
    Q_OBJECT

public:
    explicit desktop(QWidget *parent = nullptr);
    ~desktop();

private:
    Ui::desktop *ui;
};

#endif // DESKTOP_H
