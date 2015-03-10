#include <stdio.h>

struct node
{
	int value;
	node* next;
};

class cSList
{
private:
	node* start;

public:
	cSList();

	void Add(const int);

	void AddAfter(const int, node*);

	void Del(const node*);

	unsigned int Count() const;
};