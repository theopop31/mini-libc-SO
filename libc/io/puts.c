#include <unistd.h>
#define EOF -1
int puts(const char *s)
{
    int index = 0;
    int numWritten;
    while (*(s + index) != 0) {
        numWritten = write(1, s + index, 1);
        if (numWritten != 1) {
            return EOF;
        }
        ++index;
    }
    numWritten = write(1, "\n", 1);
    if (numWritten != 1) {
        return EOF;
    }
    return index + 1;
}