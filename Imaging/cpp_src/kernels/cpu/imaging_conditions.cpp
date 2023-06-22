
#include "imaging_conditions.hpp"

extern "C"

{

void imaging(int ns, int shotSize, int nx, int nf, fcomp * forw, fcomp * back, int sizeImage, int depthIdx, float * image){
/*
    fcomp * conv = new fcomp[ns*nx];

    #pragma omp parallel for schedule(dynamic,1)
    for (int is=0; is<ns; ++is)
        for (int i=0; i<nx; i++)
            conv[is*nx + i] = fcomp(0.0,0.0);
    
    #pragma omp parallel for schedule(dynamic,1)
    for (int is=0; is<ns; ++is)
        for (int j=0; j<nf; j++)
            for (int i=0; i<nx; i++)
                conv[is*nx + i] += forw[is*shotSize + j*nx + i] * pwm::conj(back[is*shotSize + j*nx + i]);

    #pragma omp parallel for schedule(dynamic,1)
    for (int is=0; is<ns; ++is)
        for (int i=0; i<nx; i++){
            image[is*sizeImage + depthIdx*nx + i] = reinterpret_cast<float*>(&conv[is*nx])[2*i];
        }

    delete [] conv;
*/


        for (int s = 0; s < ns; ++s)
            for (int f = 0; f < nf; ++f)
                for (int x = 0; x < nx; ++x)
                    image[s * sizeImage + depthIdx * nx + x] +=
                        std::real(forw[s * shotSize + f * nx + x] * std::conj(back[s * shotSize + f * nx + x]));
}

} // end extern "C"
