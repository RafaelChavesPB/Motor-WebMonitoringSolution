#ifndef BUFFER
#define BUFFER
#include "data.hpp"
#define LIM 4000
class buffer
{
private:
    data samples[LIM];
    int front_ptr, back_ptr;

    int icr(int ptr)
    {
        if (++ptr >= LIM)
            ptr = 0;
        return ptr;
    }

    int dcr(int ptr)
    {
        if (--ptr < 0)
            ptr = LIM - 1;
        return ptr;
    }

public:
    data back()
    {
        return samples[this->back_ptr];
    }

    data front()
    {
        return samples[this->front_ptr];
    }

    bool isFull(){
        return this->icr(this->back_ptr) == this->front_ptr;
    }

    bool isEmpty(){
        return this->front_ptr == this->back_ptr;
    }

    bool push(data &sample){
        if(this->isFull())
            return false;

        this->back_ptr = this->icr(this->back_ptr);
        this->samples[this->back_ptr] = sample;

        return true;
    }

    bool pop(){
        if(this->isEmpty())
            return false;

        this->front_ptr = this->icr(this->front_ptr);
    
        return true;
    }

    void clear(){
        this->front_ptr = 0;
        this->back_ptr = 0;
    }

};
#endif