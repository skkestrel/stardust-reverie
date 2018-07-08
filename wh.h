#pragma once
#include "data.h"
#include "util.h"
#include "integrator.h"

class WHIntegrator : public Integrator
{
public:
	Vf64 inverse_helio_cubed, inverse_jacobi_cubed;
	Vf64 dist, energy, vdotr;
	Vu8 mask;
	Vf64 mu, eta;

	Vf64_3 planet_rj, planet_vj;
	Vf64_3 planet_a, particle_a;

	LogQuartet<Vf64_3> planet_h0_log;

	Vf64 planet_rh;

	size_t tbsize;
	size_t encounter_n1, encounter_n2;
	double encounter_r1, encounter_r2;

	bool resolve_encounters;

	double dt;

	WHIntegrator();
	WHIntegrator(HostPlanetPhaseSpace& pl, HostParticlePhaseSpace& pa, const Configuration& config);

	void integrate_planets_timeblock(HostPlanetPhaseSpace& pl, float64_t t) override;
	void integrate_particles_timeblock(const HostPlanetPhaseSpace& pl, HostParticlePhaseSpace& pa, size_t begin, size_t length, float64_t t) override;
	void gather_particles(const std::vector<size_t>& indices, size_t begin, size_t length) override;

	void integrate_encounter_particle_catchup(const HostPlanetPhaseSpace& pl, HostParticlePhaseSpace& pa, size_t particle_index, size_t particle_deathtime_index, size_t planet_index, double t) override;

	template<bool old>
	size_t integrate_encounter_particle_step(const HostPlanetPhaseSpace& pl, HostParticlePhaseSpace& pa, size_t particle_index, size_t timestep_index, size_t* planet_index, uint8_t* encounter_level, double t);

	void step_planets(HostPlanetPhaseSpace& pl, float64_t t, size_t timestep_index);
	void step_particles(const HostPlanetPhaseSpace& pl, HostParticlePhaseSpace& pa, size_t begin, size_t length, float64_t t, size_t timestep_index);

	static bool drift_single(float64_t t, float64_t mu, f64_3* r, f64_3* v);
	void drift(float64_t t, Vf64_3& r, Vf64_3& v, size_t start, size_t n);

	template<bool old>
	void nonhelio_acc_encounter_particle(const HostPlanetPhaseSpace& pl, HostParticlePhaseSpace& p, size_t particle_index, float64_t time, size_t timestep_index, size_t central_planet_index);

	template<bool encounter, bool old>
	uint8_t helio_acc_particle(const HostPlanetPhaseSpace& pl, HostParticlePhaseSpace& pa, size_t particle_index, float64_t time, size_t timestep_index);

	template<bool encounter, bool old>
	void helio_acc_particles(const HostPlanetPhaseSpace& pl, HostParticlePhaseSpace& p, size_t begin, size_t length, float64_t time, size_t timestep_index);

	template<bool slow>
	void helio_acc_planets(HostPlanetPhaseSpace& p, size_t index);

	static uint8_t detect_encounter(float64_t r_rel_sq, float64_t rh, double r1, double r2);
};

void calculate_planet_metrics(const HostPlanetPhaseSpace& p, double* energy, f64_3* l);
