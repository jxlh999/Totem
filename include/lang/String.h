/*
 * String.h
 *
 *  Created on: Sep 18, 2011
 *      Author: xiaolei
 */

#ifndef STRING_H_
#define STRING_H_

#include <Object.h>

namespace lang {

class String: public lang::Object {
public:
	String();
	virtual ~String();
	int Length();
	bool IsEmpty();
	const char CharAt(unsigned int index);
	const char* GetBytes();
	bool EqualsIgnoreCase(String& str);
	int CompareTo(String& str);
	int CompareToIgnoreCase(String& str);
	int IndexOf(int character);
	int LastIndexOf(int character);
protected:
	String(int offset, int count, char *value);
	void GetChars(char *dst, int dst_begin);
private:
	string mString;
};

}

#endif /* STRING_H_ */
