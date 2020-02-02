int p[1000001];
vector<int> primes;

void sieve()
{
	p[0] = p[1] = 1;

	REP(i,2,1000001)
	{
		if(!p[i])
		{
			for(int j=i+i; j<=1000000; j+=i)
				p[j] = 1;
		}
	}
	FOR(i,1000001)
		if(!p[i])
			primes.pb(i);
}
