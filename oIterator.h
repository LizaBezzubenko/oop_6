#pragma once
#include "Exeption.h"
#include "ProductNode.h"


template<class key, class mean>
class oIterator {
	ProductNode* current;
public:
	oIterator() { current = nullptr; }
	oIterator(ProductNode* node) { current = node; }
	~oIterator() = default;
	oIterator& operator++();
	oIterator& operator++(int);
	mean& operator*() { return current->price; }
	bool operator==(oIterator);
	bool operator!=(oIterator);
};

template<class key, class mean>
oIterator<key, mean>& oIterator<key, mean>::operator++()
{
	if (current)
	{
		current = current->right;
	}
	return *this;
}

template<class key, class mean>
oIterator<key, mean>& oIterator<key, mean>::operator++(int)
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
bool oIterator<key, mean>::operator==(oIterator oIter)
{
	if (!current && !oIter.current)
	{
		return true;
	}
	if (!current || !oIter.current)
	{
		return false;
	}
	if (current->count == oIter.current->count && current->left == oIter.current->left && current->right == oIter.current->right)
	{
		return true;
	}
	return false;
}

template<class key, class mean>
bool oIterator<key, mean>::operator!=(oIterator oIter)
{
	if (!current && !oIter.current)
	{
		return false;
	}
	if ((!current && oIter.current) || (current && !oIter.current))
	{
		return true;
	}
	if (current->count == oIter.current->count && current->left == oIter.current->left && current->right == oIter.current->right)
	{
		return false;
	}
	return true;
}