	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wpadded"
#include <stdio.h>
#include <libnova/solar.h>
#include <libnova/julian_day.h>
#include <libnova/rise_set.h>
#include <libnova/transform.h>
	#pragma GCC diagnostic pop

static void print_date (char const title[], struct ln_zonedate* date)
{
	printf ("\n%s\n",title);
	printf (" Year    : %d\n", date->years);
	printf (" Month   : %d\n", date->months);
	printf (" Day     : %d\n", date->days);
	printf (" Hours   : %d\n", date->hours);
	printf (" Minutes : %d\n", date->minutes);
	printf (" Seconds : %f\n", date->seconds);
}

int main (int argc, char * argv[])
{
	struct ln_equ_posn equ;
	struct ln_rst_time rst;
	struct ln_zonedate rise, set, transit;
	struct ln_lnlat_posn observer;
	struct ln_helio_posn pos;
	double JD;

	/* observers location (Edinburgh), used to calc rst */
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"
	observer.lat = 55.92; /* 55.92 N */
	observer.lng = -3.18; /* 3.18 W */
	#pragma GCC diagnostic pop

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
	if (ln_get_solar_rst (JD, &observer, &rst) == 1)
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
#endif