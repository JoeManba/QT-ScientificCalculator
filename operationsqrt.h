#ifndef OPERATIONSQRT_H
#define OPERATIONSQRT_H
#include <abstractoperation.h>
#include <math.h>

class OperationSqrt : public AbstractOperation
{
public:
    OperationSqrt();
    virtual double getResult(bool &flag,QString &errorStr);
};

#endif // OPERATIONSQRT_H
