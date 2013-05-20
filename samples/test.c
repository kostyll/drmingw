/* test-c.c
 *
 * A sample C program to demonstrate the symbolic capabilities
 * of Dr.MinGW.
 *
 * Jose Fonseca
 */

#include <stdio.h>

static void YetAnotherFunction(int i)
{
    int k;

#if 0
    /* Other ways to cause a GPF */
    *(int *)i = 5;
    __asm ("int $3");
    (*((void (*)(void)) 0x12345678))();
#endif
    sscanf("12345", "%i", (int *) (size_t) (k=i));
}

struct AStructType
{
    int AnArray[2];
};

enum AnEnumType {a,b,c};

static void MyWonderfulFunction(int AnInteger, double ADouble, int AnArray[4], char * AString, enum AnEnumType AnEnum, struct AStructType AStruct, void (*AFunction)(void))
{
    YetAnotherFunction( 8 );
}

static void ASimpleFunction(void) {}

int main(int argc, char *argv[])
{
    struct AStructType AStruct = {{10, 3}};
    int AnArray[4] = {4,3,2,1};

    MyWonderfulFunction( 4, 5.6, AnArray, "Hello" , 1, AStruct, ASimpleFunction);

    return 0;
}
