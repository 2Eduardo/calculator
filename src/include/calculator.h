#ifndef CALCULATOR_APP_H
#define CALCULATOR_APP_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

// clang-format off
#define CALCULATOR_TYPE_APP       		(calculator_app_get_type ())
#define CALCULATOR_APP(obj)			      (G_TYPE_CHECK_INSTANCE_CAST ((obj), CALCULATOR_TYPE_APP, CalculatorApp))
#define CALCULATOR_APP_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST((klass), CALCULATOR_TYPE_APP, CalculatorAppClass))
#define ALMANAH_IS_APP(obj)		        (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CALCULATOR_TYPE_APP))
#define ALMANAH_IS_APP_CLASS(klass)	  (G_TYPE_CHECK_CLASS_TYPE ((klass), CALCULATOR_TYPE_APP))
#define CALCULATOR_APP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CALCULATOR_TYPE_APP, CalculatorAppClass))
// clang-format on

typedef struct _CalculatorAppPrivate CalculatorAppPrivate; /* forward. */

typedef struct
{
  GtkApplication parent;
} CalculatorApp;

typedef struct
{
  GtkApplicationClass parent;
} CalculatorAppClass;

GType calculator_app_get_type();

CalculatorApp *calculator_app_new (void);

G_END_DECLS

#endif /* CALCULATOR_APP_H */
