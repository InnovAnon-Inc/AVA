#include <restart.h>

#include <ava.h>

__attribute__ ((leaf, nonnull (1, 2), warn_unused_result))
int set_ava (coord_t *restrict coord, stdcb_t cb, void *arg) {
	struct timeval timeout;
	(void) gettimeofday(&timeout, NULL);
	error_check (getnextsunriseorsunset (&timeout, coord) != 0)
		return -1;
	error_check (r_sleept (&timeout) != 0)
		return -2;
	error_check (cb (arg) != 0)
		return -3;
	return 0;
}