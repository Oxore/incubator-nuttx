cmake_minimum_required(VERSION 3.16)
project(net-tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-unused")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fsanitize=address -fno-omit-frame-pointer")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-unused -Wno-nested-anon-types")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -fno-omit-frame-pointer")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fsanitize=address -fno-omit-frame-pointer")
set(net_sources
	"../net/devif/devif_callback.c"
	"../net/devif/devif_cansend.c"
	"../net/devif/devif_forward.c"
	"../net/devif/devif_initialize.c"
	"../net/devif/devif_iobsend.c"
	"../net/devif/devif_loopback.c"
	"../net/devif/devif_pktsend.c"
	"../net/devif/devif_poll.c"
	"../net/devif/devif_send.c"
	"../net/devif/ipv4_input.c"
	"../net/devif/ipv6_input.c"
	"../net/inet/inet_globals.c"
	"../net/inet/inet_sockif.c"
	"../net/inet/inet_txdrain.c"
	"../net/inet/ipv4_getpeername.c"
	"../net/inet/ipv4_getsockname.c"
	"../net/inet/ipv4_setsockopt.c"
	"../net/inet/ipv6_getpeername.c"
	"../net/inet/ipv6_getsockname.c"
	"../net/inet/ipv6_setsockopt.c"
	"../net/net_initialize.c"
	"../net/netdev/netdev_carrier.c"
	"../net/netdev/netdev_count.c"
	"../net/netdev/netdev_default.c"
	"../net/netdev/netdev_findbyaddr.c"
	"../net/netdev/netdev_findbyindex.c"
	"../net/netdev/netdev_findbyname.c"
	"../net/netdev/netdev_foreach.c"
	"../net/netdev/netdev_ifconf.c"
	"../net/netdev/netdev_indextoname.c"
	"../net/netdev/netdev_ioctl.c"
	"../net/netdev/netdev_lladdrsize.c"
	"../net/netdev/netdev_nametoindex.c"
	"../net/netdev/netdev_register.c"
	"../net/netdev/netdev_txnotify.c"
	"../net/netdev/netdev_unregister.c"
	"../net/netdev/netdev_verify.c"
	"../net/netdev/netdown_notifier.c"
	"../net/socket/accept.c"
	"../net/socket/bind.c"
	"../net/socket/connect.c"
	"../net/socket/getpeername.c"
	"../net/socket/getsockname.c"
	"../net/socket/getsockopt.c"
	"../net/socket/listen.c"
	"../net/socket/net_checksd.c"
	"../net/socket/net_close.c"
	"../net/socket/net_dup.c"
	"../net/socket/net_dup2.c"
	"../net/socket/net_fstat.c"
	"../net/socket/net_poll.c"
	"../net/socket/net_sendfile.c"
	"../net/socket/net_sockets.c"
	"../net/socket/net_sockif.c"
	"../net/socket/net_timeo.c"
	"../net/socket/net_vfcntl.c"
	"../net/socket/recv.c"
	"../net/socket/recvfrom.c"
	"../net/socket/recvmsg.c"
	"../net/socket/send.c"
	"../net/socket/sendmsg.c"
	"../net/socket/sendto.c"
	"../net/socket/setsockopt.c"
	"../net/socket/socket.c"
	"../net/tcp/tcp_accept.c"
	"../net/tcp/tcp_appsend.c"
	"../net/tcp/tcp_backlog.c"
	"../net/tcp/tcp_callback.c"
	"../net/tcp/tcp_close.c"
	"../net/tcp/tcp_conn.c"
	"../net/tcp/tcp_connect.c"
	"../net/tcp/tcp_devpoll.c"
	"../net/tcp/tcp_finddev.c"
	"../net/tcp/tcp_getsockopt.c"
	"../net/tcp/tcp_input.c"
	"../net/tcp/tcp_ipselect.c"
	"../net/tcp/tcp_listen.c"
	"../net/tcp/tcp_monitor.c"
	"../net/tcp/tcp_netpoll.c"
	"../net/tcp/tcp_notifier.c"
	"../net/tcp/tcp_recvfrom.c"
	"../net/tcp/tcp_recvwindow.c"
	"../net/tcp/tcp_send.c"
	"../net/tcp/tcp_send_buffered.c"
	"../net/tcp/tcp_send_unbuffered.c"
	"../net/tcp/tcp_sendfile.c"
	"../net/tcp/tcp_seqno.c"
	"../net/tcp/tcp_setsockopt.c"
	"../net/tcp/tcp_timer.c"
	"../net/tcp/tcp_txdrain.c"
	"../net/tcp/tcp_wrbuffer.c"
	"../net/tcp/tcp_wrbuffer_dump.c"
	"../net/udp/udp_callback.c"
	"../net/udp/udp_close.c"
	"../net/udp/udp_conn.c"
	"../net/udp/udp_devpoll.c"
	"../net/udp/udp_finddev.c"
	"../net/udp/udp_input.c"
	"../net/udp/udp_ipselect.c"
	"../net/udp/udp_netpoll.c"
	"../net/udp/udp_notifier.c"
	"../net/udp/udp_recvfrom.c"
	"../net/udp/udp_send.c"
	"../net/udp/udp_sendto_buffered.c"
	"../net/udp/udp_sendto_unbuffered.c"
	"../net/udp/udp_setsockopt.c"
	"../net/udp/udp_txdrain.c"
	"../net/udp/udp_wrbuffer.c"
	"../net/udp/udp_wrbuffer_dump.c"
	"../net/utils/net_chksum.c"
	"../net/utils/net_dsec2tick.c"
	"../net/utils/net_dsec2timeval.c"
	"../net/utils/net_icmpchksum.c"
	"../net/utils/net_incr32.c"
	"../net/utils/net_ipchksum.c"
	"../net/utils/net_ipv6_mask2pref.c"
	"../net/utils/net_ipv6_maskcmp.c"
	"../net/utils/net_ipv6_pref2mask.c"
	"../net/utils/net_lock.c"
	"../net/utils/net_tcpchksum.c"
	"../net/utils/net_timeval2dsec.c"
	"../net/utils/net_udpchksum.c"
	)
