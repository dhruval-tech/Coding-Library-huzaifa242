//Sparse Table
//Usage sparse_table s1(n)
#define lgs 20
struct data
{
	//data in sparse table
};
class sparse_table
{
	private:
	data sprs[MAX][lgs];
	int n;
	public:
	sparse_table(int size)
	{
		n=size;
	}
	void build()
	{
		memset(sprs,-1,sizeof(sprs));
		int i,j;
		for(i=0;i<n;i++)
		sprs[i][0]=//initialize value;
		for(j=1;j<lgs;j++)
		{
			for(i=0;i+(1<<j)<=n;i++)
			{
				sprs[i][j]= min(sprs[i][j-1],sprs[i+(1<<(j-1))][j-1]);
				//always relation between sprs[i][j-1] and sprs[i+(1<<(j-1))][j-1]
			}
		}
	}
	data query(int l, int r)
	{
		int i=log2(r-l+1),j;
		return min(sprs[l][i], sprs[r-(1<<i)+1][i]);//for O(1) relation use this
		//otherwise do log query using bits x=r-l+1
		long long sum = 0;
		for (j=lgs-1;j>=0;j--) 
		{
			if((1<<j)<=r-l+1) 
			{
				sum+=sprs[l][j];
				l+= (1<<j);
			}
		}
	}
};