#include "String.hpp"

int String :: calculateLength(const char* s) {
    int len = 0;
    for (;s[len] != '\0'; len++);

    return len;
}

void String :: copy(const String& other) {
    if (this != &other) {
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        for (int i = 0; i < length; i++)
            str[i] = other.str[i];

        str[length] = '\0';
    }
}

String String :: reverse() const {
    String rev;
    rev.length = length;
    rev.str = new char[length + 1];
    for (int i = 0; i < length; i++)
        rev.str[i] = str[length - i - 1];

    rev.str[length] = '\0';
    return rev;
}

int String :: compare(const String& other) const {
    for (int i = 0; i < length && i < other.length; i++) {
        if (str[i] < other.str[i])
            return -1;

        if (str[i] > other.str[i])
            return 1;
    }

    if (length < other.length)
        return -1;

    if (length > other.length)
        return 1;

    return 0;
}

String String :: substring(int start, int len) const {
    if ((start < 0) || (start >= length) || (len <= 0) || (start + len > length))
        return String("");

    String sub;
    sub.length = len;
    sub.str = new char[len + 1];
    for (int i = 0; i < len; i++)
        sub.str[i] = str[start + i];

    sub.str[len] = '\0';
    return sub;
}

bool String :: isPalindrome() const {
    for (int i = 0; i < length / 2; i++)
        if (str[i] != str[length - i - 1])
            return false;

    return true;
}

// Concatenate function
String String :: concatenate(const String& other) const {
    String concat;
    concat.length = length + other.length;
    concat.str = new char[concat.length + 1];
    for (int i = 0; i < length; i++)
        concat.str[i] = str[i];

    for (int i = 0; i < other.length; i++)
        concat.str[length + i] = other.str[i];

    concat.str[concat.length] = '\0';
    return concat;
}

String String :: lpad(int total_length) const {
    if (total_length <= length) 
        return *this;

    int padding = total_length - length;
    String padded;
    padded.length = total_length;
    padded.str = new char[total_length + 1];
    for (int i = 0; i < padding; i++)
        padded.str[i] = '-';

    for (int i = 0; i < length; i++)
        padded.str[padding + i] = str[i];

    padded.str[total_length] = '\0';
    return padded;
}

String String :: rpad(int total_length) const {
    if (total_length <= length)
        return *this;

    int padding = total_length - length;
    String padded;
    padded.length = total_length;
    padded.str = new char[total_length + 1];
    for (int i = 0; i < length; i++)
        padded.str[i] = str[i];

    for (int i = length; i < total_length; i++)
        padded.str[i] = '-';

    padded.str[total_length] = '\0';
    return padded;
}
