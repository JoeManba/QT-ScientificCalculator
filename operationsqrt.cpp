#include "operationsqrt.h"

OperationSqrt::OperationSqrt()
{

}

double OperationSqrt::getResult(bool &flag,QString &errorStr)
{
    if(getNumberA()>=0)
    {
        flag = true;
        errorStr = "";
        return sqrt(getNumberA());
    }
    else
    {
        flag = false;
        errorStr = "Can't sqrt minus";
        return 0;

    }
}
