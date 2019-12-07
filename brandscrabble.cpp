#include "brandscrabble.h"
#include "ui_brandscrabble.h"

BrandScrabble::BrandScrabble(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrandScrabble)
{
    ui->setupUi(this);
    QDir dir("images/");
    dir.setFilter(QDir::Files | QDir::NoSymLinks);
    //dir.setSorting(QDir::Size | QDir::Reversed);

    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
        availableFiles += fileInfo.completeBaseName();
    }
    on_PB_next_clicked();
}

BrandScrabble::~BrandScrabble()
{
    delete ui;
}

void BrandScrabble::createScrabble(QString brandname)
{
    QString cname = brandname;
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
    ui->label_2->setPixmap(QPixmap("images/"+brandname+".png"));
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
    ui->label_2->clear();
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

void BrandScrabble::on_PB_next_clicked()
{
    ui->label_2->clear();
    ui->label->clear();
    QList<QObject*> lst = ui->WD_options->children();
    for (int i = 0; i < lst.size(); ++i)
    {
        delete lst.at(i);
    }
    QString filename = getFilename();
    if(!filename.isEmpty())
        createScrabble(filename);
    else
        qDebug() << "No data";

}

QString BrandScrabble::getFilename()
{
    int num = randomIndex(availableFiles.count());
    if(usedFiles.indexOf(availableFiles.at(num))==-1)
    {
        usedFiles += availableFiles.at(num);
        return availableFiles.at(num);
    }
    else
    {
        if(usedFiles.count() != availableFiles.count())
            getFilename();
    }
    return QString();
}