set(deps_sources
	"../libs/libc/queue/dq_addafter.c"
	"../libs/libc/queue/dq_addbefore.c"
	"../libs/libc/queue/dq_addfirst.c"
	"../libs/libc/queue/dq_addlast.c"
	"../libs/libc/queue/dq_cat.c"
	"../libs/libc/queue/dq_count.c"
	"../libs/libc/queue/dq_rem.c"
	"../libs/libc/queue/dq_remfirst.c"
	"../libs/libc/queue/dq_remlast.c"
	"../libs/libc/queue/sq_addafter.c"
	"../libs/libc/queue/sq_addfirst.c"
	"../libs/libc/queue/sq_addlast.c"
	"../libs/libc/queue/sq_cat.c"
	"../libs/libc/queue/sq_count.c"
	"../libs/libc/queue/sq_rem.c"
	"../libs/libc/queue/sq_remafter.c"
	"../libs/libc/queue/sq_remfirst.c"
	"../libs/libc/queue/sq_remlast.c"
	"../mm/iob/iob_copyin.c"
	"../mm/iob/iob_remove_queue.c"
	"../mm/iob/iob_free_queue.c"
	"../mm/iob/iob_alloc.c"
	"../mm/iob/iob_peek_queue.c"
	"../mm/iob/iob_pack.c"
	"../mm/iob/iob_trimhead_queue.c"
	"../mm/iob/iob_add_queue.c"
	"../mm/iob/iob_free.c"
	"../mm/iob/iob_contig.c"
	"../mm/iob/iob_copyout.c"
	"../mm/iob/iob_statistics.c"
	"../mm/iob/iob_dump.c"
	"../mm/iob/iob_alloc_qentry.c"
	"../mm/iob/iob_free_qentry.c"
	"../mm/iob/iob_trimhead.c"
	"../mm/iob/iob_clone.c"
	"../mm/iob/iob_free_chain.c"
	"../mm/iob/iob_trimtail.c"
	"../mm/iob/iob_navail.c"
	"../mm/iob/iob_concat.c"
	"../mm/iob/iob_initialize.c"
	"../mm/iob/iob_notifier.c"
	)
set(mocks_sched_sources
	"mocks/sched/clock/clock_initialize.c"
	"mocks/sched/sched/sched_getsockets.c"
	"mocks/sched/sched/sched_idletask.c"
	"mocks/sched/sched/sched_lock.c"
	"mocks/sched/sched/sched_unlock.c"
	"mocks/sched/semaphore/sem_destroy.c"
	"mocks/sched/semaphore/sem_post.c"
	"mocks/sched/semaphore/sem_timedwait.c"
	"mocks/sched/semaphore/sem_trywait.c"
	"mocks/sched/semaphore/sem_wait.c"
	)
set(mocks_libs_sources
	"mocks/libs/libc/errno/lib_errno.c"
	"mocks/libs/libc/semaphore/sem_init.c"
	"mocks/libs/libc/semaphore/sem_setprotocol.c"
	"mocks/libs/libc/semaphore/sem_getvalue.c"
	)
set(mocks_arch_sources
	"mocks/arch/src/up_interrupt_context.c"
	)
add_library(net_lib OBJECT ${net_sources})
add_library(deps_lib OBJECT ${deps_sources})
add_library(mocks_sched_lib OBJECT ${mocks_sched_sources})
add_library(mocks_libs_lib OBJECT ${mocks_libs_sources})
add_library(mocks_arch_lib OBJECT ${mocks_arch_sources})
target_include_directories(net_lib PRIVATE
	.
	./include/
	../net/
	../include/
	)
target_include_directories(deps_lib PRIVATE
	.
	./include/
	../include/
	)
target_include_directories(mocks_sched_lib PRIVATE
	.
	./include/
	../include/
	../sched/
	)
target_include_directories(mocks_libs_lib PRIVATE
	.
	./include/
	../include/
	)
target_include_directories(mocks_arch_lib PRIVATE
	.
	./include/
	../include/
	)
add_executable(test
	"test_main.cpp"
	"tests/simple.cpp"
	)
target_include_directories(test PRIVATE . include include_nuttx)
target_link_libraries(test PRIVATE
	net_lib
	deps_lib
	mocks_sched_lib
	mocks_libs_lib
	mocks_arch_lib
	)
