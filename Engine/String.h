#pragma once


class String
{
public:
    size_t Length() const;

    String();
    String(const char* str);
    ~String();

    bool operator==(const String& other) const;
};
