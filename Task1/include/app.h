#include <SFML/Graphics.hpp>

#include "triangle.h"

class app {
public:
	app();
	void events();

private:
	sf::RenderWindow window;
	sf::Event event;
	triangle t1;
	triangle t2;
	sf::ConvexShape shape1;
	sf::ConvexShape shape2;

};
