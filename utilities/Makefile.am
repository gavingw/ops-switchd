AUTOMAKE_OPTIONS = foreign subdir-objects
OPS_OVS = $(top_builddir)/../ops-ovs
OVS = $(OPS_OVS)/sandbox/ovs
sbin_PROGRAMS = ovs-appctl ovs-vsctl
ovs_appctl_SOURCES = ovs-appctl.c
ovs_appctl_LDADD = \
        $(LIBLTDL) $(LIBADD_DL) \
        $(OVS)/lib/libopenvswitch.la
ovs_vsctl_SOURCES = ovs-vsctl.c
ovs_vsctl_LDADD = \
        $(LIBLTDL) $(LIBADD_DL) \
        $(OVS)/ofproto/libofproto.la \
        $(OVS)/lib/libopenvswitch.la
ovs_appctl_CPPFLAGS =  $(AM_CPPFLAGS) -DOPS -DOPS_TEMP
ovs_vsctl_CPPFLAGS =  $(AM_CPPFLAGS) -DOPS -DOPS_TEMP
ovs_appctl_CFLAGS = \
        -I $(OPS_OVS)/lib \
        -I $(OVS) \
        -I $(OVS)/lib \
        -I $(OVS)/include
ovs_vsctl_CFLAGS = \
        -I $(OPS_OVS)/lib \
        -I $(OVS) \
        -I $(OVS)/lib \
        -I $(OVS)/include
ovs_appctl_LDFLAGS = $(AM_LDFLAGS) -static
ovs_vsctl_LDFLAGS = $(AM_LDFLAGS) -static
