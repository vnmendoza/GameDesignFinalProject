#include "Agent.h"
#include "ofMain.h"

Agent::Agent()
{
	scaler = glm::vec3(0.2);
	position, velocity, headingVec = glm::vec3(0);
	model.setScaleNormalization(false);
	speed = 1.0;
}
void Agent::move()
{
}
void Agent::draw()
{
	drawHeading();
	model.drawFaces();
}
glm::mat4 Agent::getMatrix()
{
	glm::mat4 trans = glm::translate(glm::mat4(1.0), glm::vec3(position));
	glm::mat4 rot = glm::rotate(glm::mat4(1.0), glm::radians(rotation), glm::vec3(0, 0, 1));
	glm::mat4 scale = glm::scale(glm::mat4(1.0), scaler);
	return (trans * rot * scale);
}
glm::vec3 Agent::heading()
{
	glm::vec3 triPoint = translate(glm::vec3(0, 0, 1));
	glm::vec3 center = translate(glm::vec3(0, 0, 0));
	return triPoint - center;
}

void Agent::drawHeading()
{
	glm::vec3 triPoint = (glm::vec3(0, 0, 5));
	glm::vec3 center = (glm::vec3(0, 0, 0));

	ofDrawLine(triPoint, center);
}

glm::vec3 Agent::translate(glm::vec3 trans)
{
	return glm::vec3(getMatrix() * glm::vec4(trans, 1.0));
}





Player::Player()
{
	Agent();
	model.loadModel("geo/spacemodel.obj");
}

void Player::draw()
{
	Agent::draw();
}

void Player::setFwdPressed(bool k)
{
	cout << "fwd Pressed: " << k << endl;
	is_fwd_pressed = k;
}



void Player::move()
{
	if (is_fwd_pressed)
	{
		//activate fwd thruster
		velocity += speed * heading();
		cout << "velocity: " << velocity << endl;
	}
	if (is_left_pressed)
	{
		//activate lft thruster
		angularVelocity -= rotationSpeed;
	}
	if (is_down_pressed)
	{
		velocity -= speed * heading();
	}
	if (is_right_pressed)
	{
		angularVelocity += rotationSpeed;
	}
}
