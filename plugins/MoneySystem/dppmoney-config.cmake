add_library(dppmoney SHARED IMPORTED)
set_target_properties(dppmoney PROPERTIES
IMPORTED_LOCATION "/home/lumi/code/cpp/d++cord/plugins/MoneySystem/libdppmoney.so" 
INTERFACE_INCLUDE_DIRECTORIES "/home/lumi/code/cpp/d++cord/plugins/MoneySystem/")