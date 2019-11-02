#include "operationexp.h"

OperationExp::OperationExp()
{

}

double OperationExp::getResult(bool &flag,QString &errorStr)
{
    flag = true;
    errorStr = "";
    return exp(getNumberA());
}
