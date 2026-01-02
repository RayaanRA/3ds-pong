#include "game.h"
#include "utils.h"

bool scan_input() {
	hidScanInput();

	u32 k_down = hidKeysDown();
	if (k_down & KEY_START) {
		return false;
	}
	return true;

}