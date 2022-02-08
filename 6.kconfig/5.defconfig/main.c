#include <stdio.h>
#include "include/linux/autoconf.h"

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

#if (defined CONFIG_FUNC_A)
    a_print();
#endif

#if (defined CONFIG_FUNC_A1)
    a1_print();
#endif

#if (defined CONFIG_MENU_FUNC_B)
    b_print();
#endif

    return 0;
}
