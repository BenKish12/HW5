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

  // TODO: call parse arguments of parser

  // TODO: run command - call process operation

  return 0;
}