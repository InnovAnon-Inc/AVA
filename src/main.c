#include <stdio.h>
#include <stdlib.h>

#include <ava.h>

__attribute__ ((leaf, nonnull (1), nothrow, warn_unused_result))
static int cb (void *arg) {
	puts (arg);
	return 0;
}

int main (void) {
	coord_t coord;
	coord.latitude = ?;
	coord.longitude = ?;
	coord.altitude = ?;
	error_check (set_ava (&coord, cb, (void *) "Hello, World!") != 0)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}