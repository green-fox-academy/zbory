//
// Created by zbora on 2019-04-24.
//

#ifndef INSTRUMENTSTOSTRINGEDINSTRUMENTS_VIOLIN_H
#define INSTRUMENTSTOSTRINGEDINSTRUMENTS_VIOLIN_H


class Violin : public StringedInstrument {
public:
    Violin();

    Violin(int string);

    std::string sound() override;
};


#endif //INSTRUMENTSTOSTRINGEDINSTRUMENTS_VIOLIN_H
