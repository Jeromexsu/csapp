//show implementation of conditional branches with conditional move instructions
long absdiff(long x, long y) {
	long result;
	if(x<y) result = y-x;
	else result = x-y;
	return result;
}