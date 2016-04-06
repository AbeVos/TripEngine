#include "Priest.h"
#include "..\Import\TextureImporter.h"

using namespace TripEngine;
using namespace Actors;

Priest::Priest() : Actor()
{
	Components::Model* priest = new Components::Model(transform ,"Resources\\Models\\Priest.obj");
	AddComponent(ct_Model, priest);

	priest->SetDiffuse(Import::TextureImporter::ImportTexture("Resources\\Textures\\priestGreen.bmp", 1024, 1024));
}

Priest::~Priest()
{

}