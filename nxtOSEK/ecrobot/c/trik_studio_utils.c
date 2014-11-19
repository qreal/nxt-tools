#include "trik_studio_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

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
