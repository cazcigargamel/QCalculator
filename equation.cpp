#include "equation.h"

Equation::Equation(QObject *parent)
    : QObject{parent}
{
    m_action = Action::RESET;
    calculate();
}

const QString &Equation::sum() const
{
    return m_sum;
}

void Equation::setSum(const QString &newSum)
{
    m_sum = newSum;
}

const QString &Equation::value1() const
{
    return m_value1;
}

void Equation::setValue1(const QString &newValue1)
{
    m_value1 = newValue1;
}

const QString &Equation::value2() const
{
    return m_value2;
}

void Equation::setValue2(const QString &newValue2)
{
    m_value2 = newValue2;
}

Equation::Action Equation::action() const
{
    return m_action;
}

void Equation::setAction(Equation::Action newAction)
{
    m_action = newAction;
}

void Equation::calculate()
{
    double dval1 = getValue(m_value1);
    double dval2 = getValue(m_value2);
    double dsum = 0;

    switch (m_action) {
    case Action::NONE:
        break;
    case Action::RESET:
        m_action = Action::NONE;
        m_value1.clear();
        m_value2.clear();
        break;
    case Action::ADD:
        dsum = dval1 + dval2;
        break;
    case Action::SUBTRACT:
        dsum = dval1 - dval2;
        break;
    case Action::MULTIPLY:
        dsum = dval1 * dval2;
        break;
    case Action::DIVIDE:
        dsum = dval1 / dval2;
        break;
    }

    m_value1 = QString::number(dval1);
    m_value2 = QString::number(dval2);
    m_sum = QString::number(dsum);

    qDebug()<< QString("Number1 : %1, Number2 : %2 , Result : %3")
               .arg(m_value1)
               .arg(m_value2)
               .arg(m_sum);
}

QString Equation::toString()
{
    QString display;
    display.append(m_value1);
    display.append(" ");
    switch (m_action) {
    case Action::NONE:
        display.append("?");
        break;
    case Action::RESET:
        display.append("?");
        break;
    case Action::ADD:
        display.append("+");
        break;
    case Action::SUBTRACT:
        display.append("-");
        break;
    case Action::MULTIPLY:
        display.append("*");
        break;
    case Action::DIVIDE:
        display.append("/");
        break;
    }
    display.append(m_value2);
    display.append(" = ");
    display.append(m_sum);
    return display;
}

double Equation::getValue(QString data)
{
    bool ok;
    double value = data.toDouble(&ok);
    if(!ok) value = 0;
        return value;
}
