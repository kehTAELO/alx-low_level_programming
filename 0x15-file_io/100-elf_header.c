#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>

void print_error_and_exit(const char* message) {
    fprintf(stderr, "%s\n", message);
    exit(98);
}

void print_elf_header_info(const Elf64_Ehdr* header) {
    int i;

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             ");
    switch (header->e_ident[EI_CLASS]) {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown: %d>\n", header->e_ident[EI_CLASS]);
            break;
    }
    printf("  Data:                              ");
    switch (header->e_ident[EI_DATA]) {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown: %d>\n", header->e_ident[EI_DATA]);
            break;
    }
    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_NETBSD:
            printf("UNIX - NetBSD\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("UNIX - Solaris\n");
            break;
        case 53:  /* Value for Sortix (not defined in standard headers) */
            printf("Sortix\n");
            break;
        default:
            printf("<unknown: %d>\n", header->e_ident[EI_OSABI]);
            break;
    }
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (header->e_type) {
        case ET_NONE:
            printf("NONE (Unknown)\n");
            break;
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            printf("DYN (Shared object file)\n");
            break;
        case ET_REL:
            printf("REL (Relocatable file)\n");
            break;
        default:
            printf("<unknown: %d>\n", header->e_type);
            break;
    }

    printf("  Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char* argv[]) {
    const char* filename; /**Declare variables at the start*/
    int fd;
    Elf64_Ehdr header;

    if (argc != 2) {
        print_error_and_exit("Usage: elf_header elf_filename");
    }

    filename = argv[1];
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        print_error_and_exit("Error: Could not open the file.");
    }

    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        print_error_and_exit("Error: Could not read ELF header.");
    }

    if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
        print_error_and_exit("Error: Not an ELF file.");
    }

    print_elf_header_info(&header);

    close(fd);
    return 0;
}

