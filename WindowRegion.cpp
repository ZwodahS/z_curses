#include "WindowRegion.hpp"
namespace zc
{
    WindowRegion::WindowRegion(const int& x, const int& y, const int& width, const int& height)
        : x(x), y(y), width(width), height(height)
    {
    }

    std::string WindowRegion::toString() const
    {
        return std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(width) + " " + std::to_string(height);
    }
}
