int PARTITION( R[], int l, int h ) 
{
	int i, j, tmp;
	i = l; j = h; tmp = R[i];
	do {
		while( (R[j].key >= tmp.key) && (i<j) ) j--;
		if ( i < j ) R[i++] = R[j];
		while( ( R[i].key <= tmp.key) && (i<j) ) i++;
		if ( i < j ) R[j--] = R[i];
	}while (i != j);
	R[i] = tmp;
	return i;
}

void QUICKSORT( R[], int s1, int t1 )
{
	int i;
	if ( s1 < t1 )
	{
		i = PARTITION(R, s1, t1);
		QUICKSORT( R, s1, i-1 );
		QUICKSORT( R, i+1, t1 );
	}
}
