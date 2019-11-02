#ifndef OPERATIONLOG_H
#define OPERATIONLOG_H
#include <abstractoperation.h>

class OperationLog : public AbstractOperation
{
public:
    OperationLog();
    virtual double getResult(bool &flag, QString &errorStr);
};

#endif // OPERATIONLOG_H
