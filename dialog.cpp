#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setupUI();
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
}

Dialog::~Dialog()
{
    qDeleteAll(buttonBox);
    qDeleteAll(listWidget);
    qDeleteAll(vboxlayout);
    qDeleteAll(gridLayout);
    qDeleteAll(m_list);
    delete buttonBox;
    delete listWidget;
}

void Dialog::clear()
{

}

void Dialog::add()
{

}

void Dialog::subtract()
{

}

void Dialog::multiply()
{

}

void Dialog::divide()
{

}

void Dialog::number()
{

}

void Dialog::update()
{

}

void Dialog::addEquation()
{

}

void Dialog::init()
{
    int row = 0 ;
    int col = 2;
    for(int i = 9;i >= 0; i--)
    {
        QPushButton *btn = new QPushButton(QString::number(i), this);
        connect(btn, &QPushButton::clicked, this, &Dialog::number);
    }
}

Equation *Dialog::getLast()
{

}

void Dialog::updateValue()
{

}

void Dialog::setupUI()
{
    buttonBox = new QDialogButtonBox(this);
    buttonBox->addButton(QDialogButtonBox::StandardButton::Ok);
    buttonBox->addButton(QDialogButtonBox::StandardButton::Cancel);
    listWidget = new QListWidget(this);
    vboxlayout = new QVBoxLayout(this);
    gridLayout = new QGridLayout(this);
    vboxlayout->addWidget(listWidget);
    vboxlayout->addLayout(gridLayout);
    vboxlayout->addWidget(buttonBox);
    setLayout(vboxlayout);
}



void Dialog::accept()
{
}
