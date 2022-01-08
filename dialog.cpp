#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setupUI();
}

Dialog::~Dialog()
{
    delete buttonBox;
    delete listWidget;
}

void Dialog::setupUI()
{
    buttonBox = new QDialogButtonBox(this);
    buttonBox->addButton(QDialogButtonBox::StandardButton::Ok);
    buttonBox->addButton(QDialogButtonBox::StandardButton::Cancel);
    listWidget = new QListWidget(this);
    vboxlayout = new QVBoxLayout(this);
    vboxlayout->addWidget(listWidget);
    vboxlayout->addStretch();
    vboxlayout->addWidget(buttonBox);
    setLayout(vboxlayout);
}

