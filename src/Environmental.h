#pragma once
#include "ofxAssimpModelLoader.h"
#include "Agent.h"
#include "ofMain.h"

class AgentForce {
protected:
public:
	bool applied = false;
	bool applyOnce = false;
	virtual void updateForce(Agent*) = 0;
};

class Environmental
{
private:
	glm::vec3 position, velocity,
		acceleration, angularVelocity,
		angularAcceleration, mass;
	ofxAssimpModelLoader* ship;

public:
	Environmental();
	void add(const Agent&);
	void addForce(AgentForce*);
	void remove(int i);
	void update();
	void reset();
	void draw();
	vector<Agent> agents;
	vector<AgentForce *> forces;
};



class GravityForce : public AgentForce {
	glm::vec3 gravity;
public:
	GravityForce(const glm::vec3& gravity);
	void updateForce(Agent*);
};
class TurbulenceForce : public AgentForce {
	ofVec3f tmin, tmax;
public:
	TurbulenceForce(const ofVec3f& min, const ofVec3f& max);
	void updateForce(Agent*);
};
class ThrusterForce : public AgentForce {
	glm::vec3 thrusterForce;
public:
	ThrusterForce(const glm::vec3 &thrustForce);
	void updateForce(Agent*);
};


