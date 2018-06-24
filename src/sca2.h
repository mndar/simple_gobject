#ifndef _SCA2_H
#define _SCA2_H

#define _GNU_SOURCE
#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS
#define SCA2_TYPE                  (sca2_get_type ())
#define SCA2(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), SCA2_TYPE, Sca2))
#define SCA2_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), SCA2_TYPE, Sca2Class))
#define IS_SCA2(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SCA2_TYPE))
#define IS_SCA2_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), SCA2_TYPE))
#define SCA2_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), SCA2_TYPE, Sca2Class))

typedef struct _Sca2 Sca2;
typedef struct _Sca2Class Sca2Class;

enum
{
  PROP_FILENAME = 1,
  N_PROPERTIES
};

static GParamSpec *obj_properties[N_PROPERTIES] = { NULL, };

typedef struct {
  gchar *filename;
  /* stuff */
} Sca2Private;

struct _Sca2
{
  GObject parent;
  gchar *sent_string;

};

struct _Sca2Class
{
  /*< private >*/
  GObjectClass parent;
};



GType sca2_get_type (void) G_GNUC_CONST;
Sca2 *sca2_new (void);
void sca2_some_function (Sca2 *, gchar *);
G_END_DECLS

#endif /* _SCA2_H */
