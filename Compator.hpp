#pragma once

using namespace std;

struct Comparator{
    template<typename T>
    bool operator()(T& t1, T&t2){
        return t1.second < t2.second;
    }

};