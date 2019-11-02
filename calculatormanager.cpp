#include "calculatormanager.h"
CalculatorManager* CalculatorManager::instance=0;
CalculatorManager::CalculatorManager()
{

}

//// 将获取到的分割好的表达式数组，转化为逆波兰表达式，存入数组repolish中
/// \brief CalculatorManager::getRepolish
/// \param forlumaVec
/// \return
///
QVector<QString> CalculatorManager::getRepolish(QVector<QString> forlumaVec)
{
    QVector<QString> repolish;
    QStack<QString> st2;
    int i = 0;
    for(int j = 0 ; j < forlumaVec.size() ; j++)
    {
        if(forlumaVec[j] != "(" && forlumaVec[j] != ")"
                &&!CalculatorUtil::vec_allOperator.contains(forlumaVec[j]))
        {
            repolish.append(forlumaVec[j]);
            i++;
        }

        else if(forlumaVec[j] == "(")
        {
            st2.push(forlumaVec[j]);
        }
        else if(forlumaVec[j] == ")")
        {
            while(st2.top() != "(")
            {
                repolish.append(st2.top());
                st2.pop();
            }
            if(st2.top() == "(")
                st2.pop();
        }
        else if(st2.empty() ||CalculatorUtil::priority(forlumaVec[j]) > CalculatorUtil::priority(st2.top()))
        {
            st2.push(forlumaVec[j]);
        }
        else
        {
            while(CalculatorUtil::priority(forlumaVec[j]) <= CalculatorUtil::priority(st2.top()))
            {
                repolish.append(st2.top());
                i++;
                st2.pop();
                if(st2.empty())
                    break;
            }
            st2.push(forlumaVec[j]);
        }
    }
    while(!st2.empty())
    {
        repolish.append(st2.top());
        i++;
        st2.pop();
    }
    return repolish;
}

//// 分离符号和数字
/// \brief CalculatorManager::split
/// \param exp
/// \return
///
bool CalculatorManager::splitFormula(QString inputStr,QVector<QString> &formaulaVec,QString &errorMsg)
{

    QString num = "";
    QString pre = "";
    QString letter;

    for(int i=0; i<inputStr.length(); i++)
    {
        if(CalculatorUtil::isBadChar(inputStr[i]))//非法字符校验
        {
            errorMsg = "The formula contains illegality characters: "+QString(inputStr[i]);

            return false;
        }

        if( CalculatorUtil::isDigitOrDot(inputStr[i]))//数字或者小数点
        {
            if(!letter.isEmpty())
            {
                if(letter.contains(CalculatorUtil::PLACEHOLDER))
                {
                    letter += inputStr[i];
                    continue;
                }
                formaulaVec.append(letter);
                letter.clear();
            }
            num += inputStr[i];
            pre = inputStr[i]; //为判断+，-是否为正负号，而使用的
        }

        else if( CalculatorUtil::isLetter(inputStr[i]) )
        {
            if( !num.isEmpty() )
            {
                if(num=="+"||num=="-")
                {
                    letter += num;
                }
                else
                {
                    formaulaVec.append(num);//分离的数字入队列
                }

                num.clear();
            }
            letter += inputStr[i];
            if(CalculatorUtil::isLetterOperator(letter))
            {
                formaulaVec.append(letter);//分离的specific Symbol入队列
                letter.clear();
            }
            pre = inputStr[i];
        }
        else if( CalculatorUtil::isSymbol(inputStr[i]) )
        {
            if( !num.isEmpty() )
            {
                formaulaVec.append(num);//分离的数字入队列
                num.clear();
            }

            if( !letter.isEmpty() )
            {
                formaulaVec.append(letter);//分离的specific Symbol入队列
                letter.clear();
            }

            if( CalculatorUtil::isSign(inputStr[i]) && ((pre == "")
                                                        || (pre == "(")
                                                        || CalculatorUtil::isOperator(pre)
                                                        ||CalculatorUtil::isLetterOperator(formaulaVec.last())))
            {
                num += inputStr[i];//存储正负号
                pre = inputStr[i];//保存上一个字符
                continue;
            }
            if(pre =="<"&&inputStr[i]=="<")
            {
                formaulaVec[formaulaVec.size()-1] = "<<";
                pre = inputStr[i];//保存上一个字符
                continue;
            }

            if(pre ==">"&&inputStr[i]==">")
            {
                formaulaVec[formaulaVec.size()-1] = ">>";
                pre = inputStr[i];//保存上一个字符
                continue;
            }
            else
            {
                formaulaVec.append(""+inputStr[i]); // 运算符入队列
            }
            pre = inputStr[i];//保存上一个字符
        }
        else
        {
            errorMsg = "The formula contains illegality characters: "+QString(inputStr[i]);

            return false;
        }
    }
    if( !num.isEmpty() )
    {
        formaulaVec.append(num);//最后一个运算数
    }
    else if(!letter.isEmpty())
    {
        formaulaVec.append(letter);
    }

    if(formaulaVec.count()<=0)
    {
        errorMsg = "Please enter the calculation formula ";
        return false;
    }
    return true;
}

