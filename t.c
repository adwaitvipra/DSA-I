#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    char name[]="fromfile.txt";
    printf("%d\n",remove(name));
    return 0;
}
