#ifndef STACK_H
#define STACK_H
#include<step.h>
#include<QString>
template<class N>
class Stack
{
public:
    Stack(int max):first(0),numberElements(0),max(0){
        if(max<=0)throw QString("Invalid size");
        this->max=max;
    }


    void push(N element)
    try {
        if(isFull())throw QString("stack is full");
        numberElements++;
         Step<N>* aux=new Step<N>(element);
         aux->setNext(first);
         first=aux;
    } catch (std::bad_alloc &erro) {
        throw QString("Bad alloc");
    }
    N top()const{if(isEmpty()) throw QString("Lista esta vazia (top())");
        return first->getData();}
    N pop(){
        if(isEmpty())throw QString("Lista esta vazia (pop())");
        numberElements--;
        Step<N>*aux=first;
        first=aux->getNext();
        N valor=aux->getData();
        delete aux;
        return valor;
    }
    int size()const{return numberElements;}

private:
    bool isEmpty()const{return (!numberElements);}
    bool isFull()const{return (numberElements==max);}
   Step<N> *first;
   int numberElements;
   int max;
};

#endif // STACK_H
