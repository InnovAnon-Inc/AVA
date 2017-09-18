#ifdef DEBUG
#include <stdio.h>
#endif

#include <restart.h>

#include <ava.h>

__attribute__ ((leaf, nonnull (1, 2), warn_unused_result))
int set_ava (coord_t *restrict coord, stdcb_t cb, void *arg) {
	struct timeval timeout;
#ifdef DEBUG
	char buffer[32];
#endif
	(void) gettimeofday(&timeout, NULL);
#ifdef DEBUG
	strftime(buffer, sizeof (buffer), "%m-%d-%Y  %H:%M:%S", &timeout);
	printf("gettimeofday: %s\n", buffer);
#endif
	error_check (getnextsunriseorsunset (&timeout, coord) != 0)
		return -1;
#ifdef DEBUG
	strftime(buffer, sizeof (buffer), "%m-%d-%Y  %H:%M:%S", &timeout);
	printf("getnextsunriseorsunset: %s\n", buffer);
#endif
	error_check (r_sleept (&timeout) != 0)
		return -2;
#ifdef DEBUG
	strftime(buffer, sizeof (buffer), "%m-%d-%Y  %H:%M:%S", &timeout);
	printf("r_sleept: %s\n", buffer);
#endif
	error_check (cb (arg) != 0)
		return -3;
	return 0;
}