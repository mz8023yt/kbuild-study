#include <stdio.h>

void cmd_print(void)
{
	printf("%s %s %d\r\n", __FILE__, __FUNCTION__, __LINE__);
}