#include "ip_search.h"
#include <ctype.h>
#include <string.h>

bool is_ip(const char *ip)
{
    size_t ip_len = strlen(ip);
    if (ip_len > MAX_IP_LEN)
        return false;

    size_t octet_count = 1;
    size_t octet_len = 0;
    int num = 0;
    for (size_t i = 0; i < ip_len; i++)
    {
        char c = ip[i];
        if (isdigit(c))
        {
            octet_len++;
            num = num * 10 + (c - '0');
            if (octet_len > MAX_OCTET_LEN || num > MAX_IP_OCTET)
                return false;
        }
        else if (c == '.')
        {
            if (octet_len == 0)
                return false;

            octet_count++;
            octet_len = 0;
            num = 0;

            if (octet_count > OCTET_COUNT)
                return false;
        }
        else
        {
            return false;
        }
    }
    if (octet_count != OCTET_COUNT || octet_len == 0)
        return false;
    return true;
}
