#include "abstractoperation.h"

AbstractOperation::AbstractOperation()
{
    m_numberA = 0;
    m_numberB = 0;
}

void AbstractOperation::setNumberA(const double &numberA)
{
    m_numberA = numberA;
}

double AbstractOperation::getNumberA() const
{
    return m_numberA;
}

void AbstractOperation::setNumberB(const double &numberB)
{
    m_numberB = numberB;
}

double AbstractOperation::getNumberB() const
{
    return m_numberB;
}

double AbstractOperation::getResult(bool &flag,QString &errorStr)
{
    flag = false;
    errorStr = "error formula";
    return 0;
}
