#ifndef OPERATIONCOT_H
#define OPERATIONCOT_H
#include <abstractoperation.h>

class OperationCot : public AbstractOperation
{
public:
    OperationCot();
    virtual double getResult(bool &flag, QString &errorStr);
};

#endif // OPERATIONCOT_H
