#ifndef OPERATIONLEFTMOVE_H
#define OPERATIONLEFTMOVE_H
#include <abstractoperation.h>
#include <math.h>

class OperationLeftMove : public AbstractOperation
{
public:
    OperationLeftMove();
    virtual double getResult(bool &flag,QString &errorStr);
};

#endif // OPERATIONLEFTMOVE_H
