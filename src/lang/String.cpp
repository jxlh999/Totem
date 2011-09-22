/*
 * String.cpp
 *
 *  Created on: Sep 18, 2011
 *      Author: xiaolei
 */

#include <String.h>

namespace lang {

String::String() {
	// TODO Auto-generated constructor stub
	mString = "";
}

int String::Length() {
	return mString.size();
}

bool String::IsEmpty() {
	return mString.size() == 0;
}

const char String::CharAt(unsigned int index) {
	if(index >= 0 && index < mString.size()) {
		return mString.at(index);
	} else {
		return NULL;
	}
}

const char* String::GetBytes() {
	return mString.c_str();
}

bool String::EqualsIgnoreCase(String& str) {
	return false;
}

int String::CompareTo(String& str) {
	return 0;
}

int String::CompareToIgnoreCase(String& str) {
	return 0;
}

int String::IndexOf(int character) {
	return mString.find(character, 0);
}

int String::LastIndexOf(int character) {
	return mString.rfind(character, 0);
}

String::~String() {
	// TODO Auto-generated destructor stub

}

}
