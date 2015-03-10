#include <string.h>
#include <stdarg.h>
#define TMP_STRING_SIZE 4096

#ifndef __cSTRING__
#define __cSTRING__

class cString
{

private:
	char* cadena;
	int tamany;
public:

	////////////////
	//Constructors//
	////////////////

	cString();
	
	cString(const cString&);

	cString(const char* format, ...);

	///////////
	//Métodes//
	//////////

	void Alloc(int);

	void Clear();

	int Len() const;

	int Capacity() const;

	char* GetString() const;

	/////////////
	//Operadors//
	/////////////

	bool operator== (const cString&) const;

	bool operator== (const char*) const;

	bool operator!= (const cString&) const;

	bool operator!= (const char*) const;
	
	cString operator= (const char*);

	cString operator= (const cString&);

	cString operator+= (const char*);

	cString operator+= (const cString&);

	//////////////
	//Destructor//
	//////////////

	~cString();
};

#endif //__cSTRING__