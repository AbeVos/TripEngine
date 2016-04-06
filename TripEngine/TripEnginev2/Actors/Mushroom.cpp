#include "Mushroom.h"
#include "..\Import\TextureImporter.h"

using namespace TripEngine;
using namespace Actors;

Mushroom::Mushroom() : Actor()
{
	Components::Model* mushroom = new Components::Model(transform, "Resources/Models/Mushroom.obj");
	AddComponent(ct_Model, mushroom);

	mushroom->SetDiffuse(Import::TextureImporter::ImportTexture("Resources/Textures/Mushroom_dif.bmp", 1024, 1024));
}

Mushroom::~Mushroom()
{

}