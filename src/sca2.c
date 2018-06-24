#include <glib.h>
#include "sca2.h"

G_DEFINE_TYPE_WITH_PRIVATE (Sca2, sca2, G_TYPE_OBJECT);

static guint sca2_signals[1] = { 0 };

static void
sca2_init (Sca2 *self)
{
	self = SCA2 (self);
}

static void
sca2_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec) {
	Sca2 *self = SCA2 (object);
	switch (property_id) {
		default:
			/* We don't have any other property... */
			G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
			break;
	}
}

static void
sca2_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec) {
	Sca2 *self = SCA2 (object);
	Sca2Private *priv = sca2_get_instance_private (self);
	switch (property_id) {
		case PROP_FILENAME:
			g_value_set_string (value, priv->filename);
			break;
	}
}

static void
sca2_class_init (Sca2Class *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);
	object_class->set_property = sca2_set_property;
	object_class->get_property = sca2_get_property;

	obj_properties[PROP_FILENAME] = g_param_spec_string ("filename", "Filename", "Name of the file to load and display from.", NULL, G_PARAM_READWRITE);

	g_object_class_install_properties (object_class, N_PROPERTIES, obj_properties);
	
	GType param_types[2];
	param_types[0] = G_TYPE_POINTER;
	param_types[1] = G_TYPE_UINT;
	sca2_signals[0] =   g_signal_newv ("child-finished",
																						G_TYPE_FROM_CLASS (object_class),
																						G_SIGNAL_RUN_LAST | G_SIGNAL_NO_RECURSE | G_SIGNAL_NO_HOOKS,
																						NULL /* closure */,
																						NULL /* accumulator */,
																						NULL /* accumulator data */,
																						NULL /* C marshaller */,
																						G_TYPE_NONE /* return_type */,
																						2     /* n_params */,
																						param_types  /* param_types */);


}

Sca2 *
sca2_new (void)
{
	Sca2 *obj;
	obj = g_object_new (SCA2_TYPE, NULL);

	return obj;
}
