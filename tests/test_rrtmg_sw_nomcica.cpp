//! This file contains the usage and unit tests for the c_rrtmg_sw_() function.

#include <rrtmg_sw/rrtmg_sw.hpp>

int main(int argc, char **argv) {
    // Test the c_rrtmg_sw_() function
    // Test 1
    // Test the function with the following inputs:
    int ncol = 1;
    int nlay = 1;
    int icld = 0;
    int iaer = 0;

    double **play;
    double **plev;
    double **tlay;
    double **tlev;
    double **tsfc;

    double **h2ovmr;
    double **o3vmr;
    double **co2vmr;
    double **ch4vmr;
    double **n2ovmr;
    double **o2vmr;

    double *asdir;
    double *asdif;
    double *aldir;
    double *aldif;
    double *coszen;

    double adjes;
    int dyofyr;
    double scon;
    int isolvar;

    int inflgsw;
    int iceflgsw;
    int liqflgsw;

    double **cldfr;
    double **taucld;
    double **ssacld;
    double **asmcld;
    double **fsfcld;

    double **cicewp;
    double **cliqwp;
    double **reice;
    double **reliq;

    double **tauaer;
    double **ssaaer;
    double **asmser;
    double **ecaer;

    double *swuflx;
    double *swdflx;
    double *swhr;
    double *swuflxc;
    double *swdflxc;
    double *swhrc;

    RRTMG_SW rrtmg_sw(1, 1000.);

    rrtmg_sw.Run(swuflx, swdflx, swhr, swuflxc, swdflxc, swhrc);
}
