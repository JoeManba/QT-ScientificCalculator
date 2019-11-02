#include "operationtan.h"

OperationTan::OperationTan()
{

}

double OperationTan::getResult(bool &flag, QString &errorStr)
{
    try
    {
        flag = true;
        errorStr = "";
        return tan(getNumberA());
    }
    catch(...)
    {
        flag = true;
        errorStr = "error";
        return 0;
    }

}
