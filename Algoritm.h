#pragma once
#include <iostream>
#include "Tree.h"
#include "stack.h"
#include <locale>
#include "stack.h"
#include <string>

using namespace std;

class Algoritm {
	TreeCont<ProductNode, double> Tree;
	Stack* myStack; //указатель на объект класса
public:
	void Menu();
	void MoreThan10(ProductNode*);
	void LessThan20(ProductNode*);
	void ShowTree(ProductNode*);
	void showStack();
	void AddElement();
	void FindAnyElement();
};

void Algoritm::Menu()
{
	myStack = nullptr;
	ProductNode* node;
	fIterator<ProductNode, double> fIter;
	int num;
	do
	{
		try
		{
			cout << "1. Add Element\n";
			cout << "2. Find Element(by key)\n";
			cout << "3. Show Begin\n";
			cout << "4. Show End\n";
			cout << "5. Show Sort\n";
			cout << "6. Enough\n";
			if (!(cin >> num))
			{
				cin.clear();
				rewind(stdin);
				throw myExep("error: incorrect input");
			}
			switch (num)
			{
			case 1:
				AddElement();
				break;
			case 2:
				FindAnyElement();
				break;
			case 3:
				fIter = Tree.Begin(Tree.head);
				node = fIter.First();
				cout << "Name: " << node->name << endl;
				cout << "Quantity: " << node->count << endl;
				cout << "Storage duration: " << node->date << endl;
				cout << "Price: " << node->price << endl;
				break;
			case 4:
				fIter = Tree.End(Tree.head);
				node = fIter.First();
				cout << "Name: " << node->name << endl;
				cout << "Quantity: " << node->count << endl;
				cout << "Storage duration: " << node->date << endl;
				cout << "Price: " << node->price << endl;
				break;
			case 5:
				cout << "Sort by name:\n";
				ShowTree(Tree.head);
				break;
			}
		}
		catch (myExep exep)
		{
			cout << exep.ShowExepName() << endl;
		}
	} while (num != 6);
	cout << "1. Condition: stock days more than 10.\n";
	cout << "2. Condition: push all prices less than 20 onto the stack.\n";
	do
	{
		while (!(cin >> num))
		{
			cin.clear();
			rewind(stdin);
		}
	} while (num < 1 || num > 2);
	switch (num)
	{
	case 1:
		MoreThan10(Tree.head);
		system("pause");
		break;
	case 2:
		LessThan20(Tree.head);
		showStack();
		system("pause");
		break;
	}

}

void Algoritm::MoreThan10(ProductNode* head)
{
	if (head)
	{
		MoreThan10(head->left);
		if (head->date <= 10)
		{
			cout << "This element does not satisfy the condition:\n";
			cout << head->count << endl;
			cout << head->date << endl;
			cout << head->name << endl;
			cout << head->price << endl;
		}
		MoreThan10(head->right);
	}
}

void Algoritm::LessThan20(ProductNode* head)
{
	if (head)
	{
		LessThan20(head->left);
		if (head->price < 20)
		{
			myStack->push(&myStack, head);
		}
		LessThan20(head->right);
	}

}

void Algoritm::showStack()
{
	while (myStack)
	{
		myStack->pop(&myStack);
	}
}

void Algoritm::AddElement()
{
	ProductNode* objProd = new ProductNode;
	cout << "Enter name: ";
	cin >> objProd->name;
	cout << "Enter count: ";
	while (!(cin >> objProd->count))
	{
		cin.clear();
		rewind(stdin);
	}
	cout << "Enter storage duration: ";
	while (!(cin >> objProd->date))
	{
		cin.clear();
		rewind(stdin);
	}
	cout << "Enter price: ";
	while (!(cin >> objProd->price))
	{
		cin.clear();
		rewind(stdin);
	}
	Tree.head = Tree.Insert(Tree.head, objProd);
}

void Algoritm::FindAnyElement()
{
	ProductNode* objProd = new ProductNode;
	cout << "Enter name: ";
	cin >> objProd->name;
	if (!Tree.Find(Tree.head, objProd))
	{
		cout << "error:nullptr\n";
	}
}

void Algoritm::ShowTree(ProductNode* head)
{
	if (head)
	{
		ShowTree(head->left);
		cout << endl;
		cout << "Name: " << head->name << endl;
		cout << "Quantity: " << head->count << endl;
		cout << "Storage duration: " << head->date << endl;
		cout << "Price: " << head->price << endl;
		ShowTree(head->right);
	}
}