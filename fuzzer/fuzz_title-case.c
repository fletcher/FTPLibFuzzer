#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#include "libTitleCase.h"
#include "d_string.h"

int LLVMFuzzerTestOneInput(const unsigned char * unsigned_data, unsigned long size) {
	// Copy data to new DString so we can null terminate
	DString * data = d_string_new("");
	d_string_append_c_array(data, (const char *) unsigned_data, size);

	char * result;

	result = title_case_string_len(data->str, data->currentStringLength);
	free(result);
	d_string_erase(data, 0, -1);

	result = sentence_case_string_len(data->str, data->currentStringLength);
	free(result);

	d_string_free(data, true);

	return 0;
}
