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

/* XMMS Remote C++ Wrapper
 *
 * A safer, less ambiguous way to use xmms_remote.
 *
 * Daniel Holth <dholth@fastmail.fm>
 * 12 July 2003
 */

#ifndef XMMSPP_H
#define XMMSPP_H

#include <xmms/xmmsctrl.h>
#include <string>
#include <vector>
#include <utility>

class XMMSRemote {
  public:
    gint id;

    XMMSRemote()  { this->id = 0; }

    void playlist(gchar ** list, gint num, gboolean enqueue);
    gint get_version();
    void playlist_add(GList * list);
    void playlist_delete(gint pos);
    void play();
    void pause();
    void stop();
    gboolean is_playing();
    gboolean is_paused();
    gint get_playlist_pos();
    void set_playlist_pos(gint pos);
    gint get_playlist_length();
    void playlist_clear();
    gint get_output_time();
    void jump_to_time(gint pos);
    
    std::pair<gint, gint> get_volume();
    void set_volume(gint vl, gint vr);
    
    gint get_main_volume();
    gint get_balance();
    void set_main_volume(gint v);
    void set_balance(gint b);
    gchar* get_skin();
    void set_skin(gchar * skinfile);
    gchar* get_playlist_file(gint pos);
    gchar* get_playlist_title(gint pos);
    gint get_playlist_time(gint pos);
    void get_info(gint * rate, gint * freq, gint * nch);
    void main_win_toggle(gboolean show);
    void pl_win_toggle(gboolean show);
    void eq_win_toggle(gboolean show);
    gboolean is_main_win();
    gboolean is_pl_win();
    gboolean is_eq_win();
    void show_prefs_box();
    void toggle_aot(gboolean ontop);
    void eject();
    void playlist_prev();
    void playlist_next();
    void playlist_add_url_string(gchar * string);
    gboolean is_running();
    void toggle_repeat();
    void toggle_shuffle();
    gboolean is_repeat();
    gboolean is_shuffle();
    void get_eq(gfloat *preamp, gfloat **bands);
    gfloat get_eq_preamp();
    gfloat get_eq_band(gint band);
    void set_eq(gfloat preamp, gfloat *bands);
    void set_eq_preamp(gfloat preamp);
    void set_eq_band(gint band, gfloat value);
    void quit();
    void play_pause();
    void playlist_ins_url_string(gchar * string, gint pos); 
};

#endif
