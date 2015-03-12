#include <stdio.h>
#include "Node.h"

template < class T>

class cSList
{
private:
	Node<T>* start;

public:
	cSList()
	{ start = NULL; }

	void Add(const int valor)
	{
		Node<T> *createdNode = new node;
		createdNode->value = valor;
		createdNode->next = NULL;

		if (start != NULL)
		{
			Node<T>* nextNode = start;
			while (nextNode->next != NULL)
			{
				nextNode = nextNode->next;
			}
			nextNode->next = createdNode;
		}
		else
		{
			start = createdNode;
		}
	}

	void AddAfter(const int valor, Node<T>* nAdd)
	{
		if (nAdd != NULL)
		{
			Node<T> *createdNode = new node;
			createdNode->value = valor;
			if (start != NULL)
			{
				createdNode->next = nAdd->next;
				nAdd->next = createdNode;
			}
			else
			{
				start = createdNode;
				createdNode->next = NULL;
			}
		}
	}

	void Del(const Node<T>* nDel)
	{
		if (nDel != NULL && start != NULL)
		{
			if (nDel != start)
			{
				Node<T>* nextNode = start;
				while (nextNode->next != nDel)
				{
					nextNode = nextNode->next;
				}
				nextNode->next = nDel->next;
			}
			else
			{
				start = start->next;
			}
			delete nDel;
		}
	}

	unsigned int Count() const
	{
		unsigned int count = 0;
		Node<T>* nextNode = start;

		while (nextNode != NULL)
		{
			nextNode = nextNode->next;
			count++;
		}
		return count;
	}


	void delList()
	{
		if (start != NULL){
			Node<T>* tmp = start;
			while (tmp->next != NULL){
				Node<T>* tmp_2 = tmp;
				tmp = tmp->next;
				delete tmp_2;
			}
			delete tmp;
			start = NULL;
		}
	}
};