/// <summary>
/// 验证得到的逆波兰表达式列表的正确性
/// </summary>
/// <param name="exp">表达式列表</param>
/// <returns>正确返回true，错误返回false</returns>
bool CalculatorManager:: checkRPN(QVector<QString>& rpns,QString &errorMsg)
{
    if(rpns.count()<=0)
    {
        errorMsg = "Please enter the calculation formula ";
        return false;
    }
    QStack<QString> result;  //运算符

    try
    {
        for (int i = 0; i < rpns.size(); i++)
        {
            if (CalculatorUtil::isNumber(rpns[i])||rpns[i].contains(CalculatorUtil::PLACEHOLDER))
            {
                result.push(rpns[i]);
            }

            else
            {
                if(CalculatorUtil::isLetter(rpns[i][0]))
                {
                    if(!CalculatorUtil::isLetterOperator(rpns[i]))
                        return false;
                }
                int level = CalculatorUtil::priority(rpns[i]);  //获得运算符的优先级
                if (level == 4)                 //说明是单目运算符
                {
                    if(result.empty()) return false;
                    QString topItem = result.top();  //弹出栈顶元素
                    result.pop();
                    result.push(rpns[i] + "(" + topItem + ")");   //压入栈
                }
                else   //说明是双目运算符
                {
                    if(result.empty())
                    {
                        errorMsg = "Wrong formula";
                        return false;
                    }
                    QString topItem1 = result.top();
                    result.pop();  //弹出栈顶元素
                    if (result.empty())
                    {
                        errorMsg = "Wrong formula";
                        return false;
                    }
                    QString topItem2 = result.top(); result.pop();  //弹出栈顶元素
                    result.push("(" + topItem2 + rpns[i] + topItem1 + ")");   //压入栈
                }
            }
        }
        //看看result最后是不是还剩一个元素
        result.pop();
        if (result.empty())return true;
        errorMsg = "Wrong formula";
        return false;
    }
    catch (...)
    {
        errorMsg = "Wrong formula";
        return false;
    }

}

/** 计算公式值并显示
 * @brief CalculatorManager::getRepolishResult
 * @param repolish 公式
 * @param result 结果
 * @param errorMsg 错误信息
 * @return
 */
bool CalculatorManager::getRepolishResult(QVector<QString> repolish,double &result,QString &errorMsg)
{

    QStack <double> st;
    bool flag = false;
    for(int m = 0 ; m < repolish.size() ; m ++)
    {
        if(!CalculatorUtil::vec_allOperator.contains(repolish[m]))
        {
            /*Qstring转化为double数据存入堆栈*/
            st.push(repolish[m].toDouble());
        }
        else
        {
            flag = false;
            AbstractOperation *operation = OperationFactory::getOperationFunction(repolish[m]);
            //双目运算
            if(CalculatorUtil::vec_binaryOperator.contains(repolish[m]))
            {
                operation->setNumberA(st.top());
                st.pop();
                operation->setNumberB(st.top());
                st.pop();
                st.push(operation->getResult(flag,errorMsg));
            }
            //单目运算
            else if (CalculatorUtil::vec_unaryOperator.contains(repolish[m]))
            {
                operation->setNumberA(st.top());
                st.pop();
                st.push(operation->getResult(flag,errorMsg));
            }
            else
            {
                errorMsg = "error formaula";
                return false;
            }

            if(!flag)
            {
                return false;
            }
        }
    }
    result = st.top();
    return true;
}

