/******************************************************************************
 * Copyright (C) 2017, The Linux Foundation. All rights reserved.
 * Not a Contribution.
 ******************************************************************************/
/******************************************************************************
 *
 *  Copyright (C) 2016 The Android Open Source Project
 *  Copyright (C) 2009-2012 Broadcom Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/

/*
 * Changes from Qualcomm Innovation Center are provided under the following license:
 * Copyright (c) 2022 Qualcomm Innovation Center, Inc. All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */

#ifndef BTIF_A2DP_H
#define BTIF_A2DP_H

#include <stdbool.h>

#include "bta_av_api.h"

// Process 'idle' request from the BTIF state machine during initialization.
void btif_a2dp_on_idle();

// Process 'start' request from the BTIF state machine to prepare for A2DP
// streaming.
// |p_av_start| is the data associated with the request - see |tBTA_AV_START|.
// |pending_start| should be set to true if the BTIF state machine is in
// 'pending start' state.
// Returns true if an ACK for the local command was sent, otherwise false.
bool btif_a2dp_on_started(tBTA_AV_START* p_av_start, bool pending_start,
                          tBTA_AV_HNDL hdl);

// Process 'stop' request from the BTIF state machine to stop A2DP streaming.
// |p_av_suspend| is the data associated with the request - see
// |tBTA_AV_SUSPEND|.
void btif_a2dp_on_stopped(tBTA_AV_SUSPEND* p_av_suspend);

// Process 'suspend' request from the BTIF state machine to suspend A2DP
// streaming.
// |p_av_suspend| is the data associated with the request - see
// |tBTA_AV_SUSPEND|.
void btif_a2dp_on_suspended(tBTA_AV_SUSPEND* p_av_suspend);

// BA suspended ack
void btif_ba_audio_on_suspended(uint8_t result);

// BA stopped ack
void btif_ba_audio_on_stopped(uint8_t result);

// BA started ack
void btif_ba_audio_on_started(uint8_t result);

// Process 'offload start' request from the BTIF state machine to start
// offloading of the A2DP streaming.
// |status| is the processing status of the request prior to this call.
// The value can be |BTA_AV_SUCCESS| if the processing has been successful
// so far, or |BTA_AV_FAIL*| if the request has already failed.
void btif_a2dp_on_offload_started(tBTA_AV_STATUS status);

// Dump debug-related information for the A2DP module.
// |fd| is the file descriptor to use for writing the ASCII formatted
// information.
void btif_debug_a2dp_dump(int fd);

// Initialize sink variables
void btif_a2dp_sink_on_init(void);

// Honor remote start
void btif_a2dp_honor_remote_start(struct alarm_t **remote_start_alarm, int index);

bool btif_a2dp_sink_is_hal_v2_enabled(void);

bool btif_a2dp_sink_is_hal_v2_supported(void);

bt_status_t btif_a2dp_sink_setup_codec(tBTA_AV_HNDL hndl);

bool btif_a2dp_sink_start_session(const RawAddress& peer_address);

bool btif_a2dp_sink_is_restart_session_needed();

bool btif_a2dp_sink_end_session(const RawAddress& peer_address);

bool btif_a2dp_sink_restart_session(const RawAddress& old_peer_address,
                                      const RawAddress& new_peer_address);

void btif_a2dp_sink_process_request(tA2DP_CTRL_CMD cmd);
#endif /* BTIF_A2DP_H */
