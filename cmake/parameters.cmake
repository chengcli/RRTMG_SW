## defines default parameters

## define a macro to set a variable if it is empty
macro(SET_IF_EMPTY _variable)
    if("${${_variable}}" STREQUAL "")
        set(${_variable} ${ARGN})
    endiF()
endmacro()

string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
