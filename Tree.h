#pragma once
#include "fIterdtor.h"
#include "oIterator.h"
#include "ProductNode.h"
#include "Exeption.h"

template<class key, class mean>
class TreeCont {
public:
	ProductNode* head;
	TreeCont() { head = nullptr; }
	~TreeCont() = default;
	ProductNode* Insert(ProductNode*, ProductNode*); // добавление элемента
	fIterator<key, mean> Begin(ProductNode*); // получение итератора на первый( самый маленький) элемент 
	fIterator<key, mean> End(ProductNode*); // получение итератора на последний( самый большой) элемент 
	bool Find(ProductNode* , ProductNode*); // получение итератора на заданный элемент  
	mean operator[] (const char*); // оператор произвольного доступа по КЛЮЧУ  
};

template<class key, class mean>
ProductNode* TreeCont<key, mean>::Insert(ProductNode* head, ProductNode* node)
{
	if (!head)
	{
		head = new ProductNode;
		head = node;
	}
	else if (strcmp(node->name, head->name) < 0)
	{
		head->left = this->Insert(head->left, node);
	}
	else if (strcmp(node->name, head->name) > 0)
	{
		head->right = this->Insert(head->right, node);
	}
	else
	{
		throw myExep("error: Such a key is already there");
	}
	return head;
}


template<class key, class mean>
fIterator<key, mean> TreeCont<key, mean>::Begin(ProductNode* head)
{
	while (head && head->left)
	{
		head = head->left;
	}
	fIterator<key, mean> fIter(head);
	if (!fIter.First())
	{
		throw myExep("error: nullptr");
	}
	return fIter;
}

template<class key, class mean>
fIterator<key, mean> TreeCont<key, mean>::End(ProductNode* head)
{
	while (head && head->right)
	{
		head = head->right;
	}
	fIterator<key, mean> fIter(head);
	if (!fIter.First())
	{
		throw myExep("error: nullptr");
	}
	return fIter;
}

template<class key, class mean>
bool TreeCont<key, mean>::Find(ProductNode* head, ProductNode* node)
{
	static bool flag = false;
	if (head)
	{
		flag = false;
		if (strcmp(node->name, head->name) < 0)
		{
			return Find(head->left, node);
		}
		else if (strcmp(node->name, head->name) > 0)
		{
			return Find(head->right, node);
		}
		else
		{
			flag = true;
			std::cout << "Name: " << head->name << std::endl;
			std::cout << "Quantity: " << head->count << std::endl;
			std::cout << "Storage duration: " << head->date << std::endl;
			std::cout << "Price: " << head->price << std::endl;
		}
	}
	return flag;
}

template<class key, class mean>
mean TreeCont<key, mean>::operator[](const char* str)
{
	ProductNode* node = new ProductNode;
	strcpy_s(node->name, str);
	fIterator<key, mean> fIter = Find(node);
	if (!fIter.First())
	{
		throw myExep("error: nullptr");
	}
	delete node;
	return fIter.Second();
}