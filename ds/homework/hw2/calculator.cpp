#include "../../Stack/Stack.h"
#include <stdio.h>
#include<string.h>

#define N_OPTR 9 //���������
typedef enum { ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE } Operator; //���������
//�ӡ������ˡ������˷����׳ˡ������š������š���ʼ������ֹ��

const char pri[N_OPTR][N_OPTR] = { //��������ȵȼ� [ջ��] [��ǰ]
	/*              |-------------------- �� ǰ �� �� �� --------------------| */
	/*              +      -      *      /      ^      !      (      )      \0 */
	/* --  + */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
	/* |   - */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
	/* ջ  * */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
	/* ��  / */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
	/* ��  ^ */    '>',   '>',   '>',   '>',   '>',   '<',   '<',   '>',   '>',
	/* ��  ! */    '>',   '>',   '>',   '>',   '>',   '>',   ' ',   '>',   '>',
	/* ��  ( */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   '=',   ' ',
	/* |   ) */    ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',
	/* -- \0 */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   ' ',   '='
};//�������ϴ���4.6 

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
	case '+': return ADD; //��
	case '-': return SUB; //��
	case '*': return MUL; //��
	case '/': return DIV; //��
	case '^': return POW; //�˔�
	case '!': return FAC; //�׳�
	case '(': return L_P; //������
	case ')': return R_P; //������
	case '\0': return EOE;
	default: exit(-1); //δ֪�����
	}
}


char orderBetween(char op1, char op2) {//�Ƚ����ȼ�
	return pri[optr2rank(op1)][optr2rank(op2)];
}



float calcu(char optr, float opnd) {
	int result = opnd;
	for (int i = opnd - 1; i > 0; i--) {
		result = result * i;
	}
	return result;
}//������Ϊ������ʱ������һ�º���


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


			return result; }//�ж������
	}//switch
}


float evaluate(char* S) { //�ԣ����޳��׿ո�ģ����ʽS��ֵ����ת��Ϊ�沨��ʽRPN
	Stack<float> opnd;
	Stack<char> optr; //������ջ�������ջ
	optr.push('\0'); //β�ڱ�'\0'Ҳ��Ϊͷ�ڱ�������ջ
	while (!optr.empty()) { //�������ջ�ǿ�֮ǰ�����������ʽ�и��ַ�
		if (isdigit(*S)) { //����ǰ�ַ�Ϊ����������
			readNumber(S, opnd);
			//��������������������RPNĩβ
		}
		else //����ǰ�ַ�Ϊ���������
			switch (orderBetween(optr.top(), *S)) {//���䲻ջ�������֮�����ȼ��ߵͷֱ���
			case '<': //ջ����������ȼ�����ʱ
				optr.push(*S);
				S++; //�����Ƴ٣���ǰ�������ջ
				break;
			case '=': //���ȼ���ȣ���ǰ�����Ϊ�����Ż���β���ڱ�'\0'��ʱ
				optr.pop();
				S++; //�����Ų�������һ���ַ�
				break;
			case '>': { //ջ����������ȼ�����ʱ����ʵ����Ӧ�ļ��㣬�������������ջ
				char op = optr.pop();
				//ջ���������ջ��������RPNĩβ
				if ('!' == op) { //������һԪ�����
					float pOpnd = opnd.pop(); //ֻ��ȡ��һ������������
					opnd.push(calcu(op, pOpnd)); //ʵ��һԪ���㣬�����ջ
				}
				else { //������������Ԫ�������
					float pOpnd2 = opnd.pop(), pOpnd1 = opnd.pop(); //ȡ����ǰ������
					opnd.push(calcu(pOpnd1, op, pOpnd2)); //ʵ�ֶ�Ԫ���㣬�ᖈ��ջ
				}
				break;
			}
			default: cout << "ʽ����Ч" << endl; //���﷨���󣬲�������ֱ���˳�
			}//switch
	}//while
	return opnd.pop(); //�������������ļ�����
}//�ο�����4.7 



int main() {
	char a[100];
	cout << "��������ʽ:" << endl;
	cin >> a;
	cout << "��ʽ��ֵΪ��" << evaluate(a) << endl;//�ֶ�������ʽ���Զ���� 

	char a1[] = "5.4-4.1";
	cout << "5.4-4.1=" << evaluate(a1) << endl;
	char a2[] = "4*6";
	cout << "4*6=" << evaluate(a2) << endl;
	char a3[] = "12/2";
	cout << "12/2=" << evaluate(a3) << endl;
	char a4[] = "6^9";
	cout << "6^9=" << evaluate(a4) << endl;//һЩ���� 

}