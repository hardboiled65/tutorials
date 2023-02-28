#!/usr/bin/python3
import sys
import os

LOCALES = [
    'en_US',
    'ja_JP',
]

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('usage: make.py COMMAND')
        exit(0)

    if sys.argv[1] == 'template':
        os.system(
            'xgettext --keyword=_ --language=C --add-comments --sort-output -o po/hello.pot main.c'
        )
        exit(0)

    if sys.argv[1] == 'po':
        for locale in LOCALES:
            os.system(f'mkdir -p po/{locale}')
            os.system(
                f'msginit --input=po/hello.pot --locale={locale} --output=po/{locale}/hello.po'
            )
        exit(0)

    if sys.argv[1] == 'mo':
        for locale in LOCALES:
            os.system(f'mkdir -p {locale}/LC_MESSAGES')
            os.system(f'msgfmt --output-file={locale}/LC_MESSAGES/hello.mo po/{locale}/hello.po')
        exit(0)

    if sys.argv[1] == 'clean':
        os.system(f'rm -r {" ".join(LOCALES)}')
        exit(0)

