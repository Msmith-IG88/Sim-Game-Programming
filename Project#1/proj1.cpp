#include <stdio.h>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

#define GLM_FORCE_RADIANS
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/matrix_inverse.hpp"
#include <iostream>
#include "glm/gtx/string_cast.hpp"

glm::vec3
WhatPartOfALivesInBDir( glm::vec3 a, glm::vec3 b )
{
	glm::vec3 x = glm::normalize(b) * glm::dot(a, glm::normalize(b));
	return x;
}


glm::vec3
WhatPartOfALivesPerpToB( glm::vec3 a, glm::vec3 b )
{
	glm::vec3 x = a -  WhatPartOfALivesInBDir(a, b);
	return x;
}


glm::vec3
UnitSurfaceNormal( glm::vec3 q, glm::vec3 r, glm::vec3 s )
{
	glm::vec3 x = glm::normalize(glm::cross((r-q), (s-q)));
	return x;
}


float
Area( glm::vec3 q, glm::vec3 r, glm::vec3 s )
{
	float area = glm::length(glm::cross((r-q),(s-q))) * 0.5;
	return area;
}


bool
IsPointInTriangle( glm::vec3 q, glm::vec3 r, glm::vec3 s, glm::vec3 p )
{
	glm::vec3 x = glm::cross((r-q), (s-q));
	if (((glm::dot(x, glm::cross((r-q), (p-q)))) > 0) && ((glm::dot(x, glm::cross((s-r), (p-r)))) > 0) && ((glm::dot(x, glm::cross((q-s), (p-s)))) > 0)){
		return true;
	} else {
		return false;
	}
}



float
DistanceFromPointToPlane( glm::vec3 q, glm::vec3 r, glm::vec3 s, glm::vec3 p )
{
	float dist = glm::dot((p-q), UnitSurfaceNormal(q, r, s));
	return dist;
}


void
WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
	yourName = "Michael Smith";
	yourEmailAddress = "smitmic5@oregonstate.edu" ;
}
/*
int main(){
	glm::vec3 v1 = glm::vec3(0.0, 0.0, 0.0);
	glm::vec3 v2 = glm::vec3(5.0, 0.0, 0.0);
	glm::vec3 v3 = glm::vec3(0.0, 0.0, 5.0);

	glm::vec3 p1 = glm::vec3(-1.0, 0.0, 1.0);
	glm::vec3 p2 = glm::vec3(9182349, 423, 0.5);

	std::cout<<"UnitSurfaceNormal: " + glm::to_string(UnitSurfaceNormal(v1, v3, v2))<<std::endl;
}
*/