/// 检查公式
/// \brief CalculatorManager::checkExpression
/// \param exp
/// \return
///
bool CalculatorManager::checkFormulaExp(QString& inputStr,QVector<QString> &formaulaVec,QString &errorMsg,int dataSize)
{

    bool ret = false;
    int left = 0;
    int right = 0;


    ret = splitFormula(inputStr,formaulaVec,errorMsg);
    if(!ret)
    {
        return false;
    }

    for(int i=0;i<formaulaVec.size();i++)
    {
        if(i<formaulaVec.size()-1)
        {
            if(CalculatorUtil::isLetterOperator(formaulaVec[i])&&formaulaVec[i+1]!="(")
            {
                errorMsg = formaulaVec[i]+" less '(',please check";
                return false;
            }
        }

        if(CalculatorUtil::isLeft(formaulaVec[i])) left++;
        if(CalculatorUtil::isRight(formaulaVec[i])) right++;

        if(formaulaVec[i].contains(CalculatorUtil::PLACEHOLDER)&&formaulaVec[i].contains("+"))
        {
            formaulaVec[i].replace("+","");
        }
        if(formaulaVec[i].contains(CalculatorUtil::PLACEHOLDER)&&formaulaVec[i].contains("-"))
        {
            formaulaVec[i].replace("-","");
        }

        if(!CalculatorUtil::isLetterOperator(formaulaVec[i])&&!CalculatorUtil::isSymbol(*formaulaVec[i].data())
                &&!CalculatorUtil::isNumber(formaulaVec[i]))
        {
            if(formaulaVec[i].contains(CalculatorUtil::PLACEHOLDER))
            {

                if(formaulaVec[i].trimmed().length()<=3)
                {

                }
                else
                {
                    QString num="";
                    QString parameter = formaulaVec[i];
                    for(int j=3;j<parameter.length();j++)
                    {
                        if((parameter[j]<'0') || (parameter[j] > '9'))
                        {
                            errorMsg = CalculatorUtil::PLACEHOLDER + " include other letter";
                            return false;
                        }
                        num += parameter[j];
                    }
                    int index = num.trimmed().toInt();
                    if(index>dataSize-1)
                    {
                        errorMsg = CalculatorUtil::PLACEHOLDER + " Index Out Of Bounds Exception";
                        return false;
                    }
                }
            }
            else
            {
                errorMsg = "Include other unknow parameter,Please check!\n"
                           "Tips:The format of the placeholder is:"+CalculatorUtil::PLACEHOLDER+"0,"+CalculatorUtil::PLACEHOLDER+"1...";
                return false;
            }
        }
    }
    if(left!=right)
    {
        errorMsg = "Please check '(' or ')'";
        return false;
    }
    QVector<QString> repolistVec = getRepolish(formaulaVec);
    if(repolistVec.count()<=0)
    {
        errorMsg = "Please enter the calculation formula ";
        return false;
    }

    ret = checkRPN(repolistVec,errorMsg);
    return ret;
}

/// 获取计算结果
/// \brief CalculatorManager::getResult
/// \param forluma 公式
/// \param parameterValueVec ans 对应值
/// \param currentIndex 当前index
/// \param result 逆波兰式计算结果
/// \param errorMsg 错误信息
/// \return 是否计算成功
///
bool CalculatorManager:: getResult(QString forluma,QVector<QString> &parameterValueVec,int currentIndex,double &result,QString &errorMsg)
{

    if(forluma.length()<=0){
        return false;
    }
    //分离符号和数字
    QVector<QString> forlumaVec;
    bool check = checkFormulaExp(forluma,forlumaVec,errorMsg,parameterValueVec.count());
    if(!check)
    {
        return false;
    }


    //    QVector<QString> forlumaVec = splitFormula(forluma);
    for(int i=0;i<forlumaVec.size();i++)
    {
        bool isMinus = false;
        if(forlumaVec[i].contains(CalculatorUtil::PLACEHOLDER)&&forlumaVec[i].contains("+"))
        {
            forlumaVec[i].replace("+","");
        }
        if(forlumaVec[i].contains(CalculatorUtil::PLACEHOLDER)&&forlumaVec[i].contains("-"))
        {
            isMinus = true;
            forlumaVec[i].replace("-","");
        }

        if(!CalculatorUtil::isLetterOperator(forlumaVec[i])&&!CalculatorUtil::isSymbol(*forlumaVec[i].data())
                &&!CalculatorUtil::isNumber(forlumaVec[i]))
        {
            if(forlumaVec[i].contains(CalculatorUtil::PLACEHOLDER))
            {

                if(forlumaVec[i].trimmed().length()<=3)
                {
                    forlumaVec[i] = parameterValueVec[currentIndex];
                    if(isMinus) forlumaVec[i] = "-" + parameterValueVec[currentIndex];

                }
                else
                {
                    QString num="";
                    QString parameter = forlumaVec[i];
                    for(int j=3;j<parameter.length();j++)
                    {
                        if((parameter[j]<'0') || (parameter[j] > '9'))
                        {
                            errorMsg = CalculatorUtil::PLACEHOLDER + " include other letter";
                            return false;
                        }
                        num += parameter[j];
                    }
                    int index = num.trimmed().toInt();
                    if(index>parameterValueVec.size()-1)
                    {
                        errorMsg = CalculatorUtil::PLACEHOLDER+num+ " Index Out Of Bounds Exception";
                        return false;
                    }
                    forlumaVec[i] = parameterValueVec[index];
                    if(isMinus)
                    {
                        forlumaVec[i] = QString::number(0-forlumaVec[i].toInt());
                    }
                }
            }
            else
            {
                errorMsg = "Include other unknow parameter,please check";
                return false;
            }
        }
    }

    QVector<QString> repolishVec = getRepolish(forlumaVec);
    return getRepolishResult(repolishVec,result,errorMsg);
}
