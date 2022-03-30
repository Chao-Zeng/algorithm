#include <cstdarg>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <exception>

#define LOG(...) write_log(__VA_ARGS__)

void write_log(const char *format, ...)
{
    va_list args1, args2;
    va_start(args1, format);
    va_copy(args2, args1);
    int len = std::vsnprintf(nullptr, 0, format, args1);
    va_end(args1);

    if (len < 0)
    {
        fprintf(stderr, "vsnprintf error");
        return;
    }

    std::vector<char> buff(len+1);
    std::vsnprintf(buff.data(), buff.size(), format, args2);
    va_end(args2);
    std::string msg(buff.data());

    std::cout << msg << std::endl;
}

template<typename T, typename... Args>
void MyPrint(std::ostream &out, const char *format, T arg1, Args&&... args)
{
    while (format && *format)
    {
        if (*format == '{' && *(format+1) == '}')
        {
            out << arg1;
            format += 2;
            return MyPrint(out, format, std::forward<Args>(args)...);
        }
        
        out << *format++;
    }

    //throw std::runtime_error("extra arguments");
    std::cerr << "*extra arguments*" << std::endl;
}

void MyPrint(std::ostream &out, const char* format)
{
    while (format && *format)
    {
        if (*format == '{' && *(format+1) == '}')
        {
            //throw std::runtime_error("missing arguments");
            std::cerr << "*missing arguments*";
        }

        out << *format++;
    }

    // add \n at the end
    out << '\n';
}

int main()
{
    LOG("");
    LOG("this is a %s %d log", "test", 1);
    // program will abort
    //LOG("type is not match %s", 1);
    LOG("missing args %s %d", "test");
    LOG("extra args %s", "test", 1);

    MyPrint(std::cout, "");
    MyPrint(std::cout, "this is {} {} {} string", "MyPrint", 1, std::string("test"));
    MyPrint(std::cout, "missing args {} {}", "test");
    MyPrint(std::cout, "extra args {}", "test", 1);

    return 0;
}
