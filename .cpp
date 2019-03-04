#include <cstdlib>
#include <iostream>
#include <cstddef>
#include <assert.h>

class Vector {
private:
  int* data;
  unsigned capacity;

public:
  Vector(int ap);
  ~Vector();
  &cat(int index);
  &operator [](unsigned i);
};

Vector::Vector(int ap) {
  data = new int[ap];
  capacity = ap;
};

Vector::~Vector()
{
  delete[]data;
  data = NULL;
};

int& Vector::cat(int index) {
  assert (0 <= index && index < capacity);
  return data[index];
};

int& Vector::operator [](unsigned index) {
  return data[index];
};

int main() {
    Vector V(10);
    V[0] = 1;
    std::cout << V[0];
    return 0;
}
