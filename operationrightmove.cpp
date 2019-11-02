#include "operationrightmove.h"

OperationRightMove::OperationRightMove()
{

}

double OperationRightMove::getResult(bool &flag,QString &errorStr)
{
    flag = true;
    errorStr = "";
    return (int)getNumberB()>>(int)getNumberA();
}
