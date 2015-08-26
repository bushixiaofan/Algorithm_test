#include"stdafx.h"
#include<iostream>
#include<string>

using namespace std;

#define MAXCH 1000

char str[MAXCH], *posStr[MAXCH]; 
int maxStart;
int maxLen;

int comLen(const char *p, const char *q)
{
	int len = 0;
	while(*p && (*p++ == *q++))
		len++;
	return len;
}

int posCmp(const void *p, const void *q)
{
	return strcmp( *(char* const *)p, *(char* const*)q );
}

int LRS(char str[], char *posStr[], int length)
{
	maxLen = 0;
	maxStart = -1;
	qsort(posStr, length, sizeof(char*), posCmp);
	for(int i = 0; i < length -1; i ++)
	{
		int len = comLen(posStr[i], posStr[i + 1]);
		if(maxLen < len){
			maxLen = len;
			maxStart = i;
		}
	}
	return maxLen;
}

int main()
{
	cin.getline(str, MAXCH);
	int n;
	for(n = 0; str[n] != '\0'; n ++)
		posStr[n] = &str[n];
	LRS(str, posStr, n);
	cout<<maxStart<<" "<<maxLen<<endl;
	for(int i = 0; i < maxLen; i ++)
		cout<<posStr[maxStart][i];
	cout<<endl;
	while(true){}
}


//enum status{kvalid = 0, kinvalid};
//int g_nstatus = kvalid;
//
//int strtoint(char * str)
//{
//	g_nstatus = kinvalid;
//	int num = 0;
//
//	if(str != null){
//		const char* digit = str;
//		bool minus = false;
//
//		if(str[0] == '+'){
//			digit ++;
//		}
//		else if(str[0] == '-'){
//			digit --;
//			minus = true;
//		}
//
//		while(*digit++ != '\0'){
//			if(*digit > '0' && *digit < '9'){
//				num += num * 10 + *digit - '0';
//			}
//			else{
//				num = 0;
//				break;
//			}
//		}
//		if(*digit == '\0'){
//			g_nstatus = kvalid;
//			if(minus)
//				num = 0 - num;
//		}
//	}
//	return num;
//}

