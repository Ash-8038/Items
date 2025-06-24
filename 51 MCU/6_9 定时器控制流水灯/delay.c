
void Delay1ms(int x)		//@11.0592MHz
{
	unsigned char i, j;

	while(x--)
	{
			i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
	}
}
