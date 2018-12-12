char str[] = ">_<\n1:)2 > : = ->\n: 3\n8)\n:->\no_0\n(*V*)\n= ^. ^=\n: o3\n<> <\n< : 3)~\n= 8)\n:(III)-\n> 8--3\n^ o, o ^\n(*) >\n(‘.’)\n_@_v\n300!", *p = str;
	int sum = 0;
	int r = 0;
	do
	{
		if (*p >= '0' && *p <= '9') r = r * 10 + *p - '0';
		else
		{
			sum += r; r = 0;
		}
	} while (*p++);
	cout << sum;
	return 0;