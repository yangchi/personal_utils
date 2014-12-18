package main

import "fmt"

func main() {
	var a, b uint8 = 123, 2
	fmt.Printf("%d\n", Multiply(a, b))
	a = 255
	b = 255
	fmt.Printf("%d\n", Add8(a, b))
	var c, d uint16 = 65535, 65535
	fmt.Printf("%d\n", Add16(c ,d))
}

func Multiply (a, b uint8) (uint16) {
	var b_shifted uint16 = uint16(b)
	var result uint16 = 0
	for a > 0 {
		var a_last_bit uint8 = a & 1
		if a_last_bit > 0 {
			result = uint16(Add16(result, b_shifted))
		}
		b_shifted <<= 1
		a >>= 1
	}
	return result
}

func Add16 (a, b uint16) (uint32) {
	var pos uint16 = 1
	var result, carryover uint32 = 0, 0
	var temp_a, temp_b uint16 = a, b
	for temp_a | temp_b > 0 {
		var cur_a, cur_b uint16 = a & pos, b & pos
		var cur uint32 = uint32(cur_a ^ cur_b) ^ carryover;
		result |= cur | carryover
		carryover = uint32(cur_a & cur_b) | (uint32(cur_a) & carryover) | (uint32(cur_b) & carryover)
		carryover <<= 1
		pos <<= 1
		temp_a >>= 1
		temp_b >>= 1
	}
	return result | carryover
}

func Add8 (a, b uint8) (uint16) {
	var pos uint8 = 1 
	var result, carryover uint16 = 0, 0
	var temp_a, temp_b uint8 = a, b
	for temp_a | temp_b > 0 {
		var cur_a, cur_b uint8 = a & pos, b & pos
		var cur uint16 = uint16(cur_a ^ cur_b) ^ carryover;
		result |= cur | carryover
		carryover = uint16(cur_a & cur_b) | (uint16(cur_a) & carryover) | (uint16(cur_b) & carryover)
		carryover <<= 1 
		pos <<= 1
		temp_a >>= 1
		temp_b >>= 1
	}
	return result | carryover
}

