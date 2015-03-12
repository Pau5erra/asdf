/*#include "LinkedList.h";

cSList::cSList (){ start = NULL; }

void cSList::Add(const int valor)
{
	node *createdNode = new node();
	createdNode->value = valor;
	createdNode->next = NULL;

	if (start != NULL)
	{
		node* nextNode = start;
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

void cSList::AddAfter(const int valor, node* nAdd)
{
	if (nAdd != NULL)
	{
		node *createdNode = new node();
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

void cSList::Del(const node* nDel)
{
	if (nDel != NULL && start != NULL)
	{
		if (nDel != start)
		{
			node* nextNode = start;
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

unsigned int cSList::Count() const
{
	unsigned int count = 0;
	node* nextNode = start;

	while (nextNode != NULL)
	{
		nextNode = nextNode->next;
		count++;
	}
	return count;
}

void cSList::delList() 
{ 
	if (start != NULL){ 
		node* tmp = start;
		while (tmp->next != NULL){
			node* tmp_2 = tmp;
			tmp = tmp->next;
			delete tmp_2;
		}
		delete tmp;
		start = NULL;
	}
}*/