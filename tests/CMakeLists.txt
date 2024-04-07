
macro(setup_test namel)
  string(TOLOWER ${CMAKE_BUILD_TYPE} buildl)
  string(TOUPPER ${CMAKE_BUILD_TYPE} buildu)

  add_executable(${namel}.${buildl} ${namel}.cpp)

  set_target_properties(${namel}.${buildl}
                        PROPERTIES 
                        COMPILE_FLAGS ${CMAKE_CXX_FLAGS_${buildu}})

  target_include_directories(${namel}.${buildl}
                             PRIVATE ${RRTMG_SW_INCLUDE_DIR})

  target_link_libraries(${namel}.${buildl}
                        rrtmg::rrtmg_sw++)

  add_test(NAME ${namel}.${buildl} COMMAND ${namel}.${buildl})
endmacro()

setup_test(test_rrtmg_sw_nomcica)
