#ifndef OPERATIONRIGHTMOVE_H
#define OPERATIONRIGHTMOVE_H
#include <abstractoperation.h>

class OperationRightMove : public AbstractOperation
{
public:
    OperationRightMove();
    virtual double getResult(bool &flag,QString &errorStr);
};

#endif // OPERATIONRIGHTMOVE_H
