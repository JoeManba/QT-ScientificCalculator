#include "operationleftmove.h"

OperationLeftMove::OperationLeftMove()
{

}

double OperationLeftMove::getResult(bool &flag,QString &errorStr)
{
    flag = true;
    errorStr = "";
    return (int)getNumberB()<<(int)getNumberA();
}

