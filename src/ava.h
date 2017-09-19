#ifndef _AVA_H_
#define _AVA_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <libnova/ln_types.h>

#include <glitter.h>
/*#include <solar.h>

int set_ava (coord_t *restrict coord, stdcb_t cb, void *arg)*/
int set_ava (
	struct ln_lnlat_posn *restrict observer,
	stdcb_t cb,
	void *arg)
__attribute__ ((leaf, nonnull (1, 2), warn_unused_result)) ;

#ifdef __cplusplus
}
#endif

#endif /* _AVA_H_ */