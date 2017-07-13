#ifndef __CONTEXT__
#define __CONTEXT__

#include "core_debug.h"
#include "core_param.h"
#include "core_jsmn.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define MAX_CONFIG_FILE_SIZE    1024
#define MAX_NUM_OF_CONFIG_TOKEN 256

typedef struct _config_t {
    char            json[MAX_CONFIG_FILE_SIZE+1];
    size_t          json_len;

    jsmn_parser     parser;

    int             num_of_token;
    jsmntok_t       token[MAX_NUM_OF_CONFIG_TOKEN];
} config_t;

#define MAX_DB_URI_LEN          256

typedef struct _context_t {
    config_t config;

    char *log_path;
    char *db_uri;
} context_t;

CORE_DECLARE(status_t)      context_init(void);
CORE_DECLARE(status_t)      context_final(void);
CORE_DECLARE(context_t*)    context_self(void);

CORE_DECLARE(status_t)      context_read_file(char *file_path);
CORE_DECLARE(status_t)      context_parse_config(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __CONTEXT__ */
