/*
 * xdx - GTK+ DX-cluster client for amateur radio
 * Copyright (C) 2002-2006 Joop Stakenborg <pg4i@amsat.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

/*
 * gui_logdialog.c - dialog for opening the connection log
 */

#include <gtk/gtk.h>
#include <unistd.h>

#include "utils.h"
#include "gui.h"
#include "gui_logdialog.h"

/*
 * called from the menu
 */
void
on_log_activate (GtkMenuItem * menuitem, gpointer user_data)
{
  GtkWidget *logdialog, *vbox, *logdialog_scrolledwindow, *logdialog_textview;
  gint response;
  FILE *fd;
  gchar *filename;
  GtkTextBuffer *buffer;
  GtkTextIter start, end;
  GtkTextMark *mark;
  gint numread = 0;
  gchar buf[1025];

  logdialog = gtk_dialog_new_with_buttons (_("xdx - connection log"),
              GTK_WINDOW (gui->window),
              GTK_DIALOG_MODAL |
              GTK_DIALOG_DESTROY_WITH_PARENT,
              GTK_STOCK_CLEAR, GTK_RESPONSE_CANCEL, 
              GTK_STOCK_CLOSE, GTK_RESPONSE_OK,
              NULL);
  gtk_widget_set_size_request (logdialog, 600, 300);
  vbox = gtk_vbox_new (FALSE, 8);
  gtk_container_set_border_width (GTK_CONTAINER (vbox), 8);
  gtk_container_add (GTK_CONTAINER
                        (GTK_DIALOG (logdialog)->vbox), vbox);
  logdialog_scrolledwindow = gtk_scrolled_window_new (NULL, NULL);
  gtk_box_pack_start (GTK_BOX (vbox), logdialog_scrolledwindow, TRUE, TRUE, 0);
  gtk_scrolled_window_set_policy
    (GTK_SCROLLED_WINDOW (logdialog_scrolledwindow),
     GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  logdialog_textview = gtk_text_view_new ();
  gtk_text_view_set_editable (GTK_TEXT_VIEW(logdialog_textview), FALSE);
  gtk_text_view_set_cursor_visible (GTK_TEXT_VIEW(logdialog_textview), FALSE);
  gtk_container_add
    (GTK_CONTAINER (logdialog_scrolledwindow), logdialog_textview);

  filename = g_strdup_printf ("%s/log.txt", gui->preferencesdir);
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (logdialog_textview));
  gtk_text_buffer_get_bounds (buffer, &start, &end);

  fd = fopen (filename, "r");
  if ((fd = fopen(filename, "r"))) 
  { 
    while (!feof(fd))  
    {
      numread = fread(buf, 1, 1024, fd);
      gtk_text_buffer_insert (buffer, &end, buf, numread);
      mark = gtk_text_buffer_get_mark (buffer, "insert");
      gtk_text_view_scroll_to_mark(GTK_TEXT_VIEW(logdialog_textview), mark,
        0.0, FALSE, 0.0, 1.0);
     }
     fclose (fd);
  }

  gtk_widget_show_all (logdialog);
  response = gtk_dialog_run (GTK_DIALOG (logdialog));
  if (response == GTK_RESPONSE_CANCEL)
  {
    gtk_text_buffer_set_text (buffer, "", -1);
    unlink (filename);
    response = gtk_dialog_run (GTK_DIALOG (logdialog));
  }
  gtk_widget_destroy (logdialog);
}
