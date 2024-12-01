/* 
 * Include para detectar si un jugador está usando Android o PC basado en su serial (GPCI).
 * Créditos: Tamer & VAAM.
 * Basado en la documentación oficial de SA-MP.
 *
 * URL: https://www.open.mp/docs/scripting/functions/gpci
 */

#if !defined gpci
    native gpci(playerid, serial[], len);
#endif

#define PC_SERIAL "EEACC9DA0D4E9E5EEFEF55C890489095090DD8AF" //CI serial de PC, ten encuenta que no todos los seriales de PC son iguales. (No recomendable para detectar si es de PC)

#define MOBILE_CI_SERIAL "ED40ED0E8089CC44C08EE9580F4C8C44EE8EE990" //CI serial de android...

#define PLAYER_PC 1
#define PLAYER_ANDROID 2

stock CheckDevice(playerid)
{
	new serial[41];

	gpci(playerid, serial, sizeof(serial));

    if(!strcmp(MOBILE_CI_SERIAL, serial, true)) 
		return PLAYER_PC;
    else
		return PLAYER_ANDROID;
}