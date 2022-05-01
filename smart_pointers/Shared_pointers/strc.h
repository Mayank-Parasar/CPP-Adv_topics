/***********************************************************************
* Course: Advance Topics in C++
* Created by: Mayank Parasar
* Created on: 04/30/2022
* Email-ID: mayankparasar@gmail.com
* Topic: 
* 
* ***********************************************************************
*/


// '#pragma once' is not portable
#ifndef __STRC_H_
#define __STRC_H_

#include <cstddef>

constexpr const char * __strc_class = "strc";
constexpr const char * __strc_version = "1.1";
constexpr size_t _maxlen = 10240;

class strc {
    char * data = nullptr;
    void msg(const char *);
public:
    strc();
    strc(const char * s);
    strc(const strc &);
    strc(strc &&);
    ~strc();
    strc & operator = (strc);
    const char * value() const;
    operator const char * () const;
    void swap(strc &);
};

#endif // __STRC_H_
