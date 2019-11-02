#ifndef OPERATIONADD_H
#define OPERATIONADD_H
#include <abstractoperation.h>


class OperationAdd : public AbstractOperation
{
public:
    OperationAdd();
    virtual double getResult(bool &flag,QString &errorStr);
};

#endif // OPERATIONADD_H
