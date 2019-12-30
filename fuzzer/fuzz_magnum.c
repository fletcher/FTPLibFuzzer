#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#include "libMagnum.h"
#include "d_string.h"

int LLVMFuzzerTestOneInput(const unsigned char * unsigned_data, unsigned long size) {
	if (size < 2) {
		return 0;
	}

	size_t offset = (unsigned_data[0] << 8) + unsigned_data[1];

	if (offset + 2 > size) {
		return 0;
	}

	if (offset < 2) {
		return 0;
	}

	// Copy data to new DString so we can null terminate
	DString * json = d_string_new("");
	d_string_append_c_array(json, (const char *) &unsigned_data[2], offset - 2);

	DString * source = d_string_new("");
	d_string_append_c_array(source, (const char *) &unsigned_data[offset], size - offset);


	DString * out = d_string_new("");
	magnum_populate_from_string(source, json->str, out, NULL);

	d_string_free(out, true);
	d_string_free(json, true);
	d_string_free(source, true);

	return 0;
}
