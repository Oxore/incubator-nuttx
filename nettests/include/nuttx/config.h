#define CONFIG_ARCH_INTEL64 1

/* TCP and UDP depend on IOB chains. If CONFIG_IOB_NCHAINS is not defined, then
 * the type of iob is not defined at all and TCP fails to compile */

#define CONFIG_MM_IOB 1
#define CONFIG_IOB_NCHAINS 16
#define CONFIG_IOB_NBUFFERS 16
#define CONFIG_IOB_BUFSIZE 255

#define CONFIG_MM_REGIONS 1

/* Network, of course */

#define CONFIG_NET 1
#define CONFIG_NET_IPv4 1
#define CONFIG_NET_IPv6 1
#define CONFIG_NET_READAHEAD 1

/* TCP will be tested */

#define CONFIG_NET_TCP 1
#define CONFIG_NET_TCP_NPOLLWAITERS 16

/* UDP will be tested */

#define CONFIG_NET_UDP 1
#define CONFIG_NET_UDP_NPOLLWAITERS 16

#define CONFIG_NET_TUN 1
#define CONFIG_NET_WRITE_BUFFERS 1
#define CONFIG_NFILE_DESCRIPTORS 16
#define CONFIG_NSOCKET_DESCRIPTORS 16

/* For sched mocks, required by sched/sched/sched.h */

#define CONFIG_MAX_TASKS 16
