add_library(dppcord SHARED IMPORTED)

set_target_properties(dppcord PROPERTIES
IMPORTED_LOCATION "/home/lumi/code/cpp/d++cord/bin/libdppcord.so" 
INTERFACE_INCLUDE_DIRECTORIES "/home/lumi/code/cpp/d++cord/include/")