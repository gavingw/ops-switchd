AUTOMAKE_OPTIONS = foreign subdir-objects
sbin_PROGRAMS = ops-switchd
OPS_OVS = $(top_builddir)/../ops-ovs
ops_switchd_SOURCES = \
	bridge.c \
	bridge.h \
	ovs-vswitchd.c \
	system-stats.c \
	system-stats.h \
	subsystem.c \
	bufmon.c \
        bufmon-provider.c \
        bufmon-provider.h \
	vrf.c \
	vrf.h \
        openswitch-idl.h \
        openswitch-dflt.h \
        ops-dirs.h \
        ops-dirs.c \
        plugins.c \
        plugins.h
ops_switchd_LDADD = \
        $(LIBLTDL) $(LIBADD_DL) \
        $(OPS_OVS)/lib/libopsopenvswitch.la \
        $(OPS_OVS)/ofproto/libopsofproto.la \
        $(OPS_OVS)/sandbox/ovs/ofproto/libofproto.la \
        $(OPS_OVS)/sandbox/ovs/lib/libsflow.la \
        $(OPS_OVS)/sandbox/ovs/lib/libopenvswitch.la
ops_switchd_CPPFLAGS =  $(AM_CPPFLAGS) -DOPS -DOPS_TEMP
ops_switchd_CFLAGS = \
        -I $(OPS_OVS) \
        -I $(OPS_OVS)/lib \
        -I $(OPS_OVS)/sandbox/ovs \
        -I $(OPS_OVS)/sandbox/ovs/lib \
        -I $(OPS_OVS)/sandbox/ovs/include
ops_switchd_LDFLAGS = $(AM_LDFLAGS) -static
ops-dirs.c: ops-dirs.c.in Makefile
	$(AM_V_GEN)(echo '/* -*- mode: c; buffer-read-only: t -*- */' \
                        && sed < ops-dirs.c.in \
                            -e 's,[@]libdir[@],"$(libdir)",g') \
	     > ops-dirs.c.tmp && \
	mv ops-dirs.c.tmp ops-dirs.c
