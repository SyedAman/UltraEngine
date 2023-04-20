// Copyright Syed Aman. All Rights Reserved.
#include "String.h"

#include <cstring>

String::String()
{
    Size = 0;
}

String::String(const char* str)
{
    Size = strlen(str);
    constexpr size_t SizeOfNullTerminator = 1;
    Buffer = new char[Size + SizeOfNullTerminator];
    std::memcpy(Buffer, str, Size + SizeOfNullTerminator);
    Buffer[Size] = '\0';
}

size_t String::Length() const
{
    return Size;
}

const char* String::Data() const
{
    return Buffer;
}

String::~String()
{
}

bool String::operator==(const String& other) const
{
    return true;
}