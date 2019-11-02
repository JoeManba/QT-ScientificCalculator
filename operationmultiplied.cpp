#include "operationmultiplied.h"

OperationMultiplied::OperationMultiplied()
{

}

double OperationMultiplied::getResult(bool &flag,QString &errorStr)
{
    flag = true;
    errorStr = "";
    return getNumberB()*getNumberA();
}
