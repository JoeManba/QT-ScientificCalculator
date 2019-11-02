#include "operationcot.h"

OperationCot::OperationCot()
{

}

double OperationCot::getResult(bool &flag, QString &errorStr)
{
    try
    {
        flag = true;
        errorStr = "";
        return 1/tan(getNumberA());
    }
    catch(...)
    {
        flag = false;
        errorStr = "error";
        return 0;
    }

}
