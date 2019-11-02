#include "operationmodule.h"


OperationModule::OperationModule()
{

}

double OperationModule::getResult(bool &flag, QString &errorStr)
{
    flag = true;
    errorStr = "";
    return (int)getNumberB() % (int)getNumberA() ;
}
