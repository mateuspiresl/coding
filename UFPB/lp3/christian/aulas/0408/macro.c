#define OFFSET_VALUE 10
#define OFFSET_FUNCTION(val) val + OFFSET_VALUE

int main(int argc, char *argv[])
{
	int x = argc > 1 ? 2 : 1;
	int y = OFFSET_FUNCTION(x);

	return y;
}