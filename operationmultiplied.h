#ifndef OPERATIONMULTIPLIED_H
#define OPERATIONMULTIPLIED_H
#include <abstractoperation.h>


class OperationMultiplied : public AbstractOperation
{
public:
    OperationMultiplied();

    virtual double getResult(bool &flag,QString &errorStr);
};

#endif // OPERATIONMULTIPLIED_H
