#include "error_types.h"
#include "parser.h"
// TODO - add you includes here

static int process_operation(command_t cmd) {
  // TODO:
  // Assuming cmd is OK, no need to validate members as they are beeing
  // validated inside parse args & within each processed operation.

  // TODO: process command according to operation

  return OK;
}

int main(int argc, const char *argv[]) {

  // TODO: check if need to print help (no args or 1 arg and its help) and print it.
	command_t p_cmd;
	int parse_val = -1;
	if (argc == 1 || (argc == 2 && argv[1] == HELP_FLAG))
		print_help();
	else
		// TODO: call parse arguments of parser
		parse_val = parse_args(argc, argv, &p_cmd);
  // TODO: run command - call process operation
	if (parse_val == OK)
		process_operation(p_cmd);
  return 0;
}
