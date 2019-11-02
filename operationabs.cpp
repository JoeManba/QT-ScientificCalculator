#include "operationabs.h"

OperationAbs::OperationAbs()
{

}

double OperationAbs::getResult(bool &flag, QString &errorStr)
{
    flag = true;
    errorStr = "";
    return abs(getNumberA());
}
