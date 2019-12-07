#ifndef BRANDSCRABBLE_H
#define BRANDSCRABBLE_H

#include <QDialog>
#include <QDebug>
#include <QPushButton>
#include <QBoxLayout>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

namespace Ui {
class BrandScrabble;
}

class BrandScrabble : public QDialog
{
    Q_OBJECT

public:
    explicit BrandScrabble(QWidget *parent = 0);
    ~BrandScrabble();
    void createScrabble(QString);

private slots:
    int randomIndex(int size);
    void optionClicked();
    void on_PB_close_clicked();
    void on_PB_reset_clicked();
    void on_PB_next_clicked();
    QString getFilename();

private:
    Ui::BrandScrabble *ui;
    QList<QString> usedFiles;
    QList<QString> availableFiles;
};

#endif // BRANDSCRABBLE_H
