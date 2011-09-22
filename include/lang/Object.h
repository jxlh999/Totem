/*
 * Object.h
 *
 *  Created on: Sep 18, 2011
 *      Author: xiaolei
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include <iostream>
#include <string>
using namespace std;

namespace lang {

class Object {
public:
	Object();
	virtual ~Object();
	virtual bool Equals(Object &object) {
		return this == &object;
	}
	virtual bool operator==(Object &object) {
		return Equals(object);
	}
	virtual char* ToString() {
		return NULL;
	}
	virtual int HashCode() {
		return 0;
	}
};

}

#endif /* OBJECT_H_ */
