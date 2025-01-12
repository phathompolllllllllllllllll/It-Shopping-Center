#ifndef REMOVE_TABLET_H
#define REMOVE_TABLET_H

#include <QDialog>

namespace Ui {
class Remove_tablet;
}

class Remove_tablet : public QDialog
{
    Q_OBJECT

public:
    explicit Remove_tablet(QWidget *parent = nullptr);
    ~Remove_tablet();

private:
    Ui::Remove_tablet *ui;
};

#endif // REMOVE_TABLET_H
