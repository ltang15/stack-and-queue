//
// Created by tangb on 4/26/2020.
//
#include "sq_test.h"

void stack_test(){
    Stack <int> s;


    for (int i =0; i <5; i++){
        s.push(i*2);
    }
    cout << s << endl;
    Stack <int> :: Iterator it = s.Begin();

    cout << "print out first three elements" << endl;
    for (int i =0; i <3; i++){
        cout <<*it << " ";
        ++it;
    }
    cout << endl;


    cout << "top: " << s.top() << endl;
    for (int i =0; i <3; i++) {
        cout << "pop " << i << ": " << s.pop() << endl;
    }

    cout << s << endl;
    cout << "Push 10: ";
    s.push(10);
    cout << s << endl;
    cout << "Push 20: ";
    s.push(20);
    cout <<  s << endl;
}
void queue_test (){
    Queue <int> q;



    for (int i =0; i <5; i++){
        q.push(i*10);
    }
    cout << q << endl;

    cout << "print out first three elements" << endl;
    Queue <int> :: Iterator it = q.Begin();
    for (int i =0; i <3; i++){
        cout <<*it << " ";
        ++it;
    }
    cout << endl;
    cout << "pop: " << q.pop() << endl;
    cout << "top: " << q.front() << endl;


    cout << "The final queue: " << q << endl;
}