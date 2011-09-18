/*
 * Object.cpp
 *
 *  Created on: Sep 18, 2011
 *      Author: xiaolei
 */

#include "Object.h"

namespace lang {

Object::Object() {
	// TODO Auto-generated constructor stub

}

Object::~Object() {
	// TODO Auto-generated destructor stub
}

bool Equals(Object &object) {
	return this == &object;
}

bool operator==(Object &object) {
	return Equals(object);
}

}
