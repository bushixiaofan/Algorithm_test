// hellSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

//�����
#define sz(a) int((a).size())
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define tr(c, i) for(auto i = (c).begin(); i != (c).end(); i++)

//ϣ������ģ����
template<typename Type>
class hellSort
{
public:
	hellSort(const vector<Type>& a_array){
		m_array.assign(all(a_array));
	}
	//�ϸ��ն���д������Ӧ�ò���������̣�
	template<typename Compare> void sort1(Compare comp);
	//ֱ�Ӳ�������ķ���
	template<typename Compare> void sort2(Compare comp);
	//��ӡvector�е�����
	void printArray();

private:
	vector<Type> m_array;
	template<typename Compare> void insertSort(int ini, int gap, Compare comp);
};

//ϣ�����򻮷�������
template<typename Type>
template<typename Compare>
void hellSort<Type>::sort1(Compare comp){
	int gap;
	for(gap = sz(m_array)/2; gap > 0; gap /= 2){
		for(int i = 0; i < gap; i++){
			insertSort(i, gap, comp);
		}
	}
}

//�������е��ò�������
template<typename Type>
template<typename Compare>
void hellSort<Type>::insertSort(int ini, int gap, Compare comp){
	for(int i = ini + gap; i < sz(m_array); i += gap){
		int j = i - gap;
		if(comp(m_array[i], m_array[j])){
			Type temp = m_array[i];
			while(j >= 0 && comp(temp, m_array[j])){
				m_array[j + gap] = m_array[j];
				j -= gap;
			}
			m_array[j + gap] = temp;
		}
	}
}

//ֱ�Ӳ�������ķ���
template<typename Type>
template<typename Compare>
void hellSort<Type>::sort2(Compare comp){
	int i, j, gap;
	//ÿ�δ������gap��Ԫ�ؿ�ʼ��ÿ��Ԫ�����Լ����ڵ����ݽ���ֱ�Ӳ�������
	for(gap = sz(m_array)/2; gap > 0; gap /= 2){
		for(i = gap; i < sz(m_array); i++){
			for(j = i - gap; j >= 0 && comp(m_array[j + gap], m_array[j]); j -= gap){
				swap(m_array[j + gap], m_array[j]);//����������������
			}
		}
	}
}

template<typename Type>
void hellSort<Type>::printArray(){
	tr(m_array, i)
		cout<<*i<<" ";
	cout<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> array;
	for(int i = 0; i < 10; i++)
	  array.pb(i);
	random_shuffle(array.begin(), array.end());
	hellSort<int> HS(array);
	HS.printArray();
	HS.sort1(less<int>());
	HS.printArray();
	HS.sort2(greater<int>());
	HS.printArray();

	vector<char> array2;
	for(int i = 0; i < 10; i++){
		array2.push_back(i + 65);
	}
	random_shuffle(array2.begin(), array2.end());
	hellSort<char> HS2(array2);
	HS2.printArray();
	HS2.sort1(less<char>());
	HS2.printArray();
	HS2.sort2(greater<char>());
	HS2.printArray();
	cout<<"Press any key to continue..."<<endl;
	char a;
	cin.get(a);
	return 0;
}

