//
// Created by zbora on 2019-04-17.
//

#ifndef COUNTER_COUNTER_H
#define COUNTER_COUNTER_H


class Counter {
public:
    Counter();
    Counter(int value);
    int get();
    void add();
    void add(int number);
    void reset();

private:
    int initial;
    int value;
};


#endif //COUNTER_COUNTER_H
