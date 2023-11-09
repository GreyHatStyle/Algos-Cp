
const int N = 1e7+10;
vector <bool> primer(N, 1);

void Sieve(){
	primer[0] = primer[1] = false;
	for(int i=2 ; i < N ; i++){
		if (primer[i] == true){
			for(int j = 2*i; j<N; j+=i)
				primer[j] = false;
		}
	}
}
