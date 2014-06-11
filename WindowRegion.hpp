#ifndef _ZF_ZCURSES_WINDOWREGION_H_
#define _ZF_ZCURSES_WINDOWREGION_H_
#include <string>
namespace zc
{
    struct WindowRegion
    {
        WindowRegion(const int& x = 0, const int& y = 0, const int& width = 0, const int& height = 0);
        int x;
        int y;
        int width;
        int height;

        std::string toString() const;
    };
}
#endif
