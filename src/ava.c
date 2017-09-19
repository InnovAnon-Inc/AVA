#ifdef DEBUG
#include <stdio.h>
#endif

#include <libnova/solar.h>
#include <libnova/julian_day.h>
#include <libnova/rise_set.h>
#include <libnova/transform.h>

#include <restart.h>

#include <ava.h>

__attribute__ ((leaf, nonnull (1, 2), warn_unused_result))
/*int set_ava (coord_t *restrict coord, stdcb_t cb, void *arg) {*/
int set_ava (
	struct ln_lnlat_posn *restrict observer,
	stdcb_t cb,
	void *arg) {
#ifdef DEBUG
	char buffer[32];
#endif
	struct ln_equ_posn equ;
	struct ln_rst_time rst;
	struct ln_zonedate rise, set, transit;
	struct ln_helio_posn pos;
	double JD;

	/* observers location (Edinburgh), used to calc rst */
	/*observer.lat = 55.92;*/ /* 55.92 N */
	/*observer.lng = -3.18;*/ /* 3.18 W */

	/* get Julian day from local time */
	JD = ln_get_julian_from_sys();
	/*printf ("JD %f\n", JD);*/

	/* geometric coordinates */
	ln_get_solar_geom_coords (JD, &pos);
	/*printf("Solar Coords longitude (deg) %f\n", pos.L);
	printf("             latitude (deg) %f\n", pos.B);
	printf("             radius vector (AU) %f\n", pos.R);*/

	/* ra, dec */
	ln_get_solar_equ_coords (JD, &equ);
	/*printf("Solar Position RA %f\n", equ.ra);
	printf("               DEC %f\n", equ.dec);*/

	/* rise, set and transit */
	if (ln_get_solar_rst (JD, observer, &rst) == 1)
		/*printf ("Sun is circumpolar\n");*/
		return -1;
	else {
		/*ln_get_local_date (rst.rise, &rise);
		ln_get_local_date (rst.transit, &transit);
		ln_get_local_date (rst.set, &set);
		print_date ("Rise", &rise);
		print_date ("Transit", &transit);
		print_date ("Set", &set);*/
		double minrs;
		struct timeval tv;
		tv.tv_usec = 0;
		minrs = minf (rst.rise, rst.set);
		ln_get_timet_from_julian (minrs, &(tv.tv_sec));
#ifdef DEBUG
		strftime(buffer, sizeof (buffer), "%m-%d-%Y  %H:%M:%S", &tv);
		printf("getnextsunriseorsunset: %s\n", buffer);
#endif
		error_check (r_sleept (&timeout) != 0)
			return -2;
		error_check (cb (arg) != 0)
			return -3;
		return 0;
	}

	return 0;
	/*
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
	*/
}