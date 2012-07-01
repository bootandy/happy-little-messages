#!/usr/bin/env python
#
# For xmmspy.  Control XMMS from Python.
#
# Daniel Holth <dholth@fastmail.fm>
# 13 July 2003

from distutils.core import setup
from distutils.extension import Extension

description = """xmmspy is a wrapper for all but one xmms_remote
function. (xmms_remote_playlist).  It's written with boost::python,
exposing an included C++ XMMSRemote class to Python."""

setup(name="xmmspy",
      version="0.4",
      description="boost::python wrapper for xmms_remote*",
      long_description=description,
      author="Daniel Holth",
      author_email="dholth@fastmail.fm",
      url="http://dingoskidneys.com/xmmspy/",
      platforms="linux",
      license="LGPL",
      data_files="xmmsremote.h",
      ext_modules=[Extension("xmms", ["xmms-python.cc", "xmmsremote.cc"],
                             libraries= ["glib", "boost_python", "xmms"],
                             include_dirs=["/usr/lib/boost", 
                                           "/usr/include/glib-1.2",
                                           "/usr/lib/glib/include"])])
