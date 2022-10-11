#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N 1000

int64_t cache[N];

int64_t fibonacci(int index)
{
    if (index < 0)
        return -1;
    if (index <= 1)
        return index;

    if (cache[index - 2] == -1)
        cache[index - 2] = fibonacci(index - 1) + fibonacci(index - 2);

    return cache[index - 2];
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;

    for (int i = 0; i < N; i++)
    {
        cache[i] = -1;
    }

    printf("%" PRId64 "\n", fibonacci(atoi(argv[1])));

    return 0;
}
