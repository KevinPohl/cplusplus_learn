// own definition of function strstr()
//------------------------------------------------------------------------------
#include <string.h> // for strlen() and strncmp()

namespace MyScope
{
    char *strstr(const char *s1, const char *s2)
    { // search s2 in string s1
        int len = strlen(s2);
        for( ; *s1 != '\0'; ++s1)
            if(strncmp(s1, s2, len) == 0) // s2 found?
                return (char *)s1; // if true -> point here
        return NULL; // else NULL-pointer
    }
}