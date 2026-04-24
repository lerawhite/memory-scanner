
#include <operation(l2)\memory\search_byte_pattern.h>


std::vector<SIZE_T> search_byte_pattern(const BYTE* data, SIZE_T data_size, const BYTE* pattern, SIZE_T pattern_size)
{
	std::vector<SIZE_T> results;

	if (pattern_size == 0 || data_size < pattern_size)
		return results;

	for (SIZE_T i = 0; i <= data_size - pattern_size; i++)
	{
		bool match = true;

		for (SIZE_T j = 0; j < pattern_size; j++)
		{
			if (data[i + j] != pattern[j])
			{
				match = false;
				break;
			}
		}
		if (match)
			results.push_back(i);	
	}
	return results;
}