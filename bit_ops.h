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
