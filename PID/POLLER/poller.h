﻿#ifndef POLLER_H
#define POLLER_H

#include "Std_Types.h"
void poller_Init(void);
void Poller__StartPolling(void);
void Poller__StopPolling(void);
void poller_SetPollTime(uint32 time_ms);
static void updatePollCounter(void);
static void poll(void);

#endif
