#ifndef OPERATIONTG_H
#define OPERATIONTG_H
#include <abstractoperation.h>

class OperationTan : public AbstractOperation
{
public:
    OperationTan();
    virtual double getResult(bool &flag, QString &errorStr);

};

#endif // OPERATIONTG_H
