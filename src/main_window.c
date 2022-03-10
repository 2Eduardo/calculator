/**
 * @file main_window.c
 * @author Eduardo Luis
 *
 * @brief Implementation of CalculatorMainWindow, the main user interface
 * class.
 * 
 * @version 0.1
 * @date 2022-03-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "main_window.h"

#include <gtk/gtk.h>

#include "app.h"
#include "math_parse.h"

struct _CalculatorMainWindow
{
  GtkApplicationWindow parent;

  GtkWidget *result_box;
  GtkWidget *entry;
  GtkWidget *submit_btn;
};

struct _CalculatorMainWindowClass
{
  GtkApplicationWindowClass parent_class;
};

G_DEFINE_TYPE (CalculatorMainWindow, calculator_main_window,
               GTK_TYPE_APPLICATION_WINDOW);

static void on_submit_btn (GtkButton *button, CalculatorMainWindow *window);
static void on_result (double value, CalculatorMainWindow *window);

/* ----------------------------------------------*
 * GObject implementations.
 * ----------------------------------------------*/

static void
calculator_main_window_class_init (CalculatorMainWindowClass *klass)
{
  GtkWidgetClass *widget_class;

  widget_class = GTK_WIDGET_CLASS (klass);
  gtk_widget_class_set_template_from_resource (
      widget_class, "/org/2Eduardo/calculator/ui/main_window.ui");

  gtk_widget_class_bind_template_child (widget_class, CalculatorMainWindow,
                                        result_box);
  gtk_widget_class_bind_template_child (widget_class, CalculatorMainWindow,
                                        entry);
  gtk_widget_class_bind_template_child (widget_class, CalculatorMainWindow,
                                        submit_btn);
}

static void
calculator_main_window_init (CalculatorMainWindow *main_window)
{
  gtk_widget_init_template (GTK_WIDGET (main_window));

  g_signal_connect (GTK_BUTTON (main_window->submit_btn), "clicked",
                    G_CALLBACK (on_submit_btn), main_window);
}

/*  */

static void
on_submit_btn (GtkButton *button, CalculatorMainWindow *window)
{
  const char *expression = gtk_entry_get_text (GTK_ENTRY (window->entry));
  ParseNode *parse;
  double result;

  parse = math_parse_str (expression);
  result = math_parse_eval (parse);
  math_parse_free (parse);

  on_result (result, window);
}

static void
on_result (double value, CalculatorMainWindow *window)
{
  GtkBox *box = GTK_BOX (window->result_box);
  GtkWidget *result_label;
  char result_str[50];

  snprintf (result_str, 50, "%lf", value);

  result_label = gtk_label_new (result_str);
  gtk_box_pack_start (box, result_label, 1, 1, 1);
  gtk_widget_set_visible (window->result_box, TRUE);
  gtk_widget_show_all (GTK_WIDGET (window));
}

/* ----------------------------------------------*
 * Public functions.
 * ----------------------------------------------*/

CalculatorMainWindow *
calculator_main_window_new (CalculatorApp *app)
{
  CalculatorMainWindow *main_window;

  main_window = CALCULATOR_MAIN_WINDOW (
      g_object_new (CALCULATOR_TYPE_MAIN_WINDOW, "application", app, NULL));

  return main_window;
}
