/*  
 *  xdx - GTK+ DX-cluster client for amateur radio
 *  Copyright (C) 2002-2006 Joop Stakenborg <pg4i@amsat.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

/*
 * utils.h
 */

/*
 * Standard gettext macros.
 */
#ifdef ENABLE_NLS
#  include <libintl.h>
#  undef _
#  define _(String) dgettext (PACKAGE, String)
#  ifdef gettext_noop
#    define N_(String) gettext_noop (String)
#  else
#    define N_(String) (String)
#  endif
#else
#  define textdomain(String) (String)
#  define gettext(String) (String)
#  define dgettext(Domain,Message) (Message)
#  define dcgettext(Domain,Message,Type) (Message)
#  define bindtextdomain(Domain,Directory) (Domain)
#  define _(String) (String)
#  define N_(String) (String)
#endif


void add_pixmap_directory (const gchar * directory);
void updatestatusbar (GString * statusmessage, gboolean timeout);
void menu_set_sensitive (GtkUIManager *uim, const gchar * path, gboolean sens);
void openurl (const char *url);
void openmail (const char *url);
void opensound (const char *file);
gchar *try_utf8 (const gchar *str);
gchar *xdxgetdate (gboolean formatted);
gchar *xdxgettime (gboolean formatted);
void logconnection (GString *logstr);
gchar *my_strreplace(const char *str, const char *delimiter, const char *replacement);
