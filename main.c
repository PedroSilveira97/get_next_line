#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int   fd;
    char *line;

    if (argc != 2)
    {
        write(2, "Usage: ./a.out <file>\n", 23);
        return 1;
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return perror("open"), 1;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
