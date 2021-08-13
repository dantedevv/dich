#pragma once

#include <stdint.h>
#include <stddef.h>

int load_from_file(void *element, const char *fname, size_t size);
int save_to_file(const void *element, const char *fname, size_t size);
