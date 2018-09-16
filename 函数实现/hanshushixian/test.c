//#include <stdio.h>
//#include <stdarg.h>
//int my_average(int n, ...)
//{
//	va_list arg;         // typdef char*  va_list;  char* arg;
//	int i = 0;
//	int sum = 0;
//	va_start(arg, n);    //宏 arg=(char*)&n+4
//	for (i = 0; i < n; i++)
//	{
//		sum += va_arg(arg, int);    // ( *(int *)((arg += _INTSIZEOF(int)) - _INTSIZEOF(int)) )
//	}
//	va_end(arg);         //      arg=(char*)0
//	return sum / n;
//}
//int main()
//{
//	int ret = my_average(4, 4, 5, 6, 7, 8);
//	printf("平均数:%d\n", ret);
//}
//
//#include <stdio.h>
//#include <stdarg.h>
//int my_Max(int n, ...)
//{
//	va_list arg;
//	int max=*(va_start(arg, n));
//	while (n--)
//	{
//		int tmp = va_arg(arg, int);
//		if (max < tmp)
//		{
//			max = tmp;
//		}
//	}
//	return max;
//}
//int main()
//{
//	int ret = my_Max(5, 0, -3, -8, -2 ,-1);
//	printf("最大数:%d\n", ret);
//	return 0;
//}
//
//#include <stdio.h>
//#include <stdarg.h>
//void my_count(int n)
//{
//	if (n > 9)
//	{
//		my_count(n / 10);
//	}
//	putchar((n % 10) + '0');
//}
//void my_print(const char* format, ...)
//{
//	int count = 0;
//	va_list arg;
//	va_start(arg, format);
//	char* p = NULL;
//	int ch = 0;
//	int d = 0;
//	while (*format)
//	{
//		if (*format == '%')
//		{
//			format++;
//			switch (*format)
//			{
//			case 's':
//			{
//						p = va_arg(arg, char*);
//						while (*p)
//						{
//							putchar(*p);
//							p++;
//						}
//						break;
//			}
//			case 'c':
//			{
//						ch = va_arg(arg, char);
//						putchar(ch);
//						break;
//			}
//			case 'd':
//			{
//						d = va_arg(arg, char);
//						my_count(d);
//						break;
//			}
//			default:
//				putchar(*(format - 1));
//				putchar(*format);
//			}
//			format++;
//		}
//		else
//		{
//			putchar(*format);
//			format++;
//		}
//	}
//	va_end(arg);
//}
//int main()
//{
//	my_print("%s %s %c %c %c %d", "s ccc d.", "hello", 'b', 'i', 't',100);
//	printf("hello world\n");//1
//	printf("%s", "hello world\n");//2
//    printf("%s %s", "hello", "world\n");//3
//	return 0;
//}
//
//#include <stdio.h>                    //找出一个数组中两个不同的数（其余都两两相同）
//void my_find_nummber(int* p,int sz)
//{
//	int i = 0;
//	int ret = 0;
//	int flag = 0;
//	int num1 = 0;
//	int num2 = 0;
//	for (i = 0; i < sz; i++)
//	{
//		ret = ret^*(p+i);             //ret保存的是两个不同的数的异或结果
//	}
//	for (i = 0; i < 32; i++)
//	{
//		if (((ret >> i) & 1) != 1)     //ret的二进制中最低位为1的比特位flag
//			flag++;                    //这两个数中必有一个在flag位上为1，另一个为0
//		else
//			break;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		if (((*(p+i) >> flag) & 1) == 1)       //在所有的数中找第flag位为1的数
//		{
//			num1 = num1^*(p + i);              //再两两相与，得到那个不同的数
//		}
//		else                                   //在所有的数中找第flag位为0的数
//		{
//			num2 = num2^*(p + i);              //再两两相与，得到那个不同的数
//		}
//	}
//	printf("%d %d", num1, num2);
//}
//int main()
//{
//	int arr[] = {1,2,3,4,1,2,3,6};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	my_find_nummber(arr,sz);
//	return 0;
//}
//
//
//#include <stdio.h>    //喝汽水问题
//int main()
//{
//	int money = 11;
//	int danjia = 1;
//	int number = 0;
//	int tmp = 0;
//	int a = 0;
//	int b = 0;
//	number = money / danjia;
//	tmp = number;
//	while (tmp>=1)
//	{
//		b = tmp;
//		tmp = tmp / 2;             //2个空瓶换一瓶
//		number = number +tmp;
//		if (b % 2 == 1)			//余下的空瓶先收着
//			a++;
//	}
//	number = number + a / 2;        //最后把余下的空瓶数一下再看能换几瓶
//	printf("%d\n", number);
//	return 0;
//}

