#include <iostream>

template <typename T>
class weak_ptr;

template <typename T> class shared_ptr
{
public:
    friend class weak_ptr<T>;
    shared_ptr();
    shared_ptr(T* obj);
    shared_ptr(const shared_ptr<T>& right);
    ~shared_ptr();
    shared_ptr<T>&  operator=(shared_ptr<T>& right);
    operator bool() const;
    T& operator*();
    int getCount() const;
private:
    T* m_obj = nullptr;
    int* m_count = nullptr;
};

template <typename T>
shared_ptr<T>::shared_ptr()
{
    m_count = new int(1);
    m_obj = new T;
}

template <typename T>
shared_ptr<T>::~shared_ptr()
{
    if (--(*m_count) == 0)
    {
        delete m_count;
        delete m_obj;
    }
}

template <typename T>
shared_ptr<T>::shared_ptr(T* obj)
{
    m_count = new int(1);
    m_obj = obj;
}

template <typename T>
shared_ptr<T>::shared_ptr(const shared_ptr<T>& right)
{
    m_count = right.m_count;
    ++(*m_count);
    m_obj = right.m_obj;
}

template <typename T>
shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr<T>& right)
{
    m_count = right.m_count;
    ++(*m_count);
    m_obj = right.m_obj;
    return *this;
}

template <typename T>
shared_ptr<T>::operator bool() const
{
    return m_obj != nullptr && m_count != nullptr;
}

template <typename T>
T& shared_ptr<T>::operator*()
{
    return *m_obj;
}

template <typename T>
int shared_ptr<T>::getCount() const
{
    return *m_count;
}

template <typename T>
class weak_ptr
{
public:
    weak_ptr();
    weak_ptr(T* obj);
    weak_ptr(const weak_ptr<T>& right);
    ~weak_ptr();
    void operator=(weak_ptr<T>& right);
    void operator=(shared_ptr<T>& right);
    operator bool() const;
    T& operator*();
private:
    T* m_obj = nullptr;
};

template <typename T>
weak_ptr<T>::weak_ptr()
{}

template <typename T>
weak_ptr<T>::~weak_ptr()
{
    delete m_obj;
}

template <typename T>
weak_ptr<T>::weak_ptr(T* obj)
{
    m_obj = obj;
}

template <typename T>
weak_ptr<T>::weak_ptr(const weak_ptr<T>& right)
{
    m_obj = right.m_obj;
}

template <typename T>
void weak_ptr<T>::operator=(weak_ptr<T>& right)
{
    m_obj = right.m_obj;
}

template <typename T>
void weak_ptr<T>::operator=(shared_ptr<T>& right)
{
    m_obj = right.m_obj;
}

template <typename T>
weak_ptr<T>::operator bool() const
{
    return m_obj != nullptr;
}

template <typename T>
T& weak_ptr<T>::operator*()
{
    return *m_obj;
}