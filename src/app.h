/* Replacement for GtkApplication. */
#ifndef CALCULATOR_APP_H
#define CALCULATOR_APP_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define CALCULATOR_TYPE_APP (calculator_app_get_type ())
G_DECLARE_FINAL_TYPE (CalculatorApp, calculator_app, CALCULATOR, APP,
                      GtkApplication);

CalculatorApp *calculator_app_new ();

G_END_DECLS

#endif /* CALCULATOR_APP_H */
