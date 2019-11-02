#ifndef OPERATIONPOWER_H
#define OPERATIONPOWER_H
#include <abstractoperation.h>

class OperationPower : public AbstractOperation
{
public:
    OperationPower();
    virtual double getResult(bool &flag,QString &errorStr);
};

#endif // OPERATIONPOWER_H
