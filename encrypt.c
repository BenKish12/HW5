#include "encrypt.h"
#include "error_types.h"
#include <stdio.h>

int encrypt_file(const char *input_file_path, const char *output_file_path,
                 encrypt_t enc_type) {
    // TODO
	if ((input_file_path == NULL) || (output_file_path == NULL))
		return ERR_NULL_PTR;
	FILE *fp_i = fopen(input_file_path, "r");
	FILE *fp_o = fopen(output_file_path, "w");
	if ((fp_i == NULL) || (fp_o == NULL))
		return ERR_FILE;
	if (enc_type == 0)
		//enc_0();
	if (enc_type == 1)
		//enc_1();
	if (enc_type == 2)
		//enc_2();
	if (enc_type == 3)
		//enc_3();
	fclose(fp_i);
	fclose(fp_o);
    return OK;
}

int decrypt_file(const char *input_file_path, const char *output_file_path,
                 encrypt_t enc_type) {
  // TODO
  return OK;
}
