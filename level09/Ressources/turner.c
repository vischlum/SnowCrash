#include <unistd.h>
#include <string.h>

int main(int ac, char **av)
{
        char *str;
        size_t i;

        if (ac != 2)
                return (0);
        str = av[1];
        i = 0;
        int len = strlen(str);
        while (i <= len)
        {
                char tmp = str[i] - i;
                write(1, &tmp, 1);
                i++;
        }
        return (0);
}

