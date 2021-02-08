#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <Windows.h>
#include <cstdlib>

using std::endl;
using std::string;
using std::stack;
using std::cout;
using std::cin;
using std::cerr;
using Unit = double;                                       //实数运算
//添加小数计算器

/* 六．实现计算器功能，示例：求15 - 9 / 3 + 23 * 2 - 3 + (12 + 3) / 4的值；*/
/***************************************************************************/

// 遇到一个数字就将其压入数字栈，若是连续数字就先弹栈处理后再压栈
// 若前后运算符优先级相同或正常，就直接计算
// 若后运算符优先级大于前运算符，就先将运算符压如符号栈
// 若遇到前括号，同样将运算符压入符号栈

class Solution
{
private:
    stack<Unit> num;
    stack<char> sym;
public:
    //先以一个最低优先级的当先，以便最初的运算
    char order[8][8] =
    {
        //	    +    -    *    /    (    )    !    @   当前的
        /*+*/ {'>', '>', '<', '<', '<', '>', '<', '>'},
        /*-*/ {'>', '>', '<', '<', '<', '>', '<', '>'},
        /***/ {'>', '>', '>', '>', '<', '>', '<', '>'},
        /*/*/ {'>', '>', '>', '>', '<', '>', '<', '>'},
        /*(*/ {'<', '<', '<', '<', ' ', '=', '<', ' '},
        /*)*/ {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        /*!*/ {'>', '>', '>', '>', ' ', '>', ' ', '>'},
        /*@*/ {'<', '<', '<', '<', '<', ' ', '<', '='}
        //栈顶的
    };


    int getfirst(char c);                                            //将四则运算符号转化为对应的行列

    void getvalue(Unit c1, char value, Unit c2);                    //将计算结果压入栈

    char getorder(char c1, char c2);

    Unit ans(string fun);

    Unit fac(Unit n);

};

int main(void)
{
    cout << "此版本支持浮点运算" << endl;
    cout << "请输入式子，按ctrl-z退出\n";
    string s, vice(s);
    while (getline(cin, s))
    {
        Solution ss;
        cout << s + " = "<< ss.ans(s) << endl;
        cout << "请输入式子，按ctrl-z退出\n";
    }
    Sleep(200);
    cout << "退出成功!" << endl;
    system("pause");
    return 0;
}

Unit Solution::ans(string fun)
{
    sym.push('@');
    fun += '@';                                                            //与服战栈最初的@对应
    string::const_iterator i = fun.begin();
    int key = 1, index = 0, point = 0;                                  	//判断是否为连续数字
    double wei = 1;
    for (; i < fun.end(); ++i)
    {
        if (*i == ' ')
            continue;
        else if (*i >= '0' && *i <= '9')
        {
            if (key)
            {
                num.push(static_cast<double>(*i) - static_cast<double>('0'));
                key = 0;
            }
            else
            {
                Unit t = num.top();    num.pop();

                if (point)                                                 //验证是否出现小数点
                {
                    ++index;
                    t = t + (static_cast<double>(*i) - static_cast<double>('0'))* pow(wei, index);
                }
                else
                {
                    t = 10 * t + (static_cast<double>(*i) - static_cast<double>('0'));
                }
                num.push(t);
            }
        }
        else if (*i == '.')                                                  //是否出现小数点          
        {
            try                                                              //错误处理
            {
                if (key)
                    throw("point should follow after a number!\nThe program will exit!after 3 seconds\n");
                else
                {
                    wei = 0.1;                                               //若一切正常
                    point = 1;
                }
            }
            catch (const char* msg)
            {
                cerr << msg << endl;
                Sleep(1000);
                for (int i = 0; i < 3; ++i)
                {
                    cout << 3 - i << "s..." << endl;
                    Sleep(1000);

                }
                cout << "退出成功!" << endl;
                exit(0);
            }							   	                          //一般而言都在数字中间  

        }
        else
        {
            key = 1;
            point = 0;
            index = 0;
            char t = getorder(*i, sym.top());                         //当前    前一个
            if (t == '>')
            {
                if (sym.top() == '!')                                 //阶乘
                {
                    double t = num.top(); num.pop();
                    num.push(fac(t));
                }
                else
                {
                    Unit s1 = num.top(); num.pop();
                    Unit s2 = num.top(); num.pop();
                    getvalue(s1, sym.top(), s2);
                }
                sym.pop();
                --i;                                                 //之后还要用这一个运算符
            }
            else if (t == '=')
            {
                sym.pop();
            }
            else if (t == '<')
            {
                sym.push(*i);
            }
        }

    }
    if (!sym.empty())
    {
        Unit s1 = num.top(); num.pop();
        Unit s2 = num.top(); num.pop();
        getvalue(s1, sym.top(), s2);
        sym.pop();
    }
    return num.top();

}

Unit Solution::fac(Unit n)
{
    try
    {
        if (n != (long)n)
            throw("The num nust be integer! The program will exit after 3 seconds\n");
    }
    catch (const char* smg)
    {
        cout << smg << endl;
        exit(0);
    }
    if (n == 1 || n == 0)
        return 1;
    else
    {
        long res = 1;
        while (n >= 2)
        {
            res *= n--;
        }
        return res;
    }

    //return Unit();
}


inline int Solution::getfirst(char c)
{
    switch (c)
    {
    case('+'): return 0; break;
    case('-'): return 1; break;
    case('*'): return 2; break;
    case('/'): return 3; break;
    case('('): return 4; break;
    case(')'): return 5; break;
    case('!'): return 6; break;
    default: return 7;
    }
}

inline char Solution::getorder(char c1, char c2)                  //得到运算符优先级
{
    int s1 = getfirst(c1);
    int s2 = getfirst(c2);
    return order[s2][s1];
}

inline void Solution::getvalue(Unit value1, char c, Unit value2)   // 记得之前把那两个数弹栈
{
    if (c == '+')
    {
        num.push(value1 + value2);
    }
    if (c == '-')
    {
        num.push(value2 - value1);
    }
    if (c == '*')
    {
        num.push(value1 * value2);
    }
    if (c == '/')
    {
        try                                                           //错误处理 
        {
            if (value1 == 0)
                throw("The divisor can't be zero!\n");
            else
                num.push(value2 / value1);                           //若一切正常
        }
        catch (const char* msg)
        {
            cerr << msg;
            cout << "The program will exit after 3 seconds" << endl;
            Sleep(1000);
            for (int i = 0; i < 3; ++i)
            {
                cout << 3 - i << "s..." << endl;
                Sleep(1000);

            }
            cout << "退出成功!" << endl;
            exit(0);
        }
    }
}
