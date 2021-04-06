#include <boot/boot.hpp>
#include <memory/memory.hpp>
#include <screen/screen.hpp>

namespace system::io {
entity::Screen::Screen()
    : graphicMemory((uint32_t *)system::memory::phyicalToVirtualAddr(
          (void *)system::boot::getBootInfo()
              ->graphicInfo.FrameBufferBase)),
      height(system::boot::getBootInfo()->graphicInfo.VerticalResolution),
      width(system::boot::getBootInfo()->graphicInfo.HorizontalResolution),
      pixelsPerScanLine(
          system::boot::getBootInfo()->graphicInfo.PixelsPerScanLine) {}

void entity::Screen::drawPixel(uint32_t x, uint32_t y,
                               system::media::entity::Color color) {
    if(0 <= x && x < width && 0 <= y && y < height) {
        size_t    padding      = (pixelsPerScanLine - width);
        size_t    leftPadding  = padding / 2;
        size_t    rightPadding = padding - leftPadding;
        uint32_t *addr = (uint32_t *)graphicMemory + (y + padding) * width
                         + x + leftPadding;
        *addr = color.getColor().u32;
    }
}

void entity::Screen::clear() {
    for(int x = 0; x < width; x++) {
        for(int y = 0; y < height; y++) {
            drawPixel(x, y, system::media::common_color::black);
        }
    }
}

} // namespace system::io
