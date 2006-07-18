// viewpoints - interactive linked scatterplots and more.
// copyright 2005 Creon Levit, all rights reserved.
//*****************************************************************
// File name: include_libraries_vp.h
//
// Class definitions: none
//
// Classes referenced: many
//
// Required packages
//    FLTK 1.1.6 -- Fast Light Toolkit graphics package
//    FLEWS 0.3 -- Extensions to FLTK 
//    OGLEXP 1.2.2 -- Access to OpenGL extension under Windows
//    GSL 1.6 -- Gnu Scientific Library package for Windows
//    Blitz++ 0.9 -- Various math routines
//
// Compiler directives:
//   May require D__WIN32__ for the C++ compiler
//
// Purpose: Commands to access the include libraries needed by
//   Creon Levit's viewpoints.  These are so numerous and involved
//   that it is simplest to concentrate these commands in one
//   central header file.
//
// General design philosophy:
//   1) Add comments and get this code to run under Windows.
//
// Author: Creon Levitt    unknown
// Modified: P. R. Gazis   27-MAR-2006
//*****************************************************************

// Protection to make sure this header is not included twice
#ifndef INCLUDE_LIBRARIES_VP_H
#define INCLUDE_LIBRARIES_VP_H 1

// Defines under Windows: Several defines are required to account 
// for variable and function definitions that seem to be missing.
// This is a temporary fix that should be replaced by actual 
// source code if possible.
#ifdef __WIN32__
  #define MAXFLOAT 3.402823466e+38f 
  #define usleep(v) Sleep(v/1000)
#endif // __WIN32__

// Include libraries under Windows in the Dev-C++ programming 
// environment: The FLTK package should be handled by Dev-C++ as
// a 'devpak', but several include libraries are needed in 
// addition to the regular Dev-C++ and FLTK libraries.  These are 
// listed below along with their locations on the primary Windows 
// development system.
//
// Flews
//   c:\devusr\flews
// OglExt (Needed to use OpenGL 1.2+)
//   c:\devuser\oglext\include
// GSL (Needed for parts of Blitz++)
//   c:\devuser\GnuWin32\include
//   c:\devuser\GnuWin32\include\glibc
// Blitz++
//   c:\devusr\blitz

// Add C includes here.  Note that under Windows in the Dev-C++ 
// programming environment, some of the relevant libraries are 
// part of GSL rather than the Dev-C++ package.  Locations of some 
// crucial files on the primary Windows development system are 
// listed below:
// <unistd.h>    -- c:\Dev-cpp\include
// <fcntl.h>     -- c:\Dev-cpp\include
// <assert.h>    -- c:\Dev-cpp\include
// <sys/types.h> -- c:\Dev-cpp\include\sys
// <sys/uio.h>   -- c:\devuser\GnuWin32\include\glibc\sys
// <sys/stat.h>  -- c:\Dev-cpp\include\sys
// <sys/time.h>  -- c:\Dev-cpp\include
//               -- c:\Dev-cpp\include\sys
//               -- c:\devuser\GnuWin32\include\glibc
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <assert.h>
#include <math.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <getopt.h>

// These includes should all be part of Dev-C++ environment
// <float.h>  -- c:\Dev-cpp\include
// <values.h> -- c:\Dev-cpp\include
//            -- c:\devuser\GnuWin32\include\glibc
#ifdef __APPLE__
  #include <float.h>
#else
  #include <values.h>
#endif // __APPLE__

// Add C++ includes here.  These should all be part of Dev-C++
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
 
// FLTK.  These includes should be handled by the relevant Dev-C++
// 'dev-pak'.
#include <FL/math.h>
#include <FL/gl.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Hor_Value_Slider.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Color_Chooser.H>

// XXX: for main menu bar
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Help_View.H>

// flews (FLTK extension) extras.  On the primary Windows system,
// these should be located in c:\devusr\flews as described above
#include <FL/Fl_flews.h>
#include <FL/Fl_Value_Slider_Input.H>
#include "Fl_Hor_Value_Slider_Input.H"  // my modified flews slider

// OpenGL extensions.  NOTE: Some of these will clobber a Windows 
// compile, so they must be excluded by the relevant defines!
#ifdef __APPLE__
  #include <OpenGL/glext.h>
#endif // __APPLE__
#ifdef __LINUX__
  #include <GL/glext.h>
#endif // __LINUX__
#ifdef __WIN32__
  // OglExt.  Obtain from c:\devusr\oglext\include as described
  // above and invoke as described in OGLEXT documentation
  #define GL_GLEXT_PROTOTYPES
  #include <glext.h>
  #include <GL/glext.h>
#endif // __WIN32__

// GSL (Must be included before Blitz++!)
#ifdef __WIN32__
  #include <C:\devusr\GnuWin32\include\config.h>
  #include <winx/sys/timex.h>
#endif // __WIN32__
#include <gsl/gsl_sys.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cdf.h>

// Blitz++ (C++ array operations via template metaprogramming)
#include <blitz/array.h>

// BLAS
#ifdef __APPLE__
  #include <vecLib/vBLAS.h>
#elif linux
  //extern "C" {
  //# include <cblas.h>
  //}
#endif // __APPLE__

// Use the Standard Template Library
using namespace std;

// Define to allow fast Apple vertex extensions.  Used by both 
// class control_panel_window and plot_window.  Move to
// include_libraries_vp?
#ifdef __APPLE__
#define FAST_APPLE_VERTEX_EXTENSIONS
#endif // __APPLE__

#endif   // INCLUDE_LIBRARIES_VP_H