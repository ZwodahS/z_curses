#ifndef _ZF_ZCURSES_F_CURSES_H_
#define _ZF_ZCURSES_F_CURSES_H_
#include <ncurses.h>
#include "WindowRegion.hpp"
/**
 * I kind of want to follow the naming convention of ncurses, 
 * but for now just implemented the functions I want
 */
namespace zc
{
    struct RowRegion
    {
        int x;
        int y; // store the row position start
        int width;
    };
    
    struct ColRegion
    {
        int x;
        int y;
        int height;
    };


    enum class AlignmentX
    {
        Left,
        Right,
        Center,
    };
    // draw box using the ACS stuffs //
    /**
     * Draw a box with the region in this window.
     * assumption : region size is at least 2 x 2
     */
    void drawBox(WINDOW* window, const WindowRegion& region);
    /**
     * draw the box as a the border for this window.
     */
    void drawBorderBox(WINDOW* window);

    void print(WINDOW* window, const RowRegion& row, const std::string& message, const AlignmentX& alignment, const int& xoffset = 0);

    void mvwteehline(WINDOW* window, const int& y, const int& x, const int& width);

    WindowRegion centerRegion(const WindowRegion& innerRegion, const WindowRegion& outerRegion);
};
#endif
