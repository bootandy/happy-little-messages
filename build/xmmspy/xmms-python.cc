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

/**
 * @file xmms-python.cc
 *
 * Write xmms remote controls in Python!
 * 
 * @author Daniel Holth
 */

#include <boost/python.hpp>
#include <boost/python/def.hpp>
#include <boost/python/module.hpp>
#include <boost/python/errors.hpp>
#include <boost/python/tuple.hpp>
#include <boost/python/args.hpp>

#include <list>
#include <utility>

#include "xmmsremote.h"

using namespace boost::python;

struct gchar_to_python
{
  static PyObject* convert(gchar *x)
  {
    if(x == NULL)
    {
      return Py_None;
    } else {
      return PyString_FromString((char*)x);
    }
  }
};

struct gintpair_to_tuple
{
  static PyObject* convert(std::pair<gint, gint> const &x)
  {
    return Py_BuildValue("(ii)", x.first, x.second);
  }
};

tuple XMMSRemote_get_eq(XMMSRemote &r)
{
  gfloat bands[10];
  gfloat preamp;
  tuple pybands;
  
  preamp = r.get_eq_preamp();
  for(int i = 0; i < 10; i++)
  {
    bands[i] = r.get_eq_band(i);
  }

  pybands = make_tuple(bands[0],
                       bands[1], 
                       bands[2],
                       bands[3],
                       bands[4],
                       bands[5],
                       bands[6],
                       bands[7],
                       bands[8],
                       bands[9]);

  return make_tuple(preamp, pybands);
}

tuple XMMSRemote_get_info(XMMSRemote &r)
{
  gint rate;
  gint freq;
  gint nch;
  r.get_info(&rate, &freq, &nch);
  return make_tuple(rate, freq, nch);
}


void XMMSRemote_set_eq(XMMSRemote &r, gfloat preamp, tuple pybands)
{
  gfloat bands[10];
  for(int i = 0; i < 10; i++)
  {
    bands[i] = extract<float>(pybands[i]);
  }
  r.set_eq(preamp, bands);
}


