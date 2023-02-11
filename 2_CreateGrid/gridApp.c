#include <gtk/gtk.h>

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{

    // Initialize Window properties
  GtkWidget *window;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Grid");
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 400);


    // Make grid and set it
  GtkWidget *grid = gtk_grid_new ();
  gtk_window_set_child (GTK_WINDOW (window), grid);

    // Create button and attach it to grid
  GtkWidget *button = gtk_button_new_with_label ("Button 1");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 0, 2, 1);

    // Create button and attach it to grid
  button = gtk_button_new_with_label ("Button 2");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 1, 2, 1);

    // Create Exit button and attach it to grid
  button = gtk_button_new_with_label ("Quit");
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), window);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 0, 1, 2);


  // Show window
  gtk_widget_show (window);
}

// Driver code

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}

