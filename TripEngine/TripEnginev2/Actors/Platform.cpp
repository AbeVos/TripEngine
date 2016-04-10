#include "Platform.h"
#include "..\Import\TextureImporter.h"

using namespace TripEngine;
using namespace Actors;

Platform::Platform() : Actor()
{
	Components::Model* platform = new Components::Model(transform, "Resources\\Models\\Platform.obj");
	AddComponent(ct_Model, platform);

	platform->SetDiffuse(Import::TextureImporter::ImportTexture("Resources\\Textures\\priestGreen.bmp", 1024, 1024));
}

Platform::~Platform()
{

}