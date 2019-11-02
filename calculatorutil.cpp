#include "calculatorutil.h"

CalculatorUtil::CalculatorUtil()
{

}

QString CalculatorUtil::PLACEHOLDER = "ans";

//左括号
QString CalculatorUtil::LeftBracket = "(";
//右括号
QString CalculatorUtil::RightBracket = ")";

QString CalculatorUtil::Operation_Add = "+";

QString CalculatorUtil::Operation_Minus = "-";

QString CalculatorUtil::Operation_Multiplied = "*";

QString CalculatorUtil::Operation_Divided = "/";

QString CalculatorUtil::Operation_Power = "^";

QString CalculatorUtil::Operation_Left_Move = "<<";

QString CalculatorUtil::Operation_Right_Move = ">>";
//NumberA#NumberB 取NumberA的第NumberB个字节 NumberB[0,3] 0从低位开始
QString CalculatorUtil::Operation_Get_Byte = "#";

QString CalculatorUtil::Operation_Module = "%";


/// 单目运算

QString CalculatorUtil::Operation_Sin = "sin";

QString CalculatorUtil::Operation_Cos = "cos";

//以自然常数e为底的指数函数
QString CalculatorUtil::Operation_Exp = "exp";

QString CalculatorUtil::Operation_Sqrt = "sqrt";

QString CalculatorUtil::Operation_Log = "log";

QString CalculatorUtil::Operation_Ln = "ln";

QString CalculatorUtil::Operation_Abs = "abs";

QString CalculatorUtil::Operation_Tan = "tan";

QString CalculatorUtil::Operation_Cot = "cot";

//字母表示的运算符集合
 QVector<QString> CalculatorUtil::vec_letterOperator = {CalculatorUtil::Operation_Sin,
                                     CalculatorUtil::Operation_Cos,
                                     CalculatorUtil::Operation_Exp,
                                     CalculatorUtil::Operation_Sqrt,
                                     CalculatorUtil::Operation_Log,
                                     CalculatorUtil::Operation_Ln,
                                     CalculatorUtil::Operation_Abs,
                                     CalculatorUtil::Operation_Tan,
                                     CalculatorUtil::Operation_Cot};
 //非字母表示的运算符集合
 QVector<QString> CalculatorUtil::vec_noLetterOperator = {CalculatorUtil::Operation_Add,
                                         CalculatorUtil::Operation_Minus,
                                         CalculatorUtil::Operation_Multiplied,
                                         CalculatorUtil::Operation_Divided,
                                         CalculatorUtil::Operation_Power,
                                         QString(CalculatorUtil::Operation_Left_Move[0]),//由于<<由两个<组成，取其中一个即可
                                         QString(CalculatorUtil::Operation_Right_Move[0]),//由于>>由两个>组成，取其中一个即可
                                         CalculatorUtil::Operation_Get_Byte,
                                         CalculatorUtil::Operation_Module};

  //所有运算符集合
  QVector<QString> CalculatorUtil::vec_allOperator = {CalculatorUtil::Operation_Add,
                                    CalculatorUtil::Operation_Minus,
                                    CalculatorUtil::Operation_Multiplied,
                                    CalculatorUtil::Operation_Divided,
                                    CalculatorUtil::Operation_Power,
                                    CalculatorUtil::Operation_Left_Move,
                                    CalculatorUtil::Operation_Right_Move,
                                    CalculatorUtil::Operation_Get_Byte,
                                    CalculatorUtil::Operation_Sin,
                                    CalculatorUtil::Operation_Cos,
                                    CalculatorUtil::Operation_Exp,
                                    CalculatorUtil::Operation_Sqrt,
                                    CalculatorUtil::Operation_Log,
                                    CalculatorUtil::Operation_Ln,
                                    CalculatorUtil::Operation_Abs,
                                    CalculatorUtil::Operation_Tan,
                                    CalculatorUtil::Operation_Cot,
                                    CalculatorUtil::Operation_Module};

  //单目运算集合
  QVector<QString> CalculatorUtil::vec_unaryOperator={CalculatorUtil::Operation_Sin,
                                                      CalculatorUtil::Operation_Cos,
                                                      CalculatorUtil::Operation_Exp,
                                                      CalculatorUtil::Operation_Sqrt,
                                                      CalculatorUtil::Operation_Log,
                                                      CalculatorUtil::Operation_Ln,
                                                      CalculatorUtil::Operation_Abs,
                                                      CalculatorUtil::Operation_Tan,
                                                      CalculatorUtil::Operation_Cot};
  //双目运算集合
  QVector<QString> CalculatorUtil::vec_binaryOperator={CalculatorUtil::Operation_Add,
                                                       CalculatorUtil::Operation_Minus,
                                                       CalculatorUtil::Operation_Multiplied,
                                                       CalculatorUtil::Operation_Divided,
                                                       CalculatorUtil::Operation_Power,
                                                       CalculatorUtil::Operation_Left_Move,
                                                       CalculatorUtil::Operation_Right_Move,
                                                       CalculatorUtil::Operation_Get_Byte,
                                                       CalculatorUtil::Operation_Module};
