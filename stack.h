//
// Created by tangb on 4/25/2020.
//

#ifndef STACKANDQUEUE_STACK_H
#define STACKANDQUEUE_STACK_H
#include <iostream>
#include "list.h"
#include "node.h"

template <class T>
class Stack {
public:
    class Iterator {

    public:
        friend class Stack;
        Iterator next()                     //return an iterator to the
        {                                   //  next location in the list
            return Iterator(_ptr ->_next);
        }

        Iterator(node <T> *p = NULL) : _ptr(p) {}     //ctor

        T &operator*() {                    //dereference oprator
            assert(_ptr);
            return _ptr ->_item;
        }


        T* operator ->(){
            assert(_ptr);
            return &(_ptr ->_item);
        }


        friend bool operator !=(const Iterator& left, const Iterator& right){
            return left._ptr  != right._ptr ;
        }
        friend  Iterator operator ++(Iterator& it, int unused){
            assert(it._ptr);
            Iterator hold;
            hold = it;
            it._ptr = it._ptr->_next;
            return hold;
        }

        Iterator& operator ++(){
            assert(_ptr);
            _ptr = _ptr ->_next;
            return *this;
        }
        bool is_null(){
            return _ptr = NULL;
        }

    private:
        node <T> *_ptr;                    //pointer being
        //  encapsulated
    };

    Stack ();
    //---------------------------- big three ----------------------------------

    Stack(const Stack& other);
    Stack& operator =(const Stack& RHS);
    ~Stack();
    Iterator push (const T& item);
    Iterator Begin()const;
    Iterator End ()const;
    T pop ();
    bool empty ();
    T top ();
    void clear ();
    friend ostream& operator <<(ostream& outs, const Stack<T>& stack){

        for (Stack<T>::Iterator it=stack.Begin(); it != stack.End (); it++){
            outs<<*it<<"|";
        }
        return outs;
    }

private:
    node <T>* _top;
};

template <class T>
Stack <T> :: Stack (){
    _top = nullptr;
}

template <class T>
Stack<T>::~Stack() {
    clear();
}

template <class T>
Stack<T>::Stack(const Stack& other){

    _top = _copy_list(other._top);

}
template <class T>
Stack<T>& Stack<T>::operator =(const Stack& RHS) {
    if (this == &RHS) return *this;
    clear();

    _top = _copy_list(RHS._top);
    return *this;
}

template <class T>
void Stack<T> ::clear() {
    while (_top != nullptr){
        _remove_head(_top);
    }
}

template <class T>
bool Stack<T> ::empty(){
    return _top == NULL;
}

template <class T>
typename Stack <T>::Iterator Stack<T> :: push (const T& item){
    return Iterator(_insert_head(_top, item));
}

template <class T>
T Stack<T> :: pop (){

//    T del = *Iterator (_top);
//    _remove_head(_top);
    return _delete_head(_top);
}

template <class T>
T Stack<T> :: top (){
    assert(!empty());
    return *Iterator(_top);
}

template <class T>
typename Stack<T>::Iterator Stack<T> ::Begin() const{
    return Iterator (_top);

}


template <class T>
typename Stack<T>::Iterator Stack<T> ::End() const{
    return Iterator (nullptr);
}




#endif //STACKANDQUEUE_STACK_H
