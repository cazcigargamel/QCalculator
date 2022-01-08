#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QListWidget>
#include <QVBoxLayout>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    QDialogButtonBox *buttonBox = nullptr;
    QListWidget *listWidget = nullptr;
    QVBoxLayout *vboxlayout = nullptr;
    void setupUI();
};
#endif // DIALOG_H
