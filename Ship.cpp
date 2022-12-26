#include "Ship.h"
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "Game.h"
#include "Laser.h"

Ship::Ship(Game* game) :
	Actor(game),
	mLaserCooldown(0.0f) {
	
	SpriteComponent* sc = new SpriteComponent(this, 150);
	sc->SetTexture(game->GetTexture("Assets/Ship.png"));

	Inputcomponent* ic = new InputComponent(this);
	ic->SetForwardKey(SDL_SCANCODE_W);
	ic->SetBackKey(SDL_SCANCODE_S);
	ic->setClockwiseKey(SDL_SCANCODE_A);
	ic->setCounterClockwiseKey(SDL_SCANCODE_D);
	ic->SetMaxForwardSpeed(300.0f);
	ic->SetMaxAngularSpeed(Math::twoPi);
}

void Ship::UpdateActor(float deltaTime) {
	mLasercooldown -= deltatime;
}

void Ship::ActorInput(const uint8_t keyState) {
	if (keyState[SDL_SCANCODE_SPACE] && mLaserCooldown <= 0.0f) {
		Laser* laser = new Laser(GetGame());
		laser->SetPosition(GetPosition());
		laser->Setrotation(GetRotation());

		mLaserCooldown = 0.5f;
	}
}