/// //是否为数字（0-9）或者小数点
/// \brief CalculatorUtil::isDigitOrDot
/// \param c
/// \return
///
bool CalculatorUtil::isDigitOrDot(QChar c)
{
    return (('0' <= c) && (c <= '9')) || (c == '.');
}

/// 判断是否是('a'~'z','A'~'Z'）字符
/// \brief CalculatorUtil::isLetter
/// \param c
/// \return
///
bool CalculatorUtil::isLetter(QChar c)
{
    return (('a' <= c) && (c <= 'z'))
            || (('A' <= c) && (c <= 'Z'));
}

/// 判断是否为非法字符
/// \brief CalculatorUtil::isChineseLetter
/// \param c
/// \return
///
bool CalculatorUtil::isBadChar(QChar c)
{
    ushort uni = c.unicode();


    if(uni > 0x007E || uni < 0x0021)//非法字符
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// 是否为操作符或者括号
/// \brief CalculatorUtil::isSymbol
/// \param c
/// \return
///
bool CalculatorUtil::isSymbol(QChar c)

{

    return isOperator(c) || (c == '(') || (c == ')');

}

/// 是否为正负号
/// \brief CalculatorUtil::isSign
/// \param c
/// \return
///
bool CalculatorUtil::isSign(QChar c)

{

    return (c == '+') || (c == '-');

}


/// 是否为一个合法的数字
/// \brief CalculatorUtil::isNumber
/// \param s
/// \return
///
bool CalculatorUtil::isNumber(QString s)

{

    bool ret = false;

    s.toDouble(&ret);

    return ret;

}

/// 是否是非字母的运算符
/// \brief CalculatorUtil::isOperator
/// \param s
/// \return
///
bool CalculatorUtil::isOperator(QString s)
{

//    return (s == "+") || (s == "-") || (s == "*")
//            || (s == "/")||(s=="^")||(s=="%")||(s=="<")||(s==">")||(s=="#");
    return vec_noLetterOperator.contains(s);

}

/** 是否是含字母的运算符
 * @brief CalculatorUtil::isLetterOperator
 * @param s
 * @return
 */
bool CalculatorUtil::isLetterOperator(QString s)
{
//    return (s=="sqrt")||(s=="sin")||(s=="cos")||
//            (s=="exp")||(s=="log")||(s=="abs")||
//            (s=="ctg")||(s=="asin")||(s=="acos")||
//            (s=="ln")||(s=="tg")||(s=="atg");
    return vec_letterOperator.contains(s);
}

/// 是否为左括号
/// \brief CalculatorUtil::isLeft
/// \param s
/// \return
///
bool CalculatorUtil::isLeft(QString s)

{

    return (s == "(");

}

////是否为右括号
/// \brief CalculatorUtil::isRight
/// \param s
/// \return
///
bool CalculatorUtil::isRight(QString s)

{

    return (s == ")");

}

////*获取操作符优先级*/
/// \brief CalculatorUtil::Priority
/// \param data
/// \return
///
int CalculatorUtil::priority(QString data)
{
    int priority;
    if(data == "(")
        priority = 1;
    else if(data == CalculatorUtil::Operation_Add
            || data == CalculatorUtil::Operation_Minus)
        priority = 2;
    else if(data == CalculatorUtil::Operation_Multiplied
            || data == CalculatorUtil::Operation_Divided
            || data == CalculatorUtil::Operation_Left_Move
            || data == CalculatorUtil::Operation_Right_Move
            || data == CalculatorUtil::Operation_Power
            || data == CalculatorUtil::Operation_Get_Byte)
        priority = 3;
    else if(data == CalculatorUtil::Operation_Sin
            || data == CalculatorUtil::Operation_Cos
            || data == CalculatorUtil::Operation_Exp
            || data == CalculatorUtil::Operation_Sqrt
            || data == CalculatorUtil::Operation_Log
            || data == CalculatorUtil::Operation_Ln
            || data == CalculatorUtil::Operation_Abs
            || data == CalculatorUtil::Operation_Tan
            || data == CalculatorUtil::Operation_Cot)
    {
        priority = 4;
    }
    else if (data == ")")
        priority = 5;
    else
        priority = -1;
    return priority;
}
