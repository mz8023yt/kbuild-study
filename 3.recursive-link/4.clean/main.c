#include <stdio.h>

extern void keypad_print(void);
extern void touchpad_print(void);
extern void st7735_print(void);
extern void st7789_print(void);
extern void sensor_print(void);
extern void cmd_print(void);
extern void list_print(void);

void main_print(void)
{
	printf("%s %s %d\r\n", __FILE__, __FUNCTION__, __LINE__);
}

int main()
{
	main_print();
	keypad_print();
	touchpad_print();
	st7735_print();
	st7789_print();
	sensor_print();
	cmd_print();
	list_print();
	return 0;
}
