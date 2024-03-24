//! This file contains the usage and unit tests for the c_rrtmg_sw_() function.

#include <rrtmg_sw_nomcica.h>

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

    double **swuflx;
    double **swdflx;
    double **swhr;
    double **swuflxc;
    double **swdflxc;
    double **swhrc;

    c_rrtmg_sw_(ncol, nlay, icld, iaer, 
        play[0], plev[0], tlay[0], tlev[0], tsfc[0], 
        h2ovmr[0], o3vmr[0], co2vmr[0], ch4vmr[0], n2ovmr[0], o2vmr[0],
        asdir, asdif, aldir, aldif, coszen,
        adjes, dyofyr, scon, isolvar,
        inflgsw, iceflgsw, liqflgsw,
        cldfr[0], taucld[0], ssacld[0], asmcld[0], fsfcld[0],
        cicewp[0], cliqwp[0], reice[0], reliq[0],
        tauaer[0], ssaaer[0], asmser[0], ecaer[0],
        swuflx[0], swdflx[0], swhr[0], swuflxc[0], swdflxc[0], swhrc[0]
    );
}
