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

add_library(${namel}_${buildl}_lib
    OBJECT
    ${_${namel}_lib}
    )

add_library(${namel}_${buildl}
    OBJECT
    rrtmg_sw_k_g.f90
    rrtmg_sw_init.f90
    rrtmg_sw_rad.nomcica.f90
    )

target_include_directories(${namel}_${buildl}_lib
    PRIVATE
    ${${nameu}_MOD_DIR}
    )

target_include_directories(${namel}_${buildl}
    PRIVATE
    ${${nameu}_MOD_DIR}
    )

add_dependencies(${namel}_${buildl} 
  ${namel}_${buildl}_lib
  )

set_target_properties(${namel}_${buildl}
    PROPERTIES
    COMPILE_FLAGS ${CMAKE_Fortran_FLAGS_${buildu}}
    )
