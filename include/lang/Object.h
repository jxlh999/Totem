/*
 * Object.h
 *
 *  Created on: Sep 18, 2011
 *      Author: xiaolei
 */

#ifndef OBJECT_H_
#define OBJECT_H_

namespace lang {

class Object {
public:
	Object();
	virtual ~Object();
	virtual bool Equals(Object &object);
	virtual bool operator==(Object &object);
	virtual char* ToString();
	virtual int HashCode();
};

}

#endif /* OBJECT_H_ */
