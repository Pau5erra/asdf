#include "String.h"
#include <stdio.h>

cString::cString()
{
	Alloc(1);
	strcpy_s(cadena, tamany, "");
}

cString::cString(const cString& cRecieved)
{
	Alloc(cRecieved.Len() + 1);
	strcpy_s(cadena, tamany, cRecieved.GetString());
}

cString::cString(const char* format, ...)
{
	tamany = 0;

	if (format != NULL)
	{
		static char tmp[TMP_STRING_SIZE];
		static va_list ap;

		//Construir la cadena a partir dels arguments variables
		va_start(ap, format);
		int res = vsprintf_s(tmp, TMP_STRING_SIZE, format, ap);
		va_end(ap);

		if (res > 0)
		{
			Alloc(res + 1);
			strcpy_s(cadena, tamany, tmp);
		}
	}
	if (tamany == 0)
	{
		Alloc(1);
		Clear();
	}
}


///////////
//Métodes//
//////////

void cString::Alloc(int res)
{
	tamany = res;
	cadena = new char[tamany];
}

void cString::Clear()
{
	if (cadena != NULL)
	{
		delete[] cadena;
		Alloc(1);
		strcpy_s(cadena, tamany, "");
	}
}

int cString::Len() const
{
	return strlen(cadena);
}

int cString::Capacity() const
{
	return tamany;
}

char* cString::GetString() const
{
	return cadena;
}




/////////////
//Operadors//
/////////////

bool cString::operator== (const cString& string) const
{
	return strcmp(string.cadena, cadena) == 0;
}

bool cString::operator== (const char* string) const
{
	if (string != NULL)
	{
		return strcmp(string, cadena) == 0;
	}
	return false;
}

bool cString::operator!= (const cString& string) const
{
	return strcmp(string.cadena, cadena) != 0;
}

bool cString::operator!= (const char* string) const
{
	if (string != NULL)
	{
		return strcmp(string, cadena) != 0;
	}
	return false;
}


cString cString::operator= (const char* string)
{
	if (string != NULL)
	{
		if (strlen(string) + 1 > tamany)
		{
			delete[] cadena;
			Alloc(strlen(string) + 1);	
		}
		strcpy_s(cadena, tamany, string);
	}
	else
	{
		Clear();
	}
	return(*this);
}

cString cString::operator= (const cString& string)
{
	if (string.cadena != NULL)
	{
		if (string.Len() + 1 > tamany)
		{
			delete[] cadena;
			Alloc(string.Len() + 1);
		}
		strcpy_s(cadena, tamany, string.cadena);
	}
	else
	{
		Clear();
	}

	return(*this);
}

cString cString::operator+= (const char* string)
{
	if (string != NULL)
	{
		cString tmp(*this);
		delete[] cadena;
		Alloc(strlen(string) + tamany);
		strcpy_s(cadena, tmp.tamany, tmp.cadena);
		strcat_s(cadena, tamany, string);
	}
	return(*this);
}

cString cString::operator+= (const cString& string)
{
	if (string.cadena != NULL)
	{
		cString tmp(*this);
		delete[] cadena;
		Alloc(strlen(string.cadena) + tamany);
		strcpy_s(cadena, tmp.tamany, tmp.cadena);
		strcat_s(cadena, tamany, string.cadena);
	}
	return(*this);
}

//////////////
//Destructor//
//////////////

cString::~cString()
{
	if (cadena)
	{
		delete[] cadena;
	}
}