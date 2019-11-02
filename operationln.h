#ifndef OPERATIONLN_H
#define OPERATIONLN_H
#include <abstractoperation.h>

class OperationLn : public AbstractOperation
{
public:
    OperationLn();
    virtual double getResult(bool &flag, QString &errorStr);
};

#endif // OPERATIONLN_H
