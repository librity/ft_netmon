// SOURCE: https://gist.github.com/sbz/1090868

// cc -lcap capabilities.c  && ./a.out
// cc -lcap capabilities.c  && sudo ./a.out

// gcc -Wl,--no-as-needed -lcap capabilities.c  && ./a.out
// gcc -Wl,--no-as-needed -lcap capabilities.c  && sudo ./a.out

// gcc capabilities.c -lcap && ./a.out
// gcc capabilities.c -lcap && sudo ./a.out

#include <sys/capability.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define nitems(x) (sizeof(x) / sizeof(x[0]))

int
main(void) {
	pid_t pid;
	cap_t cap;
	cap_value_t cap_list[CAP_LAST_CAP+1];
	cap_flag_t cap_flags;
	cap_flag_value_t cap_flags_value;
	//
	// generated list with command line below:
	// sed -n 's/^#define \(CAP_.*\) .*/\1/p' /usr/include/linux/capability.h | tr A-Z a-z
	// don't take cap_last_cap which is the same as the last cap_audit_read capability
	//
	const char *cap_name[CAP_LAST_CAP+1] = {
		"cap_chown",
		"cap_dac_override",
		"cap_dac_read_search",
		"cap_fowner",
		"cap_fsetid",
		"cap_kill",
		"cap_setgid",
		"cap_setuid",
		"cap_setpcap",
		"cap_linux_immutable",
		"cap_net_bind_service",
		"cap_net_broadcast",
		"cap_net_admin",
		"cap_net_raw",
		"cap_ipc_lock",
		"cap_ipc_owner",
		"cap_sys_module",
		"cap_sys_rawio",
		"cap_sys_chroot",
		"cap_sys_ptrace",
		"cap_sys_pacct",
		"cap_sys_admin",
		"cap_sys_boot",
		"cap_sys_nice",
		"cap_sys_resource",
		"cap_sys_time",
		"cap_sys_tty_config",
		"cap_mknod",
		"cap_lease",
		"cap_audit_write",
		"cap_audit_control",
		"cap_setfcap",
		"cap_mac_override",
		"cap_mac_admin",
		"cap_syslog",
		"cap_wake_alarm",
		"cap_block_suspend",
		"cap_audit_read",
	};
	int i, j;
        /* temporary use for cap_get_flag calls */
	struct {
		const char *str;
		cap_flag_t flag;
	} const flags[3] = {
		{"EFFECTIVE", CAP_EFFECTIVE},
		{"PERMITTED", CAP_PERMITTED},
		{"INHERITABLE", CAP_INHERITABLE}
	};

	pid = getpid();
	cap = cap_get_pid(pid);
	if (cap == NULL) {
		perror("cap_get_pid");
		exit(-1);
	}

	/* dump them */
	for (i=0; i < cap_max_bits(); i++) {
		cap_from_name(cap_name[i], &cap_list[i]);
		printf("%-20s %d\t\t", cap_to_name(cap_list[i]), cap_list[i]);
		printf("flags: \t\t");
		for (j=0; j < nitems(flags); j++) {
			cap_get_flag(cap, cap_list[i], flags[j].flag, &cap_flags_value);
			printf(" %s %-4s ", flags[j].str, (cap_flags_value == CAP_SET) ? "OK" : "NOK");
		}
		printf("\n");
	}

	cap_free(cap);

	return 0;
}
