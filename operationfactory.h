#ifndef OPERATIONFACTORY_H
#define OPERATIONFACTORY_H
#include <abstractoperation.h>
#include <operationadd.h>
#include <QString>
#include <operationminus.h>
#include <operationdivided.h>
#include <operationmultiplied.h>
#include <operationpower.h>
#include <operationleftmove.h>
#include <operationrightmove.h>
#include <operationgetbyte.h>
#include <operationsin.h>
#include <operationcos.h>
#include <operationsqrt.h>
#include <operationexp.h>
#include <operationlog.h>
#include <operationln.h>
#include <operationtan.h>
#include <operationcot.h>
#include <operationabs.h>
#include <operationmodule.h>

///
///  计算器工厂
/// \brief The OperationFactory class
///
class OperationFactory
{
public:
    OperationFactory();
    static AbstractOperation *getOperationFunction(QString operationStr);
private:
    static AbstractOperation *m_operation;
    //加
    static OperationAdd *m_operationAdd;
    //减
    static OperationMinus *m_operationMinus;
    //乘
    static OperationMultiplied *m_operationMultiplied;
    //除
    static OperationDivided *m_operationDivided;
    //次方
    static OperationPower *m_operationPower;
    //左移
    static OperationLeftMove *m_operationLeftMove;
    //右移
    static OperationRightMove *m_operationRightMove;
    //取字节
    static OperationGetByte *m_operationGetByte;
    // 正弦
    static OperationSin *m_operationSin;
    // 余弦
    static OperationCos *m_operationCos;
    //以自然常数e为底的指数函数
    static OperationExp *m_operationExp;
    //开根号
    static OperationSqrt *m_operationSqrt;
    // 以10为底的NamuberA的对数
    static OperationLog *m_operationLog;
    // 自然对数 以e为底的NamuberA的对数
    static OperationLn *m_operationLn;
    //绝对值
    static OperationAbs *m_operationAbs;
    //正切
    static OperationTan *m_operationTan;
    //余切
    static OperationCot *m_operationCot;
    //取模
    static OperationModule *m_operationModule;





};

#endif // OPERATIONFACTORY_H
