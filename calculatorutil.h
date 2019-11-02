#ifndef CALCULATORUTIL_H
#define CALCULATORUTIL_H
#include <QChar>
#include <QString>
#include <calculatorcommon.h>
#include <QVector>

///
/// 计算器工具类
/// \brief The CalculatorUtil class
///
class CalculatorUtil
{
public:
    CalculatorUtil();
    /**
     * 占位符
     * 如果 PLACEHOLDER = "ans"
     * ans0 ans1 ans2... 分别代表一个数值
     * 这些数值将会在运算的时候使用数组传进来
     * @brief PLACEHOLDER
     */
    static QString PLACEHOLDER;

    //左括号
    static QString LeftBracket;
    //右括号
    static QString RightBracket;


    /// 双目运算符
    //加号
    static QString Operation_Add;
    //减号
    static QString Operation_Minus;
    //乘号
    static QString Operation_Multiplied;
    //除号
    static QString Operation_Divided;
    //次方
    static QString Operation_Power;
    //左移号
    static QString Operation_Left_Move;
    //右移
    static QString Operation_Right_Move;
    //取模
    static QString Operation_Module;

    ///取字节
    /// NumberA#NumberB
    /// 取NumberA的第NumberB个字节
    /// NumberB取值范围[0,3] 0从低位开始
    static QString Operation_Get_Byte;


    /// 单目运算符
    // 正弦
    static QString Operation_Sin;
    // 余弦
    static QString Operation_Cos;

    //以自然常数e为底的指数函数
    static QString Operation_Exp;
    //开根号
    static QString Operation_Sqrt;
    // 以10为底的NamuberA的对数
    static QString Operation_Log;
    // 自然对数 以e为底的NamuberA的对数
    static QString Operation_Ln;
    //绝对值
    static QString Operation_Abs;
    //正切
    static QString Operation_Tan;
    //余切
    static QString Operation_Cot;


    //字母表示的运算符集合
    static QVector<QString> vec_letterOperator;
    //非字母表示的运算符集合
    static QVector<QString> vec_noLetterOperator;
    //所有运算符集合
    static QVector<QString> vec_allOperator;
    //单目运算集合
    static QVector<QString> vec_unaryOperator;
    //双目运算集合
    static QVector<QString> vec_binaryOperator;
    //数字或小数点
    static bool isDigitOrDot(QChar c);
    //判断是否是('a'~'z','A'~'Z'）字符
    static bool isLetter(QChar c);

    //判断是否为非法字符
    static bool isBadChar(QChar c);

    //判断是否为操作符或者括号
    static bool isSymbol(QChar c);

    // 判断是否为正负号
    static bool isSign(QChar c);

    // 判断是否是数字
    static bool isNumber(QString s);

    // 判断是否是运算符
    static bool isOperator(QString s);

    // 判断是否是运算符
    static bool isLetterOperator(QString s);

    //判断s是否为左括号
    static bool isLeft(QString s);

    //判断s是否为右括号
    static bool isRight(QString s);

    //获取操作符优先级
    static int priority(QString data);

};

#endif // CALCULATORUTIL_H
