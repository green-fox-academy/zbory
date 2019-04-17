//
// Created by zbora on 2019-04-17.
//

#include "Counter.h"

Counter::Counter()
{
    initial = 0;
    value = 0;
}

Counter::Counter(int value)
{
    this->initial = value;
    this->value = value;
}

int Counter::get()
{
    return value;
}

void Counter::add()
{
    value++;
}

void Counter::add(int number)
{
    value += number;
}

void Counter::reset()
{
    value = initial;
}