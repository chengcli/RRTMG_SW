//! \file rrtmg_sw_init.h
//! \brief RRTMG_SW C-Interface
// *****************************************************************************

#ifndef INTERFACE_RRTMG_SW_INIT_H_
#define INTERFACE_RRTMG_SW_INIT_H_

#include "macros.h"

#define c_rrtmg_sw_ini_ FEXPAND(rrtmg_sw_init, rrtmg_sw_ini)

#ifdef __cplusplus
extern "C" {
#endif 

void c_rrtmg_sw_ini_(double cpdair);

#ifdef __cplusplus
} //  extern "C"
#endif 

#endif // INTERFACE_RRTMG_SW_INIT_H_
