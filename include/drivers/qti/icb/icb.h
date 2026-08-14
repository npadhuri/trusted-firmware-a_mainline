/*
 * Copyright (c) 2026, Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Top-level init for the QTI ICB drivers (micro-arbiter, NoC error
 * handler, configuration). Split into qti_icb_arbiter_init() and
 * qti_icb_init() so callers can sequence qti_coreinit_init() (which
 * requires the arbiter) between the two.
 */

#ifndef QTI_ICB_H
#define QTI_ICB_H

/*
 * Initialise the QTI ICB micro-arbiter. Call once from BL31 platform setup,
 * before qti_coreinit_init() (which votes bandwidth via the arbiter) and
 * before qti_icb_init() (whose static config write list may itself depend
 * on bus rails voted through the arbiter).
 */
#ifdef QTI_ICB_ENABLED
void qti_icb_arbiter_init(void);
#else
static inline void qti_icb_arbiter_init(void) {}
#endif

/*
 * Initialise the QTI NoC error handler and static ICB configuration.
 * Call once from BL31 platform setup, after qti_icb_arbiter_init() and
 * qti_coreinit_init().
 */
#ifdef QTI_ICB_ENABLED
void qti_icb_init(void);
#else
static inline void qti_icb_init(void) {}
#endif

#endif /* QTI_ICB_H */
