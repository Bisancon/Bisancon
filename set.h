#pragma once

#include <iostream>
#include <vector>
#include <initializer_list>

template <typename T>
class Set
{
public:
    Set(const std::initializer_list<T> &list);
    Set(const Set<T> &other);
    ~Set();

    void add(const T &value);
    void del(const T &value);

    typename std::vector<T>::iterator find(const T &value);

    size_t size();
    bool empty();

private:
    std::vector<T> data;
}

template <typename T>
Set<T>::Set(const std::initializer_list<T> &list)
{
    for (auto element : list)
    {
        this->add(element);
    }
}

template <typename T>
void Set<T>::add(const T &value)
{
    for (auto element : this->data)
    {
        if (element == value)
        {
            return;
        }
    }
    data.push_back(value);
}

template <typename T>
Set<T>::Set(const Set<T> &other)
{
    data.clear();
    std::copy(other.begin(), other.end(), data);
}

template <typename T>
Set<T>::~Set()
{
    data.clear();
}

template <typename T>
typename std::vector<T>::iterator Set<T>::find(const T &value)
{
    for (auto iterator = this->data.begin(); iterator != this->data.end(); iterator++)
    {
        if (*iterator == value)
        {
            return *iterator;
        }
    }
    return this->data.end();
}

template <typename T>
void Set<T>::del(const T &value)
{
    auto iterator = this->find(value);
    if iterator
        != this->data.end() this->data.erase(iterator);
}

template <typename T>
size_t Set<T>::size()
{
    return this->data.size();
}

template <typename T>
bool Set<T>::empty()
{
    if (this->data.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}