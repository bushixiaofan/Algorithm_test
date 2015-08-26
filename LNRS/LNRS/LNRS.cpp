// LNRS.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using namespace std;

int maxStart = 0;
int maxEnd = 0;
int maxLen = 0;

int findLNRS(char str[], int length)
{
	int i = 0;
	int j = 0;
	int count[26] = {0};
	while(str[j] != '\0'){
		if(count[str[j] - 'a'] == 0){
			count[str[j] - 'a'] += 1;
		}
		else{
			if(j - i > maxLen){
				maxLen = j - i;
				maxStart = i;
				maxEnd = j;
			}
			while(i <= j)
				count[str[i++] - 'a'] = 0;
		}
		count[str[j] - 'a'] += 1;
		j ++;
	}
	return maxLen;
}


int _tmain(int argc, _TCHAR* argv[])
{
	char str[100] = "abcdefgegcsgcasse";
	int length = 17;
	findLNRS(str, length);
	cout<<maxStart<<" "<<maxEnd<<" "<<maxLen<<endl;
	while(true){}
}

