#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <math.h> 

static const int64_t COIN = 100000000;


double ConvertBitsToDouble(unsigned int nBits)
{
    int nShift = (nBits >> 24) & 0xff;

    double dDiff =
        (double)0x0000ffff / (double)(nBits & 0x00ffffff);

    while (nShift < 29)
    {
        dDiff *= 256.0;
        nShift++;
    }
    while (nShift > 29)
    {
        dDiff /= 256.0;
        nShift--;
    }

    return dDiff;
}


int64_t static GetBlockBaseValue(int nBits, int nHeight)
{
double dDiff =
        (double)0x0000ffff / (double)(nBits & 0x00ffffff);

    
    if(nHeight > 100) dDiff = ConvertBitsToDouble(nBits);

    int64_t nSubsidy = 50; 
    if(nHeight >= 100 && nHeight < 3000) {
        if((nHeight >= 101 && dDiff > 75) || nHeight >= 1000) { 
            // 222000/(((x+2600)/9)^2)
            nSubsidy = (222000.0 / (pow((dDiff+2600.0)/9.0,2.0)));
            if (nSubsidy > 25) nSubsidy = 25;
            if (nSubsidy < 5) nSubsidy = 5;
        } else { 
            nSubsidy = (1112.0 / (pow((dDiff+51.0)/6.0,2.0)));
            if (nSubsidy > 500) nSubsidy = 50;
            if (nSubsidy < 25) nSubsidy = 5;
        }
    } else {
        nSubsidy = (1111.0 / (pow((dDiff+1.0),2.0)));
        if (nSubsidy > 500) nSubsidy = 50;
        if (nSubsidy < 1) nSubsidy = 1;
            nSubsidy = pow (11.0, 3.0);
    }

if(nHeight >= 3000 && nHeight < 6000) 
{
                nSubsidy = (2222222.0 / (pow((dDiff+2600.0)/9.0,2.0)));
                if (nSubsidy > 25) nSubsidy = 50; // increase from 25 to 50 per block
                if (nSubsidy < 5) nSubsidy = 10; // increase from 5 to 10 per block
} 

if(nHeight >= 6000) 
{
                nSubsidy = (2222222.0 / (pow((dDiff+2600.0)/9.0,2.0)));
                if (nSubsidy > 25) nSubsidy = 20; // increase from 25 to 50 per block
                if (nSubsidy < 5) nSubsidy = 5; // increase from 5 to 10 per block
} 

    // printf("height %u diff %4.2f reward %i \n", nHeight, dDiff, nSubsidy);
    nSubsidy *= COIN;

    // yearly decline of production by 20% per year, projected 3M coins max by year 20XX.
    for(int i = 17520; i <= nHeight; i += 17520) nSubsidy *= 0.80;

    return nSubsidy;

}


#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
using namespace boost::python;
 
BOOST_PYTHON_MODULE(virtualcoin_subsidy)
{
    def("GetBlockBaseValue", GetBlockBaseValue);
}

