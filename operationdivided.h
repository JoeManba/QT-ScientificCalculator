#ifndef OPERATIONDIVIDED_H
#define OPERATIONDIVIDED_H
#include <abstractoperation.h>

class OperationDivided : public AbstractOperation
{
public:
    OperationDivided();
    virtual double getResult(bool &flag,QString &errorStr);
};

#endif // OPERATIONDIVIDED_H
