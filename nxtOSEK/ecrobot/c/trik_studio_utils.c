#include "trik_studio_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "ecrobot_interface.h"
#include "task.h"


// ------------------------- Timers dispath ------------------------- //

typedef struct
{
	U32 timestamp;
	TaskType task;
	EventMaskType timer;
} EventInfo;

#define TS_MAX_TIMERS 32
U8 ts_timers_count = 0;
EventInfo ts_timers[TS_MAX_TIMERS];

U8 ts_bin_search(U32 timestamp)
{
	if (!ts_timers_count)
		return 0;

	U8 l = 0;
	U8 r = ts_timers_count - 1;
	while (l < r) {
		const U8 middle = (l + r) >> 1;
		if (ts_timers[middle].timestamp == timestamp)
			return middle;
		if (ts_timers[middle].timestamp < timestamp)
			l = middle + 1;
		else
			r = middle - 1;
	}

	return l;
}

void wait(U32 delay)
{
	if (ts_timers_count >= TS_MAX_TIMERS)
		return;

	const U32 timestamp = systick_get_ms() + delay;
	U8 index = ts_bin_search(timestamp);
	if (index < ts_timers_count && ts_timers[index].timestamp <= timestamp)
		++index;

	if (ts_timers_count)
		for (U8 i = ts_timers_count - 1; i >= index; --i)
			ts_timers[i + 1] = ts_timers[i];

	ts_timers[index].timestamp = timestamp;
	ts_timers[index].task = runtsk;
	// TODO: This will not probably work if user declares own timers. Events must be taken by name or passed as parameter.
	const EventMaskType timerId = (1UL << runtsk);
	ts_timers[index].timer = timerId;
	++ts_timers_count;

	WaitEvent(timerId);
	ClearEvent(timerId);
}

void ts_dispatch_timers()
{
	if (!ts_timers_count || ts_timers[0].timestamp > systick_get_ms())
		return;

	TaskType taskId = ts_timers[0].task;
	EventMaskType timerId = ts_timers[0].timer;
	for (U8 i = 1; i < ts_timers_count; ++i)
		ts_timers[i - 1] = ts_timers[i];
	--ts_timers_count;

	SetEvent(taskId, timerId);
}


// -------------------------- String utils -------------------------- //

char *formatString(char *format, ...)
{
	char buffer[256];
	va_list args;
	va_start(args, format);
	vsnprintf(buffer, 256, format, args);
	va_end(args);
	return buffer;
}

char *concat(char *str1, char *str2) {
	char *result = (char *)malloc(strlen(str1) + strlen(str2));
	strcpy(result, str1);
	return strcat(result, str2);
}

char *int_to_string(int i) {
	return formatString("%d", i);
}

char *float_to_string(float f) {
	return formatString("%d.%d", (int)f, ((int)((f - (int)f) * 1000)));
}

char *other_to_string(void *arr) {
	return formatString("%p", arr);
}
