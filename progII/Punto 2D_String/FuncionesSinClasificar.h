
template <class TYPE> void Swap (TYPE& a, TYPE& b)
{
	TYPE tmp = a;
	a = b;
	b = tmp;
}

/*
El mateix codi per a C, sense referéncies amb punters
void SwapPunteros(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
*/