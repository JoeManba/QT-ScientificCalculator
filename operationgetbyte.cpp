#include "operationgetbyte.h"

OperationGetByte::OperationGetByte()
{

}

double OperationGetByte::getResult(bool &flag,QString &errorStr)
{
    int a = (int)getNumberA();
    int b = (int)getNumberB();
    if(a<0||a>3)
    {
        flag = false;
        errorStr = "# Index Out Of Bounds Exception";
        return 0;

    }

    flag = true;
    errorStr = "";
    return (int)int2Bytes(b)[a];
}

QByteArray OperationGetByte::  int2Bytes(int value)
{
    QByteArray src ;
    src.resize(4);
    src[0] =  value & 0xFF;
    src[1] =  (value>>8) & 0xFF;
    src[2] =  (value>>16) & 0xFF;
    src[3] =  (value>>24) & 0xFF;
    return src;
}
