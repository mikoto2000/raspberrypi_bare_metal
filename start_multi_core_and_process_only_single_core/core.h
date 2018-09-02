#include <types.h>

#include "system_register.h"

/**
 * @fn 現在実行中のコア ID を取得する
 *
 * @see http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.ddi0500j/index.html
 * @see ../src/core.c
 */
uint8 get_core_id(void);

/**
 * @fn 割込み待機
 *
 * @see http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.100069_0610_01_en/daw1476202785563.html
 * @see ../src/core.S
 */
void wait_for_interrupt(void);

