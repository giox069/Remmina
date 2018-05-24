/*
 * Remmina - The GTK+ Remote Desktop Client
 * Copyright (C) 2009-2011 Vic Lee
 * Copyright (C) 2014-2015 Antenore Gatta, Fabio Castelli, Giovanni Panozzo
 * Copyright (C) 2016-2018 Antenore Gatta, Giovanni Panozzo
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301, USA.
 *
 *  In addition, as a special exception, the copyright holders give
 *  permission to link the code of portions of this program with the
 *  OpenSSL library under certain conditions as described in each
 *  individual source file, and distribute linked combinations
 *  including the two.
 *  You must obey the GNU General Public License in all respects
 *  for all of the code used other than OpenSSL. *  If you modify
 *  file(s) with this exception, you may extend this exception to your
 *  version of the file(s), but you are not obligated to do so. *  If you
 *  do not wish to do so, delete this exception statement from your
 *  version. *  If you delete this exception statement from all source
 *  files in the program, then also delete it here.
 *
 */

#pragma once

G_BEGIN_DECLS

#define REMMINA_TYPE_MESSAGE_PANEL             (remmina_message_panel_get_type())
#define REMMINA_MESSAGE_PANEL(obj)             (G_TYPE_CHECK_INSTANCE_CAST((obj), REMMINA_TYPE_MESSAGE_PANEL, RemminaMessagePanel))
#define REMMINA_MESSAGE_PANEL_CLASS(klass)       (G_TYPE_CHECK_CLASS_CAST((klass), REMMINA_TYPE_MESSAGE_PANEL, RemminaMessagePanelClass))
#define REMMINA_IS_MESSAGE_PANEL(obj)            (G_TYPE_CHECK_INSTANCE_TYPE((obj), REMMINA_TYPE_MESSAGE_PANEL))
#define REMMINA_IS_MESSAGE_PANEL_CLASS(klass)    (G_TYPE_CHECK_CLASS_TYPE((klass), REMMINA_TYPE_MESSAGE_PANEL))
#define REMMINA_MESSAGE_PANEL_GET_CLASS(obj)     (G_TYPE_INSTANCE_GET_CLASS((obj), REMMINA_TYPE_MESSAGE_PANEL, RemminaMessagePanelClass))

enum {
	REMMINA_PANEL_MODE_IDLE,
	REMMINA_PANEL_MODE_CONNECTING,
	REMMINA_PANEL_MODE_AUTHPWD,
	REMMINA_PANEL_MODE_AUTHUSERPWD,
	REMMINA_PANEL_MODE_AUTHX509,
	REMMINA_PANEL_MODE_SERVERKEY_CONFIRM,
	REMMINA_PANEL_MODE_CERTIFICATE
};

typedef struct _RemminaMessagePanelPriv RemminaMessagePanelPriv;

typedef struct _RemminaMessagePanel {
	RemminaMessagePanelPriv *priv;
} RemminaMessagePanel;

typedef struct _RemminaMessagePanelClass {
	GtkBoxClass parent_class;
} RemminaMessagePanelClass;

GType remmina_message_panel_get_type(void)
G_GNUC_CONST;

GtkWidget* remmina_message_panel_new(const gchar *title_format, ...);
void remmina_message_panel_set_status(RemminaInitDialog *dialog, const gchar *status_format, ...);
void remmina_message_panel_set_status_temp(RemminaInitDialog *dialog, const gchar *status_format, ...);
/* Run authentication. Return GTK_RESPONSE_OK or GTK_RESPONSE_CANCEL. Caller is blocked. */
gint remmina_message_panel_authpwd(RemminaMessagePanel *mp, const gchar *message, const gchar *keylabel, gboolean allow_save);

gint remmina_message_panel_authuserpwd(RemminaInitDialog *dialog, gboolean want_domain, const gchar *default_username,
				     const gchar *default_domain, gboolean allow_save);
gint remmina_message_panel_certificate(RemminaInitDialog* dialog, const gchar* subject, const gchar* issuer, const gchar* fingerprint);
gint remmina_message_panel_certificate_changed(RemminaInitDialog* dialog, const gchar* subject, const gchar* issuer, const gchar* old_fingerprint, const gchar* new_fingerprint);
gint remmina_message_panel_authx509(RemminaInitDialog *dialog, const gchar *cacert, const gchar *cacrl, const gchar *clientcert,
				  const gchar *clientkey);
gint remmina_message_panel_serverkey_unknown(RemminaInitDialog *dialog, const gchar *serverkey);
gint remmina_message_panel_serverkey_changed(RemminaInitDialog *dialog, const gchar *serverkey);
gint remmina_message_panel_serverkey_confirm(RemminaInitDialog *dialog, const gchar *serverkey, const gchar *prompt);

gint remmina_message_panel_

G_END_DECLS


