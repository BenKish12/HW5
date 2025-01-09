#include "parser.h"
#include "error_types.h"
#include <stdio.h>

#define FLAGS_LEN(flags) (sizeof(flags) / sizeof(flag_t))

typedef struct {
  const char *short_name;
  const char *long_name;
  const char *description;
} flag_t;

static const flag_t flags[] = {{HELP_FLAG, "help", "print this description"},
                               {"-p", "operation", "enc/dec/censor"},
                               {"-t", "encryption type", "0/1/2/3"},
                               {"-i", "input", "file path"},
                               {"-o", "output", "file path"},
                               {"-b", "blacklist", "file path"}};

void print_help() {
  printf("Usage:\n");
  for (int i = 0; i < FLAGS_LEN(flags); i++) {
    printf("%*s%*s: %s,\n", 4, flags[i].short_name, 17, flags[i].long_name,
           flags[i].description);
  }
  printf("Please try again.\n");
}

int parse_args(int argc, const char *argv[], command_t *p_cmd) {
  // TODO
	int is_flag = 0;
	if (p_cmd == NULL)
		return ERR_NULL_PTR;
	if (argc != 11)
		return ERR_NUM_ARGS;
	for (int i = 0; i < argc; i++) {
		if (argv[i][0] == '-')
			is_flag = 1;
		if (is_flag) {
			if ((argv[i][1] != 'p') && (argv[i][1] != 't') && (argv[i][1] != 'i') && (argv[i][1] != 'o') && (argv[i][1] != 'b'))
				return ERR_UNKNOWN_FLAG;
			if (i == argc - 1)
				return ERR_MISSING_ARG;
			if (argv[i + 1][0] == '-')
				return ERR_MISSING_ARG;
		}
		if (argv[i] == "-p") {
			if ((argv[i + 1] != "enc") && (argv[i + 1] != "dec") && (argv[i + 1] != "censor"))
				return ERR_BAD_OP;
			if (argv[i + 1] == "enc")
				p_cmd->op = 1;
			if (argv[i + 1] == "dec")
				p_cmd->op = 2;
			if (argv[i + 1] == "censor")
				p_cmd->op = 3;
		}
		if (argv[i] == "-t") {
			if ((argv[i + 1] != "0") && (argv[i + 1] != "1") && (argv[i + 1] != "2") && (argv[i + 1] != "3"))
				return ERR_BAD_ENC_TYPE;
			p_cmd->enc_type = (int)argv[i + 1];
		}
		if (argv[i] == "-i")
			p_cmd->input_path = argv[i + 1];
		if (argv[i] == "-o")
			p_cmd->output_path = argv[i + 1];
		if (argv[i] == "-b")
			p_cmd->blacklist_path = argv[i + 1];
		is_flag = 0;
	}
  return OK;
}
