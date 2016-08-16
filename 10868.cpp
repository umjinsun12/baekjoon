for(int i=0; i < n ; i++){
	if(i%r == 0)
		group[i/r] = a[i];
	else
		group[i/r] = min(group[i/r]. a[i]);
}