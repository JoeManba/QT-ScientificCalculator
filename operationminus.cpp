#include "operationminus.h"

OperationMinus::OperationMinus()
{

}


double OperationMinus::getResult(bool &flag,QString &errorStr)
{
    flag = true;
    errorStr = "";
    return getNumberB()-getNumberA();
}
