#pragma once
#include "Exeption.h"
#include "ProductNode.h"

template<class key, class mean>
class fIterator {
	ProductNode* current;
public:
	fIterator() { current = nullptr; }
	fIterator(ProductNode* node) { current = node; }
	~fIterator() = default;
	fIterator& operator++(); // ++�
	fIterator& operator++(int); // �++ 
	mean& operator*() { return current->price; } // ������������� - ��������� �������� 
	bool operator==(fIterator);
	bool operator!=(fIterator);
	ProductNode* First() { return current; } // ��������� �����
	mean& Second() { return current->price; } // ��������� ��������
};

template<class key, class mean>
fIterator<key, mean>& fIterator<key, mean>::operator++()
{
	if (current)
	{
		current = current->right;
	}
	return *this;
}

template<class key, class mean>
fIterator<key, mean>& fIterator<key, mean>::operator++(int)
{
	if (current)
	{
		fIterator<key, mean> fIter;
		fIter.current = current;
		current = current->right;
		return fIter;
	}
	return *this;
}

template<class key, class mean>
bool fIterator<key, mean>::operator==(fIterator fIter)
{
	if (!current && !fIter.current)
	{
		return true;
	}
	if (!current || !fIter.current)
	{
		return false;
	}
	if (current->count == fIter.current->count && current->left == fIter.current->left && current->right == fIter.current->right)
	{
		return true;
	}
	return false;
}

template<class key, class mean>
bool fIterator<key, mean>::operator!=(fIterator fIter)
{
	if (!current && !fIter.current)
	{
		return false;
	}
	if ((!current && fIter.current) || (current && !fIter.current))
	{
		return true;
	}
	if (current->count == fIter.current->count && current->left == fIter.current->left && current->right == fIter.current->right)
	{
		return false;
	}
	return true;
}