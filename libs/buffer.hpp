#ifndef BUFFER
#define BUFFER
#include "data.hpp"
#define BUFFER_LIM 4000
class buffer
{
private:
    data samples[BUFFER_LIM];
    int frontPtr; //ptr to the first position of the buffer
    int backPtr; //ptr to the fist position out of the buffer

    int icr(int ptr)
    {
        if (++ptr >= BUFFER_LIM)
            ptr = 0;
        return ptr;
    }

    int dcr(int ptr)
    {
        if (--ptr < 0)
            ptr = BUFFER_LIM - 1;
        return ptr;
    }

public:

    buffer()
    {
        this->frontPtr = 0;
        this->backPtr = 0;
    }

    data back()
    {
        if (not this->isEmpty())
            return samples[this->dcr(this->backPtr)];
        return data();
    }

    data front()
    {
        if (not this->isEmpty())
            return samples[this->frontPtr];
        return data();
    }

    bool isFull()
    {
        return this->icr(this->backPtr) == this->frontPtr;
    }

    bool isEmpty()
    {
        return this->frontPtr == this->backPtr;
    }

    bool push(data &sample)
    {
        if (this->isFull())
            return false;

        this->samples[this->backPtr] = sample;
        this->backPtr = this->icr(this->backPtr);

        return true;
    }

    bool pop()
    {
        if (this->isEmpty())
            return false;

        this->frontPtr = this->icr(this->frontPtr);

        return true;
    }

    int getFrontPtr(){
        return this->frontPtr;
    }

    int getBackPtr(){
        return this->backPtr;
    }

    int size()
    {
        if (this->frontPtr <= this->backPtr)
            return this->backPtr - this->frontPtr;

        return BUFFER_LIM - (this->frontPtr - this->backPtr);

    }

    void clear()
    {
        this->frontPtr = 0;
        this->backPtr = 0;
    }
};
#endif