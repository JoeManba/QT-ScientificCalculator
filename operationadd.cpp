#include "operationadd.h"

OperationAdd::OperationAdd()
{

}

double OperationAdd::getResult(bool &flag,QString &errorStr)
{
    flag = true;
    errorStr = "";
    return getNumberB() + getNumberA();
}
