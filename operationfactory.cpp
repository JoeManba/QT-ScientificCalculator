#include "operationfactory.h"
#include <CalculatorUtil.h>

AbstractOperation *OperationFactory::m_operation;
OperationAdd *OperationFactory::m_operationAdd = new OperationAdd();
OperationMinus *OperationFactory::m_operationMinus = new OperationMinus();
OperationMultiplied *OperationFactory::m_operationMultiplied = new OperationMultiplied();
OperationDivided *OperationFactory::m_operationDivided = new OperationDivided();
OperationPower *OperationFactory::m_operationPower = new OperationPower();
OperationLeftMove *OperationFactory::m_operationLeftMove = new OperationLeftMove();
OperationRightMove *OperationFactory::m_operationRightMove = new OperationRightMove();
OperationGetByte *OperationFactory::m_operationGetByte = new OperationGetByte();
OperationSin *OperationFactory::m_operationSin = new OperationSin();
OperationCos *OperationFactory::m_operationCos = new OperationCos();
OperationExp *OperationFactory::m_operationExp = new OperationExp();
OperationSqrt *OperationFactory::m_operationSqrt = new OperationSqrt();
OperationLog *OperationFactory::m_operationLog = new OperationLog();
OperationLn *OperationFactory::m_operationLn = new OperationLn();
OperationAbs *OperationFactory::m_operationAbs = new OperationAbs();
OperationTan *OperationFactory::m_operationTan = new OperationTan();
OperationCot *OperationFactory::m_operationCot = new OperationCot();
OperationModule *OperationFactory::m_operationModule = new OperationModule();

OperationFactory::OperationFactory()
{

}

AbstractOperation *OperationFactory::getOperationFunction(QString operationStr)
{
    if(CalculatorUtil::Operation_Add == operationStr)
    {
        m_operation = m_operationAdd;
    }
    else if (CalculatorUtil::Operation_Minus == operationStr)
    {
        m_operation = m_operationMinus;
    }
    else if (CalculatorUtil::Operation_Multiplied == operationStr)
    {
        m_operation = m_operationMultiplied;
    }
    else if (CalculatorUtil::Operation_Divided == operationStr)
    {
        m_operation = m_operationDivided;
    }
    else if (CalculatorUtil::Operation_Power == operationStr)
    {
        m_operation = m_operationPower;
    }
    else if (CalculatorUtil::Operation_Left_Move == operationStr)
    {
        m_operation = m_operationLeftMove;
    }
    else if (CalculatorUtil::Operation_Right_Move == operationStr)
    {
        m_operation = m_operationRightMove;
    }
    else if (CalculatorUtil::Operation_Get_Byte == operationStr)
    {
        m_operation = m_operationGetByte;
    }
    else if (CalculatorUtil::Operation_Sin == operationStr)
    {
        m_operation = m_operationSin;
    }
    else if (CalculatorUtil::Operation_Cos == operationStr)
    {
        m_operation = m_operationCos;
    }
    else if (CalculatorUtil::Operation_Exp == operationStr)
    {
        m_operation = m_operationExp;
    }
    else if (CalculatorUtil::Operation_Sqrt == operationStr)
    {
        m_operation = m_operationSqrt;
    }
    else if (CalculatorUtil::Operation_Log == operationStr)
    {
        m_operation = m_operationLog;
    }
    else if (CalculatorUtil::Operation_Ln == operationStr)
    {
        m_operation = m_operationLn;
    }
    else if (CalculatorUtil::Operation_Abs == operationStr)
    {
        m_operation = m_operationAbs;
    }
    else if (CalculatorUtil::Operation_Tan == operationStr)
    {
        m_operation = m_operationTan;
    }
    else if (CalculatorUtil::Operation_Cot == operationStr)
    {
        m_operation = m_operationCot;
    }
    else if (CalculatorUtil::Operation_Module == operationStr)
    {
        m_operation = m_operationModule;
    }
    return m_operation;
}
