#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "errs.h"

#include <stdio.h>

#define CMD_LEN 3

err_t fread_cmd(FILE *file, char *cmd);

#endif // __COMMAND_H__
