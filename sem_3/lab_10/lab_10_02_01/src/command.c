#include "command.h"
#include <string.h>

err_t fread_cmd(FILE *file, char *cmd)
{
    char tmp_cmd[CMD_LEN + 2];

    if (!fgets(tmp_cmd, CMD_LEN + 2, file))
        return ERR_IO;

    char *cmd_end = strchr(tmp_cmd, '\n');
    if (cmd_end == NULL)
        return ERR_CMD;
    else
        *cmd_end = '\0';
    if (!strlen(tmp_cmd))
        return ERR_IO;

    strcpy(cmd, tmp_cmd);
    return OK;
}
