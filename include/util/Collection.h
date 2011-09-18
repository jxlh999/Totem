/*
 * Collection.h
 *
 *  Created on: Sep 18, 2011
 *      Author: xiaolei
 */

#ifndef COLLECTION_H_
#define COLLECTION_H_

#include "Object.h"

namespace util {

class Collection: public lang::Object {
public:
	Collection();
	virtual ~Collection();

	virtual int Size() = 0;
	virtual bollean IsEmpty() = 0;
	virtual boolean Contains(Object& object) = 0;
	virtual Iterable& Iterator() = 0;
	virtual Object& ToArray() = 0;
	virtual boolean Add(Object& object) = 0;
	virtual boolean Remove(Object& object) = 0;
	virtual boolean ContainsAll(Collection& c) = 0;
	virtual boolean AddAll(Collection& c) = 0;
	virtual boolean RemoveAll(Collection& c) = 0;
	virtual bollean RetainAll(Collection& c) = 0;
	virtual void Clear() = 0;

};

}

#endif /* COLLECTION_H_ */
