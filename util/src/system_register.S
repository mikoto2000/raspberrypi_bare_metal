.global get_mpidr_el1
get_mpidr_el1:
    mrs x0, mpidr_el1
    ret

