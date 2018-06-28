#pragma once
#include "types.h"
#include "data.h"

// void helio_to_jacobi_r_particles(const HostPlanetPhaseSpace& pl, HostParticlePhaseSpace& p);
// void helio_to_jacobi_v_particles(const HostPlanetPhaseSpace& pl, HostParticlePhaseSpace& p);
void jacobi_to_helio_planets(const Vf64& eta, const Vf64_3& rj, const Vf64_3& vj, HostPlanetPhaseSpace& pl);
void helio_to_jacobi_v_planets(const HostPlanetPhaseSpace& p, const Vf64& eta, Vf64_3& vj);
void helio_to_jacobi_r_planets(const HostPlanetPhaseSpace& p, const Vf64& eta, Vf64_3& rj);

void find_barycenter(const Vf64_3& r, const Vf64_3& v, const Vf64& m, size_t n, f64_3& r_out, f64_3& v_out);
void to_bary(HostData& hd);
void to_helio(HostData& hd);
void to_elements(double mu, f64_3 r, f64_3 v, int* esign = nullptr, double* a = nullptr, double* e = nullptr, double* i = nullptr, double* capom = nullptr, double* om = nullptr, double* f = nullptr);
