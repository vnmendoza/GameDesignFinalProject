#pragma once
#include "ofxAssimpModelLoader.h";

class Agent
{
protected:
	glm::vec3 headingVec, scaler;
	ofxAssimpModelLoader model;
public:
	glm::vec3 position, velocity,
		angularVelocity;
	float speed, rotationSpeed,rotation, mass;
	Agent();
	virtual void move();
	virtual void draw();
	glm::vec3 heading();
	void drawHeading();
	glm::mat4 getMatrix();
	glm::vec3 translate(glm::vec3 matrix2Translate);
	glm::vec3 getPosition();
	glm::vec3 getVelocity();
};

class Player : public Agent
{
private:
	bool is_left_pressed, is_right_pressed,
		is_down_pressed, is_up_pressed,
		is_fwd_pressed, is_back_pressed;

public:
	Player();
	void move();
	void draw();
	void setFwdPressed(bool);
	void setBackPressed(bool);
	void setLeftPressed(bool);
	void setRightPressed(bool);
	void setUpPressed(bool);
	void setDownPressed(bool);
	void setIncreaseYawPressed(bool k);
	void setDecreaseYawPressed(bool k);
};



