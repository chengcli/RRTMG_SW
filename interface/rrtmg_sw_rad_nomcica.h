//! \file rrtmg_sw_rad_nomciaca.h
//! \brief RRTMG_SW C-Interface
// *****************************************************************************

#ifndef INTERFACE_RRTMG_SW_RAD_NOMCIA_H_
#define INTERFACE_RRTMG_SW_RAD_NOMCIA_H_

#include "macros.h"

#define c_rrtmg_sw_rad_ FEXPAND(rrtmg_sw_rad, rrtmg_sw)

#ifdef __cplusplus
extern "C" {
#endif 

void c_rrtmg_sw_rad_(
    int ncol,         //! number of horizontal columns
    int nlay,         //! number of model layers
    int icld,         //! cloud overlap method
                      //! 0 = clear only
                      //! 1 = random overlap
                      //! 2 = maximum/random overlap
                      //! 3 = maximum overlap
    int iaer,         //! aerosol option flag
                      //! 0 = no aerosol
                      //! 6 = ECMWF method
                      //! 10 = input aerosol optical properties
    //! ------ input atmosphere ------
    double *play,     //! layer pressure [hPa], dimension = (ncol, nlay)
    double *plev,     //! level pressure [hPa], dimension = (ncol, nlay+1)
    double *tlay,     //! layer temperature [K], dimension = (ncol, nlay)
    double *tlev,     //! level temperature [K], dimension = (ncol, nlay+1)
    double *tsfc,     //! surface temperature [K], dimension = (ncol)
    //! ------ input vmr ------
    double *h2ovmr,   //! H2O volume mixing ratio [unitless], dimension = (ncol, nlay)
    double *o3vmr,    //! O3 volume mixing ratio [unitless], dimension = (ncol, nlay)
    double *co2vmr,   //! CO2 volume mixing ratio [unitless], dimension = (ncol, nlay)
    double *ch4vmr,   //! CH4 volume mixing ratio [unitless], dimension = (ncol, nlay)
    double *n2ovmr,   //! N2O volume mixing ratio [unitless], dimension = (ncol, nlay)
    double *o2vmr,    //! O2 volume mixing ratio [unitless], dimension = (ncol, nlay)
    //! ------ input surface albedo ------
    double *asdir,    //! UV/vis surface albedo direct rad, dimension = (ncol)
    double *asdif,    //! UV/vis surface albedo diffuse rad, dimension = (ncol)
    double *aldir,    //! Near-IR surface albedo direct rad, dimension = (ncol)
    double *aldif,    //! Near-IR surface albedo diffuse rad, dimension = (ncol)
    double *coszen,   //! Cosine of solar zenith angle, dimension = (ncol)
    //! ------ input solar parameters ------
    double adjes,     //! Flux adjustment for Earth/Sun distance
    int dyofyr,       //! Day of year (used to get Earth/Sun)
    double scon,      //! Solar constant [W/m^2]
    int isolvar,      //! Flag for solar variability
                      //! -1 = solar constant is constant
                      //! 0 = solar constant varies
    //! ------ input cloud flags ------
    int inflgsw,      //! Flag for cloud optical properties
    int iceflgsw,     //! Flag for ice optical properties
    int liqflgsw,     //! Flag for liquid optical properties
    //! ------ input cloud properties ------
    double *cldfr,    //! Cloud fraction [unitless], dimension = (ncol, nlay)
    double *taucld,   //! In-Cloud optical depth [unitless], dimension = (ncol, nlay)
    double *ssacld,   //! In-Cloud single scattering albedo [unitless], dimension = (ncol, nlay)
    double *asmcld,   //! In-Cloud asymmetry parameter [unitless], dimension = (ncol, nlay)
    double *fsfcld,   //! In-Cloud forward scattering fraction [unitless], dimension = (ncol, nlay)
    double *cicewp,   //! Cloud ice water path [g/m^2], dimension = (ncol, nlay)
    double *cliqwp,   //! Cloud liquid water path [g/m^2], dimension = (ncol, nlay)
    double *reice,    //! Cloud ice effective radius [microns], dimension = (ncol, nlay)
    double *reliq,    //! Cloud liquid effective radius [microns], dimension = (ncol, nlay)
    //! ------ input aerosol properties ------
    double *tauaer,   //! aerosol optical depth [unitless], dimension = (ncol, nlay)
    double *ssaaer,   //! aerosol single scattering albedo [unitless], dimension = (ncol, nlay)
    double *asmaer,   //! aerosol asymmetry parameter [unitless], dimension = (ncol, nlay)
    double *ecaer,    //! aerosol optical depth at 0.55 micron (iaer=6 only)
    //! ------ output ------ 
    double *swuflx,   //! Total sky shortwave upward flux [W/m^2], dimension = (ncol, nlay + 1)
    double *swdflx,   //! Total sky shortwave downward flux [W/m^2], dimension = (ncol, nlay + 1)
    double *swhr,     //! Total sky shortwave radiative heating rate [K/day], dimension = (ncol, nlay)
    double *swuflxc,  //! Clear sky shortwave upward flux [W/m^2], dimension = (ncol, nlay + 1)
    double *swdflxc,  //! Clear sky shortwave downward flux [W/m^2], dimension = (ncol, nlay + 1)
    double *swhrc    //! Clear sky shortwave radiative heating rate [K/day], dimension = (ncol, nlay)
);

#ifdef __cplusplus
} //  extern "C"
#endif 

#endif  // INTERFACE_RRTMG_SW_RAD_NOMCIA_H_
