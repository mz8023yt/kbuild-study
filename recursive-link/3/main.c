#include <stdio.h>

void main_print(void)
{
    printf("%s %s %d\r\n", __FILE__, __FUNCTION__, __LINE__);
}

int main()
{
    main_print();
    return 0;
}
