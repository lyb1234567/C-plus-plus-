﻿#include"list.h"
#include<iostream>
#include<string>
#include<cctype>
using namespace std;
list::list()
{
	
}
list::list(  string str)
{
	lst.str_list(str);
}
void list:: append(double n)
{
	lst.push_tail(n);
}
void list::append(string s1)
{
	lst.push_tail(s1);
}
void list::remove(double n)
{
	lst.remove(n);
}
void list::remove(string s1)
{
	lst.remove(s1);
}
void list::sort()
{
	Node* current = lst.get_head();
	Node* index;
	double temp;
	if (len() == 0)
	{
		throw "The list is empty!!";
	}
	else
	{
		while (current)
		{
			index = current->next;
			while (index)
			{
				if (current->data > index->data)
				{
					temp = current->data;
					current->data = index->data;
					index->data = temp;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
}
double list::max()
{
	double max;
	Node* current = lst.get_head();
	if (len() == 0)
	{
		return -1;
	}
	else
	{
		max = current->data;
	}
	while (current)
	{
		if (max<=current->data)
		{
			max = current->data;
		}
		if (current->data == NULL)
		{
			throw "'<' not supported between instances of 'str' and 'int'";
		}
		current = current->next;
	}
	return max;
}
double list::min()
{
	double min;
	Node* current = lst.get_head();
	if (len() == 0)
	{
		return -1;
	}
	else
	{
		min = current->data;
	}
	while (current)
	{
		if (min >= current->data)
		{
			min = current->data;
		}
		if (current->data == NULL)
		{
			throw "'<' not supported between instances of 'str' and 'int'";
		}
		current = current->next;
	}
	return min;
}
list list::operator+(double n) 
{
	lst.add_number(n);
	return *this;
}
list list::operator-(double n)
{
	lst.minus_number(n);
	return *this;
}
list operator +(double n, list& lst1)
{
	return lst1 + n;
}
list operator-(double n,  list& lst1)
{
	return lst1-n;
}
ostream& operator <<(ostream& os,   list& lst1)
{
	lst1.lst.print_list();
	return os;
 }
list operator+( list& l1, list &l2) 
{
	l1.lst.merge(l2.lst);
	return l1;
}
int list::operator[](int index)
{
	
	return lst.find_nth(index + 1);
	
}
int list::index(double n)
{
	int a=lst.search(n);
	return a;
}
int list::index(string str)
{
	int a = lst.search(str);
	return a;
}
list list::operator[](const char * str)
{
	Link_list link;
	int slice= stoi(str);
	int count = 0;
	Node* current = lst.get_head();
	while (current)
	{
		if (count == slice)
		{
			lst.change_head(current);
			return *this;
		}
		count = count + 1;
		current = current->next;
	}
	Node* n = NULL;
	lst.change_head(n);
	return *this;
}