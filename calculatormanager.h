#ifndef CALCULATORMANAGER_H
#define CALCULATORMANAGER_H
#include <QVector>
#include <QString>
#include <QMutex>
#include <calculatorutil.h>
#include <calculatorcommon.h>
#include <QStack>
#include <abstractoperation.h>
#include <operationfactory.h>

///
/// 计算器管理类
/// 支持的双目运算符有:^ * / % + - << >> #(a#b 取a的第b个字节 b[0,3] 0从低位开始)
/// 支持的单目运算符有:+(正) -(负) sin cos exp sqrt log ln abs tan cot
/// \brief The CalculatorManager class
///
class CalculatorManager
{
private:
    CalculatorManager();
    static CalculatorManager *instance;
    // 将获取到的分割好的表达式数组，转化为逆波兰表达式，并返回
    QVector<QString> getRepolish(QVector<QString> forlumaVec);

    //分离符号和数字
    bool splitFormula( QString exp,QVector<QString> &formaulaVec,QString &errorMsg);

    //验证得到的逆波兰表达式列表的正确性
    bool checkRPN(QVector<QString>& rpns,QString &errorMsg);

    //计算公式的值
    bool getRepolishResult(QVector<QString> repolish,double &result,QString &errorMsg);
    //检查公式
    bool checkFormulaExp(QString & exp,QVector<QString> &formaulaVec,QString &errorMsg,int dataSize);


public:

    static CalculatorManager* getInstance()
    {
        static QMutex mutex;
        if (!instance) {
            QMutexLocker locker(&mutex);
            if (!instance)
                instance = new CalculatorManager();
        }
        return instance;
    }
    // 获取计算结果
    bool getResult(QString forluma,QVector<QString> &parameterValueVec,int currentIndex,double &result,QString &errorMsg);


};

#endif // CALCULATORMANAGER_H
