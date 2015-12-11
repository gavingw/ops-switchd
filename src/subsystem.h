/* Copyright (c) 2008, 2009, 2010, 2011, 2012, 2014 Nicira, Inc.
 * Copyright (C) 2015 Hewlett-Packard Development Company, L.P.
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
 */

#ifndef VSWITCHD_SUBSYSTEM_H
#define VSWITCHD_SUBSYSTEM_H 1

void subsystem_init(void);
void subsystem_exit(void);

void subsystem_run(void);
void subsystem_wait(void);

#endif /* subsystem.h */
