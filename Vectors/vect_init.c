#include <stdio.h>
#define MANGLE_DOUBLE(name)     name ## _rd

typedef struct __attribute__ ((alligned(16))) {
	double x; double y; } e_double2;

#define DEFINE_VECTOR2_API(X, V)			\
	static inline V X(vadd)(const V a, const V b) { \
		V c = {a.x + b.x, a.y + b.y};		\
		return c;				\
	}						\

DEFINE_VECTOR2_API(MANGLE_DOUBLE, e_double2)
#undef DEFINE_VECTOR2_API

int
main(void)
{
	printf("double %lu\n", sizeof(double));
	printf("long double %lu\n", sizeof(long double));
	e_double2 a, b, c;
	a.x = 5.0;
	a.y = 10.0;
	b.x = 7.0;
	b.y = 15.0;

	c = vadd_rd(a, b);
	printf("c.x = %.1f\n", c.x);
	printf("c.y = %.1f\n", c.y);
	return 0;
}
