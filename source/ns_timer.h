/*
 * Copyright (c) 2014-2015 ARM Limited. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef NS_TIMER_H_
#define NS_TIMER_H_

#ifdef __cplusplus
extern "C" {
#endif

extern int8_t ns_timer_init(void);
extern int8_t ns_timer_sleep(void);

#ifdef MBED_CONF_NANOSTACK_EVENTLOOP_EXCLUDE_HIGHRES_TIMER
#define NS_EXCLUDE_HIGHRES_TIMER   MBED_CONF_NANOSTACK_EVENTLOOP_EXCLUDE_HIGHRES_TIMER
#endif

#ifdef __cplusplus
}
#endif

#endif /*NS_TIMER_H_*/
