cmake_minimum_required(VERSION 3.4.1)

aux_source_directory(. ALL_SRC)

add_library( security SHARED ${ALL_SRC} )


find_library(log-lib log )

target_link_libraries( security ${log-lib}  )
