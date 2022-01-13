#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QListWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QList>
#include <QPushButton>
#include "equation.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private slots:
    void clear();
    void add();
    void subtract();
    void multiply();
    void divide();
    void number();
    void update();
    void addEquation();
private:
    QDialogButtonBox *buttonBox = nullptr;
    QListWidget *listWidget = nullptr;
    QVBoxLayout *vboxlayout = nullptr;
    QGridLayout *gridLayout = nullptr;
    QList<Equation*> m_list;
    void init();
    Equation *getLast();
    void updateValue(QString data);
    void updateAction(Equation::Action action);
    void setupUI();


    // QDialog interface
public slots:
    void accept() override;
};
#endif // DIALOG_H
