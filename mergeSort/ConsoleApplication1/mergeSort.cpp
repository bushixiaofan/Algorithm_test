// mergeSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>

using namespace std;

//定义宏
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != c.end()

template<typename Type>

//归并排序模板类
class mergeSort
{
public:
	mergeSort(const vector<Type>& a_array){
		m_array.assign(a_array.begin(), a_array.end());
	}

	template<typename Compare> void sort(int low, int high, Compare comp);
	void printArray();

private:
	int arraySize;
	vector<Type> m_array;
	template<typename Compare> void merge(int low, int mid, int high, Compare comp);//负责归并的成员函数
};

template<typename Type>
void mergeSort<Type>::printArray(){
	tr(m_array, i){
		cout<<*i<<" ";
	}
	cout<<endl;
}

template<typename Type>
template<typename Compare>
void mergeSort<Type>::sort(int low, int high, Compare comp){
	if(arraySize == 0 || low >= high)
		return;
	int mid = (low + high)/2;//从中间切分数组
	sort(low, mid, comp);
	sort(mid + 1, high, comp);
	merge(low, mid, high, comp);//合并过程
}

template<typename Type>
template<typename Compare>
void mergeSort<Type>::merge(int low, int mid, int high, Compare comp){
	vector<Type> temp;//定义vector辅助数组
	int i = low;
	int j = mid + 1;
	while(i <= mid && j <= high){
		if(comp(m_array[i], m_array[j])){
			temp.pb(m_array[i++]);
		}else{
			temp.pb(m_array[j++]);
		}
	}
	while(i <= mid)
		temp.pb(m_array[i++]);
	while(j <= high)
		temp.pb(m_array[j++]);

	//将排序后的元素整合到原vector中
	for(int k = 0; k <= high - low; k++)
		m_array[low + k] = temp[k];
}



int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> array;
	for(int i = 0; i < 10; i++)
	  array.pb(i);
	random_shuffle(array.begin(), array.end());
	mergeSort<int> MS(array);
	MS.printArray();
	MS.sort(0, 9, less<int>());
	MS.printArray();
	MS.sort(0, 9, greater<int>());
	MS.printArray();

	vector<char> array2;
	for(int i = 0; i < 10; i++){
		array2.push_back(i + 65);
	}
	random_shuffle(array2.begin(), array2.end());
	mergeSort<char> MS2(array2);
	MS2.printArray();
	MS2.sort(0, 9, less<char>());
	MS2.printArray();
	MS2.sort(0, 9, greater<char>());
	MS2.printArray();
	cout<<"Press any key to continue..."<<endl;
	char a;
	cin.get(a);
	return 0;
}

