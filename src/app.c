/* Implementation of CalculatorApp. */
#include "app.h"

#include <gtk/gtk.h>

#include "main_window.h"

struct _CalculatorApp
{
  GtkApplication parent;
};

struct _CalculatorAppClass
{
  GtkApplicationClass parent;
};

G_DEFINE_TYPE (CalculatorApp, calculator_app, GTK_TYPE_APPLICATION);

static void calculator_app_activate (GApplication *app);

/* ----------------------------------------------*
 * GObject implementations.
 * ----------------------------------------------*/

static void
calculator_app_class_init (CalculatorAppClass *klass)
{
  GApplicationClass *g_app_class;

  g_app_class = G_APPLICATION_CLASS (klass);
  g_app_class->activate = calculator_app_activate;
}

static void
calculator_app_init (CalculatorApp *app)
{
}

/* ----------------------------------------------*
 * GApplication implementations.
 * ----------------------------------------------*/

static void
calculator_app_activate (GApplication *app)
{
  CalculatorMainWindow *win;

  win = calculator_main_window_new (CALCULATOR_APP (app));
  gtk_window_present (GTK_WINDOW (win));
}

/* ----------------------------------------------*
 * Public functions.
 * ----------------------------------------------*/

CalculatorApp *
calculator_app_new ()
{
  CalculatorApp *app;

  app = CALCULATOR_APP (g_object_new (CALCULATOR_TYPE_APP, "application-id",
                                      "org.eduardo.calculator", "flags",
                                      G_APPLICATION_FLAGS_NONE, NULL));
  return app;
}
