#include "operationpower.h"
#include <math.h>
OperationPower::OperationPower()
{

}

double OperationPower::getResult(bool &flag,QString &errorStr)
{
    flag = true;
    errorStr = "";
    return pow(getNumberB(),getNumberA());
}
