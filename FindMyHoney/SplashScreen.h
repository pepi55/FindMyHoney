#pragma once

// Splash screen shows a splash image if available otherwise skips screen.
class SplashScreen
{
	public:
		SplashScreen(void);
		~SplashScreen(void);

		void show(sf::RenderWindow &window);
};