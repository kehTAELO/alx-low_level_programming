#include "main.h"

#include <stdlib.h>


/**

 * read_textfile- Read text file print to STDOUT.

 * @filename: text file being read

 * @letters: number of letters to be read

 * Return: w- actual number of bytes read and printed

 *        0 when function fails or filename is NULL.

 */

ssize_t read_textfile(const char *filename, size_t letters)

{

        char *buf;

        ssize_t td;

        ssize_t p;

        ssize_t z;


        td = open(filename, O_RDONLY);

        if (td == -1)

                return (0);

        buf = malloc(sizeof(char) * letters);

        z = read(td, buf, letters);

        p = write(STDOUT_FILENO, buf, z);


        free(buf);

        close(td);

        return (p);

}
