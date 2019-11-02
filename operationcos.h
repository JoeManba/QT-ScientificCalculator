#ifndef OPERATIONCOS_H
#define OPERATIONCOS_H
#include <abstractoperation.h>
#include <math.h>

class OperationCos : public AbstractOperation
{
public:
    OperationCos();
    virtual double getResult(bool &flag,QString &errorStr);
};

#endif // OPERATIONCOS_H
