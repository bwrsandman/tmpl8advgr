#include "precomp.h" // include (only) this in every .cpp file

// -----------------------------------------------------------
// Initialize the application
// -----------------------------------------------------------
void Game::Init()
{
	// allocate memory for the floating point render target
	floatBuffer = new float3[SCRWIDTH * SCRHEIGHT];
	// clear the render target
	memset( floatBuffer, 0, SCRWIDTH * SCRHEIGHT * 4 );
}

// -----------------------------------------------------------
// Close down application
// -----------------------------------------------------------
void Game::Shutdown()
{
	delete [] floatBuffer;
}

// -----------------------------------------------------------
// Convert the floating point pixel buffer to integer pixels
// -----------------------------------------------------------
void Game::PresentFloatBuffer()
{
	int pixelIndex = 0;
	uint* screenBuffer = screen->GetBuffer();
	for( int y = 0; y < SCRHEIGHT; y++ ) for( int x = 0; x < SCRWIDTH; x++ )
	{
		float3 pixel = floatBuffer[pixelIndex];
		int red = clamp( (int)(pixel.x * 256.0f), 0, 255 );
		int green = clamp( (int)(pixel.y * 256.0f), 0, 255 );
		int blue = clamp( (int)(pixel.z * 256.0f), 0, 255 );
		screenBuffer[pixelIndex++] = (red << 16) + (green << 8) + blue;
	}
}

// -----------------------------------------------------------
// Main application tick function
// -----------------------------------------------------------
void Game::Tick( float deltaTime )
{
	// draw something in the float buffer
	for( int y = 0; y < SCRHEIGHT; y++ ) for( int x = 0; x < SCRWIDTH; x++ )
	{
		float3 color = make_float3( 0.2f, 0.2f, 0.25f ); // replace by ray tracing calculation
		floatBuffer[x + y * SCRWIDTH] = color;
	}
	// convert the float buffer to integer pixels
	PresentFloatBuffer();
	// print something over the rendered pixels
	screen->Print( "hello world", 2, 2, 0xffffff );
	// draw something over the rendered pixels
	screen->Bar( 50, 200, 100, 250, 0xff0000 ); // red
	screen->Bar( 125, 200, 175, 250, 0x00ff00 ); // green
	screen->Bar( 200, 200, 250, 250, 0x0000ff ); // blue
}