/**
 * @file main.c
 * @author Eduardo Luis
 * @brief The Calculator application entry point.
 * @version 0.1
 * @date 2022-03-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <gtk/gtk.h>

#include "app.h"

/*
  1 - Get a string from view module;
  2 - Parse a string into math expressions.
  3 - Calculate the result.
*/

int
main (int argc, char *argv[])
{
  CalculatorApp *app;
  int status;

  app = calculator_app_new ();
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
