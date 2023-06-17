#pragma once

/// <summary>
/// Enum responsible for storing every bomb/explosion type present in the game
/// </summary>
enum Source {

	// type representing missiles
	MISSILE,
	// type representing normal bombs
	NORMAL,
	// type representing nuclear bombs
	NUCLEAR,
	// type representing cluster bombs
	CLUSTER,
	// type representing bomblets, that may spawn from cluster bombs
	BOMBLET,
	// type representing napalm bombs
	NAPALM,
	// type representing ultimate bombs - Rods of God
	RODOFGOD
};
