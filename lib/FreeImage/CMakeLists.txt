find_path(FreeImage_INCLUDE_DIR
  NAMES
  FreeImage.h
  PATHS
  ENV "PROGRAMFILES(X86)"
  /usr/local/include
  PATH_SUFFIXES
  include)

find_library(FreeImage_LIBRARY
  NAMES freeimage
  PATHS
  ENV "PROGRAMFILES"
  PATH_SUFFIXES
  lib/x64
  lib/Win64)

set(FreeImage_LIBRARIES ${FreeImage_LIBRARY})
set(FreeImage_INCLUDE_DIRS ${FreeImage_INCLUDE_DIR})

mark_as_advanced(
  FreeImage_INCLUDE_DIR
  FreeImage_LIBRARY)

add_library(FreeImage INTERFACE)
set_target_properties(FreeImage PROPERTIES
  INTERFACE_LINK_LIBRARIES "${FreeImage_LIBRARY}")
set_target_properties(FreeImage PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${FreeImage_INCLUDE_DIRS}")

