#include <stdint.h>
// #include "st7735.h"
#include "st7789.h"

int lcd_area_draw(int x1, int y1, int x2, int y2, uint16_t *rgb565)
{
	// return st7735_area_draw(x1, y1, x2, y2, rgb565);
	return st7789_area_draw(x1, y1, x2, y2, rgb565);
}
