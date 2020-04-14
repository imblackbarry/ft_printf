#include "libft.h"

void	ft_bitset(uint8_t bits, unsigned short value, size_t index)
{
	uint8_t bit_at_index;

	bit_at_index = 1 << (index - 1);
	if (value == 1)
		bits |= bit_at_index;
	else if (value == 0)
	{
		bit_at_index = ~bit_at_index;
		bits &= bit_at_index;
	}
}