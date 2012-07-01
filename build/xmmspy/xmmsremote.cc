/* boost::python wrapper for xmms                                            */
/*                                                                           */
/* This library is free software; you can redistribute it and/or             */
/* modify it under the terms of the GNU Lesser General Public                */
/* License as published by the Free Software Foundation; either              */
/* version 2.1 of the License, or (at your option) any later version.        */
/*                                                                           */
/* This library is distributed in the hope that it will be useful,           */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of            */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         */
/* Lesser General Public License for more details.                           */
/*                                                                           */
/* You should have received a copy of the GNU Lesser General Public          */
/* License along with this library; if not, write to the Free Software       */
/* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */
/*                                                                           */
/* For questions regarding this program contact                              */
/* Daniel Holth <dholth@fastmail.fm>                                         */

/* @class XMMSRemote
 *
 * C++ wrapper for the XMMS remote functions.
 *
 * Daniel Holth
 * 12 July 2003
 */

#include "xmmsremote.h"

void XMMSRemote::playlist(gchar ** list, gint num, gboolean enqueue)
{
  xmms_remote_playlist(this->id, list, num, enqueue);
}

gint XMMSRemote::get_version()
{
  return xmms_remote_get_version(this->id);
}

void XMMSRemote::playlist_add(GList * list)
{
  xmms_remote_playlist_add(this->id, list);
}

void XMMSRemote::playlist_delete(gint pos)
{
  xmms_remote_playlist_delete(this->id, pos);
}

void XMMSRemote::play()
{
  xmms_remote_play(this->id);
}

void XMMSRemote::pause()
{
  xmms_remote_pause(this->id);
}

void XMMSRemote::stop()
{
  xmms_remote_stop(this->id);
}

gboolean XMMSRemote::is_playing()
{
  return xmms_remote_is_playing(this->id);
}

gboolean XMMSRemote::is_paused()
{
  return xmms_remote_is_paused(this->id);
}

gint XMMSRemote::get_playlist_pos()
{
  return xmms_remote_get_playlist_pos(this->id);
}

void XMMSRemote::set_playlist_pos(gint pos)
{
  xmms_remote_set_playlist_pos(this->id, pos);
}

gint XMMSRemote::get_playlist_length()
{
  return xmms_remote_get_playlist_length(this->id);
}

void XMMSRemote::playlist_clear()
{
  xmms_remote_playlist_clear(this->id);
}

gint XMMSRemote::get_output_time()
{
  return xmms_remote_get_output_time(this->id);
}

void XMMSRemote::jump_to_time(gint pos)
{
  xmms_remote_jump_to_time(this->id, pos);
}

std::pair<gint, gint> XMMSRemote::get_volume()
{
  gint vl, vr;
  xmms_remote_get_volume(this->id, &vl, &vr);
  return std::pair<gint, gint>(vl, vr);
}

gint XMMSRemote::get_main_volume()
{
  return xmms_remote_get_main_volume(this->id);
}

gint XMMSRemote::get_balance()
{
  return xmms_remote_get_balance(this->id);
}

void XMMSRemote::set_volume(gint vl, gint vr)
{
  xmms_remote_set_volume(this->id, vl, vr);
}

void XMMSRemote::set_main_volume(gint v)
{
  xmms_remote_set_main_volume(this->id, v);
}

void XMMSRemote::set_balance(gint b)
{
  xmms_remote_set_balance(this->id, b);
}

gchar* XMMSRemote::get_skin()
{
  return xmms_remote_get_skin(this->id);
}

void XMMSRemote::set_skin(gchar * skinfile)
{
  xmms_remote_set_skin(this->id, skinfile);
}

gchar* XMMSRemote::get_playlist_file(gint pos)
{
  return xmms_remote_get_playlist_file(this->id, pos);
}

gchar* XMMSRemote::get_playlist_title(gint pos)
{
  return xmms_remote_get_playlist_title(this->id, pos);
}

gint XMMSRemote::get_playlist_time(gint pos)
{
  return xmms_remote_get_playlist_time(this->id, pos);
}

void XMMSRemote::get_info(gint * rate, gint * freq, gint * nch)
{
  xmms_remote_get_info(this->id, rate, freq, nch);
}

void XMMSRemote::main_win_toggle(gboolean show)
{
  xmms_remote_main_win_toggle(this->id, show);
}

void XMMSRemote::pl_win_toggle(gboolean show)
{
  xmms_remote_pl_win_toggle(this->id, show);
}

void XMMSRemote::eq_win_toggle(gboolean show)
{
  xmms_remote_eq_win_toggle(this->id, show);
}

gboolean XMMSRemote::is_main_win()
{
  return xmms_remote_is_main_win(this->id);
}

gboolean XMMSRemote::is_pl_win()
{
  return xmms_remote_is_pl_win(this->id);
}

gboolean XMMSRemote::is_eq_win()
{
  return xmms_remote_is_eq_win(this->id);
}

void XMMSRemote::show_prefs_box()
{
  xmms_remote_show_prefs_box(this->id);
}

void XMMSRemote::toggle_aot(gboolean ontop)
{
  xmms_remote_toggle_aot(this->id, ontop);
}

void XMMSRemote::eject()
{
  xmms_remote_eject(this->id);
}

void XMMSRemote::playlist_prev()
{
  xmms_remote_playlist_prev(this->id);
}

void XMMSRemote::playlist_next()
{
  xmms_remote_playlist_next(this->id);
}

void XMMSRemote::playlist_add_url_string(gchar * string)
{
  xmms_remote_playlist_add_url_string(this->id, string);
}

gboolean XMMSRemote::is_running()
{
  return xmms_remote_is_running(this->id);
}

void XMMSRemote::toggle_repeat()
{
  xmms_remote_toggle_repeat(this->id);
}

void XMMSRemote::toggle_shuffle()
{
  xmms_remote_toggle_shuffle(this->id);
}

gboolean XMMSRemote::is_repeat()
{
  return xmms_remote_is_repeat(this->id);
}

gboolean XMMSRemote::is_shuffle()
{
  return xmms_remote_is_shuffle(this->id);
}

void XMMSRemote::get_eq(gfloat *preamp, gfloat **bands)
{
  xmms_remote_get_eq(this->id, preamp, bands);
}

gfloat XMMSRemote::get_eq_preamp()
{
  return xmms_remote_get_eq_preamp(this->id);
}

gfloat XMMSRemote::get_eq_band(gint band)
{
  return xmms_remote_get_eq_band(this->id, band);
}

void XMMSRemote::set_eq(gfloat preamp, gfloat *bands)
{
  xmms_remote_set_eq(this->id, preamp, bands);
}

void XMMSRemote::set_eq_preamp(gfloat preamp)
{
  xmms_remote_set_eq_preamp(this->id, preamp);
}

void XMMSRemote::set_eq_band(gint band, gfloat value)
{
  xmms_remote_set_eq_band(this->id, band, value);
}

void XMMSRemote::quit()
{
  xmms_remote_quit(this->id);
}

void XMMSRemote::play_pause()
{
  xmms_remote_play_pause(this->id);
}

void XMMSRemote::playlist_ins_url_string(gchar * string, gint pos)
{
  xmms_remote_playlist_ins_url_string(this->id, string, pos);
}
