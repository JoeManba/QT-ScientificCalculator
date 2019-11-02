#ifndef OPERATIONSIN_H
#define OPERATIONSIN_H
#include <abstractoperation.h>
#include <math.h>

class OperationSin : public AbstractOperation
{
public:
    OperationSin();
    virtual double getResult(bool &flag,QString &errorStr);
};

#endif // OPERATIONSIN_H
