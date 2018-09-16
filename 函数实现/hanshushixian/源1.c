#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
//char* my_strcpy(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while ((*dest++ = *src++))           //��Դ�ַ�������Ŀ���ַ�����Ҫ��֤Ŀ���ַ����ܷŵ���
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
	while (n--)           //��Դ�ַ�����ǰn���ַ�����Ŀ���ַ�����Ҫ��֤Ŀ���ַ����ܷŵ���
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
	while (*dest)                          // ��Դ�ַ�������Ŀ���ַ����ĺ��棬Ҫ��֤Ŀ���ַ����ܷŵ���
	{
		dest++;
	}
	while (n--)
	{
		*dest++ = *src++;
	}
	return ret;
}
int my_strncmp(const char* p, const char* q,int n)   //�Ƚ�p��q�ַ����������ȣ�����0�����p>q,����1��p<q����-1
{                                            //��ʱ��p>q����ָ�ַ������ȣ�����p��q�е�һ������ͬ�ַ���ASCII��ֵ�Ĳ�
	int ret = 0;							 //��p-q�Ĳ�ֵ����p-q>0,����1��p-q<0,����-1
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
//	while (*dest)                          // ��Դ�ַ�������Ŀ���ַ����ĺ��棬Ҫ��֤Ŀ���ַ����ܷŵ���
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
//{                                                     //��p�в�����û��q�ַ���
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

//const char* my_strchr(const char* src, int x)        //��p�ַ����в���һ���ַ��������ظ��ַ��ĵ�ַ
//{													//���û�У��򷵻ؿ�ָ��
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
//int my_strcmp(const char* p,const char* q)   //�Ƚ�p��q�ַ����������ȣ�����0�����p>q,����1��p<q����-1
//{                                            //��ʱ��p>q����ָ�ַ������ȣ�����p��q�е�һ������ͬ�ַ���ASCII��ֵ�Ĳ�
//	int ret = 0;							 //��p-q�Ĳ�ֵ����p-q>0,����1��p-q<0,����-1
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
//	void* ret = dst;                    //��src��ǰcount���ַ����Ƶ�dst��,����Ӧ��ַ�����ݸ��ǵ����������ݲ���
//	while (count--)                     //��src�е�\0Ҳ��һ����,��ӡ��������Ҫ���ڴ�
//	{                                   //�����ڴ��ص�����������
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
