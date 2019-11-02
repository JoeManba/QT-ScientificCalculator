#include "operationsin.h"

OperationSin::OperationSin()
{

}

double OperationSin::getResult(bool &flag,QString &errorStr)
{
    flag = true;
    errorStr = "";
    return sin(getNumberA());
}
