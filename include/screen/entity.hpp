#pragma once

#include <color/color.hpp>
#include <std/stdcxx.hpp>

namespace system::io::entity {
class Screen {
public:
    Screen();

    uint32_t *graphicMemory;
    size_t    height;
    size_t    width;
    size_t    pixelsPerScanLine;

    void drawPixel(uint32_t x, uint32_t y,
                   system::media::entity::Color color);
    void clear();
}; // class screen

} // namespace system::io::entity
