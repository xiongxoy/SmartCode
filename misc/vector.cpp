#include <cstdio>
template <typename T>
class MyVector<T> {
  public:
  MyVector<T>():m_capacity(5), m_size(0) {
    m_data = _allocate_memory(m_capacity);
  }
  MyVector<T>(int capacity):m_capacity(capacity), m_size(0) {
    m_data = _allocate_memory(m_capacity);
  }
  T back() {
    return m_data[m_size-1];
  }
  void pop_back() {
    m_size--;
  }
  void push_back( const T d ) {
    if (m_size < m_capacity) {
      m_data[m_size++] = d; // 真的可以用copy constructor 么？
      return;
    }
    // 扩充容量
    m_capacity *= 2;
    T *tmp = _allocate_memory(n);
    // 转移数据
    for (int i = 0; i < m_size; i++) {
      tmp[i] = m_data[i]
    }
    delete [] m_data;  // 删除旧数据
    m_data = tmp;
    m_size++;
    m_data[m_size-1] = d;
  }
  private:
  T * _allocate_memory(int n) {
    T * mem = new T[n];
    if (NULL == T)
      std::cerr << "Not Enough Memory\n";
    return mem;
  }
  int  m_capacity = 5;
  int  m_size     = 0;
  T   *m_data     = new T[5];
};


int main(int argc, const char *argv[])
{

  return 0;
}
