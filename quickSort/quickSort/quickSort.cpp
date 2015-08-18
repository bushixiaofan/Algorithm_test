// quickSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != c.end()

using namespace std;

//快速排序模板类
template<typename Type>
class quickSort
{
public:
	quickSort(const vector<Type> & a_array){
		m_array.assign(all(a_array));
	}

	template<typename Compare> void sort(int low, int high, Compare comp);

	void printArray();//查看vector元素
private:
	vector<Type> m_array;

	template<typename Compare> int partion(int low, int high, Compare comp);//vector数组的分割函数
};

template<typename Type>
template<typename Compare>
void quickSort<Type>::sort(int low, int high, Compare comp){
	int q;
	if(high > low){
		q = partion(low, high, comp);//以q为中心点分割
		sort(low, q - 1, comp);
		sort(q + 1, high, comp);
	}
}

template<typename Type>
void quickSort<Type>::printArray(){
	tr(m_array, i){
		cout<<*i<<" ";
	}
	cout<<endl;
}

template<typename Type>
template<typename Compare>
int quickSort<Type>::partion(int low, int high, Compare comp){
	Type x = m_array[high];
	int i = low - 1;//从最后一个元素开始，i保存比其小的元素在数组中位置，j从最后往前遍历
	for(int j = low; j < high; j++){
		if(comp(m_array[j], x)){
			i++;
			swap(m_array[i], m_array[j]);
		}
	}
	swap(m_array[i+1], m_array[high]);
	return i + 1;
}

int _tmain()
{
	vector<int> array;
	for(int i = 0; i < 10; i++)
	  array.pb(i);
	random_shuffle(array.begin(), array.end());
	quickSort<int> QS(array);
	QS.printArray();
	QS.sort(0, 9, less<int>());
	QS.printArray();
	QS.sort(0, 9, greater<int>());
	QS.printArray();

	vector<char> array2;
	for(int i = 0; i < 10; i++){
		array2.push_back(i + 65);
	}
	random_shuffle(array2.begin(), array2.end());
	quickSort<char> QS2(array2);
	QS2.printArray();
	QS2.sort(0, 9, less<char>());
	QS2.printArray();
	QS2.sort(0, 9, greater<char>());
	QS2.printArray();
	cout<<"Press any key to continue..."<<endl;
	char a;
	cin.get(a);
	return 0;
}

