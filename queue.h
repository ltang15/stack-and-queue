//
// Created by tangb on 4/25/2020.
//

#ifndef STACKANDQUEUE_QUEUE_H
#define STACKANDQUEUE_QUEUE_H

#include <iostream>
#include "list.h"
#include "node.h"

template <class T>
class Queue{
public:
    class Iterator {

    public:
        friend class Queue;
        Iterator next()                     //return an iterator to the
        {                                   //  next location in the list
            return Iterator(_ptr.next());
        }

        Iterator(typename List <T> ::Iterator p = NULL) : _ptr(p) {}     //ctor

        T &operator*() {                    //dereference operator
            return *_ptr;
        }


        T* operator ->(){
            assert(_ptr);
            return &(*_ptr);
        }


        friend bool operator !=(const Iterator& left, const Iterator& right){
            return left._ptr  != right._ptr ;
        }

        friend bool operator ==(const Iterator& left, const Iterator& right){
            return left._ptr  == right._ptr ;
        }

        friend  Iterator operator ++(Iterator& it, int unused){

            return Iterator (++it._ptr);
        }

        Iterator& operator ++(){
            ++_ptr;
            return *this;
        }
        bool is_null(){
            return _ptr = NULL;
        }

    private:
        typename List <T>::Iterator _ptr;                    //pointer being encapsulated
    };

    Queue ();
    //---------------------------- big three ----------------------------------

    Queue (const Queue& other);
    Queue& operator =(const Queue& RHS);
    ~Queue();
    Iterator push (const T& item);
    T pop ();
    Iterator Begin()const;
    Iterator End ()const;

    bool empty ();
    int size ();
    T front ()const;

    friend ostream& operator <<(ostream& outs, const Queue<T>& q){

        for (Queue<T>::Iterator it=q.Begin(); it != q.End (); it++){
            outs<<*it<<"|";
        }
        return outs;
    }

private:
    List <T> _q;
    typename List <T> ::Iterator _rear;
};

template <class T>
Queue <T> :: Queue (){
    _q = List <T>();
    _rear = _q.last_node();
}

template <class T>
Queue<T>::Queue (const Queue& other){
    _q = other._q;
    _rear = _q.last_node();
}

template <class T>
Queue<T>& Queue<T>:: operator =(const Queue& RHS){
    if (this == &RHS) return *this;
    _q.clear();
    _q = RHS._q;
    _rear = _q.last_node();
    return *this;

}
template <class T>
Queue<T>::~Queue(){
    //
}

template <class T>
typename Queue<T>::Iterator Queue<T> ::Begin() const{
    return Iterator (_q.Begin());

}


template <class T>
typename Queue<T>::Iterator Queue<T> ::End() const{
    return Iterator (nullptr);
}

template <class T>
typename Queue<T>::Iterator Queue<T> :: push (const T& item){

    if (empty()){
        _rear = _q.insert_head(item);
        return Iterator(_rear);

    }


    Queue<T>::Iterator add = Iterator(_q.insert_after(_rear, item));

    _rear = _q.previous(nullptr);

    return add ;

}

template <class T>
T Queue <T> :: pop (){
    T del =_q.delete_head();
    return del;
}

template <class T>
T Queue <T> :: front ()const{

    return *Iterator(_q.Begin());
}
template <class T>
bool Queue <T> :: empty (){
    typename List <T>::Iterator emp;

    if(_q.Begin() == emp)
        return true;
    else
        return false;

}
template <class T>
int Queue <T> :: size (){
    int count = 0;
    for (Queue <T>::Iterator it=_q.Begin(); it != _q.End (); it++){
        count ++;
    }
    return count;

}


#endif //STACKANDQUEUE_QUEUE_H
