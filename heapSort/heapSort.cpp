// heapSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>

using namespace std;

//inline function
inline int Parent(int i);
inline int Left(int i);
inline int Right(int i);

template<typename Type>
class Heap
{
	public:
		Heap(const vector<Type> & a_array){
			m_array.assign(a_array.begin(), a_array.end());
		}

		template<typename Compare> void sort(Compare comp);

		void printArray();
	private:
		int heapSize;//排序数组的长度

		vector<Type> m_array;//存储排序数组的vector容器

		template<typename Compare> 
			void createHeap(Compare comp);//建立堆
		
		template<typename Compare> 
			void maxHeap(Compare comp, int i, int Hsize);//最大堆或最小堆的构造函数
};

template<typename Type>
template<typename Compare>
void Heap<Type>::sort(Compare comp)
{
	createHeap(comp);
	int heapSize = m_array.size();
	for(int i = m_array.size(); i > 0; i--){
		swap(m_array[0], m_array[i-1]);
		heapSize = i -1;
		maxHeap(comp, 1, heapSize);
	}
}

template<typename Type>
template<typename Compare>
void Heap<Type>::createHeap(Compare comp)
{
	for(int i = m_array.size()/2 ; i > 0; i--){
		maxHeap(comp, i, m_array.size());
	}
}

template<typename Type>
template<typename Compare>
void Heap<Type>::maxHeap(Compare comp, int i, int heapSize)
{
	int l = Left(i);
	int r = Right(i);
	int largest = 0;
	if(l <= heapSize && comp(m_array[l - 1], m_array[i - 1]))
	  largest = l;
	else
	  largest = i;
	if(r <= heapSize && comp(m_array[r - 1], m_array[largest - 1]))
	  largest = r;
	if(largest != i){
		swap(m_array[i - 1], m_array[largest - 1]);
		maxHeap(comp, largest, heapSize);
	}
}

template<typename Type> void Heap<Type>::printArray()
{
	for(int i = 0; i < m_array.size(); i++)
		cout<<m_array[i]<<" ";
	cout<<endl;
}

int Parent(int i)
{
	return i/2;
}

int Left(int i)
{
	return 2*i;
}

int Right(int i)
{
	return 2*i + 1;
}
	
int _tmain()
{
	vector<int> array;
	for(int i = 0; i < 10; i++)
	  array.push_back(i);
	random_shuffle(array.begin(), array.end());
	Heap<int> heap(array);//排序数组vector
	heap.printArray();
	heap.sort(less<int>());
	heap.printArray();
	heap.sort(greater<int>());
	heap.printArray();

	vector<char> array2;
	for(int i = 0; i < 10; i++){
		array2.push_back(i + 65);
	}
	random_shuffle(array2.begin(), array2.end());
	Heap<char> heap2(array2);//排序字符vector
	heap2.printArray();
	heap2.sort(less<char>());
	heap2.printArray();
	heap2.sort(greater<char>());
	heap2.printArray();
	int a;
	cin>>a;
	return 0;
}
