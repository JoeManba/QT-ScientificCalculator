#include "operationcos.h"

OperationCos::OperationCos()
{

}

double OperationCos::getResult(bool &flag,QString &errorStr)
{
    flag = true;
    errorStr = "";
    return cos(getNumberA());
}
