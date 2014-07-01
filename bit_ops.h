/*
 * Almost everything in this file comes from the PPAA book
 */

/*
 * Clear the Least Significant Bit
 */
unsigned clear_last_bit(unsigned x)
{
    return x & (x-1);
}

/*
 * Identify the Least Significant Bit
 * e.g.:
 *  lowest_set_bit(1011) = 0001
 *  lowest_set_bit(1010) = 0010
 */
unsigned lowest_set_bit(unsigned x)
{
    return x & ~(x-1);
}

bool power_of_two(unsigned x)
{
    if (!x)
        return false;
    return 0 == (x & (x - 1));
}

unsigned count_bits_set(unsigned x)
{
    unsigned count = 0;
    while(x) {
        x = clear_last_bit(x);
        ++count;
    }
    return count;
}

/*
 * In my words, folding over is to find the most significant set bit,
 * and make everything to the right set. E.g.:
 *  fold_over(0010000000000000) = 0011111111111111
 */
unsigned fold_over(unsigned x)
{
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    return x;
}

/*
 * Identify the most significant set bit
 */
unsigned highest_set_bit(unsigned x)
{
    x = fold_over(x);
    return (x & ~(x-1));
}

/*
 * log_2(x)
 */
unsigned log_two(unsigned x)
{
    x = x - 1;
    x = fold_over(x);
    x = x + 1;
    for (auto index = 0; index < 32; index++) {
        if (x == (0x1 << index))
            return index;
    }
}

unsigned next_power_of_two(unsigned x)
{
    x = fold_over(x);
    return (x + 1);
}

unsigned reverse_bits(unsigned x)
{
    x = ((x & 0xffff0000) >> 16) | ((x & 0x0000ffff) << 16);
    x = ((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8);
    x = ((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4);
    x = ((x & 0xcccccccc) >> 2) | ((x & 0x55555555) << 2);
    return x;
}

int multiply(int x, int y)
{
    int product = 0;
    while (y) {
        product += x << log_x(lowest_set_bit(y));
        y = clear_last_bit(y);
    }
}
