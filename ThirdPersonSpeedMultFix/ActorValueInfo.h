#pragma once

#define DEFAULT_ANIM_MULT 100.0f
#define DEFAULT_MOD_VALUE 0.0f

class ActorValue
{
public:
	enum ACTOR_VALUE_MODIFIER {
		Temp,
		Perm,
		Damage
	};

	enum class AVType
	{
		kDerivedAttribute,
		kAttribute,
		kSkill,
		kAIAttribute,
		kResistance,
		kCondition,
		kCharge,
		kIntValue,
		kVariable,
		kResource
	};

	// members
	ActorValueInfo* absorbChance;                       // 000
	ActorValueInfo* actionPoints;                       // 008
	ActorValueInfo* aggression;                         // 010
	ActorValueInfo* agility;                            // 018
	ActorValueInfo* aimStability;                       // 020
	ActorValueInfo* alchemy;                            // 028
	ActorValueInfo* animationMult;                      // 030
	ActorValueInfo* armorPerks;                         // 038
	ActorValueInfo* assistance;                         // 040
	ActorValueInfo* attackDamageMult;                   // 048
	ActorValueInfo* blindness;                          // 050
	ActorValueInfo* block;                              // 058
	ActorValueInfo* bloodyMess;                         // 060
	ActorValueInfo* bowSpeedBonus;                      // 068
	ActorValueInfo* bowStaggerBonus;                    // 070
	ActorValueInfo* brainCondition;                     // 078
	ActorValueInfo* carryWeight;                        // 080
	ActorValueInfo* charisma;                           // 088
	ActorValueInfo* combatHealthRegenMult;              // 090
	ActorValueInfo* confidence;                         // 098
	ActorValueInfo* criticalChance;                     // 0A0
	ActorValueInfo* damageResistance;                   // 0A8
	ActorValueInfo* deafness;                           // 0B0
	ActorValueInfo* enchanting;                         // 0B8
	ActorValueInfo* endurance;                          // 0C0
	ActorValueInfo* enduranceCondition;                 // 0C8
	ActorValueInfo* experience;                         // 0D0
	ActorValueInfo* health;                             // 0D8
	ActorValueInfo* healRateMult;                       // 0E0
	ActorValueInfo* idleChatterTimeMin;                 // 0E8
	ActorValueInfo* idleChatterTimeMAx;                 // 0F0
	ActorValueInfo* ignoreCrippledLimbs;                // 0F8
	ActorValueInfo* intelligence;                       // 100
	ActorValueInfo* invisibility;                       // 108
	ActorValueInfo* karma;                              // 110
	ActorValueInfo* leftAttackCondition;                // 118
	ActorValueInfo* leftItemCharge;                     // 120
	ActorValueInfo* leftMobiltyCondition;               // 128
	ActorValueInfo* leftWeaponSpeedMult;                // 130
	ActorValueInfo* lockpicking;                        // 138
	ActorValueInfo* luck;                               // 140
	ActorValueInfo* mass;                               // 148
	ActorValueInfo* meleeDamage;                        // 150
	ActorValueInfo* morality;                           // 158
	ActorValueInfo* movementNoiseMult;                  // 160
	ActorValueInfo* nightEyeBonus;                      // 168
	ActorValueInfo* perception;                         // 170
	ActorValueInfo* perceptionCondition;                // 178
	ActorValueInfo* pickpocket;                         // 180
	ActorValueInfo* poisonResistance;                   // 188
	ActorValueInfo* powerArmorBattery;                  // 190
	ActorValueInfo* powerArmorHeadCondition;            // 198
	ActorValueInfo* powerArmorTorsoCondition;           // 1A0
	ActorValueInfo* powerArmorLeftArmCondition;         // 1A8
	ActorValueInfo* powerArmorRightArmCondition;        // 1B0
	ActorValueInfo* powerArmorLeftLegCondition;         // 1B8
	ActorValueInfo* powerArmorRightLegCondition;        // 1C0
	ActorValueInfo* radHealthMax;                       // 1C8
	ActorValueInfo* rads;                               // 1D0
	ActorValueInfo* fatigueAPMax;                       // 1D8
	ActorValueInfo* fatigue;                            // 1E0
	ActorValueInfo* reflectDamage;                      // 1E8
	ActorValueInfo* restoreConditionRate;               // 1F0
	ActorValueInfo* rightAttackCondition;               // 1F8
	ActorValueInfo* rightItemCharge;                    // 200
	ActorValueInfo* rightMobilityCondition;             // 208
	ActorValueInfo* rotationSpeedCondition;             // 210
	ActorValueInfo* shieldPerks;                        // 218
	ActorValueInfo* shoutRecoveryMult;                  // 220
	ActorValueInfo* sneak;                              // 228
	ActorValueInfo* speechcraft;                        // 230
	ActorValueInfo* speedMult;                          // 238
	ActorValueInfo* stamina;                            // 240
	ActorValueInfo* strength;                           // 248
	ActorValueInfo* suspicious;                         // 250
	ActorValueInfo* telekinesis;                        // 258
	ActorValueInfo* unarmedDamage;                      // 260
	ActorValueInfo* vansPerk;                           // 268
	ActorValueInfo* wardPower;                          // 270
	ActorValueInfo* waitingForPlayer;                   // 278
	ActorValueInfo* waterBreathing;                     // 280
	ActorValueInfo* waterWalking;                       // 288
	ActorValueInfo* weaponSpeedMult;                    // 290
	ActorValueInfo* weapReloadSpeedMult;                // 298
	ActorValueInfo* restoreHealthRate;                  // 2A0
	ActorValueInfo* restoreAPRate;                      // 2A8
	ActorValueInfo* apRateMult;                         // 2B0
	ActorValueInfo* restoreRadsRate;                    // 2B8
	ActorValueInfo* radsRateMult;                       // 2C0
	ActorValueInfo* restoreFatigueRate;                 // 2C8
	ActorValueInfo* fatigueRateMult;                    // 2D0
	ActorValueInfo* conditionRateMult;                  // 2D8
	ActorValueInfo* fireResistance;                     // 2E0
	ActorValueInfo* electricalResistance;               // 2E8
	ActorValueInfo* frostResistance;                    // 2F0
	ActorValueInfo* magicResistance;                    // 2F8
	ActorValueInfo* radIngestionResistance;             // 300
	ActorValueInfo* radExposureResistance;              // 308
	ActorValueInfo* energy;                             // 310
	ActorValueInfo* energyResistance;                   // 318
	ActorValueInfo* paralysis;                          // 320
	ActorValueInfo* attackConditionAlt1;                // 328
	ActorValueInfo* attackConditionAlt2;                // 330
	ActorValueInfo* attackConditionAlt3;                // 338
	ActorValueInfo* powerGenerated;                     // 340
	ActorValueInfo* powerRadation;                      // 348
	ActorValueInfo* powerRequired;                      // 350
	ActorValueInfo* resourceFood;                       // 358
	ActorValueInfo* resourceWater;                      // 360
	ActorValueInfo* resourceSafety;                     // 368
	ActorValueInfo* resourceBed;                        // 370
	ActorValueInfo* resourceHappiness;                  // 378
	ActorValueInfo* resourceArtillery;                  // 380
	ActorValueInfo* workshopItemOverlap;                // 388
	ActorValueInfo* workshopItemClampDirection;         // 390
	ActorValueInfo* workshopItemZOffset;                // 398
	ActorValueInfo* workshopPlayerOwned;                // 3A0
	ActorValueInfo* workshopActorWounded;               // 3A8
	ActorValueInfo* workshopStackableItem;              // 3B0
	ActorValueInfo* workshopSnapPointRadius;            // 3B8
	ActorValueInfo* workshopAnythingIsGround;           // 3C0
	ActorValueInfo* workshopMaxTriangles;               // 3C8
	ActorValueInfo* workshopMaxDraws;                   // 3D0
	ActorValueInfo* workshopCurrentTriangles;           // 3D8
	ActorValueInfo* workshopCurrentDraws;               // 3E0
	ActorValueInfo* workshopIgnoreSimpleIntersections;  // 3E8
	ActorValueInfo* workshopAllowUnsupportedStacking;   // 3F0
	ActorValueInfo* workshopSnapTransmitsPower;         // 3F8
	ActorValueInfo* workshopPowerConnection;            // 400
	ActorValueInfo* logicOperation;                     // 408
	ActorValueInfo* logicOutput;                        // 410
	ActorValueInfo* ignorePlayerWhileFrenzied;          // 418
	tArray<ActorValueInfo*> hardcodedActorValues;		// 420
	tArray<ActorValueInfo*> conditionActorValues;		// 438
	std::uint32_t avTypeCounts[10];                     // 450
};

struct ModifiedValues {
	float base;
	float temp;
	float perm;
	float damage;

	ModifiedValues& operator += (ModifiedValues const& obj) {
		base += obj.base;
		temp += obj.temp;
		perm += obj.perm;
		damage += obj.damage;
		return *this;
	}

	void ClearValues() {
		base = temp = perm = damage = 0.0f;
	}

	bool IsModified() {
		if (base == 0 && temp == 0 && perm == 0 && damage == 0)
			return false;
		return true;
	}

	float GetTotalSum() {
		return base + temp + perm + damage;
	}
};

void ModifyAnimMult();
void RestoreAnimMult();