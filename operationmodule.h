#ifndef OPERATIONMODULE_H
#define OPERATIONMODULE_H
#include <abstractoperation.h>

class OperationModule : public AbstractOperation
{
public:
    OperationModule();
    virtual double getResult(bool &flag, QString &errorStr);
};

#endif // OPERATIONMODULE_H
