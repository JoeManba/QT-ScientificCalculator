#ifndef OPERATIONEXP_H
#define OPERATIONEXP_H
#include <abstractoperation.h>
#include <math.h>


class OperationExp : public AbstractOperation
{
public:
    OperationExp();
    virtual double getResult(bool &flag,QString &errorStr);
};

#endif // OPERATIONEXP_H
