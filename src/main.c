#include <stdio.h>
#include <stdlib.h>

#include <solar-common.h>

#include <ava.h>

__attribute__ ((leaf, nonnull (1), nothrow, warn_unused_result))
static int cb (void *arg) {
	puts (arg);
	return 0;
}

__attribute__ ((nonnull (2), nothrow))
int main (int argc, char *argv[]) {
	struct coord_t coord;
	double zenith;
	int localoffset;
	error_check (argc != 6) {
		printf ("Usage: %s <latitude> <longitude> <altitude> "
		        "<zenith> <local offset>\n",
		      argv[0]);
		return EXIT_FAILURE;
	}

	error_check (parseDouble (&(coord.latitude),  argv[1]) != 0) return EXIT_FAILURE;
	error_check (parseDouble (&(coord.longitude), argv[2]) != 0) return EXIT_FAILURE;
	error_check (parseDouble (&(coord.altitude),  argv[3]) != 0) return EXIT_FAILURE;
	error_check (parseDouble (&zenith,      argv[4]) != 0) return EXIT_FAILURE;
	error_check (parseInt    (&localoffset, argv[5]) != 0) return EXIT_FAILURE;

	error_check (set_ava (&coord, cb, (void *) "Hello, World!") != 0)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}