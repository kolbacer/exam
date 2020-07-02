﻿/*8. Реализовать шаблон класса "круговой буфер фиксированной емкости" с
возможностью добавления элементов.При превышении заданного количества
элементов добавление очередного элемента приводит к замене первого,
второго, третьего и т.д.элементов на вновь добавляемый.Извлечение
элементов осуществляется по принципу стека.Параметрами шаблона
является тип размещаемого элемента и размер буфера.*/

#include <iostream>
#include "storage.h"
using namespace std;

template<typename T, int size>
class Buffer
{
public:
	Buffer() :m_size(size), cur(0), ar(size) {};
	~Buffer() {};

	void addElem(T val)
	{
		index = cur % m_size;
		ar[index] = val;
		++cur;
	}

	T getElem()
	{
		if (cur>0)
			return ar[index];
		else
		{
			cout << endl << "Haven't elements" << endl;
			return ar[index];
		}
	}

	bool delElem()
	{
		if (cur == 0)
		{
			cout << endl << "Haven't elements" << endl;
			return false;
		}
		else
		{
			--cur;
			if (cur != 0)
				index = (cur - 1) % m_size;
			else
				index = 0;
			return true;
		}
	}

private:
	int m_size;
	int cur;
	int index;
	Storage<T> ar;
};

bool test1()
{
	Buffer<int, 5> buf;
	buf.addElem(15);
	buf.addElem(28);

	int a, b;

	a = buf.getElem();
	buf.delElem();
	b = buf.getElem();
	
	return ((a == 28) && (b == 15));
}

bool test2()
{
	Buffer<int, 2> buf;
	buf.addElem(1);
	buf.addElem(2);
	buf.addElem(3);

	int a, b;

	a = buf.getElem();
	buf.delElem();
	b = buf.getElem();

	return ((a == 3) && (b == 2));
}

int main()
{
	cout << (test1() ? "TRUE" : "FALSE") << endl;
	cout << (test2() ? "TRUE" : "FALSE") << endl;
}