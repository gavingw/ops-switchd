/*
 * Copyright (c) 2016 Hewlett Packard Enterprise Development LP
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *
 * VXLAN SwitchD ASIC Provider API
 *
 * Declares the functions and data structures that are used between the
 * SwitchD VXLAN feature and ASIC-specific providers.
 */
#ifndef VXLAN_ASIC_PLUGIN_H
#define VXLAN_ASIC_PLUGIN_H 1

#include "ofproto/ofproto.h"
#include "bridge.h"
#include "hmap.h"
#include "log-switch-asic-provider.h"


/** @def VXLAN_ASIC_PLUGIN_INTERFACE_NAME
 *  @brief asic plugin name definition
 */
#define VXLAN_ASIC_PLUGIN_INTERFACE_NAME     "VXLAN_ASIC_PLUGIN"

/** @def VXLAN_ASIC_PLUGIN_INTERFACE_MAJOR
 *  @brief plugin major version definition
 */
#define VXLAN_ASIC_PLUGIN_INTERFACE_MAJOR    1

/** @def ASIC_PLUGIN_INTERFACE_MINOR
 *  @brief plugin minor version definition
 */
#define VXLAN_ASIC_PLUGIN_INTERFACE_MINOR    1



struct vxlan_asic_plugin_interface {
    /*
     * set_logical_switch
     *
     * configure (add/delete/modify) Logical Switch settings per-bridge
     *
     * @param ofproto     struct ofproto that describes either a bridge or a VRF.
     * @param aux         pointer to struct port that is used to look up a
     *                    previously-added bundle
     * @param action      add/delete/modify action.
     * @param log_switch  pointer to logical_switch_node, describes how the logical switch
     *                    should be configured.
     *
     * @return int        API status:
     *                    0               success
     *                    EOPNOTSUPP      this API not supported by this provider
     *                    other value     ASIC provider dependent error
     */
    int (*set_logical_switch)(const struct ofproto *ofproto, void *aux,
            enum logical_switch_action action,
            struct logical_switch_node *log_switch);

    /* vxlan plugin functions */
    int (*vport_bind_all_ports_on_vlan)(int vni, int vlan);
    int (*vport_unbind_all_ports_on_vlan)(int vni, int vlan);
    int (*vport_bind_port_on_vlan)(int vni, int vlan, struct port *port);
    int (*vport_unbind_port_on_vlan)(int vni, int vlan, struct port *port);

};

#endif /* vxlan_asic_provider.h */
