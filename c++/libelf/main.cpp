#include <stdio.h>
#include <string.h>

#include <fcntl.h>  // open()
#include <unistd.h> // close()

#include <libelf.h>
#include <gelf.h>

int main(int argc, char *argv[])
{
    Elf *elf;
    Elf_Scn *scn = NULL;
    Elf64_Shdr *shdr;
    Elf_Data *data;
    char *section_name;

    int fd;

    // Init libelf.
    elf_version(EV_CURRENT);

    // Open ELF file.
    fd = open("libfoo.so", O_RDONLY);
    elf = elf_begin(fd, ELF_C_READ, NULL);

    scn = elf_nextscn(elf, scn);
    while (scn != NULL) {
        shdr = elf64_getshdr(scn);
        size_t shdrstrndx;
        elf_getshdrstrndx(elf, &shdrstrndx);
        section_name = elf_strptr(elf, shdrstrndx, shdr->sh_name);
        printf("Section name: %s\n", section_name);

        if (shdr->sh_type == SHT_DYNSYM) {
            data = elf_getdata(scn, NULL);
            int count = shdr->sh_size / shdr->sh_entsize;
            printf(" - .dynsym count: %d\n", count);

            for (int i = 0; i < count; ++i) {
                GElf_Sym sym;
                gelf_getsym(data, i, &sym);
                printf("[%s]\n", elf_strptr(elf, shdr->sh_link, sym.st_name));
            }
        }

        scn = elf_nextscn(elf, scn);
    }

    elf_end(elf);
    close(fd);

    return 0;
}
