#pragma once

namespace TripEngine
{
	namespace Actors
	{
		namespace Components
		{
			enum ComponentTypes {
				Transform,
				Camera,
				Model,
				Light,
				Quad
			};

			class Component
			{
			public:
				Component();
				virtual ~Component();
			};
		}
	}
}