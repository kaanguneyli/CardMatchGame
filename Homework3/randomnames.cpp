#include <random>
#include <iostream>
#include <algorithm>
#include <string>
#include "randomnames.h"
std::array<std::string, 30>  random_init() {
    std::array<std::string, 30> elements = {"zebra","zebra","lion","lion","eagle","eagle","fish","fish"
        ,"bee","bee","dog","dog","cat","cat","bird","bird","elephant","elephant",
        "giraffe","giraffe","tiger","tiger","turtle","turtle","ant","ant",
        "cheetah","cheetah","spider","spider"
    };
    for(int i = 0;i<30;i++) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(i, 29);

        int randomNum = distribution(gen);
        std::swap(elements[i], elements[randomNum]);
    }

    return elements;
}
