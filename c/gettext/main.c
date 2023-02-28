#include <stdio.h>
#include <stdlib.h>

#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)

void print_hello()
{
    printf("%s\n", _("SAY_HELLO"));
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    bindtextdomain("hello", getenv("PWD"));
    textdomain("hello");

    setlocale(LC_ALL, "en_US.UTF-8");
    print_hello();

    setlocale(LC_ALL, "ja_JP.UTF-8");
    print_hello();

    return 0;
}
