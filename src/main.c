#include <stdio.h>
#include <stdlib.h>

#include <ezparse.h>

#include <ava.h>

__attribute__ ((nonnull (1), nothrow, warn_unused_result))
static int cb (void *arg) {
	puts (arg);
	return 0;
}

__attribute__ ((nonnull (2), nothrow))
int main (int argc, char *argv[]) {
	struct ln_lnlat_posn coord;
	/*double zenith;
	int localoffset;*/
	/*error_check (argc != 4) {
		printf ("Usage: %s <latitude> <longitude> <message>\n", argv[0]);
		return EXIT_FAILURE;
	}*/

	error_check (parseDouble (&(coord.lat), argv[1]) != 0) return EXIT_FAILURE;
	error_check (parseDouble (&(coord.lng), argv[2]) != 0) return EXIT_FAILURE;
	/*error_check (parseDouble (&(coord.altitude),  argv[3]) != 0) return EXIT_FAILURE;*/
	/*error_check (parseDouble (&zenith,      argv[4]) != 0) return EXIT_FAILURE;*/
	/*error_check (parseInt    (&localoffset, argv[5]) != 0) return EXIT_FAILURE;*/

	error_check (set_ava (&coord, cb, argv[3]) != 0)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}