#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setupUI();
    init();
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
}

Dialog::~Dialog()
{
    delete buttonBox;
    delete listWidget;
    delete vboxlayout;
    delete gridLayout;
    delete buttonBox;
    delete listWidget;
}

void Dialog::clear()
{
    qDeleteAll(m_list);
    m_list.clear();
    update();
}

void Dialog::add()
{
    updateAction(Equation::Action::ADD);
}

void Dialog::subtract()
{
    updateAction(Equation::Action::SUBTRACT);
}

void Dialog::multiply()
{
    updateAction(Equation::Action::MULTIPLY);
}

void Dialog::divide()
{
    updateAction(Equation::Action::DIVIDE);
}

void Dialog::number()
{
    QPushButton *btn = static_cast<QPushButton*>(sender());
    if(!btn) return;

    bool ok;
    double value = btn->text().toDouble(&ok);
    if(!ok)
    {
        QMessageBox::critical(this,"Error", "Not a Number");
        return;
    }

    updateValue(btn->text());

}

void Dialog::update()
{
    if(listWidget->count() != m_list.count())
    {
        listWidget->clear();
        foreach(Equation *e, m_list)
        {
            listWidget->addItem(e->toString());
        }
        listWidget->setCurrentRow(listWidget->count() - 1);
    }
    else
    {
        listWidget->setCurrentRow(listWidget->count() - 1);
        listWidget->item(listWidget->count() - 1)->setText(m_list.last()->toString());
    }
}

void Dialog::addEquation()
{
    m_list.append(new Equation(this));
    update();
}

void Dialog::init()
{
    int row = 0 ;
    int col = 2;
    for(int i = 9;i >= 0; i--)
    {
        QPushButton *btn = new QPushButton(QString::number(i), this);
        connect(btn, &QPushButton::clicked, this, &Dialog::number);
        gridLayout->addWidget(btn,row,col);
        col--;
        if(col < 0)
        {
            row++;
            col = 2;
            if(row == 3) col = 0;
        }
    }
    QPushButton *btnAdd = new QPushButton("+", this);
    QPushButton *btnSubtract = new QPushButton("-", this);
    QPushButton *btnMultiply = new QPushButton("*", this);
    QPushButton *btnDivide = new QPushButton("/", this);
    QPushButton *btnClear = new QPushButton("Clear", this);
    QPushButton *btnRow = new QPushButton("Add Equation", this);

    connect(btnAdd, &QPushButton::clicked, this, &Dialog::add);
    connect(btnSubtract, &QPushButton::clicked, this, &Dialog::subtract);
    connect(btnMultiply, &QPushButton::clicked, this, &Dialog::multiply);
    connect(btnDivide, &QPushButton::clicked, this, &Dialog::divide);
    connect(btnClear, &QPushButton::clicked, this, &Dialog::clear);
    connect(btnRow, &QPushButton::clicked, this, &Dialog::addEquation);

    gridLayout->addWidget(btnAdd,0,3);
    gridLayout->addWidget(btnSubtract,1,3);
    gridLayout->addWidget(btnMultiply,2,3);
    gridLayout->addWidget(btnDivide,3,3);

    buttonBox->addButton(btnClear, QDialogButtonBox::ButtonRole::ActionRole);
    buttonBox->addButton(btnRow, QDialogButtonBox::ButtonRole::ActionRole);
}

Equation *Dialog::getLast()
{
    if(m_list.count() == 0) m_list.append(new Equation(this));
    return m_list.last();
}

void Dialog::updateValue(QString data)
{
    Equation *equation = getLast();
    QString value;
    if(equation->action() == Equation::Action::NONE)
    {
        value = equation->value1();
        value.append(data);
        equation->setValue1(value);
    }
    else
    {
        value = equation->value2();
        value.append(data);
        equation->setValue2(value);
    }
    equation->calculate();
    update();
}

void Dialog::updateAction(Equation::Action action)
{
    Equation *equation = getLast();
    if(!equation) return;

    equation->setAction(action);
    equation->calculate();
    update();
}

void Dialog::setupUI()
{
    buttonBox = new QDialogButtonBox(this);
    buttonBox->addButton(QDialogButtonBox::StandardButton::Ok);
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
    double total = 0;
    foreach(Equation *e, m_list)
    {
        bool ok;
        double value = e->sum().toDouble(&ok);
        if(!ok) continue;
        total = total + value;
    }
    QMessageBox::information(this, "Total", "Total is " + QString::number(total));
}
