

#include "sfwdraw.h"

#include "Player.h"



int main()
{
	
	sfw::initContext(800, 600, "0G Shooter");

	sfw::setBackgroundColor(BLACK);



	Player player;




	while (sfw::stepContext())
	{
		
		player.update();

		player.draw();

	}

	return 0;
}