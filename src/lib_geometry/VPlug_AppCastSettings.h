/*****************************************************************/
/*    NAME: Michael Benjamin                                     */
/*    ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA     */
/*    FILE: VPlug_AppCastSettings.h                              */
/*    DATE: Sep 20th, 2012                                       */
/*                                                               */
/* This file is part of IvP Helm Core Libs                       */
/*                                                               */
/* IvP Helm Core Libs is free software: you can redistribute it  */
/* and/or modify it under the terms of the Lesser GNU General    */
/* Public License as published by the Free Software Foundation,  */
/* either version 3 of the License, or (at your option) any      */
/* later version.                                                */
/*                                                               */
/* IvP Helm Core Libs is distributed in the hope that it will    */
/* be useful but WITHOUT ANY WARRANTY; without even the implied  */
/* warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR       */
/* PURPOSE. See the Lesser GNU General Public License for more   */
/* details.                                                      */
/*                                                               */
/* You should have received a copy of the Lesser GNU General     */
/* Public License along with MOOS-IvP.  If not, see              */
/* <http://www.gnu.org/licenses/>.                               */
/*****************************************************************/

#ifndef VPLUG_APPCAST_SETTINGS_HEADER
#define VPLUG_APPCAST_SETTINGS_HEADER

#include <vector>
#include <map>
#include <string>
#include "ColorPack.h"

class VPlug_AppCastSettings {
public:
  VPlug_AppCastSettings();
  virtual ~VPlug_AppCastSettings() {}

 public:   // A Catch-All Setter
  bool   setParam(const std::string& param, std::string value);

 protected: // Specfic Setters
  bool   setViewMapping(std::string, std::string);
  bool   setSizeMapping(std::string, std::string);
  bool   setSizeMapping(std::string, std::string, double min, double max);
  bool   setAttrMapping(std::string, std::string);
  bool   setColorMapping(std::string, std::string);

 public:  // Specific Gettters (Custom return format)
  bool         viewable(const std::string&, bool view_default=true) const;
  double       geosize(const std::string&, double size_default=0) const;
  std::string  attribute(const std::string&, std::string str_default="") const;
  std::string  colorname(const std::string&, std::string color_default="") const;
  ColorPack    geocolor(const std::string&, std::string color_default="") const;

 public:  // A Catch-All Getter (String return format)
  std::string  strvalue(const std::string&);  

protected:
  std::map<std::string, bool>        m_viewable_map;
  std::map<std::string, double>      m_gsize_map;
  std::map<std::string, std::string> m_attribute_map;
  std::map<std::string, std::string> m_color_str_map;
  std::map<std::string, ColorPack>   m_color_pck_map;
};

#endif








