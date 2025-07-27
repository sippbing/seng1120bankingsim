/**
 * queue.hpp
 * Written by : Chi Tai Nguyen (c3444339)
 * Modified: 23/09/2024
 */ 

#include "queue.h"

template <typename T>
queue<T>::queue()
{
    list = std::list<T>();
}


template <typename T>
queue<T>::~queue()
{

}

template <typename T>
void queue<T>::enqueue(const T& data)
{
    list.push_back(data);
}

template <typename T>
void queue<T>::dequeue()
{
    if (!empty()) list.pop_front();
}

template <typename T>
const T& queue<T>::front() const
{
    if (!empty()) return list.front();
    else throw std::out_of_range("Queue is empty.");
}

template <typename T>
int queue<T>::size() const
{
    return list.size();
}

template <typename T>
bool queue<T>::empty() const
{
    return list.empty();
}

template <typename T>
void queue<T>::print(std::ostream& out) const
{
    if (!empty())
    {
        for (typename std::list<T>::const_iterator iter = list.begin();
             iter != list.end();
             iter++)
            out << *iter << " ";
    }
}

template <typename T>
std::ostream& operator << (std::ostream& out, const queue<T>& q)
{
    q.print(out);
    return out;
}
