glm::mat4
Multiply( glm::mat4 a, glm::mat4 b )
{
	return a * b;
}



glm::vec3
Multiply( glm::mat4 a, glm::vec3 b )
{
	glm::vec3 product = glm::vec3(a*glm::vec4(b, 1.f));
	return product;
}



glm::vec3
ScalePointAroundAnotherPoint( glm::vec3 inputPoint, glm::vec3 centerPoint, glm::vec3 scale )
{
	glm::mat4 translation = glm::translate(glm::mat4(1.f), -centerPoint); //Move to origin
	glm::mat4 scale_transform = glm::scale(glm::mat4(1.f), scale); //Apply scaling
	glm::mat4 reverse_translation = glm::inverse(translation); //Return to orignal position
	glm::vec3 resultPoint = Multiply(Multiply(reverse_translation, Multiply(scale_transform, translation)), inputPoint);

	return resultPoint;
}



glm::vec3
RotatePointAroundAnotherPoint( glm::vec3 inputPoint, glm::vec3 centerPoint, glm::mat4 first, glm::mat4 second, glm::mat4 third )
{
	glm::vec3 relativePoint = inputPoint - centerPoint;
	glm::vec3 resultPoint = Multiply(Multiply(third, Multiply(second, first)), relativePoint);
	
	return resultPoint + centerPoint;
}


void
WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
	yourName = "Michael Smith";
	yourEmailAddress = "smitmic5@oregonstate.edu" ;
}


void
PrintMatrix( glm::mat4 mat )
{
	for( int row = 0; row < 4; row++ )
	{
		fprintf( stderr, "  %7.2f %7.2f %7.2f %7.2f\n", mat[row][0], mat[row][1], mat[row][2], mat[row][3] );
	}
}