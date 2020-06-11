#pragma once
#include <string>

struct ProductNode {
	char name[50];
	int count, date;
	double price;
	ProductNode* left;
	ProductNode* right;
	ProductNode() { left = nullptr, right = nullptr; }
	ProductNode(const char* Name, int Count, int Date, double Price) {
		count = Count;
		price = Price;
		date = Date;
		strcpy_s(name, Name);
		left = nullptr;
		right = nullptr;
	}
	~ProductNode() = default;
};