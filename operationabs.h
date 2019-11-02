#ifndef OPERATIONABS_H
#define OPERATIONABS_H
#include <abstractoperation.h>

class OperationAbs : public AbstractOperation
{
public:
    OperationAbs();
    virtual double getResult(bool &flag, QString &errorStr);
};

#endif // OPERATIONABS_H
