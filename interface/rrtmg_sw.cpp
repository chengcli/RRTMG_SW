
#include "rrtmg_sw_rad_nomcica.h"
#include "rrtmg_sw_init.h"

#include "rrtmg_sw.hpp"

RRTMG_SW::RRTMG_SW(int nlay, double cpdair) :
  ncol(1), nlay(nlay), icld(0), iaer(0)
{
  play_.resize(ncol * nlay);
  plev_.resize(ncol * (nlay + 1));
  tlay_.resize(ncol * nlay);
  tlev_.resize(ncol * (nlay + 1));
  tsfc_.resize(ncol);

  c_rrtmg_sw_ini_(&cpdair);
}

void RRTMG_SW::SetTemperatureOnLevel(double const *temp)
{
  for (int i = 0; i < ncol; ++i)
    for (int j = 0; j <= nlay; ++j) {
      tlev_[j * ncol + i] = temp[i * nlay + j];
    }

  for (int i = 0; i < ncol; ++i)
    for (int j = 0; j < nlay; ++j) {
      tlay_[j * ncol + i] = 0.5 * (tlev_[j * ncol + i] + tlev_[(j + 1) * ncol + i]);
    }
}

void RRTMG_SW::SetPressureOnLevel(double const *pres)
{
  for (int i = 0; i < ncol; ++i)
    for (int j = 0; j <= nlay; ++j) {
      plev_[j * ncol + i] = pres[i * nlay + j];
    }

  for (int i = 0; i < ncol; ++i)
    for (int j = 0; j < nlay; ++j) {
      play_[j * ncol + i] = 0.5 * (plev_[j * ncol + i] + plev_[(j + 1) * ncol + i]);
    }
}

void RRTMG_SW::Run(double *swuflx, double *swdflx, double *swhr,
                   double *swuflxc, double *swdflxc, double *swhrc)
{
  c_rrtmg_sw_rad_(
      &ncol, &nlay, &icld, &iaer,
      play_.data(), plev_.data(), tlay_.data(), tlev_.data(), tsfc_.data(),
      h2ovmr_.data(), o3vmr_.data(), co2vmr_.data(), ch4vmr_.data(), n2ovmr_.data(), o2vmr_.data(),
      asdir_.data(), asdif_.data(), aldir_.data(), aldif_.data(), coszen_.data(),
      &adjes, &dyofyr, &scon, &isolvar,
      &inflgsw, &iceflgsw, &liqflgsw,
      cldfr_.data(), taucld_.data(), ssacld_.data(), asmcld_.data(), fsfcld_.data(), cicewp_.data(), cliqwp_.data(), reice_.data(), reliq_.data(),
      tauaer_.data(), ssaaer_.data(), asmaer_.data(), ecaer_.data(),
      swuflx, swdflx, swhr, swuflxc, swdflxc, swhrc
      );
}
