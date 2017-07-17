#include <stdio.h>

void Print_Factorial(const int N);

int main()
{
    int N;

    scanf("%d",&N);
    Print_Factorial(N);
    return 0;
}

void Print_Factorial(const int N)
{
    if (N<0)//N<0的时候直接输出错误提示
	{
		printf("Invalid input");
		return;
	}
	else if (0==N)//N==0
	{
		printf("1");
		return;
	}
	int reverse_factorial[3000];//反序存储阶乘的数组
	int product[3000];//存储每个数字和当前reverse_factorial数组数字相乘后的结果，也是反序存储
	for (int i=0;i<3000;++i)//将两个数组初始化为0
	{
		reverse_factorial[i]=0;
		product[i]=0;
	}
	reverse_factorial[0]=1;//输入为1的情况
	int num_reverse=1;
	int num_product;
	for (int i=2;i<=N;++i)
	{
		int n=i;
		int digit;
		int j=-1;
		while (n)//逐次分离数进行计算
		{
		    ++j;//用来表示偏移量
			digit=n%10;
			int reminder=0;
            int carry_num=0;//存储下一位的进位数
			for (int i=0;i<num_reverse;++i)//此循环用来计算临时乘积数组product的值
			{
				int tmp=digit*reverse_factorial[i]+carry_num+product[i+j];//临时变量存储此次数字的乘积+下一位的进位数+临时乘积数组对应位
				carry_num=tmp/10;
				reminder=tmp%10;
				product[i+j]=reminder;
			}
			num_product=num_reverse+j;//product数组的有效位通常比reverse_factorial数组的有效位偏移j位
			if (carry_num>0)//数字和最高位的乘积有进位的情况下，product比reverse_factorial的有效位多1位
			{
				++num_product;
				product[num_product-1]=carry_num;
			}
			n/=10;
		}
		for (int i=0;i<num_product;++i)//本次乘法已完成，将product上的内容复制到reverse_factorial上
        {
            reverse_factorial[i]=product[i];
            product[i]=0;//清除product，为和下一个数相乘做准备
        }
        num_reverse=num_product;//更新reverse_factorial数组的长度
	}

	for (int i=num_reverse-1;i>=0;--i)
	{
		printf("%d",reverse_factorial[i]);
	}
}

