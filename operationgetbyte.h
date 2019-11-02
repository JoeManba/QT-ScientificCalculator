#ifndef OPERATIONGETBYTE_H
#define OPERATIONGETBYTE_H
#include <abstractoperation.h>
#include <QByteArray>

class OperationGetByte : public AbstractOperation
{
public:
    OperationGetByte();
    virtual double getResult(bool &flag,QString &errorStr);

private:
    QByteArray int2Bytes(int value);
};

#endif // OPERATIONGETBYTE_H
