// Thomas Learning Project

#pragma once

#include "AuraNativeGameplayTags.h"

// Vital Attributes
UE_DEFINE_GAMEPLAY_TAG(Attributes_Vital_Health, "Attributes.Vital.Health");
UE_DEFINE_GAMEPLAY_TAG(Attributes_Vital_MaxHealth, "Attributes.Vital.MaxHealth");
UE_DEFINE_GAMEPLAY_TAG(Attributes_Vital_Mana, "Attributes.Vital.Mana");
UE_DEFINE_GAMEPLAY_TAG(Attributes_Vital_MaxMana, "Attributes.Vital.MaxMana");


// Primary Attributes
UE_DEFINE_GAMEPLAY_TAG(Attributes_Primary_Strength, "Attributes.Primary.Strength");
UE_DEFINE_GAMEPLAY_TAG(Attributes_Primary_Intelligence, "Attributes.Primary.Intelligence");
UE_DEFINE_GAMEPLAY_TAG(Attributes_Primary_Resilience, "Attributes.Primary.Resilience");
UE_DEFINE_GAMEPLAY_TAG(Attributes_Primary_Vigor, "Attributes.Primary.Vigor");


// Secondary Attributes
UE_DEFINE_GAMEPLAY_TAG(Attributes_Secondary_Armor, "Attributes.Secondary.Armor");
UE_DEFINE_GAMEPLAY_TAG(Attributes_Secondary_ArmorPenetration, "Attributes.Secondary.ArmorPenetration");
UE_DEFINE_GAMEPLAY_TAG(Attributes_Secondary_BlockChance, "Attributes.Secondary.BlockChance");
UE_DEFINE_GAMEPLAY_TAG(Attributes_Secondary_CriticalHitChance, "Attributes.Secondary.CriticalHitChance");
UE_DEFINE_GAMEPLAY_TAG(Attributes_Secondary_CriticalHitDamage, "Attributes.Secondary.CriticalHitDamage");
UE_DEFINE_GAMEPLAY_TAG(Attributes_Secondary_CriticalHitResistance, "Attributes.Secondary.CriticalHitResistance");
UE_DEFINE_GAMEPLAY_TAG(Attributes_Secondary_HealthRegeneration, "Attributes.Secondary.HealthRegeneration");
UE_DEFINE_GAMEPLAY_TAG(Attributes_Secondary_ManaRegeneration, "Attributes.Secondary.ManaRegeneration");


// Attributes_Resistance
UE_DEFINE_GAMEPLAY_TAG(Attributes_Resistance, "Attributes.Resistance");
UE_DEFINE_GAMEPLAY_TAG(Attributes_Resistance_Fire, "Attributes.Resistance.FireResistance");
UE_DEFINE_GAMEPLAY_TAG(Attributes_Resistance_Lightning, "Attributes.Resistance.LightningResistance");
UE_DEFINE_GAMEPLAY_TAG(Attributes_Resistance_Arcane, "Attributes.Resistance.ArcaneResistance");
UE_DEFINE_GAMEPLAY_TAG(Attributes_Resistance_Physical, "Attributes.Resistance.PhysicalResistance");


// Experience Attributes
UE_DEFINE_GAMEPLAY_TAG(Attributes_Experience, "Attributes.Experience");
UE_DEFINE_GAMEPLAY_TAG(Attributes_Experience_XP, "Attributes.Experience.XP");
UE_DEFINE_GAMEPLAY_TAG(Attributes_Experience_IncomingXP, "Attributes.Experience.IncomingXP");
UE_DEFINE_GAMEPLAY_TAG(Attributes_Experience_Level, "Attributes.Experience.Level");


// Damage Types
UE_DEFINE_GAMEPLAY_TAG(Damage, "Damage");
UE_DEFINE_GAMEPLAY_TAG(Damage_Fire, "Damage.Fire");
UE_DEFINE_GAMEPLAY_TAG(Damage_Lightning, "Damage.Lightning");
UE_DEFINE_GAMEPLAY_TAG(Damage_Arcane, "Damage.Arcane");
UE_DEFINE_GAMEPLAY_TAG(Damage_Physical, "Damage.Physical");

UE_DEFINE_GAMEPLAY_TAG(Common_Event, "Common.Event");
UE_DEFINE_GAMEPLAY_TAG(Common_Event_HitReact, "Common.Event.HitReact");


// Character Events Tags
UE_DEFINE_GAMEPLAY_TAG(CharacterEvents_LeveledUp, "CharacterEvents.LeveledUp");


// Character Status Tags
UE_DEFINE_GAMEPLAY_TAG(Common_Status_Dead, "Common.Status.Dead");


// Input Tags
UE_DEFINE_GAMEPLAY_TAG(Input, "Input");
UE_DEFINE_GAMEPLAY_TAG(Input_Move, "Input.Move");
UE_DEFINE_GAMEPLAY_TAG(Input_Mouse_LeftButton, "Input.Mouse.LeftButton");
UE_DEFINE_GAMEPLAY_TAG(Input_Mouse_RightButton, "Input.Mouse.RightButton");


// HUDLayout Tags
UE_DEFINE_GAMEPLAY_TAG(HUDLayout_Overlay, "HUDLayout.Overlay");


// Widget Tags
UE_DEFINE_GAMEPLAY_TAG(Widget, "Widget");
UE_DEFINE_GAMEPLAY_TAG(Widget_Player, "Widget.Player");
