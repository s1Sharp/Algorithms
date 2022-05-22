#pragma once

#include <iostream>
#include <string>

#ifndef NDEBUG
#   define m_Assert(Expr, Msg) \
    __M_Assert(#Expr, Expr, __FILE__, __LINE__, Msg)
#else
#   define m_Assert(Expr, Msg) ;
#endif

void __M_Assert(const char* expr_str, bool expr, const char* file, int line, const char* msg)
{
    if (!expr)
    {
        std::cerr << "Assert failed:\t" << msg << "\n"
            << "Expected:\t" << expr_str << "\n"
            << "Source:\t\t" << file << ", line " << line << "\n";
        abort();
    }
}

void __M_Assert(const char* expr_str, bool expr, const char* file, int line, const std::string& msg)
{
    if (!expr)
    {
        std::cerr << "Assert failed:\t" << msg << "\n"
            << "Expected:\t" << expr_str << "\n"
            << "Source:\t\t" << file << ", line " << line << "\n";
        abort();
    }
}