BOOST_PYTHON_MODULE_INIT(xmms)
{
  to_python_converter < gchar*, gchar_to_python > ();
  to_python_converter < std::pair<gint, gint>,  gintpair_to_tuple > ();

  ////////////////// xmms remote ///////////////////
  class_<XMMSRemote>("Remote")
    // .def("playlist", &XMMSRemote::playlist)                     // NOT OK
    .def("get_version", &XMMSRemote::get_version)               // ok
    .def("playlist_add", &XMMSRemote::playlist_add)             // ok
    .def("playlist_delete", &XMMSRemote::playlist_delete)       // ok
    .def("play", &XMMSRemote::play)                             // ok
    .def("pause", &XMMSRemote::pause)                           // ok
    .def("stop", &XMMSRemote::stop)                             // ok
    .def("is_playing", &XMMSRemote::is_playing)                 // ok
    .def("is_paused", &XMMSRemote::is_paused)                   // ok

    .def("get_playlist_pos", &XMMSRemote::get_playlist_pos)     // ok
    .def("set_playlist_pos", &XMMSRemote::set_playlist_pos)     // ok (doesn't raise IndexError if oob)
    .add_property("playlist_pos", &XMMSRemote::get_playlist_pos, &XMMSRemote::set_playlist_pos) // ok

    .def("get_playlist_length", &XMMSRemote::get_playlist_length,
         "Return the number of elements in playlist.")                  // ok
    .add_property("playlist_length", &XMMSRemote::get_playlist_length)  // ok

    .def("playlist_clear", &XMMSRemote::playlist_clear)                 // ok

    .def("get_output_time", &XMMSRemote::get_output_time,
         "Return playback position of current audio (milliseconds).")   // ok
    .def("jump_to_time", &XMMSRemote::jump_to_time,
         "Seek to a number of milliseconds past the beginning of the current file.")  // ok
    
    .def("get_volume", &XMMSRemote::get_volume) // ok
    .def("set_volume", &XMMSRemote::set_volume) // ok (doesn't accept tuple)              
    
    .def("get_main_volume", &XMMSRemote::get_main_volume)
    .def("set_main_volume", &XMMSRemote::set_main_volume)
    .add_property("main_volume", &XMMSRemote::get_main_volume, &XMMSRemote::set_main_volume)
    
    .def("get_balance", &XMMSRemote::get_balance)
    .def("set_balance", &XMMSRemote::set_balance)
    .add_property("balance", &XMMSRemote::get_balance, &XMMSRemote::set_balance)

    .def("get_skin", &XMMSRemote::get_skin, return_value_policy<return_by_value>())
    .def("set_skin", &XMMSRemote::set_skin)

    // these three are ok:
    .def("get_playlist_file", &XMMSRemote::get_playlist_file,
         return_value_policy<return_by_value>(),
         "Return the filename of a playlist item.")
    .def("get_playlist_title", &XMMSRemote::get_playlist_title, 
         return_value_policy<return_by_value>(),
         "Return the title of a playlist item.")
    .def("get_playlist_time", &XMMSRemote::get_playlist_time,
         "Return length (milliseconds) of a playlist item")
    
    .def("get_info", &XMMSRemote_get_info,
         "Return (bits per second, frequency, channels) for the playing audio.")    // ok
    
    .def("is_main_win", &XMMSRemote::is_main_win)                                   // ok
    .def("main_win_toggle", &XMMSRemote::main_win_toggle)                           // ok
    
    .def("is_pl_win", &XMMSRemote::is_pl_win)                                       // ok
    .def("pl_win_toggle", &XMMSRemote::pl_win_toggle)                               // ok
    
    .def("is_eq_win", &XMMSRemote::is_eq_win)                                       // ok
    .def("eq_win_toggle", &XMMSRemote::eq_win_toggle)                               // ok

    .def("show_prefs_box", &XMMSRemote::show_prefs_box)                             // ok
    .def("toggle_aot", &XMMSRemote::toggle_aot)                                     // what does it do?
    .def("eject", &XMMSRemote::eject)                                               // ok
    .def("playlist_prev", &XMMSRemote::playlist_prev)                               // ok
    .def("playlist_next", &XMMSRemote::playlist_next)                               // ok
    .def("playlist_add_url_string", &XMMSRemote::playlist_add_url_string)           // ok
    .def("is_running", &XMMSRemote::is_running)                                     // ok
    
    .def("is_repeat", &XMMSRemote::is_repeat)
    .def("toggle_repeat", &XMMSRemote::toggle_repeat)                               // ok
    
    .def("is_shuffle", &XMMSRemote::is_shuffle)                                     // ok
    .def("toggle_shuffle", &XMMSRemote::toggle_shuffle)                             // ok
    
    .def("get_eq", &XMMSRemote_get_eq)    // ok
    .def("set_eq", &XMMSRemote_set_eq)    // ok but needs two arguments
    
    .def("get_eq_preamp", &XMMSRemote::get_eq_preamp, "Return equalizier preamp (-20.0 to 20.0 db).") // ok
    .def("set_eq_preamp", &XMMSRemote::set_eq_preamp)                                                 // ok
    .add_property("eq_preamp", &XMMSRemote::get_eq_preamp, &XMMSRemote::set_eq_preamp)
    
    .def("get_eq_band", &XMMSRemote::get_eq_band, 
         "Return gain (-20.0 to 20.0 db) for one of ten equalizer bands.")  // ok (no IndexError on oob)
//    .def("set_eq", &XMMSRemote::set_eq)
    .def("set_eq_band", &XMMSRemote::set_eq_band)                           // ok (no IndexError on oob)
    .def("quit", &XMMSRemote::quit)                                         // ok
    .def("play_pause", &XMMSRemote::play_pause)                             // ok
    .def("playlist_ins_url_string", &XMMSRemote::playlist_ins_url_string)   // ok
    ;
}

