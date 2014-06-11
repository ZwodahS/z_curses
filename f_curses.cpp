#include "f_curses.hpp"

namespace zc
{
    void drawBox(WINDOW* window, const WindowRegion& region)
    {
        // draw the corners
        mvwaddch(window, region.y, region.x, ACS_ULCORNER); // upper left corner.
        mvwaddch(window, region.y, region.x + region.width - 1, ACS_URCORNER); // upper right corner.
        mvwaddch(window, region.y + region.height - 1, region.x, ACS_LLCORNER); // lower left corner.
        mvwaddch(window, region.y + region.height - 1, region.x + region.width - 1, ACS_LRCORNER); // lower right corner.
        // draw al the lines
        if(region.width > 2)
        {
            mvwhline(window, region.y, region.x + 1, ACS_HLINE, region.width - 2); // top line
            mvwhline(window, region.y + region.height - 1, region.x + 1, ACS_HLINE, region.width - 2); // bottom line
        }
        if(region.height > 2)
        {
            mvwvline(window, region.y + 1, region.x, ACS_VLINE, region.height - 2); // left line
            mvwvline(window, region.y + 1, region.x + region.width - 1, ACS_VLINE, region.height - 2); // right line
        }
    }

    void mvwteehline(WINDOW* window, const int& y, const int& x, const int& width)
    {
        mvwaddch(window, y, x, ACS_LTEE);
        mvwhline(window, y, x + 1, ACS_HLINE, width-2);
        mvwaddch(window, y, x + width - 1, ACS_RTEE);
    }

    void print(WINDOW* window, const RowRegion& row, const std::string& message, const AlignmentX& alignment, const int& offset)
    {
        if(alignment == AlignmentX::Left)
        {
            mvwprintw(window, row.y, row.x + offset, message.c_str());
        }
        else if(alignment == AlignmentX::Right)
        {
            mvwprintw(window, row.y, row.x + row.width - message.size() - offset, message.c_str());
        }
        else
        {
            mvwprintw(window, row.y, row.x + (row.width - message.size())/2 + offset, message.c_str());
        }
    }


    WindowRegion centerRegion(const WindowRegion& innerRegion, const WindowRegion& outerRegion)
    {
        // calculate the spare space.
        int spareX = outerRegion.width - innerRegion.width;
        int spareY = outerRegion.height - innerRegion.height;
        return WindowRegion(spareX / 2, spareY / 2, innerRegion.width, innerRegion.height);
    }

    
    
};
