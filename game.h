#pragma once

// Forward declarations
struct float3;

namespace Tmpl8 {

// Forward declarations
class Surface;

class Game
{
public:
	void SetTarget( Surface* surface ) { screen = surface; }
	void Init();
	void PresentFloatBuffer();
	void Shutdown();
	void Tick( float deltaTime );
	void MouseUp( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseDown( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseMove( int x, int y ) { /* implement if you want to detect mouse movement */ }
	void KeyUp( int key ) { /* implement if you want to handle keys */ }
	void KeyDown( int key ) { /* implement if you want to handle keys */ }
	Surface* screen;
	float3* floatBuffer;
};

}; // namespace Tmpl8
