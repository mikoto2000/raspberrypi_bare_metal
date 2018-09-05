/*
 * system_register.h
 *
 * a_armv8_arm:
 *     https://developer.arm.com/docs/ddi0487/latest/arm-architecture-reference-manual-armv8-for-armv8-a-architecture-profile
 * cortex_a53_trm:
 *     http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.ddi0500j/index.html
 */
#include <types.h>

/**
 * @fn MIDR_EL1 の値を取得する
 *
 * @see cortex_a53_trm - 4.3.1 Main ID Register, EL1
 */
uint64 get_midr_el1(void);

/**
 * @fn MPIDR_EL1 の値を取得する
 *
 * @see cortex_a53_trm - 4.3.2 Multiprocessor Affinity Register
 */
uint32 get_mpidr_el1(void);

/**
 * @fn REVIDR_EL1 の値を取得する
 *
 * @see cortex_a53_trm - 4.3.3 Revision ID Register
 */
uint32 get_revidr_el1(void);

/**
 * @fn ID_AA64PFR0_EL1 の値を取得する
 *
 * @see cortex_a53_trm - 4.3.18 AArch64 Processor Feature Register 0
 */
uint64 get_id_aa64pfr0_el1(void);

/**
 * @fn ID_AA64ISAR0_EL1 の値を取得する
 *
 * @see cortex_a53_trm - 4.3.20 AArch64 Instruction Set Attribute Register 0, EL1
 */
uint64 get_id_aa64isar0_el1(void);

/**
 * @fn ISR_EL1 の値を取得する
 *
 * @see cortex_a53_trm - 4.3.77 Interrupt Status Register
 */
uint64 get_isr_el1(void);

/**
 * @fn CurrentEL の値を取得する
 *
 * @see a_armv8_arm - C5.2.1 CurrentEL, Current Exception Level
 */
uint32 get_currentel(void);

/**
 * @fn NZCV の値を取得する
 *
 * @see a_armv8_arm - C5.2.10 NZCV, Condition Flags
 */
uint32 get_nzcv(void);

/**
 * @fn DAIF フラグの値を取得す
 *
 * @see a_armv8_arm - C5.2.2 DAIF, Interrupt Mask Bits
 */
uint32 get_daif(void);

/**
 * @fn SPSR_EL1 の値を取得する
 *
 * @fn a_armv8_arm - D1.6.4 Saved Program Status Registers (SPSRs)
 */
uint32 get_spsr_el1(void);

/**
 * @fn SPSR_EL2 の値を取得する
 *
 * @fn a_armv8_arm - D1.6.4 Saved Program Status Registers (SPSRs)
 */
uint32 get_spsr_el2(void);

/**
 * @fn SPSR_EL3 の値を取得する
 *
 * @fn a_armv8_arm - D1.6.4 Saved Program Status Registers (SPSRs)
 */
uint32 get_spsr_el3(void);

