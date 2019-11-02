#ifndef OPERATIONMINUS_H
#define OPERATIONMINUS_H
#include <abstractoperation.h>

class OperationMinus : public AbstractOperation
{
public:
    OperationMinus();
    virtual double getResult(bool &flag,QString &errorStr);
};

#endif // OPERATIONMINUS_H
