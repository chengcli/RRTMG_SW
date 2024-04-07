
string(TOLOWER ${CMAKE_BUILD_TYPE} buildl)
string(TOUPPER ${CMAKE_BUILD_TYPE} buildu)

set(namel rrtmg_sw_mod)
string(TOUPPER ${namel} nameu)

file(GLOB _rrtmg_sw_mods
    *.f90
    )

add_library(${namel}_${buildl}
    STATIC
    ${_rrtmg_sw_mods}
    )

set_target_properties(${namel}_${buildl}
    PROPERTIES
    COMPILE_FLAGS ${CMAKE_Fortran_FLAGS_${buildu}}
    )

set(${nameu}_DIR ${CMAKE_CURRENT_BINARY_DIR}
    CACHE INTERNAL "${nameu} directory")
