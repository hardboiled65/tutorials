# gettext Tutorial

This tutorial describes how to internationalise software in C on Linux with **gettext**.

## Create a Template File

```sh
$ xgettext --keyword=_ --language=C --add-comments --sort-output -o po/hello.pot main.c
```

## Make .po File

```sh
$ mkdir po/ja_JP
$ msginit --input=po/hello.pot --locale=ja_JP --output=po/ja_JP/hello.po
```

## Edit the .po File

Edit the charset and msgstr field.

```
"Content-Type: text/plain; charset=UTF-8\n"

...

#: main.c:11
msgid "SAY_HELLO"
msgstr "こんにちは！"
```

## Make the .mo File

When edit is done, let's make the `.mo` file.

```sh
$ mkdir ja_JP
$ msgfmt --output-file=ja_JP/LC_MESSAGES/hello.mo po/ja_JP/hello.po
```

## Compile and Run

```sh
$ gcc main.c
$ ./a.out
```

