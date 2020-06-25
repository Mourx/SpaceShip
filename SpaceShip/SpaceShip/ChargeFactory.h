#pragma once
#include "Charge.h"
#include "enums.h"
class ChargeFactory
{
	typedef Charge* (*CreateCharge)();
	public:
		static Charge* GenerateCharge(CHARGE_RARITY rarity) {
			CreateCharge createCommon[] =
			{
				BasicCharge::Create,
				BasicShield::Create

			};
			const int countCom = sizeof(createCommon) / sizeof(*createCommon);

			CreateCharge createUncommon[] =
			{
				EasyBomb::Create,
				WideShield::Create

			};
			const int countUnc = sizeof(createUncommon) / sizeof(*createUncommon);

			CreateCharge createRare[] =
			{
				BasicCharge::Create,
				BasicShield::Create

			};
			const int countRare = sizeof(createRare) / sizeof(*createRare);

			switch (rarity)
			{
			case COMMONC:
				
				return createCommon[rand() % countCom]();
				break;
			case UNCOMMONC:
				return  createUncommon[rand() % countUnc]();
				break;
			case RAREC:
				return createRare[rand() % countRare]();
				break;
			default:
				return NULL;
				break;
			}
			
		}
};

