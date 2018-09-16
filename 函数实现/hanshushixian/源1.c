#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
//char* my_strcpy(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while ((*dest++ = *src++))           //把源字符串赋给目标字符串，要保证目标字符串能放得下
//	{
//		;
//	}
//	return ret;
//}
char* my_strncpy(char* dest, const char* src,int n)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (n--)           //把源字符串的前n个字符赋给目标字符串，要保证目标字符串能放得下
	{
		*dest++=*src++;
	}
	return ret;
}
char* my_strncat(char *dest, const char* src,int n)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest)                          // 把源字符串赋在目标字符串的后面，要保证目标字符串能放得下
	{
		dest++;
	}
	while (n--)
	{
		*dest++ = *src++;
	}
	return ret;
}
int my_strncmp(const char* p, const char* q,int n)   //比较p和q字符串，如果相等，返回0；如果p>q,返回1；p<q返回-1
{                                            //此时的p>q不是指字符串长度，而是p和q中第一个不相同字符的ASCII码值的差
	int ret = 0;							 //即p-q的差值，即p-q>0,返回1，p-q<0,返回-1
	while (n--)
	{
		if (((ret = *(unsigned char*)p - *(unsigned char*)q) && *q) == 0)
		{
			++p;
			++q;
		}
	}
	if (ret < 0)
	{
		ret = -1;
	}
	else if (ret>0)
	{
		ret = 1;
	}
	return ret;
}
int main()
{
	char p[20] = "abcd";
	char q[20] = "abcde";
	int ret = my_strncmp(p,q,5);
	printf("%d\n", ret);
}
//char* my_strcat(char *dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest)                          // 把源字符串赋在目标字符串的后面，要保证目标字符串能放得下
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char p[20] = "abcde";
//	char q[10] = "abcde";
//	char* ret = strcat(p, q);
//	printf("%s", ret);
//	return 0;
//}
//char* my_strstr(const char* str, const char* substr)   
//{                                                     //在p中查找有没有q字符串
//	assert(str != NULL);
//	assert(substr != NULL);
//	const char*s1;
//	const char*s2;
//	const char* cur = str;
//	if (*substr == '\0')
//	{
//		return (char*)str;
//	}
//	while (*cur)
//	{
//		s1 = cur;
//		s2 = substr;
//		while (*s1&&*s2 && (*s1 == *s2))
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return (char*)cur;
//		}
//		cur++;
//	}
//	return NULL;
//}

//const char* my_strchr(const char* src, int x)        //在p字符串中查找一个字符，并返回该字符的地址
//{													//如果没有，则返回空指针
//	assert(src!=NULL);
//	while (*src)
//	{
//		if (*src == x)
//		{
//			return src;
//		}
//		src++;
//	}
//	return NULL;
//}
//int my_strcmp(const char* p,const char* q)   //比较p和q字符串，如果相等，返回0；如果p>q,返回1；p<q返回-1
//{                                            //此时的p>q不是指字符串长度，而是p和q中第一个不相同字符的ASCII码值的差
//	int ret = 0;							 //即p-q的差值，即p-q>0,返回1，p-q<0,返回-1
//	while (!(ret = *(unsigned char*)p - *(unsigned char*)q)&&*q)
//	{
//		++p, ++q;
//	}
//	if (ret < 0)
//	{
//		ret = -1;
//	}
//	else if (ret>0)
//	{
//		ret = 1;
//	}
//	return ret;
//}
//void* my_memcpy(void* dst, const void* src, size_t count)
//{
//	void* ret = dst;                    //把src中前count个字符复制到dst中,将对应地址的内容覆盖掉，其余内容不变
//	while (count--)                     //对src中的\0也会一起复制,打印不出来，要看内存
//	{                                   //出现内存重叠，结果会错误
//		*(char*)dst = *(char*)src;      //
//		dst = (char*)dst + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//
//void* my_memmove(void* dst, const void* src, size_t count)
//{
//	void* ret = dst;   
//	if (dst <= src || (char*)dst >= ((char*)src + count))
//	{
//		while (count--)
//		{
//			*(char*)dst = *(char*)src;
//			dst = (char*)dst + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		dst = (char*)dst + count - 1;
//		src = (char*)src + count - 1;
//		while (count--)
//		{
//			*(char*)dst = *(char*)src;
//			dst = (char*)dst - 1;
//			src = (char*)src - 1;
//		}
//	}
//	return ret;
//}
//int main()
//{
//	char p[20] = "abcdefghjk";
//	char q[10] = "bcde\0fgh";
//    my_memmove(p+2,q,5);                     
//	printf("%s\n", p);
//	return 0;
//}
