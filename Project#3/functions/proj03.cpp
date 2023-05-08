void
Forward( float th1, float th2, float th3,  float l1, float l2, glm::mat4& m1g, glm::mat4& m2g, glm::mat4& m3g )
{
  th1 *= (M_PI / 180.);
	th2 *= (M_PI / 180.);
	th3 *= (M_PI / 180.);
	
	glm::mat4 tran1 = glm::translate(glm::mat4(1.f), glm::vec3(l1, 0, 0)); 
	glm::mat4 tran2 = glm::translate(glm::mat4(1.f), glm::vec3(l2, 0, 0));
	glm::mat4 rot1 = glm::rotate(glm::mat4(1.f), th1, glm::vec3(0, 0, 1));
	glm::mat4 rot2 = glm::rotate(glm::mat4(1.f), th2, glm::vec3(0, 0, 1));
	glm::mat4 rot3 = glm::rotate(glm::mat4(1.f), th3, glm::vec3(0, 0, 1));
	glm::mat4 final1 = tran1 * rot2;
	glm::mat4 final2 = tran2 * rot3;

	m1g = rot1;
	m2g = m1g * final1;
	m3g = m2g * final2;
}

void
WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
        yourName = "Michael Smith";
        yourEmailAddress = "smitmic5@oregonstate.edu" ;
}