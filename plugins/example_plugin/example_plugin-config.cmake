add_library(example_plugin SHARED IMPORTED)
set_target_properties(example_plugin PROPERTIES
IMPORTED_LOCATION "/home/lumi/code/cpp/d++cord/plugins/example_plugin/libexample_plugin.so" 
INTERFACE_INCLUDE_DIRECTORIES "/home/lumi/code/cpp/d++cord/plugins/example_plugin/")