#include <stdio.h>

extern void a_print(void);
extern void a1_print(void);
extern void b_print(void);

void main_print(void)
{
    printf("%s %s %d\r\n", __FILE__, __FUNCTION__, __LINE__);
}

int main()
{
    main_print();
    a_print();
    a1_print();
    b_print();
    return 0;
}
