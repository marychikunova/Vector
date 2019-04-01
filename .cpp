#include <cstdlib>
#include <iostream>
#include <cstddef>
#include <assert.h>

template <typename T>
class Vector {
private:
  T* data;
  unsigned capacity;

public:
  Vector(int ap);
  ~Vector();
  Vector& operator = (const Vector& rhs);
  //&operator [](unsigned i);
  T& operator [](unsigned index);
  const T& operator [](unsigned index) const;
  //const &operator [](unsigned i) const;
  const unsigned Size() const;
};
template <typename T>
Vector<T> operator + (const Vector<T>& a, const Vector<T>& b);

template <typename T>
Vector<T>::Vector(int ap) {
  data = new int[ap];
  capacity = ap;
};

template <typename T>
Vector<T>::~Vector()
{
  delete[]data;
  data = NULL;
};

template <typename T>
T& Vector<T>::operator [](unsigned index) {
    assert (0 <= index);
    bool flag = false;
    while(index >= capacity) {
        capacity *= 2;
        flag = true;
    }
    if(!flag) {
        return data[index];
    }
    int* mas = new int[capacity];
    for(int i = 0; i < capacity; ++i) {
        mas[i] = data[i];
    }
    delete [] data;
    data = mas;
    return data[index];
};

template <typename T>
const T& Vector<T>::operator [](unsigned index) const{
    if(index < 0 || index >= capacity) {
        return 0;
    }
    return data[index];
};

template <typename T>
Vector<T>& Vector<T>::operator = (const Vector<T>& rhs) {
    this -> ~Vector();
    new(this) Vector(rhs);
    return *this;
}

template <typename T>
const unsigned Vector<T>::Size() const{
    return capacity;
}

template <typename T>
Vector<T> operator + (const Vector<T>& a, const Vector<T>& b){
    int n = std::max(a.Size(), b.Size());
    int m = std::min(a.Size(), b.Size());
    Vector<T> result(n);
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
    Vector<int> V1(5);
    for(int i = 0; i < 5; ++i)
        V1[i] = i + 1;
    for(int i = 0; i < 5; ++i)
        std::cout << V1[i] << " ";
    std::cout << "\n";

    Vector<int> V2(10);
    for(int i = 0; i < 10; ++i)
        V2[i] = i + 1;
    for(int i = 0; i < 10; ++i)
        std::cout << V2[i] << " ";
    std::cout << "\n";

    Vector<int> V = V1 + V2;
    for(int i = 0; i < 10; ++i)
        std::cout << V[i] << " ";
    return 0;
}
