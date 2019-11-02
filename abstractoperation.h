#ifndef ABSTRACTOPERATION_H
#define ABSTRACTOPERATION_H
#include <QString>
#include <math.h>

///
/// 所有运算类的基类，
/// 如果要添加新的运算类型，
/// 子类要继承此类，
/// 并重写 virtual double getResult(bool &flag,QString &errorStr)方法
/// \brief The AbstractOperation class
///
class AbstractOperation
{
public:
    AbstractOperation();
    void setNumberA(const double &numberA);
    double getNumberA() const;

    void setNumberB(const double &numberB);
    double getNumberB() const;

    virtual double getResult(bool &flag,QString &errorStr);
private:
    double m_numberA;
    double m_numberB;
};

#endif // ABSTRACTOPERATION_H
