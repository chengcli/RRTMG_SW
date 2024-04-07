# compile the rrtmg_sw module
# main module: 
#   rrtmg_sw_rad.nomcica.f90 

string(TOLOWER ${CMAKE_BUILD_TYPE} buildl)
string(TOUPPER ${CMAKE_BUILD_TYPE} buildu)

set(namel rrtmg_sw)
string(TOUPPER ${namel} nameu)

set(_${namel}_lib
    rrtmg_sw_taumol.f90
    rrtmg_sw_vrtqdr.f90
    rrtmg_sw_cldprop.f90
    rrtmg_sw_setcoef.f90
    rrtmg_sw_spcvrt.f90
    rrtmg_sw_reftra.f90
    )

add_library(${namel}_lib_${buildl}
    STATIC
    ${_${namel}_lib}
    )

add_library(${namel}_${buildl}
    STATIC
    rrtmg_sw_init.f90
    rrtmg_sw_read_nc.f90
    rrtmg_sw_rad.nomcica.f90
    )

target_include_directories(${namel}_lib_${buildl}
    PRIVATE
    ${${nameu}_MOD_DIR}
    )

target_include_directories(${namel}_${buildl}
    PRIVATE
    ${${nameu}_MOD_DIR}
    ${NETCDF_INCLUDES}
    )

add_dependencies(${namel}_${buildl} 
    ${namel}_lib_${buildl}
    )

set_target_properties(${namel}_${buildl}
    PROPERTIES
    COMPILE_FLAGS ${CMAKE_Fortran_FLAGS_${buildu}}
    )

target_link_libraries(${namel}_${buildl}
    "rrtmg_sw_mod_${buildl}"
    "rrtmg_sw_lib_${buildl}"
    ${NETCDF_LIBRARIES_F90}
    )

add_library(rrtmg::rrtmg_swf ALIAS ${namel}_${buildl})
