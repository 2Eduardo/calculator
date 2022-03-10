/**
 * @file app.h
 * @author Eduardo Luis (you@domain.com)
 *
 * @brief CalculatorApp definition. The application class extends the
 * GtkApplication for provide system integration.
 *
 * @version 0.1
 * @date 2022-03-09
 *
 * @copyright Copyright (c) 2022
 *
 */
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
