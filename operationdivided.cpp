#include "operationdivided.h"

OperationDivided::OperationDivided()
{

}

double OperationDivided::getResult(bool &flag,QString &errorStr)
{
    if(getNumberA()!=0)
    {
        flag = true;
        errorStr = "";
        return getNumberB()/getNumberA();
    }
    else
    {
        flag = false;
        errorStr = "The divisor cannot be 0";
        return 0;
    }
}
