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
  Vector& operator = (const Vector& rhs);
  &operator [](unsigned i);
  unsigned Size();
};
Vector operator + (const Vector& a, const Vector& b);

Vector::Vector(int ap) {
  data = new int[ap];
  capacity = ap;
};

Vector::~Vector()
{
  delete[]data;
  data = NULL;
};

/*int& Vector::cat(int index) { //не нужно
  assert (0 <= index && index < capacity);
  return data[index];
};*/

int& Vector::operator [](unsigned index) {
    assert (0 <= index);
    while(index >= capacity) {
        capacity *= 2;
    }
    int* mas = new int[capacity];
    for(int i = 0; i < capacity; ++i) {
        mas[i] = data[i];
    }
    data = new int[capacity];
    for(int i = 0; i < capacity; ++i) {
        data[i] = mas[i];
    }
    delete[]mas;
    return data[index];
};

Vector& Vector::operator = (const Vector& rhs) {
    this -> ~Vector();
    new(this) Vector(rhs);
    return *this;
}

unsigned Vector::Size() {
    return capacity;
}

Vector operator + (Vector& a, Vector& b){
    int n = std::max(a.Size(), b.Size());
    int m = std::min(a.Size(), b.Size());
    Vector result(n);
    for(int i = 0; i <= m; ++i) {
        result[i] = a[i] + b[i];
    }
    if(a.Size() > b.Size()) {
        for(int i = m + 1; i <= n; ++i) {
            result[i] = a[i];
        }
    }
    else if(a.Size() < b.Size()) {
        for(int i = m + 1; i <= n; ++i) {
            result[i] = b[i];
        }
    }
    return result;
}

int main() {
    Vector V1(5);
    V1[0] = 1;
    std::cout << V1[0] << " ";
    std::cout << "\n";

    for(int i = 0; i < 5; ++i)
        V1[i] = i + 1;
    for(int i = 0; i < 5; ++i)
        std::cout << V1[i] << " ";
    std::cout << "\n";

    Vector V2(10);
    for(int i = 0; i < 10; ++i)
        V2[i] = i + 1;
    for(int i = 0; i < 10; ++i)
        std::cout << V2[i] << " ";
    std::cout << "\n";

    Vector V = V1 + V2;
    for(int i = 0; i < 10; ++i)
        std::cout << V[i] << " ";
    return 0;
}
