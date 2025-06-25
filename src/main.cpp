#include "GameController.h"
#include "GameMenu/FontHolder.h"
#include "GameMenu/ImagesButtons.h"
int main()
{
	try
	{
		ImagesButton::loadAllTextures(); // ????? ?????? ?? ?????
		FontHolder::loadFont();

		GameController gameController;
		gameController.run();
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "Runtime error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (...)
	{
		std::cerr << "Unknown error occurred." << std::endl;
		return EXIT_FAILURE;
	}
}

