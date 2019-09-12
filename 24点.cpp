//24pointv2.0.c
#include <stdio.h>
#include <math.h>
#include <string.h>
char* write(int* a, int* b, int c);
char* cases(char* a, char b, int c);
double cal(double a, double b, int i);
char* cases(char* a, char b, int c)
{
	int  i;
	char d;
	switch (c)
	{
	case 1:
	{
		sprintf(a, "+%c)", b);
		for (i = (strlen(a) - 1); i >= 0; i--)
		{
			a[i + 1] = a[i];
			a[0] = '(';
			a[i + 2] = '\0';
		}
		return a;
		break;
	}
	case 2:
	{
		sprintf(a, "-%c)", b);
		for (i = (strlen(a) - 1); i >= 0; i--)
		{
			a[i + 1] = a[i];
			a[0] = '(';
			a[i + 2] = '\0';
		}
		return a;
		break;
	}
	case 3:
	{
		sprintf(a, "*%c", b);
		return a;
		break;
	}
	case 4:
	{
		sprintf(a, "/%c", b);
		return a;
		break;
	}
	case 5:
	{
		sprintf(a, ")");
		char cc[20];
		cc[0] = '(';
		cc[1] = b;
		cc[2] = '-';
		cc[3] = '\0';
		strcpy(cc, a);
		a = cc;
		return a;
		break;
	}
	case 6:
	{
		char cc[20];
		cc[0] = b;
		cc[1] = '/';
		cc[2] = '\0';
		strcpy(cc, a);
		a = cc;
		return a;
		break;
	}
	default:
	{
		printf_s("error at cases");
		break;
	}
	}
}
char* write(int* a, int* b, int c)
{
	int i;
	char ch[100];
	char output[100];
	for (i = 0; i <= (c - 1); i++)
		{
			ch[i] = '0' + a[i];
		}
	output[0] = ch[0];
	output[1] = '\0';
	for (i = 1; i <= (c - 1); i++)
	{
		 cases(output, ch[i], b[i - 1]);
	}
	return output;
}
double cal(double a, double b, int i)//执行计算过程
{
	switch (i)
	{
	case 1:return(a + b);
	case 2:return(a - b);
	case 3:return(a * b);
	case 4:return(a / b);
	case 5:return(b - a);
	case 6:return(b / a);
	default:return(114514);
	}
}
int main(void)
{
	int input[3][4];//一共三类计算顺序，按从左到右计算，乘除法不优先
	double output[3][4];
	char* writeout;//输出的表达式
	int i,j,n,a,b;
	int k[3];
	for (i = 3; i >= 0; i--)
	{
		scanf_s("%d", &input[0][i]);//读取输入 //输入阶段无问题
	}
	i = 0;
	input[1][0] = input[0][3];//定义了三类运算顺序。。不知道有无不这么野蛮的方式
	input[1][1] = input[0][1];//分别是4321，1324，3214
	input[1][2] = input[0][2];
	input[1][3] = input[0][0];
	input[2][0] = input[0][1];
	input[2][1] = input[0][2];
	input[2][2] = input[0][3];
	input[2][3] = input[0][0];
	n = 1;
	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 3; j++)
		{
			output[i][j] = input[i][j];
		}
	}
	for (i = 0; i <= 2; i++)//三种排列顺序
	{
		for (k[2] = 1; k[2] <= 6; k[2]++)//第一个运算符
		{
			for (k[1] = 1; k[1] <= 6; k[1]++)//第二个运算符
			{
				for (k[0] = 1; k[0] <= 6; k[0]++)//第三个运算符
				{
					for (n = 1; n <= 3; n++)//计算过程
					{
						output[i][n] = cal(output[i][n - 1], output[i][n], k[n - 1]);
					}
					if(fabs(output[i][3] - 24) < 0.001)//验证结果是否符合
					{
						printf_s("%d %d %d in %d\n", k[0], k[1], k[2],i);
						printf_s("%s", write(k, input[i], 3));
					}
					for (a = 0; a <= 2; a++)//重置output
					{
						for (b = 0; b <= 3; b++)
						{
							output[a][b] = input[a][b];
						}
					}
				}
			}
		}
	}
	getchar();
	getchar();
	return 0;
}