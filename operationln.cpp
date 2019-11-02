#include "operationln.h"

OperationLn::OperationLn()
{

}

double OperationLn::getResult(bool &flag, QString &errorStr)
{
    flag = true;
    errorStr = "";
    return log(getNumberA());
}
