#pragma once

#include <voe/defs.hpp>

#include <algorithm>

namespace voe {

class Object {
private:
  String name;

protected:
  Object *parent = nullptr;
  Vec<Object *> children;

public:
  Object() {}
  virtual ~Object() {};

  void set_name(const String &name) { this->name = name; }
  const String &get_name() const { return name; }

  void add_child(Object *obj) {
    obj->parent = this;
    children.push_back(obj);
  }

  void remove_child(Object *obj) {
    children.erase(std::remove(children.begin(), children.end(), obj),
                   children.end());
    obj->parent = nullptr;
  }
};

} // namespace voe
