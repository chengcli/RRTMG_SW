//! \file rrtmg_sw_rad_nomciaca.h
//! \brief RRTMG_SW C-Interface
// *****************************************************************************

#ifndef INTERFACE_RRTMG_SW_RAD_NOMCIA_H_
#define INTERFACE_RRTMG_SW_RAD_NOMCIA_H_

#include <macros.h>

#define c_rrtmg_sw_rad_ FEXPAND(rrtmg_sw_rad, rrtmg_sw)

#ifdef __cplusplus
extern "C" {
#endif 

void c_rrtmg_sw_rad_(
    int const *ncol,        //! number of horizontal columns
    int const *nlay,        //! number of model layers
    int *icld,              //! cloud overlap method
                            //! 0 = clear only
                            //! 1 = random overlap
                            //! 2 = maximum/random overlap
                            //! 3 = maximum overlap
    int *iaer,              //! aerosol option flag
                            //! 0 = no aerosol
                            //! 6 = ECMWF method
                            //! 10 = input aerosol optical properties
    //! ------ input atmosphere ------
    double const *play,     //! layer pressure [hPa], dimension = (ncol, nlay)
    double const *plev,     //! level pressure [hPa], dimension = (ncol, nlay+1)
    double const *tlay,     //! layer temperature [K], dimension = (ncol, nlay)
    double const *tlev,     //! level temperature [K], dimension = (ncol, nlay+1)
    double const *tsfc,     //! surface temperature [K], dimension = (ncol)
    //! ------ input vmr ------
    double const *h2ovmr,   //! H2O volume mixing ratio [unitless], dimension = (ncol, nlay)
    double const *o3vmr,    //! O3 volume mixing ratio [unitless], dimension = (ncol, nlay)
    double const *co2vmr,   //! CO2 volume mixing ratio [unitless], dimension = (ncol, nlay)
    double const *ch4vmr,   //! CH4 volume mixing ratio [unitless], dimension = (ncol, nlay)
    double const *n2ovmr,   //! N2O volume mixing ratio [unitless], dimension = (ncol, nlay)
    double const *o2vmr,    //! O2 volume mixing ratio [unitless], dimension = (ncol, nlay)
    //! ------ input surface albedo ------
    double const *asdir,    //! UV/vis surface albedo direct rad, dimension = (ncol)
    double const *asdif,    //! UV/vis surface albedo diffuse rad, dimension = (ncol)
    double const *aldir,    //! Near-IR surface albedo direct rad, dimension = (ncol)
    double const *aldif,    //! Near-IR surface albedo diffuse rad, dimension = (ncol)
    double const *coszen,   //! Cosine of solar zenith angle, dimension = (ncol)
    //! ------ input solar parameters ------
    double const *adjes,    //! Flux adjustment for Earth/Sun distance
    int const *dyofyr,      //! Day of year (used to get Earth/Sun)
    double const *scon,     //! Solar constant [W/m^2]
    int const* isolvar,     //! Flag for solar variability
                            //! -1 = solar constant is constant
                            //! 0 = solar constant varies
    //! ------ input cloud flags ------
    int const *inflgsw,      //! Flag for cloud optical properties
    int const *iceflgsw,     //! Flag for ice optical properties
    int const *liqflgsw,     //! Flag for liquid optical properties
    //! ------ input cloud properties ------
    double const *cldfr,    //! Cloud fraction [unitless], dimension = (ncol, nlay)
    double const *taucld,   //! In-Cloud optical depth [unitless], dimension = (ncol, nlay)
    double const *ssacld,   //! In-Cloud single scattering albedo [unitless], dimension = (ncol, nlay)
    double const *asmcld,   //! In-Cloud asymmetry parameter [unitless], dimension = (ncol, nlay)
    double const *fsfcld,   //! In-Cloud forward scattering fraction [unitless], dimension = (ncol, nlay)
    double const *cicewp,   //! Cloud ice water path [g/m^2], dimension = (ncol, nlay)
    double const *cliqwp,   //! Cloud liquid water path [g/m^2], dimension = (ncol, nlay)
    double const *reice,    //! Cloud ice effective radius [microns], dimension = (ncol, nlay)
    double const *reliq,    //! Cloud liquid effective radius [microns], dimension = (ncol, nlay)
    //! ------ input aerosol properties ------
    double const *tauaer,   //! aerosol optical depth [unitless], dimension = (ncol, nlay)
    double const *ssaaer,   //! aerosol single scattering albedo [unitless], dimension = (ncol, nlay)
    double const *asmaer,   //! aerosol asymmetry parameter [unitless], dimension = (ncol, nlay)
    double const *ecaer,    //! aerosol optical depth at 0.55 micron (iaer=6 only)
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
