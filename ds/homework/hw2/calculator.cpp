#include "../../Stack/Stack.h"
#include <stdio.h>
#include<string.h>

#define N_OPTR 9 //运算符总数
typedef enum { ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE } Operator; //运算符集合
//加、减、乘、除、乘方、阶乘、左括号、右括号、起始符与终止符

const char pri[N_OPTR][N_OPTR] = { //运算符优先等级 [栈顶] [当前]
	/*              |-------------------- 当 前 运 算 符 --------------------| */
	/*              +      -      *      /      ^      !      (      )      \0 */
	/* --  + */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
	/* |   - */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
	/* 栈  * */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
	/* 顶  / */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
	/* 运  ^ */    '>',   '>',   '>',   '>',   '>',   '<',   '<',   '>',   '>',
	/* 算  ! */    '>',   '>',   '>',   '>',   '>',   '>',   ' ',   '>',   '>',
	/* 符  ( */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   '=',   ' ',
	/* |   ) */    ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',
	/* -- \0 */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   ' ',   '='
};//参照书上代码4.6 

void readNumber(char*& p, Stack<float>& stk) {
	stk.push((float)(*p - '0'));
	while (isdigit(*(++p)))
		stk.push(stk.pop() * 10 + (*p - '0'));
	if ('.' != *p) return;
	float fraction = 1;
	while (isdigit(*(++p)))
		stk.push(stk.pop() + (*p - '0') * (fraction /= 10));
}

Operator optr2rank(char op)
{
	switch (op) {
	case '+': return ADD; //加
	case '-': return SUB; //减
	case '*': return MUL; //乘
	case '/': return DIV; //除
	case '^': return POW; //乘斱
	case '!': return FAC; //阶乘
	case '(': return L_P; //左括号
	case ')': return R_P; //右括号
	case '\0': return EOE;
	default: exit(-1); //未知运算符
	}
}


char orderBetween(char op1, char op2) {//比较优先级
	return pri[optr2rank(op1)][optr2rank(op2)];
}



float calcu(char optr, float opnd) {
	int result = opnd;
	for (int i = opnd - 1; i > 0; i--) {
		result = result * i;
	}
	return result;
}//当符号为“！”时，重载一下函数


float calcu(float opnd1, char op, float opnd2) {
	float result = 1;
	switch (op)
	{
	case '+': {
		result = opnd1 + opnd2;
		return result; }
	case '-': {
		result = opnd1 - opnd2;
		return result; }
	case '/': {
		result = opnd1 / opnd2;
		return result; }
	case '^': {
		for (int i = 0; i < opnd2; i++)
			result *= opnd1;
	case '*': {
		result = opnd1 * opnd2;
		return result; }


			return result; }//判断运算符
	}//switch
}


float evaluate(char* S) { //对（已剔除白空格的）表达式S求值，并转换为逆波兰式RPN
	Stack<float> opnd;
	Stack<char> optr; //运算数栈、运算符栈
	optr.push('\0'); //尾哨兵'\0'也作为头哨兵首先入栈
	while (!optr.empty()) { //在运算符栈非空之前，逐个处理表达式中各字符
		if (isdigit(*S)) { //若当前字符为操作数，则
			readNumber(S, opnd);
			//读入操作数，并将其接至RPN末尾
		}
		else //若当前字符为运算符，则
			switch (orderBetween(optr.top(), *S)) {//视其不栈顶运算符之间优先级高低分别处理
			case '<': //栈顶运算符优先级更低时
				optr.push(*S);
				S++; //计算推迟，当前运算符进栈
				break;
			case '=': //优先级相等（当前运算符为右括号或者尾部哨兵'\0'）时
				optr.pop();
				S++; //脱括号并接收下一个字符
				break;
			case '>': { //栈顶运算符优先级更高时，可实现相应的计算，并将结果重新入栈
				char op = optr.pop();
				//栈顶运算符出栈并续接至RPN末尾
				if ('!' == op) { //若属于一元运算符
					float pOpnd = opnd.pop(); //只需取出一个操作数，并
					opnd.push(calcu(op, pOpnd)); //实现一元计算，结果入栈
				}
				else { //对于其它（二元）运算符
					float pOpnd2 = opnd.pop(), pOpnd1 = opnd.pop(); //取出后、前操作数
					opnd.push(calcu(pOpnd1, op, pOpnd2)); //实现二元计算，结枅入栈
				}
				break;
			}
			default: cout << "式子无效" << endl; //逢语法错误，不做处理直接退出
			}//switch
	}//while
	return opnd.pop(); //弹出并返回最后的计算结果
}//参考代码4.7 



int main() {
	char a[100];
	cout << "请输入算式:" << endl;
	cin >> a;
	cout << "算式的值为：" << evaluate(a) << endl;//手动输入算式，自动输出 

	char a1[] = "5.4-4.1";
	cout << "5.4-4.1=" << evaluate(a1) << endl;
	char a2[] = "4*6";
	cout << "4*6=" << evaluate(a2) << endl;
	char a3[] = "12/2";
	cout << "12/2=" << evaluate(a3) << endl;
	char a4[] = "6^9";
	cout << "6^9=" << evaluate(a4) << endl;//一些例子 

}