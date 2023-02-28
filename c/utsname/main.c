#include <stdio.h>

#include <sys/utsname.h>

int main(int argc, char *argv[])
{
    struct utsname uts;
    uname(&uts);

    printf("sysname: %s\n", uts.sysname);
    printf("nodename: %s\n", uts.nodename);
    printf("release: %s\n", uts.release);
    printf("version: %s\n", uts.version);
    printf("machine: %s\n", uts.machine);

    return 0;
}
