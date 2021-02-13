//
// Created by Jeka8833 on 13.02.2021.
//

#include <cfloat>
#include <algorithm>
#include "Util.h"

int Util::errorCode = NONE;

void Util::print(const wstring &text) {
    wcout << text;
}

void Util::println(const wstring &text) {
    wcout << text << '\n';
}

wstring Util::readLine() {
    errorCode = NONE;
    while (true) {
        wstring str;
        getline(wcin, str);
        if (str.empty())
            continue;
        if (equalsIgnoreCase(str, L"exit")) {
            errorCode = EXIT;
            return L"";
        }
        return str;
    }
}

int Util::readInt() {
    try {
        return std::stoi(readLine());
    } catch (...) {
        if (errorCode == NONE)
            errorCode = FAIL_PARSE;
        return INT_MIN;
    }
}

float Util::readFloat() {
    try {
        return std::stof(readLine());
    } catch (...) {
        if (errorCode == NONE)
            errorCode = FAIL_PARSE;
        return -FLT_MAX;
    }
}

long long Util::readBigLong() {
    try {
        return std::stoll(readLine());
    } catch (...) {
        if (errorCode == NONE)
            errorCode = FAIL_PARSE;
        return LLONG_MIN;
    }
}

wstring Util::printAndRead(const wstring &text) {
    wcout << text;
    return readLine();
}

int Util::printAndReadInt(const wstring &text) {
    print(text);
    return readInt();
}

float Util::printAndReadFloat(const wstring &text) {
    print(text);
    return readFloat();
}

long long Util::printAndReadBigLong(const wstring &text) {
    print(text);
    return readBigLong();
}

int Util::printAndReadIntError(const wstring &text, const wstring &errorMessage, bool retry) {
    while (true) {
        int value = printAndReadInt(text);
        if (errorCode == EXIT)
            return value;
        if (value == INT_MIN) {
            wcout << L"=> " << errorMessage << '\n';
            if (!retry) {
                errorCode = FAIL_PARSE;
                return value;
            }
        } else {
            return value;
        }
    }
}

float Util::printAndReadFloatError(const wstring &text, const wstring &errorMessage, bool retry) {
    while (true) {
        float value = printAndReadFloat(text);
        if (errorCode == EXIT)
            return value;
        if (value == -FLT_MAX) {
            wcout << L"=> " << errorMessage << '\n';
            if (!retry) {
                errorCode = FAIL_PARSE;
                return value;
            }
        } else {
            return value;
        }
    }
}

long long Util::printAndReadBigLongError(const wstring &text, const wstring &errorMessage, bool retry) {
    while (true) {
        long long value = printAndReadBigLong(text);
        if (errorCode == EXIT)
            return value;
        if (value == LLONG_MIN) {
            wcout << L"=> " << errorMessage << '\n';
            if (!retry) {
                errorCode = FAIL_PARSE;
                return value;
            }
        } else {
            return value;
        }
    }
}

int Util::getIntAndCheckRange(const wstring &text, const wstring &errorMessage, int min, int max) {
    while (true) {
        int value = printAndReadIntError(text, errorMessage, true);
        if (errorCode == EXIT)
            return value;
        if (value < min || value > max) {
            Util::println(L"Число выходит за границы допустимого диапазона. Попробуй ввести допустимое число\n");
            continue;
        }
        return value;
    }
}

float Util::getFloatAndCheckRange(const wstring &text, const wstring &errorMessage, float min, float max) {
    while (true) {
        float value = printAndReadFloatError(text, errorMessage, true);
        if (errorCode == EXIT)
            return value;
        if (value < min || value > max) {
            Util::println(L"Число выходит за границы допустимого диапазона. Попробуй ввести допустимое число\n");
            continue;
        }
        return value;
    }
}

long long
Util::getBigLongAndCheckRange(const wstring &text, const wstring &errorMessage, long long int min, long long int max) {
    while (true) {
        long long value = printAndReadBigLongError(text, errorMessage, true);
        if (errorCode == EXIT)
            return value;
        if (value < min || value > max) {
            Util::println(L"Число выходит за границы допустимого диапазона. Попробуй ввести допустимое число\n");
            continue;
        }
        return value;
    }
}

inline bool caseInsCharCompareW(wchar_t a, wchar_t b) {
    return (towupper(a) == towupper(b));
}

bool Util::equalsIgnoreCase(const wstring &s1, const wstring &s2) {
    return ((s1.size() == s2.size()) && equal(s1.begin(), s1.end(), s2.begin(), caseInsCharCompareW));
}
