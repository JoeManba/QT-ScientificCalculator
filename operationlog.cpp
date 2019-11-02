#include "operationlog.h"

OperationLog::OperationLog()
{

}

double OperationLog::getResult(bool &flag, QString &errorStr)
{
    flag = true;
    errorStr = "";
    return log10(getNumberA());
}
