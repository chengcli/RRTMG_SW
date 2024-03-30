#ifndef INTERFACE_RRTMG_SW_HPP_
#define INTERFACE_RRTMG_SW_HPP_

#include <vector>

class RRTMG_SW {
 public: // public access data
  // input atmosphere
  int ncol;
  int nlay;
  int icld;
  int iaer;

  // input solar
  double adjes;
  int dyofyr;
  double scon;
  int isolvar;

  // input cloud flag
  int inflgsw;
  int iceflgsw;
  int liqflgsw;

 public:
  RRTMG_SW(int nlay, double cpdair);
  virtual ~RRTMG_SW() {}

  void Run(double *swuflx, double *swdflx, double *swhr,
           double *swuflxc, double *swdflxc, double *swhrc);

  void SetTemperatureOnLevel(double const *temp);
  void SetPressureOnLevel(double const *pres);

  void SetH2OVolumeMixingRatio(double const* vmr);
  void SetO3VolumeMixingRatio(double const* vmr);
  void SetCO2VolumeMixingRatio(double const* vmr);
  void SetCH4VolumeMixingRatio(double const* vmr);
  void SetN2OVolumeMixingRatio(double const* vmr);
  void SetO2VolumeMixingRatio(double const* vmr);

 protected:
  // input atmosphere
  std::vector<double> play_, plev_, tlay_, tlev_, tsfc_;

  // input vmr
  std::vector<double> h2ovmr_, o3vmr_, co2vmr_, ch4vmr_, n2ovmr_, o2vmr_;

  // input surface
  std::vector<double> asdir_, asdif_, aldir_, aldif_, coszen_;

  // input cloud properties
  std::vector<double> cldfr_, taucld_, ssacld_, asmcld_, fsfcld_, cicewp_, cliqwp_, reice_, reliq_;

  // input aerosol properties
  std::vector<double> tauaer_, ssaaer_, asmaer_, ecaer_;
};

#endif // INTERFACE_RRTMG_SW_HPP_
