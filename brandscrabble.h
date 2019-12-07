#ifndef BRANDSCRABBLE_H
#define BRANDSCRABBLE_H

#include <QDialog>
#include <QDebug>
#include <QPushButton>
#include <QBoxLayout>

namespace Ui {
class BrandScrabble;
}

class BrandScrabble : public QDialog
{
    Q_OBJECT

public:
    explicit BrandScrabble(QWidget *parent = 0);
    ~BrandScrabble();

private slots:
    int randomIndex(int size);
    void optionClicked();
    void on_PB_close_clicked();

    void on_PB_reset_clicked();

private:
    Ui::BrandScrabble *ui;
};

#endif // BRANDSCRABBLE_H
