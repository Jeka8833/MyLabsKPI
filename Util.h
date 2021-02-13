//
// Created by Jeka8833 on 13.02.2021.
//

#ifndef TESTPROJECT_UTIL_H
#define TESTPROJECT_UTIL_H

#include <string>
#include <iostream>

#define NONE 0
#define EXIT 1
#define FAIL_PARSE 2

using namespace std;

class Util {
public:
    static int errorCode;

    static void print(const wstring &text);

    static void println(const wstring &text);

    static wstring readLine();

    static int readInt();

    static float readFloat();

    static long long readBigLong();

    static wstring printAndRead(const wstring &text);

    static int printAndReadInt(const wstring &text);

    static float printAndReadFloat(const wstring &text);

    static long long printAndReadBigLong(const wstring &text);

    static int printAndReadIntError(const wstring &text, const wstring &errorMessage, bool retry = false);

    static float printAndReadFloatError(const wstring &text, const wstring &errorMessage, bool retry = false);

    static long long printAndReadBigLongError(const wstring &text, const wstring &errorMessage, bool retry = false);

    static int getIntAndCheckRange(const wstring &text, const wstring &errorMessage, int min, int max);

    static float getFloatAndCheckRange(const wstring &text, const wstring &errorMessage, float min, float max);

    static long long
    getBigLongAndCheckRange(const wstring &text, const wstring &errorMessage, long long min, long long max);

    static bool equalsIgnoreCase(const wstring &textA, const wstring &textB);
};


#endif //TESTPROJECT_UTIL_H
