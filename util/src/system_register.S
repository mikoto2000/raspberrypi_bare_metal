.global get_midr_el1
get_midr_el1:
    mrs x0, midr_el1
    ret

.global get_mpidr_el1
get_mpidr_el1:
    mrs x0, mpidr_el1
    ret

.global get_revidr_el1
get_revidr_el1:
    mrs x0, revidr_el1
    ret

.global get_id_aa64pfr0_el1
get_id_aa64pfr0_el1:
    mrs x0, id_aa64pfr0_el1
    ret

.global get_id_aa64isar0_el1
get_id_aa64isar0_el1:
    mrs x0, id_aa64isar0_el1
    ret

.global get_isr_el1
get_isr_el1:
    mrs x0, isr_el1
    ret

.global get_currentel
get_currentel:
    mrs x0, currentel
    ret

.global get_nzcv
get_nzcv:
    mrs x0, nzcv
    ret

.global get_daif
get_daif:
    mrs x0, daif
    ret

.global get_spsr_el1
get_spsr_el1:
    mrs x0, spsr_el1
    ret

.global get_spsr_el2
get_spsr_el2:
    mrs x0, spsr_el2
    ret

.global get_spsr_el3
get_spsr_el3:
    mrs x0, spsr_el3
    ret

