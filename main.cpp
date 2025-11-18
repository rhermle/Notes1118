#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class RainbowScreen : public Drawable
{
public:
	RainbowScreen(int pixelWidth, int pixelHeight);
	void draw(RenderTarget& target, RenderStates states) const override;  //window.draw(...) calls this polymorphically
	void update();
private:
	VertexArray m_va; //array of pixel locations and their colors (draw pixels on the screen)
	Vector2i m_pixel_size;  //size of screen 
};

RainbowScreen::RainbowScreen(int pixelWidth, int pixelHeight)
{
	m_pixel_size = { pixelWidth, pixelHeight };
	//populate the vertex array (all the pixels to draw)
	m_va.setPrimitiveType(Points); //draw every point in the container
	m_va.resize(pixelWidth * pixelHeight);
}
void RainbowScreen::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_va);
}

int main()
{
	int pixelWidth = VideoMode::getDesktopMode().width;
	int pixelHeight = VideoMode::getDesktopMode().height;
	VideoMode vm(pixelWidth, pixelHeight);
	RenderWindow window(vm, "Rainbow Screen", Style::Default);

	//Each iteration of this loop is 1 frame
	while (window.isOpen())
	{
		///Input
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close(); //x button on top left was pressed
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					cout << "Left mouse button was pressed" << endl;
					cout << "Mouse x: " << event.mouseButton.x << endl;
					cout << "Mouse y: " << event.mouseButton.y << endl;
				}
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		///Update
		float radius = 150.0;
		CircleShape circle(150);
		circle.setFillColor(Color::Magenta);
		circle.setPosition(960, 540);
		circle.setOrigin(radius, radius);

		///Draw
		window.clear();  //clear previous frame
		//window.draw(stuff);
		window.draw(circle);
		window.display(); //draw all the things we told it to draw
	}
}*/