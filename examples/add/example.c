/* example.c generated by valac 0.46.6, the Vala compiler
 * generated from example.vala, do not modify */

/* classes work!*/

#include <glib-object.h>
#include <glib.h>
#include <gobject/gvaluecollector.h>

#define TYPE_CALCULATOR (calculator_get_type ())
#define CALCULATOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_CALCULATOR, Calculator))
#define CALCULATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_CALCULATOR, CalculatorClass))
#define IS_CALCULATOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_CALCULATOR))
#define IS_CALCULATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_CALCULATOR))
#define CALCULATOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_CALCULATOR, CalculatorClass))

typedef struct _Calculator Calculator;
typedef struct _CalculatorClass CalculatorClass;
typedef struct _CalculatorPrivate CalculatorPrivate;
typedef struct _ParamSpecCalculator ParamSpecCalculator;

struct _Calculator {
	GTypeInstance parent_instance;
	volatile int ref_count;
	CalculatorPrivate * priv;
};

struct _CalculatorClass {
	GTypeClass parent_class;
	void (*finalize) (Calculator *self);
};

struct _ParamSpecCalculator {
	GParamSpec parent_instance;
};

static gpointer calculator_parent_class = NULL;

gpointer calculator_ref (gpointer instance);
void calculator_unref (gpointer instance);
GParamSpec* param_spec_calculator (const gchar* name,
                                   const gchar* nick,
                                   const gchar* blurb,
                                   GType object_type,
                                   GParamFlags flags);
void value_set_calculator (GValue* value,
                           gpointer v_object);
void value_take_calculator (GValue* value,
                            gpointer v_object);
gpointer value_get_calculator (const GValue* value);
GType calculator_get_type (void) G_GNUC_CONST;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (Calculator, calculator_unref)
gint calculator_add (gint a,
                     gint b);
Calculator* calculator_new (void);
Calculator* calculator_construct (GType object_type);
static void calculator_finalize (Calculator * obj);
gint __attribute__((visibility("default"))) add (gint a,
                                                 gint b);

gint
calculator_add (gint a,
                gint b)
{
	gint result = 0;
	result = a + b;
	return result;
}

Calculator*
calculator_construct (GType object_type)
{
	Calculator* self = NULL;
	self = (Calculator*) g_type_create_instance (object_type);
	return self;
}

Calculator*
calculator_new (void)
{
	return calculator_construct (TYPE_CALCULATOR);
}

static void
value_calculator_init (GValue* value)
{
	value->data[0].v_pointer = NULL;
}

static void
value_calculator_free_value (GValue* value)
{
	if (value->data[0].v_pointer) {
		calculator_unref (value->data[0].v_pointer);
	}
}

static void
value_calculator_copy_value (const GValue* src_value,
                             GValue* dest_value)
{
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = calculator_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}

static gpointer
value_calculator_peek_pointer (const GValue* value)
{
	return value->data[0].v_pointer;
}

static gchar*
value_calculator_collect_value (GValue* value,
                                guint n_collect_values,
                                GTypeCValue* collect_values,
                                guint collect_flags)
{
	if (collect_values[0].v_pointer) {
		Calculator * object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = calculator_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}

static gchar*
value_calculator_lcopy_value (const GValue* value,
                              guint n_collect_values,
                              GTypeCValue* collect_values,
                              guint collect_flags)
{
	Calculator ** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = calculator_ref (value->data[0].v_pointer);
	}
	return NULL;
}

GParamSpec*
param_spec_calculator (const gchar* name,
                       const gchar* nick,
                       const gchar* blurb,
                       GType object_type,
                       GParamFlags flags)
{
	ParamSpecCalculator* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TYPE_CALCULATOR), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}

gpointer
value_get_calculator (const GValue* value)
{
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_CALCULATOR), NULL);
	return value->data[0].v_pointer;
}

void
value_set_calculator (GValue* value,
                      gpointer v_object)
{
	Calculator * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_CALCULATOR));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_CALCULATOR));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		calculator_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		calculator_unref (old);
	}
}

void
value_take_calculator (GValue* value,
                       gpointer v_object)
{
	Calculator * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_CALCULATOR));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_CALCULATOR));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		calculator_unref (old);
	}
}

static void
calculator_class_init (CalculatorClass * klass,
                       gpointer klass_data)
{
	calculator_parent_class = g_type_class_peek_parent (klass);
	((CalculatorClass *) klass)->finalize = calculator_finalize;
}

static void
calculator_instance_init (Calculator * self,
                          gpointer klass)
{
	self->ref_count = 1;
}

static void
calculator_finalize (Calculator * obj)
{
	Calculator * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_CALCULATOR, Calculator);
	g_signal_handlers_destroy (self);
}

GType
calculator_get_type (void)
{
	static volatile gsize calculator_type_id__volatile = 0;
	if (g_once_init_enter (&calculator_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { value_calculator_init, value_calculator_free_value, value_calculator_copy_value, value_calculator_peek_pointer, "p", value_calculator_collect_value, "p", value_calculator_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (CalculatorClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) calculator_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Calculator), 0, (GInstanceInitFunc) calculator_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType calculator_type_id;
		calculator_type_id = g_type_register_fundamental (g_type_fundamental_next (), "Calculator", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&calculator_type_id__volatile, calculator_type_id);
	}
	return calculator_type_id__volatile;
}

gpointer
calculator_ref (gpointer instance)
{
	Calculator * self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}

void
calculator_unref (gpointer instance)
{
	Calculator * self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		CALCULATOR_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}

gint
__attribute__((visibility("default"))) add (gint a,
                                            gint b)
{
	gint result = 0;
	result = calculator_add (a, b);
	return result;
}

