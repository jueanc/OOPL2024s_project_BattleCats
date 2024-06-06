#include "stdafx.h"
#include "../Core/game.h"
#include "../Core/MainFrm.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <direct.h>
#include <string.h>
#include ".\Source\.\Library\audio.h"
#include ".\Source\.\Library\gameutil.h"
#include ".\Source\.\Library\gamecore.h"
#include "Shlwapi.h"
#include "../Game/config.h"
#include "../Game/mygame.h"
#include <filesystem>
#include <experimental/filesystem> // Header file for pre-standard implementation
#include <comdef.h>
#include"windef.h"
#include"wingdi.h"
#include"atltypes.h"
#include"time.h"
#include"afxwin.h"
#include"monster.h"
namespace game_framework {

	monster::monster(): CMovingBitmap()
	{
		
	}

	monster::monster(int type_ID)
	{
		if (type_ID == 1) {
			isBitmapLoaded = false;
			price = 50;
			heart = 200;
			attack_range = 5;
			power = 15;
			walk_speed = 2;
			if_attack = 0;
			type = 0;
			back_time = 0;
			whether_attack = false;
			single_attack = 1;
		}

		if (type_ID == 2) { //©Z§J¿ß
			isBitmapLoaded = false;
			price = 100;
			heart = 800;
			attack_range = 15;
			power = 5;
			walk_speed = 1;
			if_attack = 0;
			type = 0;
			back_time = 0;
			whether_attack = false;
			single_attack = 1;
		}

		if (type_ID == 3) { //©òÀY
			isBitmapLoaded = false;
			price = 200;
			heart = 400;
			attack_range = 5;
			power = 50;
			walk_speed = 2;
			if_attack = 0;
			type = 0;
			back_time = 0;
			whether_attack = false;
			single_attack = 1;
		}

		if (type_ID == 4) { //
			isBitmapLoaded = false;
			price = 600;
			heart = 800;
			attack_range = 10;
			power = 200;
			walk_speed = 2;
			if_attack = 0;
			type = 0;
			back_time = 0;
			whether_attack = false;
			single_attack = 1;
		}

		if (type_ID == 5) { //
			isBitmapLoaded = false;
			price = 50;
			heart = 1000;
			attack_range = 15;
			power = 50;
			walk_speed = 2;
			if_attack = 0;
			type = 0;
			back_time = 0;
			whether_attack = false;
			single_attack = 0;
		}

		if (type_ID == 11) {
			isBitmapLoaded = false;
			price = 50;
			heart = 90;
			attack_range = 5;
			power = 8;
			walk_speed = 2;
			if_attack = 0;
			type = 0;
			back_time = 0;
			whether_attack = false;
			single_attack = 1;
		}

		if (type_ID == 12) { //³D
			isBitmapLoaded = false;
			price = 50;
			heart = 100;
			attack_range = 5;
			power = 150;
			walk_speed = 2;
			if_attack = 0;
			type = 0;
			back_time = 0;
			whether_attack = false;
			single_attack = 1;
		}

		if (type_ID == 13) { 
			isBitmapLoaded = false;
			price = 50;
			heart = 200;
			attack_range = 5;
			power = 20;
			walk_speed = 2;
			if_attack = 0;
			type = 0;
			back_time = 0;
			whether_attack = false;
			single_attack = 1;
		}

		if (type_ID == 14) {
			isBitmapLoaded = false;
			price = 50;
			heart = 100;
			attack_range = 5;
			power = 15;
			walk_speed = 2;
			if_attack = 0;
			type = 0;
			back_time = 0;
			whether_attack = false;
			single_attack = 1;
		}
		if (type_ID == 15) {
			isBitmapLoaded = false;
			price = 50;
			heart = 100;
			attack_range = 5;
			power = 15;
			walk_speed = 2;
			if_attack = 0;
			type = 0;
			back_time = 0;
			whether_attack = false;
			single_attack = 1;
		}
		if (type_ID == 16) {
			isBitmapLoaded = false;
			price = 50;
			heart = 100;
			attack_range = 5;
			power = 15;
			walk_speed = 2;
			if_attack = 0;
			type = 0;
			back_time = 0;
			whether_attack = false;
			single_attack = 1;
		}
	}

	int monster::get_type()
	{
		return type;
	}

	int monster::get_back_time()
	{
		return back_time;
	}

	bool monster::get_whether_attack()
	{
		return whether_attack;
	}

	int monster::get_price() 
	{
		return price ; 
	}

	int monster::get_heart()
	{
		return heart;
	}

	int monster::get_single_attack()
	{
		return single_attack;
	}

	int monster::get_attack_range()
	{
		return attack_range;
	}

	int monster::get_power()
	{
		return power;
	}

	int monster::get_walk_speed()
	{
		return walk_speed;
	}

	int monster::get_cool_time()
	{
		return cool_time;
	}

	int monster::get_if_attack()
	{
		return if_attack;
	}
}