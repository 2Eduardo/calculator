/* The CalculatorMainWindow definition. This class extends GtkApplicationWindow
 * and act as the main user interface. */
#ifndef CALCULATOR_MAIN_WINDOW_H
#define CALCULATOR_MAIN_WINDOW_H

#include <gtk/gtk.h>

#include "app.h"

G_BEGIN_DECLS

#define CALCULATOR_TYPE_MAIN_WINDOW (calculator_main_window_get_type ())
G_DECLARE_FINAL_TYPE (CalculatorMainWindow, calculator_main_window, CALCULATOR,
                      MAIN_WINDOW, GtkApplicationWindow);

CalculatorMainWindow *calculator_main_window_new (CalculatorApp *app);

G_END_DECLS

#endif /* CALCULATOR_MAIN_WINDOW_H */
