#include "Environmental.h"

Environmental::Environmental()
{
	
}

void Environmental::add(const Agent& a) {
	agents.push_back(a);
}

void Environmental::addForce(AgentForce* f) {
	forces.push_back(f);
}

void Environmental::remove(int i) {
	agents.erase(agents.begin() + i);
}
void Environmental::update() {
	// check if empty and just return
	if (agents.size() == 0) return;

	vector<Agent>::iterator a = agents.begin();
	vector<Agent>::iterator tmp;

	// update forces on all agents first 
	//
	for (int i = 0; i < agents.size(); i++) {
		for (int k = 0; k < forces.size(); k++) {
			if (!forces[k]->applied)
				forces[k]->updateForce(&agents[i]);
		}
	}

	// update all forces only applied once to "applied"
	// so they are not applied again.
	//
	for (int i = 0; i < forces.size(); i++) {
		if (forces[i]->applyOnce)
			forces[i]->applied = true;
	}

	// move all the agents in the store
	//
	for (int i = 0; i < agents.size(); i++)
		agents[i].move();
}

//  draw the agents 
//
void Environmental::draw() {
	for (int i = 0; i < agents.size(); i++) {
		agents[i].draw();
	}
}


// Gravity Force Field 
//
GravityForce::GravityForce(const glm::vec3& g) {
	gravity = g;
}

void GravityForce::updateForce(Agent* agent) {
	// f = mg
	agent->velocity += gravity * agent->mass;
}

// Turbulence Force Field 
//
TurbulenceForce::TurbulenceForce(const ofVec3f& min, const ofVec3f& max) {
	tmin = min;
	tmax = max;
}

void TurbulenceForce::updateForce(Agent* agent) {
	//
	// We are going to add a little "noise" to a agents
	// forces to achieve a more natual look to the motion
	//
	agent->velocity.x += ofRandom(tmin.x, tmax.x);
	agent->velocity.y += ofRandom(tmin.y, tmax.y);
	agent->velocity.z += ofRandom(tmin.z, tmax.z);
}

