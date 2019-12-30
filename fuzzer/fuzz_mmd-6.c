#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#include "libMultiMarkdown.h"
#include "d_string.h"
#include "i18n.h"

int LLVMFuzzerTestOneInput(const unsigned char * unsigned_data, unsigned long size) {
	// Copy data to new DString so we can null terminate
	DString * data = d_string_new("");
	d_string_append_c_array(data, (const char *) unsigned_data, size);

	char * result;

	result = mmd_d_string_convert(data, 0, FORMAT_HTML, LC_EN);

	d_string_free(data, true);
	free(result);

	return 0;
}
