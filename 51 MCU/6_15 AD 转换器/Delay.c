
void Delay1()		//@11.0592MHz
{
	unsigned char i, j;

	i = 2;
	j = 173;
	do
	{
		while (--j);
	} while (--i);
}

