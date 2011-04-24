#include "Object.h"
namespace lang {
  
  Object::Object() {
    
  }
  
  Object::~Object() {
    
  }
  
  bool Equals(Object &object) {
    return this == &object;
  }

  bool operator==(Object &object) {
    return Equals(object);
  }

}

