#ifndef NDEBUG
#include <stdio.h>
#include <time.h>
#endif

	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wpadded"
#include <libnova/solar.h>
#include <libnova/julian_day.h>
#include <libnova/rise_set.h>
#include <libnova/transform.h>
	#pragma GCC diagnostic pop

#include <restart.h>

#include <ava.h>

#ifndef NDEBUG
__attribute__ ((nonnull (1, 2), nothrow))
static void print_date (
	char const title[],
	struct ln_zonedate const *restrict date) {
	printf ("\n%s\n",title);
	printf (" Year    : %d\n", date->years);
	printf (" Month   : %d\n", date->months);
	printf (" Day     : %d\n", date->days);
	printf (" Hours   : %d\n", date->hours);
	printf (" Minutes : %d\n", date->minutes);
	printf (" Seconds : %f\n", date->seconds);
}

/*__attribute__ ((nonnull (1), nothrow))
static void init_ln_zonedate (struct ln_zonedate *restrict rise) {*/
	/*rise->years = 0;
	rise->months = 1;
	rise->days = 0;*/
	/*rise->hours   = 0;
	rise->minutes = 0;
	rise->seconds = 0;
	rise->gmtoff  = 86400 + (-5 * 60 * 60);
}*/
#endif

/*__attribute__ ((nonnull (1), nothrow))
static void init_ln_rst_time (struct ln_rst_time *restrict rise) {
	rise->rise    = 0;
	rise->set     = 0;
	rise->transit = 0;
}*/






__attribute__ ((leaf, nonnull (1, 2), warn_unused_result))
int set_ava (
	struct ln_lnlat_posn *restrict observer,
	stdcb_t cb,
	void *arg) {
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
	printf ("JD %f\n", JD);

	/* geometric coordinates */
	ln_get_solar_geom_coords (JD, &pos);
	printf("Solar Coords longitude (deg) %f\n", pos.L);
	printf("             latitude (deg) %f\n", pos.B);
	printf("             radius vector (AU) %f\n", pos.R);

	/* ra, dec */
	ln_get_solar_equ_coords (JD, &equ);
	printf("Solar Position RA %f\n", equ.ra);
	printf("               DEC %f\n", equ.dec);

	/* rise, set and transit */
	if (ln_get_solar_rst (JD, observer, &rst) == 1)
		printf ("Sun is circumpolar\n");
	else {
		ln_get_local_date (rst.rise, &rise);
		ln_get_local_date (rst.transit, &transit);
		ln_get_local_date (rst.set, &set);
		print_date ("Rise", &rise);
		print_date ("Transit", &transit);
		print_date ("Set", &set);
	}

	return 0;
}
















#ifdef NWTF
__attribute__ ((leaf, nonnull (1, 2), warn_unused_result))
/*int set_ava (coord_t *restrict coord, stdcb_t cb, void *arg) {*/
int set_ava (
	struct ln_lnlat_posn *restrict observer,
	stdcb_t cb,
	void *arg) {
#ifndef NDEBUG
	char buffer[32];
#endif
	struct ln_equ_posn equ;
	struct ln_rst_time rst;
	struct ln_zonedate rise, set, transit;
	struct ln_helio_posn pos;
	double JD;

	double minrs;
	struct timeval tv;

	/* observers location (Edinburgh), used to calc rst */
	/*observer.lat = 55.92;*/ /* 55.92 N */
	/*observer.lng = -3.18;*/ /* 3.18 W */

	/* get Julian day from local time */
	JD = ln_get_julian_from_sys();
#ifndef NDEBUG
	printf ("JD %f\n", JD);
#endif

	/* geometric coordinates */
	ln_get_solar_geom_coords (JD, &pos);
#ifndef NDEBUG
	printf("Solar Coords longitude (deg) %f\n", pos.L);
	printf("             latitude (deg) %f\n", pos.B);
	printf("             radius vector (AU) %f\n", pos.R);
#endif

	/* ra, dec */
	ln_get_solar_equ_coords (JD, &equ);
#ifndef NDEBUG
	printf("Solar Position RA %f\n", equ.ra);
	printf("               DEC %f\n", equ.dec);
#endif

	/* rise, set and transit */
	if (ln_get_solar_rst (JD, observer, &rst) == 1) {
#ifndef NDEBUG
		printf ("Sun is circumpolar\n");
#endif
		return -1;
	} /*else {*/
#ifndef NDEBUG
	ln_get_local_date (rst.rise, &rise);
	ln_get_local_date (rst.transit, &transit);
	ln_get_local_date (rst.set, &set);
	print_date ("Rise", &rise);
	print_date ("Transit", &transit);
	print_date ("Set", &set);
#endif
/*
	tv.tv_usec = 0;
	if (rst.set < rst.rise) minrs = rst.set;
	else                    minrs = rst.rise;
	ln_get_timet_from_julian (minrs, &(tv.tv_sec));
#ifndef NDEBUG
	strftime(buffer, sizeof (buffer), "%m-%d-%Y  %H:%M:%S", localtime (&(tv.tv_sec)));
	printf("getnextsunriseorsunset: %s\n", buffer);
#endif
	error_check (r_sleept (&tv) != 0)
		return -2;
	error_check (cb (arg) != 0)
		return -3;
*/
	return 0;
	/*}*/
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
#endif