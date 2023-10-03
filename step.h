#ifndef STEP_H
#define STEP_H

template<class T>
class Step
{
public:
    Step():data(0),next(0){};
    Step(T element):data(element),next(0){};

    T getData() const{return data;};
    void setData(T newData){data=newData;}

    Step* getNext() const{return next;};
    void setNext(Step *newNext){next=newNext;};

private:
    T data;
    Step *next;
};

#endif // STEP_H
