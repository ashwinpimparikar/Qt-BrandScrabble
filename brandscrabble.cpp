#include "brandscrabble.h"
#include "ui_brandscrabble.h"

BrandScrabble::BrandScrabble(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrandScrabble)
{
    ui->setupUi(this);
    QString cname = "ferrari";
    QList<int> lstNum;
    while(lstNum.count() < cname.length())
    {
        int num = randomIndex(cname.length());
        if(lstNum.indexOf(num) == -1)
            lstNum += num;
    }

    QBoxLayout *box = new QBoxLayout(QBoxLayout::LeftToRight);
    for (int i = 0; i < lstNum.size(); ++i) {
        QPushButton *pb = new QPushButton(ui->WD_options);
        pb->setObjectName("PB_"+QString::number(i));
        connect(pb,SIGNAL(clicked()),this,SLOT(optionClicked()));
        pb->resize(20,20);
        pb->setFixedSize(20,20);
        pb->setText(QString(cname.at(lstNum.at(i))));
        box->insertWidget(-1, pb);
    }
    ui->WD_options->setLayout(box);
}

BrandScrabble::~BrandScrabble()
{
    delete ui;
}

void BrandScrabble::optionClicked()
{
    if(sender())
    {
        QPushButton *pb = static_cast<QPushButton*>(sender());
        pb->setDisabled(true);
        ui->label->setText(ui->label->text().append(pb->text()));
    }
}

int BrandScrabble::randomIndex(int size)
{
    int num = qrand() % size + 1;
    if(num < size)
    {
        return num;
    }
    else
        return 0;
}

void BrandScrabble::on_PB_close_clicked()
{
    this->close();
}

void BrandScrabble::on_PB_reset_clicked()
{
    ui->label->clear();
    QList<QObject*> lst = ui->WD_options->children();
    for (int i = 0; i < lst.size(); ++i)
    {
        if(lst.at(i)->objectName().startsWith("PB_"))
        {
            QPushButton *pb = static_cast<QPushButton*>(lst.at(i));
            pb->setDisabled(false);
        }
    }
}
