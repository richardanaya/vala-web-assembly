/* example.c generated by valac 0.46.6, the Vala compiler
 * generated from example.vala, do not modify */

#include <glib.h>
#include <float.h>
#include <math.h>

gfloat jsffiregister (gchar* msg);
gfloat jsfficall1 (gfloat context,
                   gfloat fn,
                   gfloat arg_1_type,
                   gfloat arg_1_value);
#define JS_UNDEFINED 0.0f
#define TYPE_STRING 2.0f
gint __attribute__((visibility("default"))) main (void);

gint
__attribute__((visibility("default"))) main (void)
{
	gfloat log = 0.0F;
	gint result = 0;
	log = jsffiregister ("window.alert");
	jsfficall1 ((gfloat) 0, log, TYPE_STRING, (gfloat) ((gint) "Hello World!"));
	result = 0;
	return result;
}
